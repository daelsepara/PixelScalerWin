#pragma once

public ref class FilterPlugin {

public:

	const char* DLL;
	const char* Name;
	const char* Description;
	int ID;
	int ScaleX;
	int ScaleY;
	int Parameters;
	bool Threshold;

	FilterPlugin(const char* dll, const char *name, const char* description, int id, int scalex, int scaley, int parameters, bool threshold)
	{
		DLL = dll;
		Name = name;
		Description = description;
		ID = id;
		ScaleX = scalex;
		ScaleY = scaley;
		Parameters = parameters;
		Threshold = threshold;
	}
};
