// epx.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D0F;
	const char* FilterName = "EPX/Scale 2X";
	const char* FilterDescription = "Eric's Pixel eXpander / Advance Mame Scale 2X";

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
					//   A      .---.
					//   |      |1|2|
					// C-S-B => |-+-|
					//   |      |3|4|
					//   D      .---.     

					auto S = CLR(Input, srcx, srcy, x, y, 0, 0);
					auto A = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto B = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto C = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto D = CLR(Input, srcx, srcy, x, y, 0, 1);

					int P[5];

					P[1] = IsLike(C, A) && IsNotLike(C, D) && IsNotLike(A, B) ? A : S;
					P[2] = IsLike(A, B) && IsNotLike(A, C) && IsNotLike(B, D) ? B : S;
					P[3] = IsLike(D, C) && IsNotLike(D, B) && IsNotLike(C, A) ? C : S;
					P[4] = IsLike(B, D) && IsNotLike(B, A) && IsNotLike(D, C) ? D : S;

					for (auto i = 1; i < 5; i++)
					{
						Write4RGB(ScaledImage, srcx, srcy, x, y, i, P[i]);
					}
				}
			}
		}
	}
}