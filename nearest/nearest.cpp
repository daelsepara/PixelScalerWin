// nearest.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D22;
	const char* FilterName = "Nearest-neighbor";
	const char* FilterDescription = "Image scaling by nearest-neighbor interpolation";

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

			auto SizeX = srcx * ScaleX();
			auto SizeY = srcy * ScaleY();
			auto Channels = 3;

			int x_ratio = (int)((srcx << 16) / SizeX) + 1;
			int y_ratio = (int)((srcy << 16) / SizeY) + 1;

			for (int i = 0; i < SizeY; i++)
			{
				for (int j = 0; j < SizeX; j++)
				{
					auto x2 = ((j * x_ratio) >> 16);
					auto y2 = ((i * y_ratio) >> 16);

					auto dst = (i * SizeX + j) * Channels;
					auto src = (y2 * srcx + x2) * Channels;

					for (auto Channel = 0; Channel < Channels; Channel++)
					{
						ScaledImage[dst + Channel] = Input[src + Channel];
					}
				}
			}
		}
	}
}

