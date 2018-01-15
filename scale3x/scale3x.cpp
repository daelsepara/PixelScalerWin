// scale3x.cpp : Defines the exported functions for the DLL application.
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

	const int FilterID = 0x5D29;
	const char* FilterName = "Scale 3X";
	const char* FilterDescription = "Generalization of EPX to the 3X case";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 3;
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
					//          .-----.
					// A B C    |1|2|3|
					//  \|/     |-+-+-|
					// D-E-F => |4|5|6|
					//  /|\     |-+-+-|
					// G H I    |7|8|9|
					//          .-----.

					auto E = CLR(Input, srcx, srcy, x, y);
					auto A = CLR(Input, srcx, srcy, x, y, -1, -1);
					auto B = CLR(Input, srcx, srcy, x, y, 0, -1);
					auto C = CLR(Input, srcx, srcy, x, y, 1, -1);
					auto D = CLR(Input, srcx, srcy, x, y, -1, 0);
					auto F = CLR(Input, srcx, srcy, x, y, 1, 0);
					auto G = CLR(Input, srcx, srcy, x, y, -1, 1);
					auto H = CLR(Input, srcx, srcy, x, y, 0, 1);
					auto I = CLR(Input, srcx, srcy, x, y, 1, 1);

					int P[10];

					P[1] = IsLike(D, B) && IsNotLike(D, H) && IsNotLike(B, F) ? D : E;
					P[2] = (IsLike(D, B) && IsNotLike(D, H) && IsNotLike(B, F) && IsNotLike(E, C)) || (IsLike(B, F) && IsNotLike(B, D) && IsNotLike(F, H) && IsNotLike(E, A)) ? B : E;
					P[3] = IsLike(B, F) && IsNotLike(B, D) && IsNotLike(F, H) ? F : E;
					P[4] = (IsLike(H, D) && IsNotLike(H, F) && IsNotLike(D, B) && IsNotLike(E, A)) || (IsLike(D, B) && IsNotLike(D, H) && IsNotLike(B, F) && IsNotLike(E, G)) ? D : E;
					P[5] = E;
					P[6] = (IsLike(B, F) && IsNotLike(B, D) && IsNotLike(F, H) && IsNotLike(E, I)) || (IsLike(F, H) && IsNotLike(F, B) && IsNotLike(H, D) && IsNotLike(E, C)) ? F : E;
					P[7] = IsLike(H, D) && IsNotLike(H, F) && IsNotLike(D, B) ? D : E;
					P[8] = (IsLike(F, H) && IsNotLike(F, B) && IsNotLike(H, D) && IsNotLike(E, G)) || (IsLike(H, D) && IsNotLike(H, F) && IsNotLike(D, B) && IsNotLike(E, I)) ? H : E;
					P[9] = IsLike(F, H) && IsNotLike(F, B) && IsNotLike(H, D) ? F : E;

					for (auto i = 1; i < 10; i++)
					{
						Write9RGB(ScaledImage, srcx, srcy, x, y, i, P[i]);
					}
				}
			}
		}
	}
}

