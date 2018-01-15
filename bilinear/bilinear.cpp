// bilinear.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D07;
	const char* FilterName = "Bilinear";
	const char* FilterDescription = "Image scaling by bilinear interpolation";

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

			int offset = 0;

			for (int i = 0; i < SizeY; i++) {

				for (int j = 0; j < SizeX; j++) {

					auto x = (x_ratio * j) >> 16;
					auto y = (y_ratio * i) >> 16;

					auto x_diff = (double)(((x_ratio * j) >> 16) - x);
					auto y_diff = (double)(((y_ratio * i) >> 16) - y);

					for (auto Channel = 0; Channel < Channels; Channel++)
					{
						auto index = y * srcx + x;

						auto A = Input[index * Channels + Channel];
						auto B = Input[(index + 1) * Channels + Channel];
						auto C = Input[(index + srcx) * Channels + Channel];
						auto D = Input[(index + srcx + 1) * Channels + Channel];

						// Y = A(1-w)(1-h) + B(w)(1-h) + C(h)(1-w) + Dwh
						auto color = (unsigned char)(
							A*(1.0 - x_diff)*(1.0 - y_diff) + B*(x_diff)*(1.0 - y_diff) +
							C*(y_diff)*(1.0 - x_diff) + D*(x_diff*y_diff)
							);

						ScaledImage[offset * Channels + Channel] = color;
					}

					offset++;
				}
			}
		}
	}
}


