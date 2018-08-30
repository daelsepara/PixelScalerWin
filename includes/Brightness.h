#pragma once

#include "FilterCommon.h"

unsigned char AdjustBrightness(unsigned char color, unsigned char level)
{
	return Truncate(color + level);
}
