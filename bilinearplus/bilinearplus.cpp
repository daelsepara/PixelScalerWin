// bilinearplus.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Interpolate.h"
#include "../includes/Interpolate4.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D09;
	const char* FilterName = "Bilinear+";
	const char* FilterDescription = "Bilinear+ (Original)";

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

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					auto c00 = CLR(Input, srcx, srcy, x, y, 0, 0);
					auto c01 = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto c10 = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto c11 = CLR(Input, srcx, srcy, x, y, 1, 1);

					int P[5];

					P[1] = Interpolate(c00, c01, c10, 5, 2, 1);
					P[2] = Interpolate(c00, c01);
					P[3] = Interpolate(c00, c10);
					P[4] = Interpolate4(c00, c01, c10, c11);

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}

