// epxc.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/Interpolate.h"
#include "../includes/Interpolate8.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D12;
	const char* FilterName = "EPX (C)";
	const char* FilterDescription = "SNES9x's EPXC modified by Hawkynt to support thresholds";

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
					auto c3 = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto c4 = CLR(Input, srcx, srcy, x, y);
					auto c5 = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto c6 = CLR(Input, srcx, srcy, x, y, -1, 1);
					auto c7 = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto c8 = CLR(Input, srcx, srcy, x, y, 1, 1);

					int P[5];

					P[1] = P[2] = P[3] = P[4] = c4;

					if (IsNotLike(c3, c5) && IsNotLike(c7, c1)) {
						auto neq40 = IsNotLike(c4, c0);
						auto neq41 = IsNotLike(c4, c1);
						auto neq42 = IsNotLike(c4, c2);
						auto neq43 = IsNotLike(c4, c3);
						auto neq45 = IsNotLike(c4, c5);
						auto neq46 = IsNotLike(c4, c6);
						auto neq47 = IsNotLike(c4, c7);
						auto neq48 = IsNotLike(c4, c8);

						auto eq13 = IsLike(c1, c3) && (neq40 || neq48 || IsNotLike(c1, c2) || IsNotLike(c3, c6));
						auto eq37 = IsLike(c3, c7) && (neq46 || neq42 || IsNotLike(c3, c0) || IsNotLike(c7, c8));
						auto eq75 = IsLike(c7, c5) && (neq48 || neq40 || IsNotLike(c7, c6) || IsNotLike(c5, c2));
						auto eq51 = IsLike(c5, c1) && (neq42 || neq46 || IsNotLike(c5, c8) || IsNotLike(c1, c0));
						if (
							(!neq40) ||
							(!neq41) ||
							(!neq42) ||
							(!neq43) ||
							(!neq45) ||
							(!neq46) ||
							(!neq47) ||
							(!neq48)
							) {
							
							int c3A;

							if ((eq13 && neq46) && (eq37 && neq40))
								c3A = Interpolate(c3, c1, c7);
							else if (eq13 && neq46)
								c3A = Interpolate(c3, c1);
							else if (eq37 && neq40)
								c3A = Interpolate(c3, c7);
							else
								c3A = c4;

							int c7B;
							if ((eq37 && neq48) && (eq75 && neq46))
								c7B = Interpolate(c7, c3, c5);
							else if (eq37 && neq48)
								c7B = Interpolate(c7, c3);
							else if (eq75 && neq46)
								c7B = Interpolate(c7, c5);
							else
								c7B = c4;

							int c5C;
							if ((eq75 && neq42) && (eq51 && neq48))
								c5C = Interpolate(c5, c1, c7);
							else if (eq75 && neq42)
								c5C = Interpolate(c5, c7);
							else if (eq51 && neq48)
								c5C = Interpolate(c5, c1);
							else
								c5C = c4;

							int c1D;

							if ((eq51 && neq40) && (eq13 && neq42))
								c1D = Interpolate(c1, c3, c5);
							else if (eq51 && neq40)
								c1D = Interpolate(c1, c5);
							else if (eq13 && neq42)
								c1D = Interpolate(c1, c3);
							else
								c1D = c4;

							if (eq13)
								P[1] = Interpolate(c1, c3);
							if (eq51)
								P[2] = Interpolate(c5, c1);
							if (eq37)
								P[3] = Interpolate(c3, c7);
							if (eq75)
								P[4] = Interpolate(c7, c5);

							P[1] = Interpolate(P[1], c1D, c3A, c4, 5, 1, 1, 1);
							P[2] = Interpolate(P[2], c7B, c5C, c4, 5, 1, 1, 1);
							P[3] = Interpolate(P[3], c3A, c7B, c4, 5, 1, 1, 1);
							P[4] = Interpolate(P[4], c5C, c1D, c4, 5, 1, 1, 1);

						}
						else {

							if (eq13)
								P[1] = Interpolate(c1, c3);
							if (eq51)
								P[2] = Interpolate(c5, c1);
							if (eq37)
								P[3] = Interpolate(c3, c7);
							if (eq75)
								P[4] = Interpolate(c7, c5);

							P[1] = Interpolate(c4, P[1], 3, 1);
							P[2] = Interpolate(c4, P[2], 3, 1);
							P[3] = Interpolate(c4, P[3], 3, 1);
							P[4] = Interpolate(c4, P[4], 3, 1);
						}
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

