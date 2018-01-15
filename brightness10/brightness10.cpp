// brightness10.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Brightness.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D45;
	const char* FilterName = "Brightness +10";
	const char* FilterDescription = "Adjusts image brightness (+10)";

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
			auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));

			Init(srcx, srcy);

			auto Channels = 3;

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					auto rgb = CLR(Input, srcx, srcy, x, y);
					
					auto R = Red(rgb);
					auto G = Green(rgb);
					auto B = Blue(rgb);

					auto index = (y * srcx + x) * Channels;

					ScaledImage[index] = AdjustBrightness(R, 10);
					ScaledImage[index + 1] = AdjustBrightness(G, 10);
					ScaledImage[index + 2] = AdjustBrightness(B, 10);
				}
			}
		}
	}
}



