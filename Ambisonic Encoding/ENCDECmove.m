
function [y] = ENCDECmove(input1,input2,Fs, az1Start, az1End, el1Start, el1End,  az2Start, az2End, el2Start, el2End)
%%

% Load angle for each speaker
angleData = readtable('/Users/andersbargum/Documents/MATLAB/SMCStuff/Ny-Sal-3D-data.xlsx');

anglesAz = table2array(angleData(1:48,7));
anglesEl = table2array(angleData(1:48,8));

% Create a sphere with a distribution of points
pickedSphere = [anglesAz anglesEl]';

%Specify a desired ambisonic order
order = 5;

%Create Audio Input and Output Objects
%Load the ambisonic audio file of helicopter sound and convert it to 48 kHz for compatibility with the HRTF dataset. Specify the ambisonic format of the audio file. 
%Create an audio file sampled at 48 kHz for compatibility with the HRTF dataset.

x = input1(:,1);
x1 = input2(:,1);
fs = Fs;
desiredFs = 48e3;

%%%%%%%%%%%%%%%%%%%%%%%%%
az1 = linspace(az1Start,az1End,length(x)); 
az2 = linspace(az2Start,az2End,length(x));
az1 = 360-az1; az2 = 360-az2;

el1 = linspace(el1Start,el1End,length(x)); 
el2 = linspace(el2Start,el2End,length(x));

deviceType = linspace(1,1,length(x));

devices(:,:,1) = [az1; el1; deviceType];
devices(:,:,2) = [az2; el2; deviceType];

azimuth = deg2rad(mod(devices(1, :,:), 360));
elevation = deg2rad(devices(2, :,:));

seqVector = 1:orderChannels(order);
normVector = ones(1, orderChannels(order));

%take size of only the columns in the devices matrix and assign it num
%devices (elements)
[~, numDevices,numSources] = size(devices);

%%%%%%%%%%%%%%%%%%%%%%%%%%%Parameters for matrix multiplication
c_az = cos(azimuth);
c_2az = cos(2*azimuth);
c_3az = cos(3*azimuth);
c_4az = cos(4*azimuth);
c_5az = cos(5*azimuth);
c_6az = cos(6*azimuth);
c_7az = cos(7*azimuth);

s_az = sin(azimuth);
s_2az = sin(2*azimuth);
s_3az = sin(3*azimuth);
s_4az = sin(4*azimuth);
s_5az = sin(5*azimuth);
s_6az = sin(6*azimuth);
s_7az = sin(7*azimuth);

c_el = cos(elevation);
c_el2 = c_el.*c_el;
c_el3 = c_el.*c_el.*c_el;
c_el4 = c_el.*c_el.*c_el.*c_el;
c_el5 = c_el.*c_el.*c_el.*c_el.*c_el;
c_el6 = c_el.*c_el.*c_el.*c_el.*c_el.*c_el;
c_el7 = c_el.*c_el.*c_el.*c_el.*c_el.*c_el.*c_el;

s_el = sin(elevation);
s_el2 = s_el.*s_el;
s_el3 = s_el.*s_el.*s_el;
s_el4 = s_el.*s_el.*s_el.*s_el;
s_el5 = s_el.*s_el.*s_el.*s_el.*s_el;
s_el6 = s_el.*s_el.*s_el.*s_el.*s_el.*s_el;
s_el7 = s_el.*s_el.*s_el.*s_el.*s_el.*s_el.*s_el;

s_2el = sin(2*elevation);

sqrt3 = sqrt(3);
sqrt5 = sqrt(5);
sqrt7 = sqrt(7);
sqrt15 = sqrt(15);
sqrt21 = sqrt(21);
sqrt35 = sqrt(35);
sqrt105 = sqrt(105);
sqrt231 = sqrt(231);
sqrt429 = sqrt(429);

sqrt3over2 = sqrt(3/2);
sqrt5over2 = sqrt(5/2);
sqrt7over2 = sqrt(7/2);
sqrt21over2 = sqrt(21/2);
sqrt35over2 = sqrt(35/2);
sqrt77over2 = sqrt(77/2);
sqrt105over2 = sqrt(105/2);
sqrt231over2 = sqrt(231/2);
sqrt1001over6 = sqrt(1001/6);

oneHalf = 1/2;
oneQuarter = 1/4;
oneEighth = 1/8;
threeEighth = 3/8;
oneSixteenth = 1/16;
threeSixteenths = 3/16;
oneThirtysecond = 1/32;
%%%%%%%%%%%%%%%%%%%%%%%%%%%

encodeMatrix(:,:,1) = zeros(numDevices, orderChannels(order));
encodeMatrix(:,:,2) = zeros(numDevices, orderChannels(order));

encodeMatrix(:,1,1) = deviceType;                         % W
encodeMatrix(:,1,2) = deviceType;                         % W

encodeMatrix(:, 2, :) = sin(azimuth).*cos(elevation);      % Y
encodeMatrix(:, 3, :) = sin(elevation);                    % Z
encodeMatrix(:, 4, :) = cos(azimuth).*cos(elevation);      % X
encodeMatrix(:, 5, :) = oneHalf*sqrt3.*sin(2*azimuth).*cos(elevation).*cos(elevation);      % V
encodeMatrix(:, 6, :) = oneHalf*sqrt3.*sin(azimuth).*sin(2*elevation);                      % T
encodeMatrix(:, 7, :) = oneHalf*(3.*sin(elevation).^2-1.);                                  % R
encodeMatrix(:, 8, :) = oneHalf*sqrt3.*cos(azimuth).*sin(2*elevation);                      % S
encodeMatrix(:, 9, :) = oneHalf*sqrt3.*cos(2*azimuth).*cos(elevation).*cos(elevation);      % U 

encodeMatrix(:, 10, :) = oneHalf*sqrt5over2*s_3az.*c_el3;                % Q
encodeMatrix(:, 11, :) = oneHalf*sqrt15*s_2az.*s_el.*c_el2;              % O
encodeMatrix(:, 12, :) = oneHalf*sqrt3over2*s_az.*(5*s_el2-1.).*c_el;    % M
encodeMatrix(:, 13, :) = oneHalf*s_el.*(5*s_el2-3.);                     % K
encodeMatrix(:, 14, :) = oneHalf*sqrt3over2*c_az.*(5*s_el2-1.).*c_el;    % L
encodeMatrix(:, 15, :) = oneHalf*sqrt15*c_2az.*s_el.*c_el2;              % N
encodeMatrix(:, 16, :) = oneHalf*sqrt5over2*c_3az.*c_el3;                % P

encodeMatrix(:, 17, :) = oneEighth*sqrt35*s_4az.*c_el4;                      % J
encodeMatrix(:, 18, :) = oneHalf*sqrt35over2*s_3az.*s_el.*c_el3;             % H
encodeMatrix(:, 19, :) = oneQuarter*sqrt5*s_2az.*(7.*s_el2-1.).*c_el2;       % F
encodeMatrix(:, 20, :) = oneHalf*sqrt5over2*s_az.*(7*s_el3-3*s_el).*c_el;    % D
encodeMatrix(:, 21, :) = oneEighth*(35*s_el4-30*s_el2+3.);                   % B
encodeMatrix(:, 22, :) = oneHalf*sqrt5over2*c_az.*(7*s_el3-3*s_el).*c_el;    % C
encodeMatrix(:, 23, :) = oneQuarter*sqrt5*c_2az.*(7*s_el2-1).*c_el2;         % E
encodeMatrix(:, 24, :) = oneHalf*sqrt35over2*c_3az.*s_el.*c_el3;             % G
encodeMatrix(:, 25, :) = oneEighth*sqrt35*c_4az.*c_el4;                      % I

encodeMatrix(:, 26, :) = threeEighth*sqrt7over2*s_5az.*c_el5;
encodeMatrix(:, 27, :) = threeEighth*sqrt35*s_4az.*s_el.*c_el4;
encodeMatrix(:, 28, :) = oneEighth*sqrt35over2*s_3az.*(9*s_el2-1).*c_el3;
encodeMatrix(:, 29, :) = oneQuarter*sqrt105*s_2az.*(3*s_el3-s_el).*c_el2;
encodeMatrix(:, 30, :) = oneEighth*sqrt15*s_az.*(21*s_el4-14*s_el2+1).*c_el;
encodeMatrix(:, 31, :) = oneEighth*(63*s_el5-70*s_el3+15*s_el);
encodeMatrix(:, 32, :) = oneEighth*sqrt15*c_az.*(21*s_el4-14*s_el2+1).*c_el;
encodeMatrix(:, 33, :) = oneQuarter*sqrt105*c_2az.*(3*s_el3-s_el).*c_el2;
encodeMatrix(:, 34, :) = oneEighth*sqrt35over2*c_3az.*(9*s_el2-1).*c_el3;
encodeMatrix(:, 35, :) = threeEighth*sqrt35*c_4az.*s_el.*c_el4;
encodeMatrix(:, 36, :) = threeEighth*sqrt7over2*c_5az.*c_el5;

%Waves: Each channel is encoded individually, like a mono track, in a set direction, and the results are summed together.
audioEnc = (x .* encodeMatrix(:, 1:orderChannels(order),1)) + (x1 .* encodeMatrix(:, 1:orderChannels(order),2));
audioEncNorm = bsxfun(@times, audioEnc, normVector);
audioOut = audioEncNorm(:, seqVector);

audioToWrite = resample(audioOut,desiredFs,fs);

%Create decodeMatrix
%loudspeakerInfo = sourcePosition(pick,:)';

azimuth = deg2rad(mod(pickedSphere(1, :), 360)); %%New azimuth value dependent on speaker position
elevation = deg2rad(pickedSphere(2, :));
deviceType = 1;
decodeMatrix = zeros(48,orderChannels(order)); % changed from 24 to 46 to fit the az angle of speakers

%%%%%%%%%%%%%%%%%%%%%%%%%%%
c_az = cos(azimuth);
c_2az = cos(2*azimuth);
c_3az = cos(3*azimuth);
c_4az = cos(4*azimuth);
c_5az = cos(5*azimuth);
c_6az = cos(6*azimuth);
c_7az = cos(7*azimuth);

s_az = sin(azimuth);
s_2az = sin(2*azimuth);
s_3az = sin(3*azimuth);
s_4az = sin(4*azimuth);
s_5az = sin(5*azimuth);
s_6az = sin(6*azimuth);
s_7az = sin(7*azimuth);

c_el = cos(elevation);
c_el2 = c_el.*c_el;
c_el3 = c_el.*c_el.*c_el;
c_el4 = c_el.*c_el.*c_el.*c_el;
c_el5 = c_el.*c_el.*c_el.*c_el.*c_el;
c_el6 = c_el.*c_el.*c_el.*c_el.*c_el.*c_el;
c_el7 = c_el.*c_el.*c_el.*c_el.*c_el.*c_el.*c_el;

s_el = sin(elevation);
s_el2 = s_el.*s_el;
s_el3 = s_el.*s_el.*s_el;
s_el4 = s_el.*s_el.*s_el.*s_el;
s_el5 = s_el.*s_el.*s_el.*s_el.*s_el;
s_el6 = s_el.*s_el.*s_el.*s_el.*s_el.*s_el;
s_el7 = s_el.*s_el.*s_el.*s_el.*s_el.*s_el.*s_el;

s_2el = sin(2*elevation);

sqrt3 = sqrt(3);
sqrt5 = sqrt(5);
sqrt7 = sqrt(7);
sqrt15 = sqrt(15);
sqrt21 = sqrt(21);
sqrt35 = sqrt(35);
sqrt105 = sqrt(105);
sqrt231 = sqrt(231);
sqrt429 = sqrt(429);

sqrt3over2 = sqrt(3/2);
sqrt5over2 = sqrt(5/2);
sqrt7over2 = sqrt(7/2);
sqrt21over2 = sqrt(21/2);
sqrt35over2 = sqrt(35/2);
sqrt77over2 = sqrt(77/2);
sqrt105over2 = sqrt(105/2);
sqrt231over2 = sqrt(231/2);
sqrt1001over6 = sqrt(1001/6);

oneHalf = 1/2;
oneQuarter = 1/4;
oneEighth = 1/8;
threeEighth = 3/8;
oneSixteenth = 1/16;
threeSixteenths = 3/16;
oneThirtysecond = 1/32;
%%%%%%%%%%%%%%%%%%%%%%%%%%%

%take the azimuth and elevation data from the loudspeaker positions and
%convert it to radians into the decode matrix
decodeMatrix(:, 1) = deviceType;                                    % W
decodeMatrix(:, 2) = sin(azimuth).*cos(elevation);                  % Y
decodeMatrix(:, 3) = sin(elevation);                                % Z
decodeMatrix(:, 4) = cos(azimuth).*cos(elevation);                  % X
decodeMatrix(:, 5)= oneHalf*sqrt3.*sin(2*azimuth).*cos(elevation).*cos(elevation);       % V
decodeMatrix(:, 6)= oneHalf*sqrt3.*sin(azimuth).*sin(2*elevation);                        % T
decodeMatrix(:, 7)= oneHalf*(3.*sin(elevation).^2-1.);                                     % R
decodeMatrix(:, 8)= oneHalf*sqrt3.*cos(azimuth).*sin(2*elevation);                        % S
decodeMatrix(:, 9)= oneHalf*sqrt3.*cos(2*azimuth).*cos(elevation).*cos(elevation);       % U

decodeMatrix(:, 10) = oneHalf*sqrt5over2*s_3az.*c_el3;                % Q
decodeMatrix(:, 11) = oneHalf*sqrt15*s_2az.*s_el.*c_el2;              % O
decodeMatrix(:, 12) = oneHalf*sqrt3over2*s_az.*(5*s_el2-1.).*c_el;    % M
decodeMatrix(:, 13) = oneHalf*s_el.*(5*s_el2-3.);                     % K
decodeMatrix(:, 14) = oneHalf*sqrt3over2*c_az.*(5*s_el2-1.).*c_el;    % L
decodeMatrix(:, 15) = oneHalf*sqrt15*c_2az.*s_el.*c_el2;              % N
decodeMatrix(:, 16) = oneHalf*sqrt5over2*c_3az.*c_el3;                % P

decodeMatrix(:, 17) = oneEighth*sqrt35*s_4az.*c_el4;                      % J
decodeMatrix(:, 18) = oneHalf*sqrt35over2*s_3az.*s_el.*c_el3;             % H
decodeMatrix(:, 19) = oneQuarter*sqrt5*s_2az.*(7.*s_el2-1.).*c_el2;       % F
decodeMatrix(:, 20) = oneHalf*sqrt5over2*s_az.*(7*s_el3-3*s_el).*c_el;    % D
decodeMatrix(:, 21) = oneEighth*(35*s_el4-30*s_el2+3.);                   % B
decodeMatrix(:, 22) = oneHalf*sqrt5over2*c_az.*(7*s_el3-3*s_el).*c_el;    % C
decodeMatrix(:, 23) = oneQuarter*sqrt5*c_2az.*(7*s_el2-1).*c_el2;         % E
decodeMatrix(:, 24) = oneHalf*sqrt35over2*c_3az.*s_el.*c_el3;             % G
decodeMatrix(:, 25) = oneEighth*sqrt35*c_4az.*c_el4;                      % I

decodeMatrix(:, 26) = threeEighth*sqrt7over2*s_5az.*c_el5;
decodeMatrix(:, 27) = threeEighth*sqrt35*s_4az.*s_el.*c_el4;
decodeMatrix(:, 28) = oneEighth*sqrt35over2*s_3az.*(9*s_el2-1).*c_el3;
decodeMatrix(:, 29) = oneQuarter*sqrt105*s_2az.*(3*s_el3-s_el).*c_el2;
decodeMatrix(:, 30) = oneEighth*sqrt15*s_az.*(21*s_el4-14*s_el2+1).*c_el;
decodeMatrix(:, 31) = oneEighth*(63*s_el5-70*s_el3+15*s_el);
decodeMatrix(:, 32) = oneEighth*sqrt15*c_az.*(21*s_el4-14*s_el2+1).*c_el;
decodeMatrix(:, 33) = oneQuarter*sqrt105*c_2az.*(3*s_el3-s_el).*c_el2;
decodeMatrix(:, 34) = oneEighth*sqrt35over2*c_3az.*(9*s_el2-1).*c_el3;
decodeMatrix(:, 35) = threeEighth*sqrt35*c_4az.*s_el.*c_el4;
decodeMatrix(:, 36) = threeEighth*sqrt7over2*c_5az.*c_el5;
    
decodeMatrix = pinv(decodeMatrix);

audioSeq = audioToWrite(:, seqVector);

% bsxfun applies element-by-element binary oprations, defined by the
% argument @times = array multiplication
audioSeqNorm = bsxfun(@times, audioSeq, normVector);    
audioDecoded = audioSeqNorm * decodeMatrix((1:orderChannels(order)), :);
%% OUTPUT

y = audioDecoded;

%%
%function defining the amount of ambizonic channels based on order
function channels = orderChannels(order)
    channels = (order+1)^2;
end

end