// heat70.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D48;
	const char* FilterName = "Heat (70 Degrees, 4-color)";
	const char* FilterDescription = "Apply 4-color 70 degrees heat scheme";

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
			// SEE: https://www.schemecolor.com/70-degree-heat-colors.php
			unsigned char GB_B[4] = { 229, 255, 255, 241 };
			unsigned char GB_G[4] = { 0, 132, 209, 251};
			unsigned char GB_R[4] = { 0, 31, 98, 166 };

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
					auto lookup = (int)floor(G / 64);

					ScaledImage[index] = GB_R[lookup];
					ScaledImage[index + 1] = GB_G[lookup];
					ScaledImage[index + 2] = GB_B[lookup];
				}
			}
		}
	}
}


