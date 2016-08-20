/*
  ==============================================================================

    MathHelper.h
    Created: 20 Aug 2016 2:30:34am
    Author:  Homepc

  ==============================================================================
*/
#pragma once

#ifndef MATH_HELPER
#define MATH_HELPER

#include "../JuceLibraryCode/JuceHeader.h"

class MathHelper {
	public:
		static float linearToDb(float logv) { return 20.0 * log(logv); }
		static float DbToLinear(float linv) { return powf(10.0, (linv / 20.0)); }
};


#endif