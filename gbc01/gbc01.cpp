// gbc01.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D54;
	const char* FilterName = "Gameboy Color Palette 01";
	const char* FilterDescription = "GameBoy Color (4-color, Pokemon Red Sun and Blue Moon)";

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
			// SEE: https://lospec.com/palette-list/pokemon-sgb
			unsigned char GB_B[4] = { 24, 132, 247, 255 };
			unsigned char GB_G[4] = { 16, 113, 181, 239};
			unsigned char GB_R[4] = { 16, 156, 140, 255};

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


