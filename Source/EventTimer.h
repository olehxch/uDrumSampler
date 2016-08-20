/*
  ==============================================================================

    EventTimer.h
    Created: 20 Aug 2016 9:28:37pm
    Author:  Homepc

  ==============================================================================
*/

#ifndef EVENTTIMER_H_INCLUDED
#define EVENTTIMER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class EventTimer : public Timer
{
public:
	EventTimer() :mCallback(nullptr) {};
	~EventTimer() {};

	void timerCallback() override
	{
		mCallback();
	};

	void setCallback(std::function<void()> cb)
	{
		mCallback = cb;
	}

private:
	std::function<void()> mCallback;
};

#endif  // EVENTTIMER_H_INCLUDED
