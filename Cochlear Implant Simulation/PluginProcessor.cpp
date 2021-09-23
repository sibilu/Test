/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
/*
static Array<float> getWhiteNoise(int numSamples) {
    
    Array<float> noise;
    
    float z0 = 0;
    float z1 = 0;
    bool generate = false;
    
    float mu = 0; // center (0)
    float sigma = 1; // spread -1 <-> 1
    
    float output = 0;
    float u1 = 0;
    float u2 = 0;
    
    Random r = Random::getSystemRandom();
    r.setSeed(Time::getCurrentTime().getMilliseconds());
    const float epsilon = std::numeric_limits<float>::min();
    
    for (int s=0; s < numSamples; s++)
    {
        
        // GENERATE ::::
        // using box muller method
        // https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform
        generate = !generate;
        
        if (!generate)
            output =  z1 * sigma + mu;
        else
        {
            do
            {
                u1 = r.nextFloat();
                u2 = r.nextFloat();
            }
            while ( u1 <= epsilon );
            
            z0 = sqrtf(-2.0 * logf(u1)) * cosf(2*float(double_Pi) * u2);
            z1 = sqrtf(-2.0 * logf(u1)) * sinf(2*float(double_Pi) * u2);
            
            output = z0 * sigma + mu;
        }
        
        // NAN check ...
        jassert(output == output);
        jassert(output > -50 && output < 50);
        
        //
        noise.add(output);
        
    }
    
    return noise;
    
}*/

//==============================================================================
BpfilterAudioProcessor::BpfilterAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
                    
#endif
{
}

BpfilterAudioProcessor::~BpfilterAudioProcessor()
{
}

//==============================================================================
const String BpfilterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BpfilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BpfilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BpfilterAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double BpfilterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BpfilterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BpfilterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BpfilterAudioProcessor::setCurrentProgram (int index)
{
}

const String BpfilterAudioProcessor::getProgramName (int index)
{
    return {};
}

void BpfilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void BpfilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    dsp::ProcessSpec spec;
    
    lastSampleRate = sampleRate;
    
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();

    BPchain1.prepare(spec);
    BPchain1.reset();
    BPchain2.prepare(spec);
    BPchain2.reset();
    BPchain3.prepare(spec);
    BPchain3.reset();
    BPchain4.prepare(spec);
    BPchain4.reset();
    BPchain5.prepare(spec);
    BPchain5.reset();
    BPchain6.prepare(spec);
    BPchain6.reset();
    BPchain7.prepare(spec);
    BPchain7.reset();
    BPchain8.prepare(spec);
    BPchain8.reset();
       
    sine1.prepare(spec);
    sine1.reset();
    sine2.prepare(spec);
    sine2.reset();
    sine3.prepare(spec);
    sine3.reset();
    sine4.prepare(spec);
    sine4.reset();
    sine5.prepare(spec);
    sine5.reset();
    sine6.prepare(spec);
    sine6.reset();
    sine7.prepare(spec);
    sine7.reset();
    sine8.prepare(spec);
    sine8.reset();
    /*
    BandPassNoise.prepare(spec);
    BandPassNoise.reset();
    BandPassNoise1.prepare(spec);
    BandPassNoise1.reset();
    BandPassNoise2.prepare(spec);
    BandPassNoise2.reset();
    BandPassNoise3.prepare(spec);
    BandPassNoise3.reset();
    BandPassNoise4.prepare(spec);
    BandPassNoise4.reset();
    BandPassNoise5.prepare(spec);
    BandPassNoise5.reset();
    BandPassNoiseCas.prepare(spec);
    BandPassNoiseCas.reset();
    BandPassNoise1Cas.prepare(spec);
    BandPassNoise1Cas.reset();
    BandPassNoise2Cas.prepare(spec);
    BandPassNoise2Cas.reset();
    BandPassNoise3Cas.prepare(spec);
    BandPassNoise3Cas.reset();
    BandPassNoise4Cas.prepare(spec);
    BandPassNoise4Cas.reset();
    BandPassNoise5Cas.prepare(spec);
    BandPassNoise5Cas.reset();
    */
    LP1.prepare(spec);
    LP1.reset();
    LP2.prepare(spec);
    LP2.reset();
    LP3.prepare(spec);
    LP3.reset();
    LP4.prepare(spec);
    LP4.reset();
    LP5.prepare(spec);
    LP5.reset();
    LP6.prepare(spec);
    LP6.reset();
    LP7.prepare(spec);
    LP7.reset();
    LP8.prepare(spec);
    LP8.reset();
    
    PreEmp1.prepare(spec);
    PreEmp1.reset();
    PreEmp2.prepare(spec);
    PreEmp2.reset();
    
    noiseBuffer.setSize(2, samplesPerBlock, false, true, true);
    envBuffer.setSize(2, samplesPerBlock, false, true, true);
    sineBuffer.setSize(2, samplesPerBlock, false, true, true);
    RMSBuffer.setSize(2, samplesPerBlock, false, true, true);
    
    bufferSeparation.setSize (16, int (spec.maximumBlockSize), false, false, true);
    //noiseBufferSeparation.setSize (12, int (spec.maximumBlockSize), false, false, true);
    envBufferSeparation.setSize (16, int (spec.maximumBlockSize), false, false, true);
    sineBufferSeparation.setSize (16, int (spec.maximumBlockSize), false, false, true);
    RMSBufferSeparation.setSize (16, int (spec.maximumBlockSize), false, false, true);
    
    updateFilter();

}

void BpfilterAudioProcessor::releaseResources()
{

}

#ifndef JucePlugin_PreferredChannelConfigurations
bool BpfilterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void BpfilterAudioProcessor::updateFilter(){
    
    bandFreq = 1.0/(numBands);
    
    

    
    auto coeffEnvLP = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(400, lastSampleRate, 2);
    
    
    auto coeffPre1 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(100, lastSampleRate, 1);
    
    auto coeffPre2 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(1500, lastSampleRate, 1);
    
    
    auto BLPcoeff1 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(394.0f+(265.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff1 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(394.0f-(265.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff2 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(692.0f+(331.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff2 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(692.0f-(331.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff3 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(1064.0f+(431.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff3 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(1064.0f-(431.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff4 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(1528.0f+(516.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff4 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(1528.0f-(516.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff5 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(2109.0f+(645.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff5 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(2109.0f-(645.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff6 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(2834.0f+(805.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff6 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(2834.0f-(805.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff7 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(3740.0f+(1006.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff7 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(3740.0f-(1006.0f/2.0f), lastSampleRate, 6);
    
    auto BLPcoeff8 = dsp::FilterDesign<float>::designIIRLowpassHighOrderButterworthMethod(4871.0f+(1257.0f/2.0f), lastSampleRate, 6);
    auto BHPcoeff8 = dsp::FilterDesign<float>::designIIRHighpassHighOrderButterworthMethod(4871.0f-(1257.0f/2.0f), lastSampleRate, 6);
  
    Q = 393/187;
    /*
    *BandPassNoise.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, 0) + logspace(20.0f, 20000.0f, bandFreq))/2);
    
    *BandPassNoise1.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq) + logspace(20.0f, 20000.0f, bandFreq*2))/2);
    
    *BandPassNoise2.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*2) + logspace(20.0f, 20000.0f, bandFreq*3))/2);
    
    *BandPassNoise3.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*3) + logspace(20.0f, 20000.0f, bandFreq*4))/2);
    
    *BandPassNoise4.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*4) + logspace(20.0f, 20000.0f, bandFreq*5))/2);
    
    *BandPassNoise5.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*5) + logspace(20.0f, 20000.0f, bandFreq*6))/2);
    
    *BandPassNoiseCas.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, 0) + logspace(20.0f, 20000.0f, bandFreq))/2);
    
    *BandPassNoise1Cas.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq) + logspace(20.0f, 20000.0f, bandFreq*2))/2);
    
    *BandPassNoise2Cas.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*2) + logspace(20.0f, 20000.0f, bandFreq*3))/2);
    
    *BandPassNoise3Cas.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*3) + logspace(20.0f, 20000.0f, bandFreq*4))/2);
    
    *BandPassNoise4Cas.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*4) + logspace(20.0f, 20000.0f, bandFreq*5))/2);
    
    *BandPassNoise5Cas.state = *dsp::IIR::Coefficients<float>::makeBandPass(lastSampleRate, (logspace(20.0f, 20000.0f, bandFreq*5) + logspace(20.0f, 20000.0f, bandFreq*6))/2);
    */
    
    *LP1.state = *coeffEnvLP.getFirst();
    *LP2.state = *coeffEnvLP.getFirst();
    *LP3.state = *coeffEnvLP.getFirst();
    *LP4.state = *coeffEnvLP.getFirst();
    *LP5.state = *coeffEnvLP.getFirst();
    *LP6.state = *coeffEnvLP.getFirst();
    *LP7.state = *coeffEnvLP.getFirst();
    *LP8.state = *coeffEnvLP.getFirst();
    
    *PreEmp1.state = *coeffPre1.getFirst();
    *PreEmp2.state = *coeffPre2.getFirst();
    
    // ------------ BP CASCADING CHAIN INITIALISATION -------
    
    *BPchain1.get<0> ().state = *BLPcoeff1.getObjectPointer(0);
    *BPchain1.get<1> ().state = *BLPcoeff1.getObjectPointer(1);
    *BPchain1.get<2> ().state = *BLPcoeff1.getObjectPointer(2);
    
    *BPchain1.get<3> ().state = *BHPcoeff1.getObjectPointer(0);
    *BPchain1.get<4> ().state = *BHPcoeff1.getObjectPointer(1);
    *BPchain1.get<5> ().state = *BHPcoeff1.getObjectPointer(2);
   
    //
    
    *BPchain2.get<0> ().state = *BLPcoeff2.getObjectPointer(0);
    *BPchain2.get<1> ().state = *BLPcoeff2.getObjectPointer(1);
    *BPchain2.get<2> ().state = *BLPcoeff2.getObjectPointer(2);
    
    *BPchain2.get<3> ().state = *BHPcoeff2.getObjectPointer(0);
    *BPchain2.get<4> ().state = *BHPcoeff2.getObjectPointer(1);
    *BPchain2.get<5> ().state = *BHPcoeff2.getObjectPointer(2);
   
    //
    
    *BPchain3.get<0> ().state = *BLPcoeff3.getObjectPointer(0);
    *BPchain3.get<1> ().state = *BLPcoeff3.getObjectPointer(1);
    *BPchain3.get<2> ().state = *BLPcoeff3.getObjectPointer(2);
   
    *BPchain3.get<3> ().state = *BHPcoeff3.getObjectPointer(0);
    *BPchain3.get<4> ().state = *BHPcoeff3.getObjectPointer(1);
    *BPchain3.get<5> ().state = *BHPcoeff3.getObjectPointer(2);
    
    //
    
    *BPchain4.get<0> ().state = *BLPcoeff4.getObjectPointer(0);
    *BPchain4.get<1> ().state = *BLPcoeff4.getObjectPointer(1);
    *BPchain4.get<2> ().state = *BLPcoeff4.getObjectPointer(2);
    
    *BPchain4.get<3> ().state = *BHPcoeff4.getObjectPointer(0);
    *BPchain4.get<4> ().state = *BHPcoeff4.getObjectPointer(1);
    *BPchain4.get<5> ().state = *BHPcoeff4.getObjectPointer(2);
    
    //
    
    *BPchain5.get<0> ().state = *BLPcoeff5.getObjectPointer(0);
    *BPchain5.get<1> ().state = *BLPcoeff5.getObjectPointer(1);
    *BPchain5.get<2> ().state = *BLPcoeff5.getObjectPointer(2);
       
    *BPchain5.get<3> ().state = *BHPcoeff5.getObjectPointer(0);
    *BPchain5.get<4> ().state = *BHPcoeff5.getObjectPointer(1);
    *BPchain5.get<5> ().state = *BHPcoeff5.getObjectPointer(2);
    
    //
    
    *BPchain6.get<0> ().state = *BLPcoeff6.getObjectPointer(0);
    *BPchain6.get<1> ().state = *BLPcoeff6.getObjectPointer(1);
    *BPchain6.get<2> ().state = *BLPcoeff6.getObjectPointer(2);
       
    *BPchain6.get<3> ().state = *BHPcoeff6.getObjectPointer(0);
    *BPchain6.get<4> ().state = *BHPcoeff6.getObjectPointer(1);
    *BPchain6.get<5> ().state = *BHPcoeff6.getObjectPointer(2);
    
    //
    
    *BPchain7.get<0> ().state = *BLPcoeff7.getObjectPointer(0);
    *BPchain7.get<1> ().state = *BLPcoeff7.getObjectPointer(1);
    *BPchain7.get<2> ().state = *BLPcoeff7.getObjectPointer(2);
          
    *BPchain7.get<3> ().state = *BHPcoeff7.getObjectPointer(0);
    *BPchain7.get<4> ().state = *BHPcoeff7.getObjectPointer(1);
    *BPchain7.get<5> ().state = *BHPcoeff7.getObjectPointer(2);
    
    //
    
    *BPchain8.get<0> ().state = *BLPcoeff8.getObjectPointer(0);
    *BPchain8.get<1> ().state = *BLPcoeff8.getObjectPointer(1);
    *BPchain8.get<2> ().state = *BLPcoeff8.getObjectPointer(2);
          
    *BPchain8.get<3> ().state = *BHPcoeff8.getObjectPointer(0);
    *BPchain8.get<4> ().state = *BHPcoeff8.getObjectPointer(1);
    *BPchain8.get<5> ().state = *BHPcoeff8.getObjectPointer(2);
    
    // ------- SINE INITIALISATION -----------

    sine1.initialise ([] (float x) { return std::sin (x); }, 128);
    sine1.setFrequency (394, false);
    
    sine2.initialise ([] (float x) { return std::sin (x); }, 128);
    sine2.setFrequency (692, false);
    
    sine3.initialise ([] (float x) { return std::sin (x); }, 128);
    sine3.setFrequency (1053, false);
    
    sine4.initialise ([] (float x) { return std::sin (x); }, 128);
    sine4.setFrequency (1528, false);
    
    sine5.initialise ([] (float x) { return std::sin (x); }, 128);
    sine5.setFrequency (2109, false);
    
    sine6.initialise ([] (float x) { return std::sin (x); }, 128);
    sine6.setFrequency (2834, false);
    
    sine7.initialise ([] (float x) { return std::sin (x); }, 128);
    sine7.setFrequency (3740, false);
    
    sine8.initialise ([] (float x) { return std::sin (x); }, 128);
    sine8.setFrequency (4871, false);
    
    
    
}

void BpfilterAudioProcessor::process(dsp::ProcessContextReplacing<float> context){
    
    const auto& inputBlock = context.getInputBlock();
    //const auto& noiseInputBlock = context1.getInputBlock();
    
    const auto numSamples  = inputBlock.getNumSamples();
    const auto numChannels = inputBlock.getNumChannels();
    
    //------ ENVELOPES --------
    dsp::AudioBlock<float> envelope (envBuffer);
    
    auto sepEnvBlock = dsp::AudioBlock<float> (envBufferSeparation).getSubBlock (0, (size_t) numSamples);
    
    auto env1 = sepEnvBlock.getSubsetChannelBlock (0, (size_t) numChannels);
    auto env2 = sepEnvBlock.getSubsetChannelBlock (2, (size_t) numChannels);
    auto env3 = sepEnvBlock.getSubsetChannelBlock (4, (size_t) numChannels);
    auto env4 = sepEnvBlock.getSubsetChannelBlock (6, (size_t) numChannels);
    auto env5 = sepEnvBlock.getSubsetChannelBlock (8, (size_t) numChannels);
    auto env6 = sepEnvBlock.getSubsetChannelBlock (10, (size_t) numChannels);
    auto env7 = sepEnvBlock.getSubsetChannelBlock (12, (size_t) numChannels);
    auto env8 = sepEnvBlock.getSubsetChannelBlock (14, (size_t) numChannels);
    
    env1.copyFrom(envelope);
    env2.copyFrom(envelope);
    env3.copyFrom(envelope);
    env4.copyFrom(envelope);
    env5.copyFrom(envelope);
    env6.copyFrom(envelope);
    env7.copyFrom(envelope);
    env8.copyFrom(envelope);
    
    //----- RMS -----
    
    dsp::AudioBlock<float> RMSblock (RMSBuffer);
    
    auto sepRMSBlock = dsp::AudioBlock<float> (RMSBufferSeparation).getSubBlock (0, (size_t) numSamples);
    
    auto RMS1 = sepRMSBlock.getSubsetChannelBlock (0, (size_t) numChannels);
    auto RMS2 = sepRMSBlock.getSubsetChannelBlock (2, (size_t) numChannels);
    auto RMS3 = sepRMSBlock.getSubsetChannelBlock (4, (size_t) numChannels);
    auto RMS4 = sepRMSBlock.getSubsetChannelBlock (6, (size_t) numChannels);
    auto RMS5 = sepRMSBlock.getSubsetChannelBlock (8, (size_t) numChannels);
    auto RMS6 = sepRMSBlock.getSubsetChannelBlock (10, (size_t) numChannels);
    auto RMS7 = sepRMSBlock.getSubsetChannelBlock (12, (size_t) numChannels);
    auto RMS8 = sepRMSBlock.getSubsetChannelBlock (14, (size_t) numChannels);
    
    RMS1.copyFrom(RMSblock);
    RMS2.copyFrom(RMSblock);
    RMS3.copyFrom(RMSblock);
    RMS4.copyFrom(RMSblock);
    RMS5.copyFrom(RMSblock);
    RMS6.copyFrom(RMSblock);
    RMS7.copyFrom(RMSblock);
    RMS8.copyFrom(RMSblock);
    
    // ----- AUDIO BANDS -------
    auto sepBlock = dsp::AudioBlock<float> (bufferSeparation).getSubBlock (0, (size_t) numSamples);
 
    auto BP1  = sepBlock.getSubsetChannelBlock (0, (size_t) numChannels);
    auto BP2 = sepBlock.getSubsetChannelBlock (2, (size_t) numChannels);
    auto BP3 = sepBlock.getSubsetChannelBlock (4, (size_t) numChannels);
    auto BP4  = sepBlock.getSubsetChannelBlock (6, (size_t) numChannels);
    auto BP5 = sepBlock.getSubsetChannelBlock (8, (size_t) numChannels);
    auto BP6 = sepBlock.getSubsetChannelBlock (10, (size_t) numChannels);
    auto BP7 = sepBlock.getSubsetChannelBlock (12, (size_t) numChannels);
    auto BP8 = sepBlock.getSubsetChannelBlock (14, (size_t) numChannels);
    
    BP1.copyFrom(inputBlock);
    BP2.copyFrom(inputBlock);
    BP3.copyFrom(inputBlock);
    BP4.copyFrom(inputBlock);
    BP5.copyFrom(inputBlock);
    BP6.copyFrom(inputBlock);
    BP7.copyFrom(inputBlock);
    BP8.copyFrom(inputBlock);
    
    auto myBP1 = dsp::ProcessContextReplacing<float> (BP1);
    BPchain1.process(myBP1);
    
    auto myBP2 = dsp::ProcessContextReplacing<float> (BP2);
    BPchain2.process(myBP2);
    
    auto myBP3 = dsp::ProcessContextReplacing<float> (BP3);
    BPchain3.process(myBP3);
    
    auto myBP4 = dsp::ProcessContextReplacing<float> (BP4);
    BPchain4.process(myBP4);
    
    auto myBP5 = dsp::ProcessContextReplacing<float> (BP5);
    BPchain5.process(myBP5);
   
    auto myBP6 = dsp::ProcessContextReplacing<float> (BP6);
    BPchain6.process(myBP6);
    
    auto myBP7 = dsp::ProcessContextReplacing<float> (BP7);
    BPchain7.process(myBP7);
    
    auto myBP8 = dsp::ProcessContextReplacing<float> (BP8);
    BPchain8.process(myBP8);

    
         for(int j = 0; j < numChannels; j++){
            
            for(int i = 0; i < numSamples; i++){
                
                
                envValue1 = fabsf(BP1.getSample(j, i));
                env1.setSample(j,i,envValue1);
                
                envValue2 = fabsf(BP2.getSample(j, i));
                env2.setSample(j,i,envValue2);
                
                envValue3 = fabsf(BP3.getSample(j, i));
                env3.setSample(j,i,envValue3);
                    
                envValue4 = fabsf(BP4.getSample(j, i));
                env4.setSample(j,i,envValue4);
                
                envValue5 = fabsf(BP5.getSample(j, i));
                env5.setSample(j,i,envValue5);
                
                envValue6 = fabsf(BP6.getSample(j, i));
                env6.setSample(j,i,envValue6);
                
                envValue7 = fabsf(BP7.getSample(j, i));
                env7.setSample(j,i,envValue7);
                
                envValue8 = fabsf(BP8.getSample(j, i));
                env8.setSample(j,i,envValue8);
              
                
            }
        }
    
    auto myEnv1 = dsp::ProcessContextReplacing<float> (env1);
    LP1.process(myEnv1);
    
    auto myEnv2 = dsp::ProcessContextReplacing<float> (env2);
    LP2.process(myEnv2);
    
    auto myEnv3 = dsp::ProcessContextReplacing<float> (env3);
    LP3.process(myEnv3);

    auto myEnv4 = dsp::ProcessContextReplacing<float> (env4);
    LP4.process(myEnv4);
    
    auto myEnv5 = dsp::ProcessContextReplacing<float> (env6);
    LP5.process(myEnv5);
    
    auto myEnv6 = dsp::ProcessContextReplacing<float> (env6);
    LP6.process(myEnv6);
    
    auto myEnv7 = dsp::ProcessContextReplacing<float> (env7);
    LP7.process(myEnv7);
    
    auto myEnv8 = dsp::ProcessContextReplacing<float> (env8);
    LP8.process(myEnv8);
    
      // ------------ SINES -----------------
    
      dsp::AudioBlock<float> sines (sineBuffer);
    
      auto sepSineBlock = dsp::AudioBlock<float> (sineBufferSeparation).getSubBlock (0, (size_t) numSamples);
      
      auto sin1 = sepSineBlock.getSubsetChannelBlock (0, (size_t) numChannels);
      auto sin2 = sepSineBlock.getSubsetChannelBlock (2, (size_t) numChannels);
      auto sin3 = sepSineBlock.getSubsetChannelBlock (4, (size_t) numChannels);
      auto sin4 = sepSineBlock.getSubsetChannelBlock (6, (size_t) numChannels);
      auto sin5 = sepSineBlock.getSubsetChannelBlock (8, (size_t) numChannels);
      auto sin6 = sepSineBlock.getSubsetChannelBlock (10, (size_t) numChannels);
      auto sin7 = sepSineBlock.getSubsetChannelBlock (12, (size_t) numChannels);
      auto sin8 = sepSineBlock.getSubsetChannelBlock (14, (size_t) numChannels);
      
      sin1.copyFrom(sines);
      sin2.copyFrom(sines);
      sin3.copyFrom(sines);
      sin4.copyFrom(sines);
      sin5.copyFrom(sines);
      sin6.copyFrom(sines);
      sin7.copyFrom(sines);
      sin8.copyFrom(sines);
    
      auto mySin1 = dsp::ProcessContextReplacing<float> (sin1);
      sine1.process(mySin1);
    
      auto mySin2 = dsp::ProcessContextReplacing<float> (sin2);
      sine2.process (mySin2);
    
      auto mySin3 = dsp::ProcessContextReplacing<float> (sin3);
      sine3.process (mySin3);
    
      auto mySin4 = dsp::ProcessContextReplacing<float> (sin4);
      sine4.process (mySin4);
    
      auto mySin5 = dsp::ProcessContextReplacing<float> (sin5);
      sine5.process (mySin5);
    
      auto mySin6 = dsp::ProcessContextReplacing<float> (sin6);
      sine6.process (mySin6);
    
      auto mySin7 = dsp::ProcessContextReplacing<float> (sin7);
      sine7.process (mySin7);
    
      auto mySin8 = dsp::ProcessContextReplacing<float> (sin8);
      sine8.process (mySin8);
    /*
    // ----- NOISE BANDS -------
    auto sepNoiseBlock = dsp::AudioBlock<float> (noiseBufferSeparation).getSubBlock (0, (size_t) numSamples);
    
    auto Noise1  = sepNoiseBlock.getSubsetChannelBlock (0, (size_t) numChannels);
    auto Noise2 = sepNoiseBlock.getSubsetChannelBlock (2, (size_t) numChannels);
    auto Noise3 = sepNoiseBlock.getSubsetChannelBlock (4, (size_t) numChannels);
    auto Noise4  = sepNoiseBlock.getSubsetChannelBlock (6, (size_t) numChannels);
    auto Noise5 = sepNoiseBlock.getSubsetChannelBlock (8, (size_t) numChannels);
    auto Noise6 = sepNoiseBlock.getSubsetChannelBlock (10, (size_t) numChannels);
    
    Noise1.copyFrom(noiseInputBlock);
    Noise2.copyFrom(noiseInputBlock);
    Noise3.copyFrom(noiseInputBlock);
    Noise4.copyFrom(noiseInputBlock);
    Noise5.copyFrom(noiseInputBlock);
    Noise6.copyFrom(noiseInputBlock);
    
    auto myNoise1 = dsp::ProcessContextReplacing<float> (Noise1);
    BandPassNoise.process(myNoise1);
    BandPassNoiseCas.process(myNoise1);
    
    auto myNoise2 = dsp::ProcessContextReplacing<float> (Noise2);
    BandPassNoise1.process(myNoise2);
    BandPassNoise1Cas.process(myNoise2);
    
    auto myNoise3 = dsp::ProcessContextReplacing<float> (Noise3);
    BandPassNoise2.process(myNoise3);
    BandPassNoise2Cas.process(myNoise3);
    
    auto myNoise4 = dsp::ProcessContextReplacing<float> (Noise4);
    BandPassNoise3.process(myNoise4);
    BandPassNoise3Cas.process(myNoise4);
    
    auto myNoise5 = dsp::ProcessContextReplacing<float> (Noise5);
    BandPassNoise4.process(myNoise5);
    BandPassNoise4Cas.process(myNoise5);
    
    auto myNoise6 = dsp::ProcessContextReplacing<float> (Noise6);
    BandPassNoise5.process(myNoise6);
    BandPassNoise5Cas.process(myNoise6);
    
    //---------------------------
    
    Noise1.multiplyBy(env1);
    Noise2.multiplyBy(env2);
    Noise3.multiplyBy(env3);
    Noise4.multiplyBy(env4);
    Noise5.multiplyBy(env5);
    Noise6.multiplyBy(env6);
    */
    
    sin1.multiplyBy(env1);
    sin2.multiplyBy(env2);
    sin3.multiplyBy(env3);
    sin4.multiplyBy(env4);
    sin5.multiplyBy(env5);
    sin6.multiplyBy(env6);
    sin7.multiplyBy(env7);
    sin8.multiplyBy(env8);
    
/*
    Noise1.add(Noise2);
    Noise1.add(Noise3);
    Noise1.add(Noise4);
    Noise1.add(Noise5);
    Noise1.add(Noise6);
    */
    
    sin1.add(sin2);
    sin1.add(sin3);
    sin1.add(sin4);
    sin1.add(sin5);
    sin1.add(sin6);
    sin1.add(sin7);
    sin1.add(sin8);
    
    //Noise1.multiplyBy(10);
    
    //Copy my BP buffer to my output block
    context.getOutputBlock().copyFrom(sin1);
    
}


void BpfilterAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

        int numSamples = buffer.getNumSamples();
    
        // ----- FILL BUFFER WITH NOISE ARRAY ------
    {
        //noiseBuffer.clear();
        //sineBuffer.clear();
        
        /*Array<float> noise = getWhiteNoise(numSamples);
        
        FloatVectorOperations::add(noiseBuffer.getWritePointer(0), noise.getRawDataPointer(), numSamples);
        FloatVectorOperations::add(noiseBuffer.getWritePointer(1), noise.getRawDataPointer(), numSamples); // STEREO*/
    }
    
        // ------------------------------------------
    
        dsp::AudioBlock <float> block (buffer);
        //dsp::AudioBlock <float> noiseBlock (noiseBuffer);
        
        PreEmp1.process(dsp::ProcessContextReplacing<float> (block));
        PreEmp2.process(dsp::ProcessContextReplacing<float> (block));
        
        process(dsp::ProcessContextReplacing<float>(block));
        
    
}

float BpfilterAudioProcessor::logspace(float start, float end, float prop){
    
      return start * std::powf(end / start, prop);

}

float BpfilterAudioProcessor::getRMSLevel(dsp::AudioBlock<float> block, int channel, int startSample, int numSamples){
    {
        jassert (isPositiveAndBelow (channel, block.getNumChannels()));
        jassert (startSample >= 0 && numSamples >= 0 && startSample + numSamples <= block.getNumSamples());

        if (numSamples <= 0 || channel < 0 || channel >= block.getNumChannels() || block.getNumSamples() == 0)
            return float(0);

        auto* data = block.getChannelPointer(channel) + startSample;
        double sum = 0.0;

        for (int i = 0; i < numSamples; ++i)
        {
            auto sample = data[i];
            sum += sample * sample;
        }

        return float (std::sqrt (sum / numSamples));
    }
}

//==============================================================================
bool BpfilterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BpfilterAudioProcessor::createEditor()
{
    return new BpfilterAudioProcessorEditor (*this);
}

//==============================================================================
void BpfilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void BpfilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BpfilterAudioProcessor();
}
