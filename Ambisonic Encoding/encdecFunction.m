%%
clear; clc;

%Load the ARI HRTF Dataset
ARIDataset = load('ReferenceHRTF.mat');
%Get the HRTF data in the required dimension of: [NumOfSourceMeasurements x 2 x LengthOfSamples]
hrtfData = ARIDataset.hrtfData;
sourcePosition = ARIDataset.sourcePosition(:,[1,2]);

desiredFs = 48e3;

%% HERE GOES ENC DEC FUNCTION

[x,fs] = audioread('/Users/andersbargum/Desktop/String quartet/Bongo1.wav');
[x1,fs] = audioread('/Users/andersbargum/Desktop/String quartet/Bongo2.wav');

audioDecoded = ENCDECmove(x,x1,fs,    90,180,0,0,   90,0,0,0);

%% TO LISTEN DIRECTLY 
%(See https://se.mathworks.com/help/audio/ug/ambisonic-binaural-decoding.html for source)

angleData = readtable('/Users/andersbargum/Documents/MATLAB/SMCStuff/Ny-Sal-3D-data.xlsx');
anglesAz = table2array(angleData(1:48,7));
anglesEl = table2array(angleData(1:48,8));

nPoints = 48;   % number of points to pick
sphereAZ = [anglesAz]';
sphereEL = [anglesEl]';
pickedSphere = [sphereAZ' sphereEL'];

% Compare distributed points on the sphere to points from the HRTF dataset
pick = zeros(1, nPoints);
d = zeros(size(pickedSphere,1), size(sourcePosition,1));
for ii = 1:size(pickedSphere,1)
    for jj = 1:size(sourcePosition,1)
        % Calculate arc length
        d(ii,jj) = acos( ...
            sind(pickedSphere(ii,2))*sind(sourcePosition(jj,2)) + ...
            cosd(pickedSphere(ii,2))*cosd(sourcePosition(jj,2)) * ... 
            cosd(pickedSphere(ii,1) - sourcePosition(jj,1)));
    end
    [~,Idx] = sort(d(ii,:)); % Sort points
    pick(ii) = Idx(1);       % Pick the closest point
end

FIR = cell(size(pickedSphere));

for ii = 1:length(pickedSphere)
    FIR{ii,1} = dsp.FrequencyDomainFIRFilter(hrtfData(:,pick(ii),1)');
    FIR{ii,2} = dsp.FrequencyDomainFIRFilter(hrtfData(:,pick(ii),2)');
end

desiredFs = 48e3;
samplesPerFrame = length(audioDecoded); %replace with 2048
audioFiltered = zeros(samplesPerFrame,size(FIR,1),2);

for ii = 1:size(FIR,1)
        
    audioFiltered(:,ii,1) = step(FIR{ii,1}, audioDecoded(:,ii)); % Left
    audioFiltered(:,ii,2) = step(FIR{ii,2}, audioDecoded(:,ii)); % Right
    
end
    
audioOutDecoded = 10*squeeze(sum(audioFiltered,2));   % Sum at each ear 
  
sound(audioOutDecoded, desiredFs);

%% TO EXPORT EACH INDIVIDUAL CHANNEL
for i = 1:48

filename = sprintf('/Users/andersbargum/Desktop/File for Test/18/Caj%d.wav', i);
audiowrite(filename,audioDecoded(:,i),desiredFs);

end