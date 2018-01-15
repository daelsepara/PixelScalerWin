// rgb3x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D25;
	const char* FilterName = "RGB 3X";
	const char* FilterDescription = "Dot-Matrix Printer Effect (3X)";

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

					P[1] = pixel;
					P[2] = RGBINT(0, Green(pixel), 0);
					P[3] = RGBINT(0, 0, Blue(pixel));
					P[4] = RGBINT(0, 0, Blue(pixel));
					P[5] = pixel;
					P[6] = RGBINT(Red(pixel), 0, 0);
					P[7] = RGBINT(Red(pixel), 0, 0);
					P[8] = RGBINT(0, Green(pixel), 0);
					P[9] = pixel;

					for (auto Pixel = 1; Pixel < 10; Pixel++)
					{
						Write9RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}


