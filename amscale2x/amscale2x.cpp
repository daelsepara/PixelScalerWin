// amscale2x.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Interpolate.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D05;
	const char* FilterName = "AM Scale2X";
	const char* FilterDescription = "Andrea Mazzoleni's Scale2X modified by Hawkynt to support thresholds";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 2;
	const int FilterScaleY = 2;

	#include "../includes/Init.h"

	DECLDIR int Parameters()
	{
		// No Special Parameters
		return 0;
	}

	DECLDIR void __stdcall Apply(int argc, void** argv)
	{
		if (argc >= 3)
		{
			auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));

			Init(srcx, srcy);

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					auto c1 = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto c3 = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto c4 = CLR(Input, srcx, srcy, x, y, 0, 0);
					auto c5 = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto c7 = CLR(Input, srcx, srcy, x, y, 0, 1);

					int P[5];

					P[1] = P[2] = P[3] = P[4] = c4;

					if (IsNotLike(c3, c5) && IsNotLike(c1, c7)) {
						if (IsLike(c1, c3)) {
							P[1] = Interpolate(c1, c3);
						}
						if (IsLike(c1, c5)) {
							P[2] = Interpolate(c1, c5);
						}
						if (IsLike(c7, c3)) {
							P[3] = Interpolate(c7, c3);
						}
						if (IsLike(c7, c5)) {
							P[4] = Interpolate(c7, c5);
						}
					}

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}

