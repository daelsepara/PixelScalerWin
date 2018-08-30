#pragma once
#include <cstdlib>
#include <cstring>

bool _Threshold = false;
int _ScaleX = 0;
int _ScaleY = 0;
int _SizeX = 0;
int _SizeY = 0;

void Copy(unsigned char* dst, unsigned char* src, int Length)
{
	memcpy(dst, src, Length * sizeof(unsigned char));
}
	
int CLR(unsigned char* Input, int srcx, int srcy, int x, int y)
{
	auto Channels = 3;

	if (y >= 0 && y < srcy && x >= 0 && x < srcx)
	{
		auto index = (y * srcx + x) * Channels;

		auto r = Input[index];
		auto g = Input[index + 1];
		auto b = Input[index + 2];

		return (r << 16) + (g << 8) + b;
	}

	return 0;
}

int CLR(unsigned char* Input, int srcx, int srcy, int x, int y, int dx, int dy)
{
	auto xx = x + dx;
	auto yy = y + dy;

	if (xx < 0)
	{
		xx = 0;
	}

	if (xx > srcx - 1)
	{
		xx = srcx - 1;
	}

	if (yy < 0)
	{
		yy = 0;
	}

	if (yy > srcy - 1)
	{
		yy = srcy - 1;
	}

	return CLR(Input, srcx, srcy, xx, yy);
}

unsigned char Red(int rgb)
{
	return (unsigned char)(rgb >> 16);
}

unsigned char Green(int rgb)
{
	return (unsigned char)((rgb & 0x00FF00) >> 8);
}

unsigned char Blue(int rgb)
{
	return (unsigned char)(rgb & 0x0000FF);
}

unsigned char Brightness(int rgb)
{
	auto dwordC = rgb & 0xFFFFFF;

	return (unsigned char)((Red(dwordC) * 3 + Green(dwordC) * 3 + Blue(dwordC) * 2) >> 3);
}

unsigned char Luminance(int rgb)
{
	auto r = (double)Red(rgb);
	auto g = (double)Green(rgb);
	auto b = (double)Blue(rgb);

	return (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
}

unsigned char ChromaU(int rgb)
{
	auto r = (double)Red(rgb);
	auto g = (double)Green(rgb);
	auto b = (double)Blue(rgb);

	return (unsigned char)(0.5 * r - 0.418688 * g - 0.081312 * b + 127.5);
}

unsigned char ChromaV(int rgb)
{
	auto r = (double)Red(rgb);
	auto g = (double)Green(rgb);
	auto b = (double)Blue(rgb);

	return (unsigned char)(-0.168736 * r - 0.331264 * g + 0.5 * b + 127.5);
}

bool IsLike(int pixel1, int pixel2)
{
	if (!_Threshold)
		return pixel1 == pixel2;

	static const unsigned char _LUMINANCE_TRIGGER = 48;
	static const unsigned char _CHROMA_U_TRIGGER = 7;
	static const unsigned char _CHROMA_V_TRIGGER = 6;

	auto delta = Luminance(pixel1) - Luminance(pixel2);

	if ((unsigned char)std::abs(delta) > _LUMINANCE_TRIGGER)
		return false;

	delta = ChromaV(pixel1) - ChromaV(pixel2);

	if ((unsigned char)std::abs(delta) > _CHROMA_V_TRIGGER)
		return false;

	delta = ChromaU(pixel1) - ChromaU(pixel2);

	return (unsigned char)std::abs(delta) <= _CHROMA_U_TRIGGER;
}

bool IsNotLike(int pixel1, int pixel2)
{
	return !IsLike(pixel1, pixel2);
}

void Write4RGB(unsigned char* Output, int sizex, int sizey, int x, int y, int Pixel, unsigned char R, unsigned char G, unsigned char B)
{
	if (x >= 0 && x < sizex && y >= 0 && y < sizey)
	{
		auto Channels = 3;

		auto dx = x * _ScaleX;
		auto dy = y * _ScaleY;

		dx += (Pixel == 2 || Pixel == 4) ? 1 : 0;
		dy += (Pixel == 3 || Pixel == 4) ? 1 : 0;

		auto dst = (dy * sizex * _ScaleX + dx) * Channels;

		Output[dst] = R;
		Output[dst + 1] = G;
		Output[dst + 2] = B;
	}
}

void Write4RGB(unsigned char* Output, int sizex, int sizey, int x, int y, int Pixel, int rgb)
{
	auto R = (unsigned char)(rgb >> 16);
	auto G = (unsigned char)((rgb & 0x00FF00) >> 8);
	auto B = (unsigned char)(rgb & 0x0000FF);

	Write4RGB(Output, sizex, sizey, x, y, Pixel, R, G, B);
}

void Write9RGB(unsigned char* Output, int sizex, int sizey, int x, int y, int Pixel, unsigned char R, unsigned char G, unsigned char B)
{
	if (x >= 0 && x < sizex && y >= 0 && y < sizey)
	{
		auto Channels = 3;

		auto deltax = 0;
		auto deltay = 0;

		if (Pixel == 2 || Pixel == 5 || Pixel == 8)
		{
			deltax = 1;
		}

		if (Pixel == 3 || Pixel == 6 || Pixel == 9)
		{
			deltax = 2;
		}

		if (Pixel == 4 || Pixel == 5 || Pixel == 6)
		{
			deltay = 1;
		}

		if (Pixel == 7 || Pixel == 8 || Pixel == 9)
		{
			deltay = 2;
		}

		auto dx = x * _ScaleX + deltax;
		auto dy = y * _ScaleY + deltay;

		auto dst = (dy * sizex * _ScaleX + dx) * Channels;

		Output[dst] = R;
		Output[dst + 1] = G;
		Output[dst + 2] = B;
	}
}

void Write9RGB(unsigned char* Output, int sizex, int sizey, int x, int y, int Pixel, int rgb)
{
	auto R = (unsigned char)(rgb >> 16);
	auto G = (unsigned char)((rgb & 0x00FF00) >> 8);
	auto B = (unsigned char)(rgb & 0x0000FF);

	Write9RGB(Output, sizex, sizey, x, y, Pixel, R, G, B);
}

void Write16RGB(unsigned char* Output, int sizex, int sizey, int x, int y, int Pixel, unsigned char R, unsigned char G, unsigned char B)
{
	if (x >= 0 && x < sizex && y >= 0 && y < sizey)
	{
		auto Channels = 3;

		auto deltax = 0;
		auto deltay = 0;

		/*
		01 02 03 04
		05 06 07 08
		09 10 11 12
		13 14 15 16
		*/

		if (Pixel == 2 || Pixel == 6 || Pixel == 10 || Pixel == 14)
		{
			deltax = 1;
		}

		if (Pixel == 3 || Pixel == 7 || Pixel == 11 || Pixel == 15)
		{
			deltax = 2;
		}

		if (Pixel == 4 || Pixel == 8 || Pixel == 12 || Pixel == 16)
		{
			deltax = 3;
		}

		if (Pixel == 5 || Pixel == 6 || Pixel == 7 || Pixel == 8)
		{
			deltay = 1;
		}

		if (Pixel == 9 || Pixel == 10 || Pixel == 11 || Pixel == 12)
		{
			deltay = 2;
		}

		if (Pixel == 13 || Pixel == 14 || Pixel == 15 || Pixel == 16)
		{
			deltay = 3;
		}

		auto dx = x * _ScaleX + deltax;
		auto dy = y * _ScaleY + deltay;

		auto dst = (dy * sizex * _ScaleX + dx) * Channels;

		Output[dst] = R;
		Output[dst + 1] = G;
		Output[dst + 2] = B;
	}
}

void Write16RGB(unsigned char* Output, int sizex, int sizey, int x, int y, int Pixel, int rgb)
{
	auto R = (unsigned char)(rgb >> 16);
	auto G = (unsigned char)((rgb & 0x00FF00) >> 8);
	auto B = (unsigned char)(rgb & 0x0000FF);

	Write16RGB(Output, sizex, sizey, x, y, Pixel, R, G, B);
}

void WriteMagnify(unsigned char* Input, unsigned char* Output, int sizex, int sizey, int x, int y)
{
	auto Channels = 3;

	auto x0 = x * _ScaleX;
	auto y0 = y * _ScaleY;

	for (auto deltay = 0; deltay < _ScaleY; deltay++)
	{
		for (auto deltax = 0; deltax < _ScaleX; deltax++)
		{
			auto dx = x0 + deltax;
			auto dy = y0 + deltay;

			auto dst = (dy * sizex * _ScaleX + dx) * Channels;

			auto index = (y * sizex + x) * Channels;

			for (auto Channel = 0; Channel < Channels; Channel++)
			{
				Output[dst + Channel] = Input[index + Channel];
			}
		}
	}
}

int RGBINT(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16) + (g << 8) + b;
}

unsigned char Truncate(unsigned char color)
{
	color = max(0, color);
	color = min(255, color);

	return color;
}
