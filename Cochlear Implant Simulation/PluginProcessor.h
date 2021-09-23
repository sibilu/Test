/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class BpfilterAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    BpfilterAudioProcessor();
    ~BpfilterAudioProcessor();
    
    AudioBuffer<float> noiseBuffer;
    AudioBuffer<float> envBuffer;
    AudioBuffer<float> sineBuffer;
    AudioBuffer<float> RMSBuffer;
    
    AudioBuffer<float> bufferSeparation;
    AudioBuffer<float> noiseBufferSeparation;
    AudioBuffer<float> envBufferSeparation;
    AudioBuffer<float> sineBufferSeparation;
    AudioBuffer<float> RMSBufferSeparation;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void updateFilter();
    
    // start - start frequency (typically 20Hz)
    // end - end frequency (typically 20000Hz)
    // prop - proportion from start to end (range 0 - 1)
    float logspace(float start, float end, float prop);
    
    float getRMSLevel (dsp::AudioBlock<float> block, int channel, int startSample, int numSamples);
    
    void process(dsp::ProcessContextReplacing<float> context);
    
    float envValue1 = 0;
    float envValue2 = 0;
    float envValue3 = 0;
    float envValue4 = 0;
    float envValue5 = 0;
    float envValue6 = 0;
    float envValue7 = 0;
    float envValue8 = 0;
    
    float myRMS1;
    float myRMS2;
    float myRMS3;
    float myRMS4;
    float myRMS5;
    float myRMS6;
    float myRMS7;
    float myRMS8;
    
    float Q;


private:
    //==============================================================================
    float bandFreq;
    int numBands = 8;
    float lastSampleRate;
    
    using BLP1 = dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>>;
    using BLP2 = dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>>;
    using BLP3 = dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>>;
    
    using BHP1 = dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>>;
    using BHP2 = dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>>;
    using BHP3 = dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>>;

    
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain1;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain2;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain3;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain4;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain5;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain6;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain7;
    dsp::ProcessorChain<BLP1, BLP2, BLP3, BHP1, BHP2, BHP3> BPchain8;
    
    
    dsp::Oscillator<float> sine1;
    dsp::Oscillator<float> sine2;
    dsp::Oscillator<float> sine3;
    dsp::Oscillator<float> sine4;
    dsp::Oscillator<float> sine5;
    dsp::Oscillator<float> sine6;
    dsp::Oscillator<float> sine7;
    dsp::Oscillator<float> sine8;
    
    //-------------------------
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise1;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise2;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise3;
       
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise4;
       
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise5;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoiseCas;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise1Cas;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise2Cas;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise3Cas;
       
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise4Cas;
       
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> BandPassNoise5Cas;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> PreEmp1;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> PreEmp2;
    
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP1;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP2;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP3;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP4;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP5;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP6;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP7;
    dsp::ProcessorDuplicator<dsp::IIR::Filter <float>, dsp::IIR::Coefficients<float>> LP8;


    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BpfilterAudioProcessor)
    
};
