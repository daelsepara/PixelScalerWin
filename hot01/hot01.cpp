// hot01.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D4E;
	const char* FilterName = "Hot Palette 01";
	const char* FilterDescription = "5 level heat palette (E89005, EC7505, D84A05, F42B03, 842100)";

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
			// SEE:  https://coolors.co/e89005-ec7505-d84a05-f42b03-842100
			unsigned char GB_B[5] = { 133, 244, 216, 236, 232 };
			unsigned char GB_G[5] = { 33, 43, 74, 117, 144 };
			unsigned char GB_R[5] = { 0, 3, 5, 5, 5 };

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
