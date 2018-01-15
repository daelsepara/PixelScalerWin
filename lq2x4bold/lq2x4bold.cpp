// lq2x4bold.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/lq.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D44;
	const char* FilterName = "LQ 2X4 Bold";
	const char* FilterDescription = "LQnX Family of Filters with Brightness Processing";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 2;
	const int FilterScaleY = 4;

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

					byte brightness[] = {
						Brightness(c0),
						Brightness(c1),
						Brightness(c2),
						Brightness(c3),
						Brightness(c4),
						Brightness(c5),
						Brightness(c6),
						Brightness(c7),
						Brightness(c8)
					};

					auto avgBrightness = (byte)((
						brightness[0] +
						brightness[1] +
						brightness[2] +
						brightness[3] +
						brightness[4] +
						brightness[5] +
						brightness[6] +
						brightness[7] +
						brightness[8]
						) / 9);

					auto dc4 = Brightness(c4) > avgBrightness;
					byte pattern = 0;

					if ((IsNotLike(c4, c0)) && ((brightness[0] > avgBrightness) != dc4))
						pattern |= 1;
					if ((IsNotLike(c4, c1)) && ((brightness[1] > avgBrightness) != dc4))
						pattern |= 2;
					if ((IsNotLike(c4, c2)) && ((brightness[2] > avgBrightness) != dc4))
						pattern |= 4;
					if ((IsNotLike(c4, c3)) && ((brightness[3] > avgBrightness) != dc4))
						pattern |= 8;
					if ((IsNotLike(c4, c5)) && ((brightness[5] > avgBrightness) != dc4))
						pattern |= 16;
					if ((IsNotLike(c4, c6)) && ((brightness[6] > avgBrightness) != dc4))
						pattern |= 32;
					if ((IsNotLike(c4, c7)) && ((brightness[7] > avgBrightness) != dc4))
						pattern |= 64;
					if ((IsNotLike(c4, c8)) && ((brightness[8] > avgBrightness) != dc4))
						pattern |= 128;

					int P[17];

					Lq2x4Kernel(pattern, c0, c1, c2, c3, c4, c5, c6, c7, c8, P);

					for (auto Pixel = 1; Pixel < 17; Pixel++)
					{
						Write16RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}
