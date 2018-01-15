// horiz3x.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D17;
	const char* FilterName = "Horizontal Scanlines 3X";
	const char* FilterDescription = "Horizontal Scanlines 3X";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 3;
	const int FilterScaleY = 3;

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
					int P[10];

					auto pixel = CLR(Input, srcx, srcy, x, y);

					auto R = Red(pixel) >> 1;
					auto G = Green(pixel) >> 1;
					auto B = Blue(pixel) >> 1;

					auto subPixel = RGBINT(R, G, B);
					auto subPixel2 = RGBINT(R >> 1, G >> 1, B >> 1);

					P[1] = P[2] = P[3] = pixel;
					P[4] = P[5] = P[6] = subPixel;
					P[7] = P[8] = P[9] = subPixel;

					for (auto Pixel = 1; Pixel < 10; Pixel++)
					{
						Write9RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}
