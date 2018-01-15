#define DECLDIR __declspec(dllexport)

extern "C"
{
	DECLDIR void Release();	 
	DECLDIR void __stdcall Apply(int argc, void** argv);
	DECLDIR void Threshold(bool threshold);
	DECLDIR int ID();
	DECLDIR int ScaleX();
	DECLDIR int ScaleY();
	DECLDIR int SizeX();
	DECLDIR int SizeY();
	DECLDIR int Parameters();
	DECLDIR const char* Name();
	DECLDIR const char* Description();
	DECLDIR unsigned char* Image();

}
