#pragma once

void FlipUD(unsigned char* src, int sizex, int sizey)
{
	auto Channels = 3;
	
	if (src != NULL)
	{
		for (auto y = 0; y < sizey / 2; y++)
		{
			for (auto x = 0; x < sizex; x++)
			{
				auto index = (y * sizex + x) * Channels;
				auto rev = ((sizey - y - 1) * sizex + x) * Channels;

				for (auto Channel = 0; Channel < Channels; Channel++)
				{
					auto temp = src[index + Channel];
					src[index + Channel] = src[rev + Channel];
					src[rev + Channel] = temp;
				}
			}
		}
	}
}

void FlipLR(unsigned char* src, int sizex, int sizey)
{
	if (src != NULL)
	{
		auto Channels = 3;

		for (auto y = 0; y < sizey; y++)
		{
			for (auto x = 0; x < sizex / 2; x++)
			{
				auto index = (y * sizex + x) * Channels;
				auto rev = (y * sizex + (sizex - x - 1)) * Channels;

				for (auto Channel = 0; Channel < Channels; Channel++)
				{
					auto temp = src[index + Channel];
					src[index + Channel] = src[rev + Channel];
					src[rev + Channel] = temp;
				}
			}
		}
	}
}
