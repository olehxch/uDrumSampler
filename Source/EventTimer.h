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
	EventTimer():callback(nullptr) {};
	~EventTimer() {};

	void timerCallback() override
	{
		callback();
	};

	void setCallback(std::function<void()> cb) {
		callback = cb;
	}

private:
	std::function<void()> callback;
};

#endif  // EVENTTIMER_H_INCLUDED
