// supersai.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Interpolate.h"
#include "../includes/kreed.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D2C;
	const char* FilterName = "Super SAI";
	const char* FilterDescription = "Kreed's SuperSaI";

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
					auto c0 = CLR(Input, srcx, srcy, x, y, -1, -1);
					auto c1 = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto c2 = CLR(Input, srcx, srcy, x, y, 1, -1);
					auto d3 = CLR(Input, srcx, srcy, x, y, 2, -1);
					auto c3 = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto c4 = CLR(Input, srcx, srcy, x, y);
					auto c5 = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto d4 = CLR(Input, srcx, srcy, x, y, 2, 0);
					auto c6 = CLR(Input, srcx, srcy, x, y, -1, 1);
					auto c7 = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto c8 = CLR(Input, srcx, srcy, x, y, 1, 1);
					auto d5 = CLR(Input, srcx, srcy, x, y, 2, 1);
					auto d0 = CLR(Input, srcx, srcy, x, y, -1, 2);
					auto d1 = CLR(Input, srcx, srcy, x, y, 0, 2);
					auto d2 = CLR(Input, srcx, srcy, x, y, 1, 2);
					auto d6 = CLR(Input, srcx, srcy, x, y, 2, 2);

					int P[5];

					P[1] = P[2] = P[3] = P[4] = c4;

					if (IsLike(c7, c5) && IsNotLike(c4, c8)) {
						auto c57 = Interpolate(c7, c5);
						P[4] = c57;
						P[2] = c57;
					}
					else if (IsLike(c4, c8) && IsNotLike(c7, c5)) {
						//nothing
					}
					else if (IsLike(c4, c8) && IsLike(c7, c5)) {
						auto c57 = Interpolate(c7, c5);
						auto c48 = Interpolate(c4, c8);
						auto conc2D = 0;
						conc2D += _Conc2D(c57, c48, c6, d1);
						conc2D += _Conc2D(c57, c48, c3, c1);
						conc2D += _Conc2D(c57, c48, d2, d5);
						conc2D += _Conc2D(c57, c48, c2, d4);

						if (conc2D > 0) {
							P[4] = c57;
							P[2] = c57;
						}
						else if (conc2D == 0) {
							P[4] = Interpolate(c48, c57);
							P[2] = Interpolate(c48, c57);
						}
					}
					else {
						if (IsLike(c8, c5) && IsLike(c8, d1) && IsNotLike(c7, d2) && IsNotLike(c8, d0)) {
							P[4] = Interpolate(Interpolate(c8, c5, d1), c7, 3, 1);
						}
						else if (IsLike(c7, c4) && IsLike(c7, d2) && IsNotLike(c7, d6) && IsNotLike(c8, d1)) {
							P[4] = Interpolate(Interpolate(c7, c4, d2), c8, 3, 1);
						}
						else {
							P[4] = Interpolate(c7, c8);
						}
						if (IsLike(c5, c8) && IsLike(c5, c1) && IsNotLike(c5, c0) && IsNotLike(c4, c2)) {
							P[2] = Interpolate(Interpolate(c5, c8, c1), c4, 3, 1);
						}
						else if (IsLike(c4, c7) && IsLike(c4, c2) && IsNotLike(c5, c1) && IsNotLike(c4, d3)) {
							P[2] = Interpolate(Interpolate(c4, c7, c2), c5, 3, 1);
						}
						else {
							P[2] = Interpolate(c4, c5);
						}
					}
					if (IsLike(c4, c8) && IsLike(c4, c3) && IsNotLike(c7, c5) && IsNotLike(c4, d2)) {
						P[3] = Interpolate(c7, Interpolate(c4, c8, c3));
					}
					else if (IsLike(c4, c6) && IsLike(c4, c5) && IsNotLike(c7, c3) && IsNotLike(c4, d0)) {
						P[3] = Interpolate(c7, Interpolate(c4, c6, c5));
					}
					else {
						P[3] = c7;
					}

					if (IsLike(c7, c5) && IsLike(c7, c6) && IsNotLike(c4, c8) && IsNotLike(c7, c2)) {
						P[1] = Interpolate(Interpolate(c7, c5, c6), c4);
					}
					else if (IsLike(c7, c3) && IsLike(c7, c8) && IsNotLike(c4, c6) && IsNotLike(c7, c0)) {
						P[1] = Interpolate(Interpolate(c7, c3, c8), c4);
					}

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}

