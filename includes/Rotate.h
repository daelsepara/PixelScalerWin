#pragma once

#include "FilterCommon.h"
#include "Flip.h"

void Transpose(unsigned char* dst, unsigned char* src, int srcx, int srcy)
{
	auto Channels = 3;

	for (int y = 0; y < srcy; y++)
	{
		for (int x = 0; x < srcx; x++)
		{
			for (auto Channel = 0; Channel < Channels; Channel++)
			{
				dst[(x * srcy + y) * Channels + Channel] = src[(y * srcx + x) * Channels + Channel];
			}
		}
	}
}

void Rotate90(unsigned char* dst, unsigned char* src, int srcx, int srcy)
{
	Transpose(dst, src, srcx, srcy);

	FlipUD(dst, srcy, srcx);
}
		
void Rotate180(unsigned char* dst, unsigned char* src, int srcx, int srcy)
{
	auto Channels = 3;
	
	Copy(dst, src, srcx * srcy * Channels);

	FlipUD(dst, srcx, srcy);
	FlipLR(dst, srcx, srcy);
}

void Rotate270(unsigned char* dst, unsigned char* src, int srcx, int srcy)
{
	FlipUD(src, srcx, srcy);

	Transpose(dst, src, srcx, srcy);
}
