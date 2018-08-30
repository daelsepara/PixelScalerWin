// des2x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D0B;
	const char* FilterName = "DES 2X";
	const char* FilterDescription = "FNES' DES2 filter";

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
					auto n = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto w = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto c = CLR(Input, srcx, srcy, x, y, 0, 0);
					auto e = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto s = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto se = CLR(Input, srcx, srcy, x, y, 1, 1);

					int P[5];

					auto d1 = (((IsLike(w, n)) && (IsNotLike(n, e)) && (IsNotLike(w, s))) ? w : c);
					auto d2 = (((IsLike(n, e)) && (IsNotLike(n, w)) && (IsNotLike(e, s))) ? e : c);
					auto d3 = (((IsLike(w, s)) && (IsNotLike(w, n)) && (IsNotLike(s, e))) ? w : c);
					auto d4 = (((IsLike(s, e)) && (IsNotLike(w, s)) && (IsNotLike(n, e))) ? e : c);

					auto cx = c;
					auto ce = Interpolate(c, e, 3, 1);
					auto cs = Interpolate(c, s, 3, 1);
					auto cse = Interpolate(c, se, 3, 1);

					P[1] = Interpolate(d1, cx, 3, 1);
					P[2] = Interpolate(d2, ce, 3, 1);
					P[3] = Interpolate(d3, cs, 3, 1);
					P[4] = Interpolate(d4, cse, 3, 1);

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}
