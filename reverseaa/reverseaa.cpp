// reverseaa.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/ReverseAA.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D23;
	const char* FilterName = "ReverseAA";
	const char* FilterDescription = "Christoph Feck's (christoph@maxiom.de) Reverse Anti-Alias filter";

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
					auto b1 = CLR(Input, srcx, srcy, x, y, 0, -2);
					auto b = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto d = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto e = CLR(Input, srcx, srcy, x, y);
					auto f = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto h = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto h5 = CLR(Input, srcx, srcy, x, y, 0, 2);
					auto d0 = CLR(Input, srcx, srcy, x, y, -2, 0);
					auto f4 = CLR(Input, srcx, srcy, x, y, 2, 0);

					int rr, rg, rb, ra = 0;
					int gr, gg, gb, ga = 0;
					int br, bg, bb, ba = 0;

					_ReverseAntiAlias(Red(b1), Red(b), Red(d), Red(e), Red(f), Red(h), Red(h5), Red(d0), Red(f4), &rr, &rg, &rb, &ra);
					_ReverseAntiAlias(Green(b1), Green(b), Green(d), Green(e), Green(f), Green(h), Green(h5), Green(d0), Green(f4), &gr, &gg, &gb, &ga);
					_ReverseAntiAlias(Blue(b1), Blue(b), Blue(d), Blue(e), Blue(f), Blue(h), Blue(h5), Blue(d0), Blue(f4), &br, &bg, &bb, &ba);

					int P[5];

					P[1] = RGBINT(_FullClamp(rr), _FullClamp(gr), _FullClamp(br));
					P[2] = RGBINT(_FullClamp(rg), _FullClamp(gg), _FullClamp(bg));
					P[3] = RGBINT(_FullClamp(rb), _FullClamp(gb), _FullClamp(bb));
					P[4] = RGBINT(_FullClamp(ra), _FullClamp(ga), _FullClamp(ba));

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}

