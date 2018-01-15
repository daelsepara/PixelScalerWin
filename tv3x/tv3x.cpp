// tv3x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D2E;
	const char* FilterName = "TV 3X";
	const char* FilterDescription = "TV-like effect using interlacing and gamma reduction";

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
					//   C         P
					//
					//          +-----+
					// 0 1 2    |1|2|3|
					//  \|/     |-+-+-|
					// 3-4-5 => |4|5|6|
					//  /|\     |-+-+-|
					// 6 7 8    |7|8|9|
					//          +-----+

					int P[10];

					auto pixel = CLR(Input, srcx, srcy, x, y);
					
					auto R = Red(pixel);
					auto G = Green(pixel);
					auto B = Blue(pixel);

					auto subPixel = RGBINT((R * 5) >> 3, (G * 5) >> 3, (B * 5) >> 3);
					auto subPixel2 = RGBINT((R * 5) >> 4, (G * 5) >> 4, (B * 5) >> 4);

					P[1] = pixel;
					P[2] = pixel;
					P[3] = pixel;
					P[4] = subPixel;
					P[5] = subPixel;
					P[6] = subPixel;
					P[7] = subPixel2;
					P[8] = subPixel2;
					P[9] = subPixel2;

					for (auto Pixel = 1; Pixel < 10; Pixel++)
					{
						Write9RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}


