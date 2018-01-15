// ultra2x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D2F;
	const char* FilterName = "Ultra 2X";
	const char* FilterDescription = "FNES' Ultra 2x Scaling";

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

					auto cx = c;
					auto wx = w;
					auto ex = e;

					auto cw = _Mixpal(c, w);
					auto ce = _Mixpal(c, e);

					int P[5];

					P[1] = (((IsLike(w, n)) && (IsNotLike(n, e)) && (IsNotLike(w, s))) ? wx : cw);
					P[2] = (((IsLike(n, e)) && (IsNotLike(n, w)) && (IsNotLike(e, s))) ? ex : ce);
					P[3] = (((IsLike(w, s)) && (IsNotLike(w, n)) && (IsNotLike(s, e))) ? wx : cw);
					P[4] = (((IsLike(s, e)) && (IsNotLike(w, s)) && (IsNotLike(n, e))) ? ex : ce);

					P[1] = _Unmix(P[1], cx);
					P[2] = _Unmix(P[2], cx);
					P[3] = _Unmix(P[3], cx);
					P[4] = _Unmix(P[4], cx);

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}
