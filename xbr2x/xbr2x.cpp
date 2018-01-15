// xbr2x.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/xbr.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D31;
	const char* FilterName = "XBR 2X";
	const char* FilterDescription = "XBR2x by Hyllian";

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
					/*
					   A1 B1 C1
					A0 PA PB PC C4    P1 P2
					D0 PD PE PF F4 => --+--
					G0 PG PH PI I4    P3 P4
					   G5 H5 I5
					*/

					auto a1 = CLR(Input, srcx, srcy, x, y, -1, -2);
					auto b1 = CLR(Input, srcx, srcy, x, y, 0, -2);
					auto c1 = CLR(Input, srcx, srcy, x, y, 1, -2);

					auto a0 = CLR(Input, srcx, srcy, x, y, -2, -1);
					auto pa = CLR(Input, srcx, srcy, x, y, -1, -1);
					auto pb = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto pc = CLR(Input, srcx, srcy, x, y, 1, -1);
					auto c4 = CLR(Input, srcx, srcy, x, y, 2, -1);

					auto d0 = CLR(Input, srcx, srcy, x, y, -2, 0);
					auto pd = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto pe = CLR(Input, srcx, srcy, x, y, 0, 0);
					auto pf = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto f4 = CLR(Input, srcx, srcy, x, y, 2, 0);

					auto g0 = CLR(Input, srcx, srcy, x, y, -2, 1);
					auto pg = CLR(Input, srcx, srcy, x, y, -1, 1);
					auto ph = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto pi = CLR(Input, srcx, srcy, x, y, 1, 1);
					auto i4 = CLR(Input, srcx, srcy, x, y, 2, 1);

					auto g5 = CLR(Input, srcx, srcy, x, y, -1, 2);
					auto h5 = CLR(Input, srcx, srcy, x, y, 0, 2);
					auto i5 = CLR(Input, srcx, srcy, x, y, 1, 2);

					int P[5];

					P[1] = P[2] = P[3] = P[4] = pe;

					_Kernel2Xv5(pe, pi, ph, pf, pg, pc, pd, pb, f4, i4, h5, i5, &P[2], &P[3], &P[4], AllowAlphaBlending);
					_Kernel2Xv5(pe, pc, pf, pb, pi, pa, ph, pd, b1, c1, f4, c4, &P[1], &P[4], &P[2], AllowAlphaBlending);
					_Kernel2Xv5(pe, pa, pb, pd, pc, pg, pf, ph, d0, a0, b1, a1, &P[3], &P[2], &P[1], AllowAlphaBlending);
					_Kernel2Xv5(pe, pg, pd, ph, pa, pi, pb, pf, h5, g5, d0, g0, &P[4], &P[1], &P[3], AllowAlphaBlending);

					for (auto Pixel = 1; Pixel < 5; Pixel++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}

