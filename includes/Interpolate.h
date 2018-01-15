#pragma once

#include "FilterCommon.h"

int Interpolate(int pixel1, int pixel2, int pixel3)
{
	auto r = (unsigned char)((int)(Red(pixel1) + Red(pixel2) + Red(pixel3)) / 3);
	auto g = (unsigned char)((int)(Green(pixel1) + Green(pixel2) + Green(pixel3)) / 3);
	auto b = (unsigned char)((int)(Blue(pixel1) + Blue(pixel2) + Blue(pixel3)) / 3);

	return RGBINT(r, g, b);
}

int Interpolate(int pixel1, int pixel2)
{
	auto r = (unsigned char)((int)(Red(pixel1) + Red(pixel2)) >> 1);
	auto g = (unsigned char)((int)(Green(pixel1) + Green(pixel2)) >> 1);
	auto b = (unsigned char)((int)(Blue(pixel1) + Blue(pixel2)) >> 1);

	return RGBINT(r, g, b);
}

int Interpolate(int pixel1, int pixel2, int quantifier1, int quantifier2)
{
	auto total = (quantifier1 + quantifier2);

	auto r = (unsigned char)((int)(Red(pixel1) * quantifier1 + Red(pixel2) * quantifier2) / total);
	auto g = (unsigned char)((int)(Green(pixel1) * quantifier1 + Green(pixel2) * quantifier2) / total);
	auto b = (unsigned char)((int)(Blue(pixel1) * quantifier1 + Blue(pixel2) * quantifier2) / total);

	return RGBINT(r, g, b);
}

int Interpolate(int pixel1, int pixel2, int pixel3, unsigned char quantifier1, unsigned char quantifier2, unsigned char quantifier3)
{
	auto total = (int)(quantifier1 + quantifier2 + quantifier3);
	
	auto r = (unsigned char)((Red(pixel1) * quantifier1 + Red(pixel2) * quantifier2 + Red(pixel3) * quantifier3) / total);
	auto g = (unsigned char)((Green(pixel1) * quantifier1 + Green(pixel2) * quantifier2 + Green(pixel3) * quantifier3) / total);
	auto b = (unsigned char)((Blue(pixel1) * quantifier1 + Blue(pixel2) * quantifier2 + Blue(pixel3) * quantifier3) / total);

	return RGBINT(r, g, b);
}

int _Mixpal(int c1, int c2)
{
	return (Interpolate(c1, c2, 3, 1));
}

int _Fix(int n, int min, int max) {
	return (n < min ? min : n > max ? max : n);
}

int _Unmix(int c1, int c2)
{
	/* A variant of an unsharp mask, without the blur part. */

	auto ra = Red(c1);
	auto ga = Green(c1);
	auto ba = Blue(c1);

	auto rb = Red(c2);
	auto gb = Green(c2);
	auto bb = Blue(c2);

	auto r = ((_Fix((ra + (ra - rb)), 0, 255) + rb) >> 1);
	auto g = ((_Fix((ga + (ga - gb)), 0, 255) + gb) >> 1);
	auto b = ((_Fix((ba + (ba - bb)), 0, 255) + bb) >> 1);

	return (r << 16) + (g << 8) + b;
}
