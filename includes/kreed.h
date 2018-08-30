#pragma once

#include "FilterCommon.h"
#include "Interpolate.h"

typedef int sPixel;

int _Conc2D(sPixel c00, sPixel c01, sPixel c10, sPixel c11) {
	auto result = 0;

	auto acAreAlike = IsLike(c00, c10);
	auto x = acAreAlike ? 1 : 0;
	auto y = (IsLike(c01, c10) && !(acAreAlike)) ? 1 : 0;

	auto adAreAlike = IsLike(c00, c11);
	x += adAreAlike ? 1 : 0;
	y += (IsLike(c01, c11) && !(adAreAlike)) ? 1 : 0;

	if (x <= 1)
		result++;
	if (y <= 1)
		result--;

	return (result);
}
