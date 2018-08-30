	#pragma once
	
	unsigned char* Buffer(int Length, unsigned char c)
	{
		auto Channels = 3;

		auto buffer = (unsigned char*)malloc(Length * Channels);

		for (auto i = 0; i < Length; i++)
		{
			auto index = i * Channels;

			buffer[index] = c;
			buffer[index + 1] = c;
			buffer[index + 2] = c;
		}

		return buffer;
	}

	unsigned char* New(int x, int y)
	{
		return Buffer(x * y, (unsigned char)0);
	}

	void Init(int srcx, int srcy)
	{
		_ScaleX = FilterScaleX;
		_ScaleY = FilterScaleY;
		_SizeX = srcx * FilterScaleX;
		_SizeY = srcy * FilterScaleY;
		_Threshold = ComparisonThreshold;

		free(ScaledImage);

		ScaledImage = New(_SizeX, _SizeY);
	}

	DECLDIR int ID()
	{
		return FilterID;
	}


	DECLDIR int ScaleX()
	{
		return FilterScaleX;
	}

	DECLDIR int ScaleY()
	{
		return FilterScaleY;
	}

	DECLDIR int SizeX()
	{
		return _SizeX;
	}

	DECLDIR int SizeY()
	{
		return _SizeY;
	}

	DECLDIR const char* Name()
	{
		return FilterName;
	}

	DECLDIR const char* Description()
	{
		return FilterDescription;
	}

	DECLDIR unsigned char* Image()
	{
		return ScaledImage;
	}

	DECLDIR void Threshold(bool threshold)
	{
		ComparisonThreshold = threshold;
	}
	
	DECLDIR void Release()
	{
		free(ScaledImage);

		ScaledImage = NULL;
	}
