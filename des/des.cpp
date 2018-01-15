// des.cpp : Defines the exported functions for the DLL application.
//

// epx3.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Interpolate4.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D0A;
	const char* FilterName = "DES";
	const char* FilterDescription = "DES filters from FNES";

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
			auto Input = ((unsigned char*)(argv[0]));
			auto srcx = *((int*)(argv[1]));
			auto srcy = *((int*)(argv[2]));

			Init(srcx, srcy);

			auto Channels = 3;

			for (auto y = 0; y < srcy; y++)
			{
				for (auto x = 0; x < srcx; x++)
				{
					auto n = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto w = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto c = CLR(Input, srcx, srcy, x, y);
					auto e = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto s = CLR(Input, srcx, srcy, x, y, 0, 1);

					auto p0 = (((IsLike(w, n)) && (IsNotLike(n, e)) && (IsNotLike(w, s))) ? w : c);
					auto p1 = (((IsLike(n, e)) && (IsNotLike(n, w)) && (IsNotLike(e, s))) ? e : c);
					auto p2 = (((IsLike(w, s)) && (IsNotLike(w, n)) && (IsNotLike(s, e))) ? w : c);
					auto p3 = (((IsLike(s, e)) && (IsNotLike(w, s)) && (IsNotLike(n, e))) ? e : c);

					auto d = Interpolate4(p0, p1, p2, p3);
					
					auto index = (y * srcx + x) * Channels;

					ScaledImage[index] = Red(d);
					ScaledImage[index + 1] = Green(d);
					ScaledImage[index + 2] = Blue(d);
				}
			}
		}
	}
}

