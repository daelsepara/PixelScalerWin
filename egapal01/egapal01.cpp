// egapal01.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D50;
	const char* FilterName = "EGA Palette 01";
	const char* FilterDescription = "EGA Default Palette (16-colors)";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 1;
	const int FilterScaleY = 1;

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
			// SEE:  http://www.shikadi.net/moddingwiki/EGA_Palette
			unsigned char PAL[4] = { 0, 85, 170 , 255 };
				
			auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));

			Init(srcx, srcy);

			auto Channels = 3;

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					auto index = (y * srcx + x) * Channels;
					auto lookup = CLR(Input, srcx, srcy, x, y);
					auto factor = (double) 1.0 / 85;
					ScaledImage[index] = PAL[(int)(Red(lookup) * factor)];
					ScaledImage[index + 1] = PAL[(int)(Green(lookup) * factor)];
					ScaledImage[index + 2] = PAL[(int)(Blue(lookup) * factor)];
				}
			}
		}
	}
}


