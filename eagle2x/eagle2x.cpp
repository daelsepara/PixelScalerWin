// eagle2x.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Interpolate.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D0C;
	const char* FilterName = "Eagle 2X";
	const char* FilterDescription = "Eagle nX Family of Filters";

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
					int C[9];

					C[0] = CLR(Input, srcx, srcy, x, y, -1, -1);
					C[1] = CLR(Input, srcx, srcy, x, y, 0, -1);
					C[2] = CLR(Input, srcx, srcy, x, y, 1, -1);
					C[3] = CLR(Input, srcx, srcy, x, y, -1, 0);
					C[4] = CLR(Input, srcx, srcy, x, y, 0, 0);
					C[5] = CLR(Input, srcx, srcy, x, y, 1, 0);
					C[6] = CLR(Input, srcx, srcy, x, y, -1, 1);
					C[7] = CLR(Input, srcx, srcy, x, y, 0, 1);
					C[8] = CLR(Input, srcx, srcy, x, y, 1, 1);

					int P[5];

					P[1] = (IsLike(C[1], C[0]) && IsLike(C[1], C[3])) ? Interpolate(C[1], C[0], C[3]) : C[4];
					P[2] = (IsLike(C[2], C[1]) && IsLike(C[2], C[5])) ? Interpolate(C[2], C[1], C[5]) : C[4];
					P[3] = (IsLike(C[6], C[3]) && IsLike(C[6], C[7])) ? Interpolate(C[6], C[3], C[7]) : C[4];
					P[4] = (IsLike(C[7], C[5]) && IsLike(C[7], C[8])) ? Interpolate(C[7], C[5], C[8]) : C[4];

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}
