// rgbpal01.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D4D;
	const char* FilterName = "RGB Palette 01";
	const char* FilterDescription = "Custom RGB Palette (36213E, 554971, 63768D, 8AC6D0, B8F3FF)";

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
			// SEE:  https://coolors.co/36213e-554971-63768d-8ac6d0-b8f3ff
			unsigned char GB_B[5] = { 54, 85, 99, 138, 184 };
			unsigned char GB_G[5] = { 33, 73, 118, 198, 243 };
			unsigned char GB_R[5] = { 62, 113, 141, 208, 255 };

			auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));

			Init(srcx, srcy);

			auto Channels = 3;

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					auto G = Luminance(CLR(Input, srcx, srcy, x, y));
					auto index = (y * srcx + x) * Channels;
					auto lookup = min(4, (int)floor(G / 51));

					ScaledImage[index] = GB_R[lookup];
					ScaledImage[index + 1] = GB_G[lookup];
					ScaledImage[index + 2] = GB_B[lookup];
				}
			}
		}
	}
}
