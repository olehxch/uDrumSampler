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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "DrumPadComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DrumPadComponent::DrumPadComponent (juce::String name, Colour color, juce::String path)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (imageButton = new ImageButton ("Pad Button"));
    imageButton->setButtonText (TRANS("KICK"));
    imageButton->addListener (this);

    imageButton->setImages (false, true, true,
                            Image(), 1.000f, Colour (0x004cb8ff),
                            Image(), 1.000f, Colour (0x0069b8eb),
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (volumeSlider = new Slider ("Volume Slider"));
    volumeSlider->setRange (-60, 6, 0);
    volumeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    volumeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    volumeSlider->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    volumeSlider->setColour (Slider::thumbColourId, Colour (0xffb90deb));
    volumeSlider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    volumeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xfff92c50));
    volumeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xd027252b));
    volumeSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    volumeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x9cf7f7f7));
    volumeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x63808080));
    volumeSlider->addListener (this);

    addAndMakeVisible (openFile = new TextButton ("new button"));
    openFile->setButtonText (TRANS("Open"));
    openFile->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    openFile->addListener (this);
    openFile->setColour (TextButton::buttonColourId, Colour (0xff647fff));
    openFile->setColour (TextButton::buttonOnColourId, Colour (0xfffd5f5f));

    addAndMakeVisible (soloButton = new TextButton ("Solo"));
    soloButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    soloButton->addListener (this);
    soloButton->setColour (TextButton::buttonColourId, Colour (0xff81ff64));
    soloButton->setColour (TextButton::buttonOnColourId, Colour (0xfffd5f5f));

    addAndMakeVisible (muteButton = new TextButton ("Mute"));
    muteButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    muteButton->addListener (this);
    muteButton->setColour (TextButton::buttonColourId, Colour (0xffffcc64));
    muteButton->setColour (TextButton::buttonOnColourId, Colour (0xfffd5f5f));

    addAndMakeVisible (padName = new TextEditor ("Pad Name"));
    padName->setMultiLine (false);
    padName->setReturnKeyStartsNewLine (false);
    padName->setReadOnly (false);
    padName->setScrollbarsShown (false);
    padName->setCaretVisible (true);
    padName->setPopupMenuEnabled (true);
    padName->setColour (TextEditor::backgroundColourId, Colour (0x00ffffff));
    padName->setColour (TextEditor::outlineColourId, Colour (0x00000000));
    padName->setColour (TextEditor::shadowColourId, Colour (0x002d2d2d));
    padName->setText (String());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (128, 128);


    //[Constructor] You can add your own custom stuff here..
    //addMouseListener(this, false);
    mFormatManager.registerBasicFormats();

    volumeSlider->setValue(MathHelper::linearToDb(0.8));
    volumeSlider->setTextValueSuffix(" dB");

    loadSampleFile(path);
    this->mPadTitle = name;
    this->mBackgroudColor = color;

    padName->setFont(Font("Agency FB", 38.00f, Font::plain));
    padName->setText(name);
    //[/Constructor]
}

DrumPadComponent::~DrumPadComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    imageButton = nullptr;
    volumeSlider = nullptr;
    openFile = nullptr;
    soloButton = nullptr;
    muteButton = nullptr;
    padName = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    mTransportSource.releaseResources();
    //[/Destructor]
}

//==============================================================================
void DrumPadComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff939393));

    //[UserPaint] Add your own custom painting code here..
    if(mIsSampleLoaded) g.fillAll(mBackgroudColor);
    //[/UserPaint]
}

void DrumPadComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    imageButton->setBounds (0, 0, 128, 128);
    volumeSlider->setBounds (8, 88, 120, 40);
    openFile->setBounds (0, 0, 64, 24);
    soloButton->setBounds (64, 0, 32, 24);
    muteButton->setBounds (96, 0, 32, 24);
    padName->setBounds (0, 24, 128, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DrumPadComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == imageButton)
    {
        //[UserButtonCode_imageButton] -- add your button handler code here..
        
        mTransportSource.stop();
        mTransportSource.setPosition(0);
        mTransportSource.start();

        //[/UserButtonCode_imageButton]
    }
    else if (buttonThatWasClicked == openFile)
    {
        //[UserButtonCode_openFile] -- add your button handler code here..
        
        FileChooser chooser("Select a Wave sample...", File::nonexistent,"*.wav");
        if (chooser.browseForFileToOpen())
        {
            loadSampleFile(chooser.getResult());
        }
        
        //[/UserButtonCode_openFile]
    }
    else if (buttonThatWasClicked == soloButton)
    {
        //[UserButtonCode_soloButton] -- add your button handler code here..
        
        mIsMuted = false;
        mIsSolo = true;
        
        //[/UserButtonCode_soloButton]
    }
    else if (buttonThatWasClicked == muteButton)
    {
        //[UserButtonCode_muteButton] -- add your button handler code here..
        
        mIsMuted = true;
        mIsSolo = false;
        
        //[/UserButtonCode_muteButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void DrumPadComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volumeSlider)
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        
        mTransportSource.setGain(MathHelper::DbToLinear(volumeSlider->getValue()) );
        
        //[/UserSliderCode_volumeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DrumPadComponent::setColor(Colour c)
{
    mBackgroudColor = c;
}

void DrumPadComponent::setPadName(juce::String name)
{
    mPadTitle = name;
}

void DrumPadComponent::loadSampleFile(juce::String path)
{
    juce::File file(path);
    loadSampleFile(file);
}

void DrumPadComponent::loadSampleFile(File& file)
{
    AudioFormatReader* reader = mFormatManager.createReaderFor(file);

    if (reader != nullptr) {
        ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader, true);
        mTransportSource.setSource(newSource, 0, nullptr, reader->sampleRate);
        mReaderSource = newSource.release();
        mIsSampleLoaded = true;
        repaint();
    } else {
        mIsSampleLoaded = false;
    }
}

void DrumPadComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
    mTransportSource.getNextAudioBlock(bufferToFill);
}

void DrumPadComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    mTransportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

AudioTransportSource& DrumPadComponent::getAudioSource()
{
    return mTransportSource;
}

void DrumPadComponent::play()
{
    mTransportSource.setPosition(0);
    mTransportSource.start();
}

void DrumPadComponent::setVolume(float volume)
{
    mTransportSource.setGain(volume);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DrumPadComponent" componentName=""
                 parentClasses="public Component" constructorParams="juce::String name, Colour color, juce::String path"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="128" initialHeight="128">
  <BACKGROUND backgroundColour="ff939393"/>
  <IMAGEBUTTON name="Pad Button" id="196a771a06c79cc8" memberName="imageButton"
               virtualName="" explicitFocusOrder="0" pos="0 0 128 128" buttonText="KICK"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="" opacityNormal="1" colourNormal="4cb8ff" resourceOver=""
               opacityOver="1" colourOver="69b8eb" resourceDown="" opacityDown="1"
               colourDown="0"/>
  <SLIDER name="Volume Slider" id="5ce05c4509ea200" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="8 88 120 40" bkgcol="ffffff"
          thumbcol="ffb90deb" trackcol="7fffffff" rotarysliderfill="fff92c50"
          rotaryslideroutline="d027252b" textboxtext="ff000000" textboxbkgd="9cf7f7f7"
          textboxoutline="63808080" min="-60" max="6" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TEXTBUTTON name="new button" id="6dc717a7a33a14fb" memberName="openFile"
              virtualName="" explicitFocusOrder="0" pos="0 0 64 24" bgColOff="ff647fff"
              bgColOn="fffd5f5f" buttonText="Open" connectedEdges="15" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Solo" id="90b021306a90ff3d" memberName="soloButton" virtualName=""
              explicitFocusOrder="0" pos="64 0 32 24" bgColOff="ff81ff64" bgColOn="fffd5f5f"
              buttonText="Solo" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Mute" id="7d69657298f35ed6" memberName="muteButton" virtualName=""
              explicitFocusOrder="0" pos="96 0 32 24" bgColOff="ffffcc64" bgColOn="fffd5f5f"
              buttonText="Mute" connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="Pad Name" id="2c1f90d9cc479996" memberName="padName" virtualName=""
              explicitFocusOrder="0" pos="0 24 128 32" bkgcol="ffffff" outlinecol="0"
              shadowcol="2d2d2d" initialText="" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="0" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
