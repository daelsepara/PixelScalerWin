// hq2x3.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/hq.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D19;
	const char* FilterName = "HQ 2X3";
	const char* FilterDescription = "Maxim Stepin's High Quality 2X3 Magnification";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 2;
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

					unsigned char pattern = 0;
					if ((IsNotLike(c4, c0)))
						pattern |= 1;
					if ((IsNotLike(c4, c1)))
						pattern |= 2;
					if ((IsNotLike(c4, c2)))
						pattern |= 4;
					if ((IsNotLike(c4, c3)))
						pattern |= 8;
					if ((IsNotLike(c4, c5)))
						pattern |= 16;
					if ((IsNotLike(c4, c6)))
						pattern |= 32;
					if ((IsNotLike(c4, c7)))
						pattern |= 64;
					if ((IsNotLike(c4, c8)))
						pattern |= 128;

					int P[10];

					Hq2x3Kernel(pattern, c0, c1, c2, c3, c4, c5, c6, c7, c8, P);

					Write9RGB(ScaledImage, srcx, srcy, x, y, 1, P[1]);
					Write9RGB(ScaledImage, srcx, srcy, x, y, 2, P[2]);
					Write9RGB(ScaledImage, srcx, srcy, x, y, 4, P[4]);
					Write9RGB(ScaledImage, srcx, srcy, x, y, 5, P[5]);
					Write9RGB(ScaledImage, srcx, srcy, x, y, 7, P[7]);
					Write9RGB(ScaledImage, srcx, srcy, x, y, 8, P[8]);
				}
			}
		}
	}
}

