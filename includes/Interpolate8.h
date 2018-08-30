#pragma once

#include "FilterCommon.h"

typedef int sPixel;

sPixel Interpolate(
	sPixel pixel1,
	sPixel pixel2,
	sPixel pixel3,
	sPixel pixel4,
	unsigned char quantifier1,
	unsigned char quantifier2,
	unsigned char quantifier3,
	unsigned char quantifier4) {
	auto total = (quantifier1 + quantifier2 + quantifier3 + quantifier4);
	
	auto r = (unsigned char)((Red(pixel1) * quantifier1 + Red(pixel2) * quantifier2 + Red(pixel3) * quantifier3 + Red(pixel4) * quantifier4) / total);
	auto g = (unsigned char)((Green(pixel1) * quantifier1 + Green(pixel2) * quantifier2 + Green(pixel3) * quantifier3 + Green(pixel4) * quantifier4) / total);
	auto b = (unsigned char)((Blue(pixel1) * quantifier1 + Blue(pixel2) * quantifier2 + Blue(pixel3) * quantifier3 + Blue(pixel4) * quantifier4) / total);

	return RGBINT(r, g, b);
}
