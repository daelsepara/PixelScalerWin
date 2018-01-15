// amscale3x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D06;
	const char* FilterName = "AM Scale3X";
	const char* FilterDescription = "Andrea Mazzoleni's Scale3X modified by Hawkynt to support thresholds";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 3;
	const int FilterScaleY = 3;

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
					auto c0 = CLR(Input, srcx, srcy, x, y, -1, -1);
					auto c1 = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto c2 = CLR(Input, srcx, srcy, x, y, 1, -1);
					auto c3 = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto c4 = CLR(Input, srcx, srcy, x, y);
					auto c5 = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto c6 = CLR(Input, srcx, srcy, x, y, -1, 1);
					auto c7 = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto c8 = CLR(Input, srcx, srcy, x, y, 1, 1);

					int P[10];

					P[1] = P[2] = P[3] = P[4] = P[5] = P[6] = P[7] = P[8] = P[9] = c4;

					if (IsNotLike(c1,c7) && IsNotLike(c3,c5)) {
						if (IsLike(c3, c1))
							P[1] = Interpolate(c3, c1);
						if (IsLike(c1, c5))
							P[3] = Interpolate(c1, c5);
						if (IsLike(c3, c7))
							P[7] = Interpolate(c3, c7);
						if (IsLike(c7, c5))
							P[9] = Interpolate(c7, c5);

						if (
							(IsLike(c3, c1) && IsNotLike(c4, c2)) &&
							(IsLike(c5, c1) && IsNotLike(c4, c0))
							)
							P[2] = Interpolate(c1, c3, c5);
						else if (IsLike(c3, c1) && IsNotLike(c4, c2))
							P[2] = Interpolate(c3, c1);
						else if (IsLike(c5, c1) && IsNotLike(c4, c0))
							P[2] = Interpolate(c5, c1);

						if (
							(IsLike(c3, c1) && IsNotLike(c4, c6)) &&
							(IsLike(c3, c7) && IsNotLike(c4, c0))
							)
							P[4] = Interpolate(c3, c1, c7);
						else if (IsLike(c3, c1) && IsNotLike(c4, c6))
							P[4] = Interpolate(c3, c1);
						else if (IsLike(c3, c7) && IsNotLike(c4, c0))
							P[4] = Interpolate(c3, c7);

						if (
							(IsLike(c5, c1) && IsNotLike(c4, c8)) &&
							(IsLike(c5, c7) && IsNotLike(c4, c2))
							)
							P[6] = Interpolate(c5, c1, c7);
						else if (IsLike(c5, c1) && IsNotLike(c4, c8))
							P[6] = Interpolate(c5, c1);
						else if (IsLike(c5, c7) && IsNotLike(c4, c2))
							P[6] = Interpolate(c5, c7);

						if (
							(IsLike(c3, c7) && IsNotLike(c4, c8)) &&
							(IsLike(c5, c7) && IsNotLike(c4, c6))
							)
							P[8] = Interpolate(c7, c3, c5);
						else if (IsLike(c3, c7) && IsNotLike(c4, c8))
							P[8] = Interpolate(c3, c7);
						else if (IsLike(c5, c7) && IsNotLike(c4, c6))
							P[8] = Interpolate(c5, c7);

					}

					for (auto Pixel = 1; Pixel < 10; Pixel++)
					{
						Write9RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}

