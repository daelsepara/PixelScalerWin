// 2xscl.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D02;
	const char* FilterName = "2xSCL";
	const char* FilterDescription = "FNES' 2x Scaling";

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

					int P[5];

					P[1] = (((IsLike(w, n)) && (IsNotLike(n, e)) && (IsNotLike(w, s))) ? w : c);
					P[2] = (((IsLike(n, e)) && (IsNotLike(n, w)) && (IsNotLike(e, s))) ? e : c);
					P[3] = (((IsLike(w, s)) && (IsNotLike(w, n)) && (IsNotLike(s, e))) ? w : c);
					P[4] = (((IsLike(s, e)) && (IsNotLike(w, s)) && (IsNotLike(n, e))) ? e : c);

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}
