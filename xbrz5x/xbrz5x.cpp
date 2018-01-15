// xbrz5x.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include "../includes/FilterCommon.h"
#include "../includes/xbrz.h"

extern "C"
{
	static unsigned char* ScaledImage = NULL;

	const int FilterID = 0x5D37;
	const char* FilterName = "XBRZ 5X";
	const char* FilterDescription = "XBRZnX family of filters";

	bool ComparisonThreshold = false;
	const int FilterScaleX = 5;
	const int FilterScaleY = 5;

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

			auto src = (uint32_t*)malloc(srcx * srcy * sizeof(uint32_t));
			auto dst = (uint32_t*)malloc(SizeX() * SizeY() * sizeof(uint32_t));

			xbrz::Copy(src, Input, srcx, srcy);
			xbrz::scale(5, src, dst, srcx, srcy, xbrz::ColorFormat::ARGB, xbrz::ScalerCfg(), 0, srcy);
			xbrz::Copy(ScaledImage, dst, SizeX(), SizeY());

			free(dst);
			free(src);
		}
	}
}
