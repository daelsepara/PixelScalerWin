#pragma once
#include "PixelScalerForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	try
	{
		auto owned = false;

		auto hMutex = gcnew System::Threading::Mutex(true, L"PixelScaler v0.1", owned);

		if (owned)
		{
			Application::EnableVisualStyles();
			Application::SetCompatibleTextRenderingDefault(false);
			PixelScalerWin::PixelScalerForm form;
			Application::Run(%form);
		}
		else
		{
			MessageBox::Show("Application is already running!");
			return 0;
		}

		GC::KeepAlive(hMutex);
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message);
	}

	return 0;
}
