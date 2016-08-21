/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_46619F8651A80C50__
#define __JUCE_HEADER_46619F8651A80C50__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MathHelper.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DrumPadComponent  : public Component,
                          public ButtonListener,
                          public SliderListener
{
public:
    //==============================================================================
    DrumPadComponent (juce::String name, Colour color, juce::String path);
    ~DrumPadComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setColor(Colour c);
    void setPadName(juce::String name);

    void loadSampleFile(juce::String path);
    void loadSampleFile(File& file);

    AudioTransportSource& getAudioSource();
    //void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);

    void play();
    void setVolume(float volume);

    void muteOn();
    void muteOff();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    bool mIsSampleLoaded = false;
    bool mIsMuted = false;
    bool mIsSolo = false;

    juce::String mPadTitle = "";
    Colour mBackgroudColor = Colours::grey;
    Colour mSoloActiveColor = Colour(0xFF81FF64);
    Colour mMuteActiveColor = Colour(0xFFFFCC64);

    AudioFormatManager mFormatManager;
    ScopedPointer<AudioFormatReaderSource> mReaderSource;
    AudioTransportSource mTransportSource;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> imageButton;
    ScopedPointer<Slider> volumeSlider;
    ScopedPointer<TextButton> openFile;
    ScopedPointer<TextButton> soloButton;
    ScopedPointer<TextButton> muteButton;
    ScopedPointer<TextEditor> padName;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrumPadComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_46619F8651A80C50__
