/*
  ==============================================================================

    AudioMixer.h
    Created: 20 Aug 2016 8:23:58pm
    Author:  Homepc

  ==============================================================================
*/

#ifndef AUDIOMIXER_H_INCLUDED
#define AUDIOMIXER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AudioMixer : public MixerAudioSource
{
public:
    AudioMixer();
    ~AudioMixer();

	void setSolo(int pos, bool value);
	void setMute(int pos, bool value);
private:
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioMixer)
};


#endif  // AUDIOMIXER_H_INCLUDED
