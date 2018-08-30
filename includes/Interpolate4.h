#pragma once

#include "FilterCommon.h"

typedef int sPixel;

int Interpolate4(sPixel pixel1, sPixel pixel2, sPixel pixel3, sPixel pixel4)
{
	auto r = (unsigned char)((Red(pixel1) + Red(pixel2) + Red(pixel3) + Red(pixel4)) >> 2);
	auto g = (unsigned char)((Green(pixel1) + Green(pixel2) + Green(pixel3) + Green(pixel4)) >> 2);
	auto b = (unsigned char)((Blue(pixel1) + Blue(pixel2) + Blue(pixel3) + Blue(pixel4)) >> 2);

	return RGBINT(r, g, b);
}
