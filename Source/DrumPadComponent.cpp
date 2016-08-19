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
DrumPadComponent::DrumPadComponent ()
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

    //[UserPreSize]
    //[/UserPreSize]

    setSize (100, 100);


    //[Constructor] You can add your own custom stuff here..
	//addMouseListener(this, false);
	formatManager.registerBasicFormats();
    //[/Constructor]
}

DrumPadComponent::~DrumPadComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    imageButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	transportSource.releaseResources();
    //[/Destructor]
}

//==============================================================================
void DrumPadComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xfff0e23c));

    //[UserPaint] Add your own custom painting code here..
	g.fillAll(m_color);

	g.setColour(Colours::black);
	g.setFont(Font("Agency FB", 38.00f, Font::plain));
	g.drawText(m_text,
		0, 0, 100, 100,
		Justification::centred, true);
    //[/UserPaint]
}

void DrumPadComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    imageButton->setBounds (0, 0, 100, 100);
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
		transportSource.stop();
		transportSource.setPosition(0);
		transportSource.start();

        //[/UserButtonCode_imageButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void DrumPadComponent::setColor(Colour c)
{
	m_color = c;
}

void DrumPadComponent::setText(juce::String text)
{
	m_text = text;
}

void DrumPadComponent::setAudioSample(char * sample, int len)
{
	m_sample = sample;
	m_len = len;

	//Stream inputStream;
	//inputStream.
	//AudioFormatReader ar = formatManager.createReaderFor(inputStream);

	//transportSource.setSource(source, 0, nullptr, 44100);

	transportSource.setLooping(true);
	//transportSource.prepareToPlay();
	transportSource.start();
	/*AudioFormatReader* reader = formatManager.createReaderFor()
	if (reader != nullptr)
	{
	ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader, true); // [11]
	transportSource.setSource(newSource, 0, nullptr, reader->sampleRate);                         // [12]
	playButton.setEnabled(true);                                                                  // [13]
	readerSource = newSource.release();

	// play
	transportSource.setLooping(true);

	//transportSource.prepareToPlay();
	transportSource.start();
	}*/
}

void DrumPadComponent::setAudioPath(juce::String path)
{

	//AudioFormatReader* reader = formatManager.createReaderFor(
	juce::File file(path);

	//AudioFormatReader* reader = formatManager.createReaderFor(file);
	AudioFormatReader* reader = formatManager.createReaderFor(file);

	if (reader != nullptr) {
		//AudioFormatReaderSource* source = new AudioFormatReaderSource(reader, true);
		ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource(reader, true);




		transportSource.setSource(newSource, 0, nullptr, reader->sampleRate);

		readerSource = newSource.release();
	}
}

void DrumPadComponent::getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill)
{
	transportSource.getNextAudioBlock(bufferToFill);
}

void DrumPadComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
	transportSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

AudioTransportSource& DrumPadComponent::getAudioSource()
{
	return transportSource;
}

void DrumPadComponent::play()
{
	transportSource.setPosition(0);
	transportSource.start();
}

void DrumPadComponent::setVolume(float volume)
{
	transportSource.setGain(volume);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="DrumPadComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="100" initialHeight="100">
  <BACKGROUND backgroundColour="fff0e23c"/>
  <IMAGEBUTTON name="Pad Button" id="196a771a06c79cc8" memberName="imageButton"
               virtualName="" explicitFocusOrder="0" pos="0 0 100 100" buttonText="KICK"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="" opacityNormal="1" colourNormal="4cb8ff" resourceOver=""
               opacityOver="1" colourOver="69b8eb" resourceDown="" opacityDown="1"
               colourDown="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
