// xbr4x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D33;
	const char* FilterName = "XBR 4X";
	const char* FilterDescription = "XBR4x by Hyllian";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 4;
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
					/*
					A1 B1 C1          P01|P02|P03|P04
					A0 PA PB PC C4    P05|P06|P07|p08
					D0 PD PE PF F4 => ---+---+---+---
					G0 PG PH PI I4    P09|P10|P11|p12
					G5 H5 I5          P13|P14|P15|p16
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

					int P[17];

					P[1] = P[2] = P[3] = P[4] = P[5] = P[6] = P[7] = P[8] = pe;
					P[9] = P[10] = P[11] = P[12] = P[13] = P[14] = P[15] = P[16] = pe;

					_Kernel4Xv2(pe, pi, ph, pf, pg, pc, pd, pb, f4, i4, h5, i5, &P[16], &P[15], &P[12], &P[4], &P[8], &P[11], &P[14], &P[13], AllowAlphaBlending);
					_Kernel4Xv2(pe, pc, pf, pb, pi, pa, ph, pd, b1, c1, f4, c4, &P[4], &P[8], &P[3], &P[1], &P[2], &P[7], &P[12], &P[16], AllowAlphaBlending);
					_Kernel4Xv2(pe, pa, pb, pd, pc, pg, pf, ph, d0, a0, b1, a1, &P[1], &P[2], &P[5], &P[13], &P[9], &P[6], &P[3], &P[4], AllowAlphaBlending);
					_Kernel4Xv2(pe, pg, pd, ph, pa, pi, pb, pf, h5, g5, d0, g0, &P[13], &P[9], &P[14], &P[16], &P[15], &P[10], &P[5], &P[1], AllowAlphaBlending);
					
					for (auto Pixel = 1; Pixel < 17; Pixel++)
					{
						Write16RGB(ScaledImage, srcx, srcy, x, y, Pixel, P[Pixel]);
					}
				}
			}
		}
	}
}


