#pragma once
#include <windows.h>
#include <string>
#include <limits>

#include "FilterPlugin.h"

namespace PixelScalerWin {

	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Runtime::InteropServices;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Summary for PixelScalerForm
	/// </summary>
	public ref class PixelScalerForm : public System::Windows::Forms::Form
	{

	public:

		Bitmap^ InputBitmap;
		Bitmap^ ScaledBitmap;

		OpenFileDialog^ OpenImageDialog;
		SaveFileDialog^ SaveImageDialog;

		List<FilterPlugin^> PluginList;
		List<FilterPlugin^> FilterProcessList;

		Form^ ZoomWindow;
		PictureBox^ ZoomPictureBox;

	public:
		Bitmap^ ZoomBitmap;

		PixelScalerForm(void)
		{
			InitializeComponent();

			Intialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PixelScalerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::PictureBox^  InputImage;
	private: System::Windows::Forms::PictureBox^  ScaledImage;
	private: System::Windows::Forms::Label^  InputImageLabel;
	private: System::Windows::Forms::Label^  ScaledImageLabel;
	private: System::Windows::Forms::Button^  OpenImageButton;
	private: System::Windows::Forms::Button^  SaveScaledImageButton;

	private: System::Windows::Forms::TabControl^  OptionsTabs;
	private: System::Windows::Forms::TabPage^  FiltersPage;
	private: System::Windows::Forms::TabPage^  AboutPage;

	private: System::Windows::Forms::ListBox^  FiltersList;
	private: System::Windows::Forms::ListBox^  OperationsList;
	private: System::Windows::Forms::Label^  FiltersListLabel;
	private: System::Windows::Forms::Label^  OperationsListLabel;

	private: System::Windows::Forms::Button^  AddToOperationsButton;
	private: System::Windows::Forms::Button^  RemoveFromOperationsButton;
	private: System::Windows::Forms::Button^  ApplyFiltersButton;
	private: System::Windows::Forms::Button^  FilterDetailsButton;
	private: System::Windows::Forms::CheckBox^  UseThresholdMode;
	private: System::Windows::Forms::Button^  MoveOperationDownButton;
	private: System::Windows::Forms::Button^  MoveOperationUpButton;

	private: System::Windows::Forms::PictureBox^  LogoBox;
	private: System::Windows::Forms::LinkLabel^  CrunchPixelsURL;

	private: System::Windows::Forms::CheckBox^  CrossHairs;
	private: System::Windows::Forms::Button^  CrossHairColor;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PixelScalerForm::typeid));
			this->InputImage = (gcnew System::Windows::Forms::PictureBox());
			this->ScaledImage = (gcnew System::Windows::Forms::PictureBox());
			this->InputImageLabel = (gcnew System::Windows::Forms::Label());
			this->ScaledImageLabel = (gcnew System::Windows::Forms::Label());
			this->OpenImageButton = (gcnew System::Windows::Forms::Button());
			this->SaveScaledImageButton = (gcnew System::Windows::Forms::Button());
			this->OptionsTabs = (gcnew System::Windows::Forms::TabControl());
			this->FiltersPage = (gcnew System::Windows::Forms::TabPage());
			this->MoveOperationDownButton = (gcnew System::Windows::Forms::Button());
			this->MoveOperationUpButton = (gcnew System::Windows::Forms::Button());
			this->UseThresholdMode = (gcnew System::Windows::Forms::CheckBox());
			this->FilterDetailsButton = (gcnew System::Windows::Forms::Button());
			this->FiltersListLabel = (gcnew System::Windows::Forms::Label());
			this->OperationsListLabel = (gcnew System::Windows::Forms::Label());
			this->OperationsList = (gcnew System::Windows::Forms::ListBox());
			this->ApplyFiltersButton = (gcnew System::Windows::Forms::Button());
			this->RemoveFromOperationsButton = (gcnew System::Windows::Forms::Button());
			this->AddToOperationsButton = (gcnew System::Windows::Forms::Button());
			this->FiltersList = (gcnew System::Windows::Forms::ListBox());
			this->AboutPage = (gcnew System::Windows::Forms::TabPage());
			this->CrunchPixelsURL = (gcnew System::Windows::Forms::LinkLabel());
			this->LogoBox = (gcnew System::Windows::Forms::PictureBox());
			this->CrossHairs = (gcnew System::Windows::Forms::CheckBox());
			this->CrossHairColor = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ScaledImage))->BeginInit();
			this->OptionsTabs->SuspendLayout();
			this->FiltersPage->SuspendLayout();
			this->AboutPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoBox))->BeginInit();
			this->SuspendLayout();
			// 
			// InputImage
			// 
			this->InputImage->BackColor = System::Drawing::SystemColors::Control;
			this->InputImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->InputImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InputImage->Location = System::Drawing::Point(40, 80);
			this->InputImage->Name = L"InputImage";
			this->InputImage->Size = System::Drawing::Size(384, 384);
			this->InputImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->InputImage->TabIndex = 0;
			this->InputImage->TabStop = false;
			this->InputImage->MouseLeave += gcnew System::EventHandler(this, &PixelScalerForm::InputImage_MouseLeave);
			this->InputImage->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PixelScalerForm::InputImage_MouseMove);
			// 
			// ScaledImage
			// 
			this->ScaledImage->BackColor = System::Drawing::SystemColors::Control;
			this->ScaledImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ScaledImage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ScaledImage->Location = System::Drawing::Point(460, 80);
			this->ScaledImage->MaximumSize = System::Drawing::Size(512, 512);
			this->ScaledImage->Name = L"ScaledImage";
			this->ScaledImage->Size = System::Drawing::Size(384, 384);
			this->ScaledImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ScaledImage->TabIndex = 1;
			this->ScaledImage->TabStop = false;
			this->ScaledImage->MouseLeave += gcnew System::EventHandler(this, &PixelScalerForm::ScaledImage_MouseLeave);
			this->ScaledImage->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PixelScalerForm::ScaledImage_MouseMove);
			// 
			// InputImageLabel
			// 
			this->InputImageLabel->AutoSize = true;
			this->InputImageLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InputImageLabel->Location = System::Drawing::Point(34, 45);
			this->InputImageLabel->Name = L"InputImageLabel";
			this->InputImageLabel->Size = System::Drawing::Size(163, 32);
			this->InputImageLabel->TabIndex = 2;
			this->InputImageLabel->Text = L"Input Image";
			// 
			// ScaledImageLabel
			// 
			this->ScaledImageLabel->AutoSize = true;
			this->ScaledImageLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ScaledImageLabel->Location = System::Drawing::Point(454, 45);
			this->ScaledImageLabel->Name = L"ScaledImageLabel";
			this->ScaledImageLabel->Size = System::Drawing::Size(188, 32);
			this->ScaledImageLabel->TabIndex = 3;
			this->ScaledImageLabel->Text = L"Scaled Image";
			// 
			// OpenImageButton
			// 
			this->OpenImageButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OpenImageButton->Location = System::Drawing::Point(40, 477);
			this->OpenImageButton->Name = L"OpenImageButton";
			this->OpenImageButton->Size = System::Drawing::Size(128, 64);
			this->OpenImageButton->TabIndex = 4;
			this->OpenImageButton->Text = L"Open";
			this->OpenImageButton->UseVisualStyleBackColor = true;
			this->OpenImageButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::OpenImageButton_Click);
			// 
			// SaveScaledImageButton
			// 
			this->SaveScaledImageButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SaveScaledImageButton->Location = System::Drawing::Point(174, 477);
			this->SaveScaledImageButton->Name = L"SaveScaledImageButton";
			this->SaveScaledImageButton->Size = System::Drawing::Size(128, 64);
			this->SaveScaledImageButton->TabIndex = 5;
			this->SaveScaledImageButton->Text = L"Save";
			this->SaveScaledImageButton->UseVisualStyleBackColor = true;
			this->SaveScaledImageButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::SaveScaledImageButton_Click);
			// 
			// OptionsTabs
			// 
			this->OptionsTabs->Controls->Add(this->FiltersPage);
			this->OptionsTabs->Controls->Add(this->AboutPage);
			this->OptionsTabs->Location = System::Drawing::Point(861, 44);
			this->OptionsTabs->Name = L"OptionsTabs";
			this->OptionsTabs->SelectedIndex = 0;
			this->OptionsTabs->Size = System::Drawing::Size(389, 497);
			this->OptionsTabs->TabIndex = 6;
			// 
			// FiltersPage
			// 
			this->FiltersPage->BackColor = System::Drawing::Color::Transparent;
			this->FiltersPage->Controls->Add(this->MoveOperationDownButton);
			this->FiltersPage->Controls->Add(this->MoveOperationUpButton);
			this->FiltersPage->Controls->Add(this->UseThresholdMode);
			this->FiltersPage->Controls->Add(this->FilterDetailsButton);
			this->FiltersPage->Controls->Add(this->FiltersListLabel);
			this->FiltersPage->Controls->Add(this->OperationsListLabel);
			this->FiltersPage->Controls->Add(this->OperationsList);
			this->FiltersPage->Controls->Add(this->ApplyFiltersButton);
			this->FiltersPage->Controls->Add(this->RemoveFromOperationsButton);
			this->FiltersPage->Controls->Add(this->AddToOperationsButton);
			this->FiltersPage->Controls->Add(this->FiltersList);
			this->FiltersPage->Location = System::Drawing::Point(4, 25);
			this->FiltersPage->Name = L"FiltersPage";
			this->FiltersPage->Padding = System::Windows::Forms::Padding(3);
			this->FiltersPage->Size = System::Drawing::Size(381, 468);
			this->FiltersPage->TabIndex = 0;
			this->FiltersPage->Text = L"Filters";
			// 
			// MoveOperationDownButton
			// 
			this->MoveOperationDownButton->Location = System::Drawing::Point(78, 373);
			this->MoveOperationDownButton->Name = L"MoveOperationDownButton";
			this->MoveOperationDownButton->Size = System::Drawing::Size(64, 54);
			this->MoveOperationDownButton->TabIndex = 11;
			this->MoveOperationDownButton->Text = L"Down";
			this->MoveOperationDownButton->UseVisualStyleBackColor = true;
			this->MoveOperationDownButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::MoveOperationDownButton_Click);
			// 
			// MoveOperationUpButton
			// 
			this->MoveOperationUpButton->Location = System::Drawing::Point(13, 373);
			this->MoveOperationUpButton->Name = L"MoveOperationUpButton";
			this->MoveOperationUpButton->Size = System::Drawing::Size(59, 54);
			this->MoveOperationUpButton->TabIndex = 10;
			this->MoveOperationUpButton->Text = L"Up";
			this->MoveOperationUpButton->UseVisualStyleBackColor = true;
			this->MoveOperationUpButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::MoveOperationUpButton_Click);
			// 
			// UseThresholdMode
			// 
			this->UseThresholdMode->AutoSize = true;
			this->UseThresholdMode->Location = System::Drawing::Point(13, 340);
			this->UseThresholdMode->Name = L"UseThresholdMode";
			this->UseThresholdMode->Size = System::Drawing::Size(309, 21);
			this->UseThresholdMode->TabIndex = 9;
			this->UseThresholdMode->Text = L"Use Threshold when Comparing Pixel Colors";
			this->UseThresholdMode->UseVisualStyleBackColor = true;
			this->UseThresholdMode->CheckedChanged += gcnew System::EventHandler(this, &PixelScalerForm::UseThresholdMode_CheckedChanged);
			// 
			// FilterDetailsButton
			// 
			this->FilterDetailsButton->Location = System::Drawing::Point(119, 124);
			this->FilterDetailsButton->Name = L"FilterDetailsButton";
			this->FilterDetailsButton->Size = System::Drawing::Size(100, 54);
			this->FilterDetailsButton->TabIndex = 8;
			this->FilterDetailsButton->Text = L"Details";
			this->FilterDetailsButton->UseVisualStyleBackColor = true;
			this->FilterDetailsButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::FilterDetailsButton_Click);
			// 
			// FiltersListLabel
			// 
			this->FiltersListLabel->AutoSize = true;
			this->FiltersListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FiltersListLabel->Location = System::Drawing::Point(12, 11);
			this->FiltersListLabel->Name = L"FiltersListLabel";
			this->FiltersListLabel->Size = System::Drawing::Size(63, 20);
			this->FiltersListLabel->TabIndex = 7;
			this->FiltersListLabel->Text = L"Filters";
			// 
			// OperationsListLabel
			// 
			this->OperationsListLabel->AutoSize = true;
			this->OperationsListLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->OperationsListLabel->Location = System::Drawing::Point(12, 211);
			this->OperationsListLabel->Name = L"OperationsListLabel";
			this->OperationsListLabel->Size = System::Drawing::Size(101, 20);
			this->OperationsListLabel->TabIndex = 6;
			this->OperationsListLabel->Text = L"Operations";
			// 
			// OperationsList
			// 
			this->OperationsList->FormattingEnabled = true;
			this->OperationsList->ItemHeight = 16;
			this->OperationsList->Location = System::Drawing::Point(13, 234);
			this->OperationsList->Name = L"OperationsList";
			this->OperationsList->Size = System::Drawing::Size(350, 100);
			this->OperationsList->TabIndex = 5;
			this->OperationsList->SelectedIndexChanged += gcnew System::EventHandler(this, &PixelScalerForm::OperationsList_SelectedIndexChanged);
			// 
			// ApplyFiltersButton
			// 
			this->ApplyFiltersButton->Location = System::Drawing::Point(254, 373);
			this->ApplyFiltersButton->Name = L"ApplyFiltersButton";
			this->ApplyFiltersButton->Size = System::Drawing::Size(100, 54);
			this->ApplyFiltersButton->TabIndex = 4;
			this->ApplyFiltersButton->Text = L"Apply";
			this->ApplyFiltersButton->UseVisualStyleBackColor = true;
			this->ApplyFiltersButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::ApplyFiltersButton_Click);
			// 
			// RemoveFromOperationsButton
			// 
			this->RemoveFromOperationsButton->Location = System::Drawing::Point(148, 373);
			this->RemoveFromOperationsButton->Name = L"RemoveFromOperationsButton";
			this->RemoveFromOperationsButton->Size = System::Drawing::Size(100, 54);
			this->RemoveFromOperationsButton->TabIndex = 3;
			this->RemoveFromOperationsButton->Text = L"Remove";
			this->RemoveFromOperationsButton->UseVisualStyleBackColor = true;
			this->RemoveFromOperationsButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::RemoveFromOperationsButton_Click);
			// 
			// AddToOperationsButton
			// 
			this->AddToOperationsButton->Location = System::Drawing::Point(13, 124);
			this->AddToOperationsButton->Name = L"AddToOperationsButton";
			this->AddToOperationsButton->Size = System::Drawing::Size(100, 54);
			this->AddToOperationsButton->TabIndex = 2;
			this->AddToOperationsButton->Text = L"Add";
			this->AddToOperationsButton->UseVisualStyleBackColor = true;
			this->AddToOperationsButton->Click += gcnew System::EventHandler(this, &PixelScalerForm::AddToOperationsButton_Click);
			// 
			// FiltersList
			// 
			this->FiltersList->FormattingEnabled = true;
			this->FiltersList->ItemHeight = 16;
			this->FiltersList->Location = System::Drawing::Point(13, 34);
			this->FiltersList->Name = L"FiltersList";
			this->FiltersList->Size = System::Drawing::Size(350, 84);
			this->FiltersList->TabIndex = 0;
			// 
			// AboutPage
			// 
			this->AboutPage->BackColor = System::Drawing::Color::Transparent;
			this->AboutPage->Controls->Add(this->CrunchPixelsURL);
			this->AboutPage->Controls->Add(this->LogoBox);
			this->AboutPage->Location = System::Drawing::Point(4, 25);
			this->AboutPage->Name = L"AboutPage";
			this->AboutPage->Padding = System::Windows::Forms::Padding(3);
			this->AboutPage->Size = System::Drawing::Size(381, 468);
			this->AboutPage->TabIndex = 1;
			this->AboutPage->Text = L"About";
			// 
			// CrunchPixelsURL
			// 
			this->CrunchPixelsURL->AutoSize = true;
			this->CrunchPixelsURL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CrunchPixelsURL->Location = System::Drawing::Point(78, 180);
			this->CrunchPixelsURL->Name = L"CrunchPixelsURL";
			this->CrunchPixelsURL->Size = System::Drawing::Size(213, 25);
			this->CrunchPixelsURL->TabIndex = 1;
			this->CrunchPixelsURL->TabStop = true;
			this->CrunchPixelsURL->Text = L"http://crunchpixels.com";
			// 
			// LogoBox
			// 
			this->LogoBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoBox.BackgroundImage")));
			this->LogoBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LogoBox->InitialImage = nullptr;
			this->LogoBox->Location = System::Drawing::Point(111, 77);
			this->LogoBox->Name = L"LogoBox";
			this->LogoBox->Size = System::Drawing::Size(150, 100);
			this->LogoBox->TabIndex = 0;
			this->LogoBox->TabStop = false;
			// 
			// CrossHairs
			// 
			this->CrossHairs->AutoSize = true;
			this->CrossHairs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CrossHairs->Location = System::Drawing::Point(460, 477);
			this->CrossHairs->Name = L"CrossHairs";
			this->CrossHairs->Size = System::Drawing::Size(188, 21);
			this->CrossHairs->TabIndex = 7;
			this->CrossHairs->Text = L"Show crosshair on zoom ";
			this->CrossHairs->UseVisualStyleBackColor = true;
			// 
			// CrossHairColor
			// 
			this->CrossHairColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CrossHairColor->Location = System::Drawing::Point(460, 505);
			this->CrossHairColor->Name = L"CrossHairColor";
			this->CrossHairColor->Size = System::Drawing::Size(182, 32);
			this->CrossHairColor->TabIndex = 8;
			this->CrossHairColor->Text = L"Select Color";
			this->CrossHairColor->UseVisualStyleBackColor = true;
			this->CrossHairColor->Click += gcnew System::EventHandler(this, &PixelScalerForm::CrossHairColor_Click);
			// 
			// PixelScalerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 553);
			this->Controls->Add(this->CrossHairColor);
			this->Controls->Add(this->CrossHairs);
			this->Controls->Add(this->OptionsTabs);
			this->Controls->Add(this->SaveScaledImageButton);
			this->Controls->Add(this->OpenImageButton);
			this->Controls->Add(this->ScaledImageLabel);
			this->Controls->Add(this->InputImageLabel);
			this->Controls->Add(this->ScaledImage);
			this->Controls->Add(this->InputImage);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1280, 600);
			this->MinimumSize = System::Drawing::Size(1280, 600);
			this->Name = L"PixelScalerForm";
			this->Text = L"PixelScaler for Windows v0.1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PixelScalerForm::PixelScalerForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ScaledImage))->EndInit();
			this->OptionsTabs->ResumeLayout(false);
			this->FiltersPage->ResumeLayout(false);
			this->FiltersPage->PerformLayout();
			this->AboutPage->ResumeLayout(false);
			this->AboutPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void Intialize()
	{
		InitializeGlobals();
		InitializeBitmaps();
		IntializeFilters();
		InitializeFileDialogs();
		InitializeZoomWindow();
	}

	private: void InitializeGlobals()
	{
		
	}

	void InitializeZoomWindow()
	{
		ZoomWindow = gcnew Form();
		ZoomWindow->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		ZoomWindow->Hide();
		ZoomWindow->Width = ScaledBitmap->Width;
		ZoomWindow->Height = ScaledBitmap->Height;
		ZoomWindow->ControlBox = false;
		ZoomWindow->MaximizeBox = false;

		ZoomPictureBox = gcnew PictureBox();
		ZoomPictureBox->Width = ScaledBitmap->Width;
		ZoomPictureBox->Height = ScaledBitmap->Height;
		ZoomPictureBox->BackColor = Color::Transparent;
		ZoomPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Normal;

		ZoomWindow->Controls->Add(ZoomPictureBox);
		ZoomPictureBox->Top = 0;
		ZoomPictureBox->Left = 0;
		ZoomPictureBox->Padding = System::Windows::Forms::Padding(0, 0, 0, 0);
	}

	void CalcCoords(int x, int y, int& xs, int& ys, PictureBox^% picturebox, Bitmap^% bitmap)
	{
		xs = x;
		ys = y;

		auto pic_aspect = ((double) picturebox->Width) / picturebox->Height;
		auto img_aspect = ((double) bitmap->Width ) / bitmap->Height;

		if (pic_aspect > img_aspect)
		{
			ys = bitmap->Height * y / picturebox->Height;

			auto scaledWidth = ((double) bitmap->Width * picturebox->Height ) / bitmap->Height;
			auto dx = (picturebox->Width - scaledWidth) / 2;

			xs = (int)((x - dx) * (double) bitmap->Height / picturebox->Height);
		}
		else
		{
			xs = bitmap->Width * x / picturebox->Width;

			auto scaledHeight = ((double)bitmap->Height * picturebox->Width) / bitmap->Width;
			auto dy = (picturebox->Height - scaledHeight) / 2;

			ys = (int)((y - dy) * (double) bitmap->Width / picturebox->Width);
		}
	}

	void ResizeZoomWindow()
	{
		ZoomWindow->Width = 256;
		ZoomWindow->Height = 256;
		ZoomPictureBox->Width = 256;
		ZoomPictureBox->Height = 256;
	}

	void ViewSelection(int x, int y, PictureBox^% picturebox, Bitmap^% bitmap)
	{
		int xAdjustment = 2;
		int yAdjustment = 1;

		int xs, ys;

		CalcCoords(x + xAdjustment, y + yAdjustment, xs, ys, picturebox, bitmap);

		auto xc = ZoomBitmap->Width / 2;
		auto yc = ZoomBitmap->Height / 2;

		xs -= xc;
		ys -= yc;

		xs = max(-xc, xs);
		xs = min((bitmap->Width - xc), xs);

		ys = max(-yc, ys);
		ys = min((bitmap->Height - yc), ys);

		auto graphics = Graphics::FromImage(ZoomBitmap);

		graphics->Clear(Color::Transparent);

		GraphicsUnit units = GraphicsUnit::Pixel;

		graphics->DrawImage(bitmap, 0, 0, System::Drawing::Rectangle(xs, ys, ZoomBitmap->Width, ZoomBitmap->Height), units);

		if (CrossHairs->Checked)
		{
			auto CrossHair = gcnew Pen(CrossHairColor->ForeColor);

			graphics->DrawLine(CrossHair, Point(xc, 0), Point(xc, ZoomBitmap->Height));
			graphics->DrawLine(CrossHair, Point(0, yc), Point(ZoomPictureBox->Width, yc));
		}

		delete graphics;

		RenderBitmap(ZoomBitmap, ZoomPictureBox);
	}

	void PreventClose(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		e->Cancel = true;

		return;
	}

	void DisplayZoomWindow(int top, int left)
	{
		ZoomWindow->Show();

		MoveZoomWindow(top, left);
	}

	void HideZoomWindow()
	{
		ZoomWindow->Hide();
	}

	void MoveZoomWindow(int top, int left)
	{
		ZoomWindow->Top = top;
		ZoomWindow->Left = left;
	}

	private: void InitializeBitmaps()
	{
		InputBitmap = NewBitmap(InputImage->Width, InputImage->Height);
		ScaledBitmap = NewBitmap(ScaledImage->Width, InputImage->Height);
		ZoomBitmap = NewBitmap(ScaledImage->Width, ScaledImage->Height);

		RenderBitmap(InputBitmap, InputImage);
		RenderBitmap(ScaledBitmap, ScaledImage);
	}

	private: void InitializeFileDialogs()
	{
		OpenImageDialog = gcnew OpenFileDialog();
		OpenImageDialog->InitialDirectory = "c:\\";
		OpenImageDialog->Filter = "png files (*.png)|*.png|jpg files (*.jpg)|*.jpg|bmp files (*.bmp)|*.bmp|tiff files (*.tiff)|*.tif|gif files (*.gif)|*.gif|All files (*.*)|*.*";
		OpenImageDialog->FilterIndex = 1;

		SaveImageDialog = gcnew SaveFileDialog();
		SaveImageDialog->InitialDirectory = "c:\\";
		SaveImageDialog->Filter = "png files (*.png)|*.png|jpg files (*.jpg)|*.jpg|bmp files (*.bmp)|*.bmp|tiff files (*.tiff)|*.tif|gif files (*.gif)|*.gif";
		SaveImageDialog->FilterIndex = 1;
	}

	private: void CleanShutdown()
	{
		ZoomWindow->Close();
		
		Free(InputBitmap, ScaledBitmap, ZoomBitmap);
	}
	
	public: void Free(... array<Bitmap^>^ bitmaps)
	{
		for each (Bitmap^ bitmap in bitmaps)
		{
			if (bitmap != nullptr)
			{
				delete bitmap;
			}
		}
	}

	private: const char* CString(String^ string)
	{
		return (const char*)(Marshal::StringToHGlobalAnsi(string)).ToPointer();
	}

	private: std::wstring WString(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}

	private: void IntializeFilters()
	{
		auto CurrentFolder = System::IO::Directory::GetCurrentDirectory();
		auto Files = System::IO::Directory::GetFiles(CurrentFolder, gcnew String("*.dll"));

		for each(auto file in Files)
		{
			ReadDLL(CString(file));
		}

		for each(auto filter in PluginList)
		{
			FiltersList->Items->Add(gcnew String(filter->Name));
		}
	}

	private: void ReadDLL(const char *dll)
	{
		typedef int(*FID)();
		typedef int(*FScaleX)();
		typedef int(*FScaleY)();
		typedef int(*FParameters)();
		typedef const char*(*FName)();
		typedef const char*(*FDescription)();

		auto FilterLibrary = LoadLibrary(WString(dll).c_str());

		if (FilterLibrary != NULL)
		{
			FName _Name = (FName)GetProcAddress(FilterLibrary, "Name");
			FDescription _Description = (FDescription)GetProcAddress(FilterLibrary, "Description");
			FID _ID = (FID)GetProcAddress(FilterLibrary, "ID");
			FScaleX _ScaleX = (FScaleX)GetProcAddress(FilterLibrary, "ScaleX");
			FScaleY _ScaleY = (FScaleY)GetProcAddress(FilterLibrary, "ScaleY");
			FParameters _Parameters = (FParameters)GetProcAddress(FilterLibrary, "Parameters");

			if (_Name && _Description && _ID && _ScaleX && _ScaleY &&  _Parameters)
			{
				auto dllfile = System::IO::Path::GetFileName(gcnew String(dll));

				auto id = _ID();
				auto name = _Name();
				auto description = _Description();
				auto scalex = _ScaleX();
				auto scaley = _ScaleY();
				auto parameters = _Parameters();

				PluginList.Add(gcnew FilterPlugin(CString(dllfile), name, description, id, scalex, scaley, parameters, false));
			}
		}
	}
	
	private: unsigned char* PrepareBitmap(Bitmap^ bitmap)
	{
		auto Channels = 3;

		auto xdim = bitmap->Width;
		auto ydim = bitmap->Height;

		auto IsNotRGB24 = (bitmap->PixelFormat != System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		auto temp = IsNotRGB24 ? ConvertTo24bpp(bitmap) : bitmap;

		auto buffer = (unsigned char*)malloc(xdim * ydim * Channels);

		auto readData = LockBits(temp);

		auto Depth = Image::GetPixelFormatSize(temp->PixelFormat);

		for (auto y = 0; y < ydim; y++)
		{
			for (auto x = 0; x < xdim; x++)
			{
				auto startIndex = y * readData->Stride + x * Channels;
				auto dst = (y * xdim + x) * Channels;

				buffer[dst] = (unsigned char) Marshal::ReadByte(readData->Scan0, startIndex);
				buffer[dst + 1] = (unsigned char) Marshal::ReadByte(readData->Scan0, startIndex + 1);
				buffer[dst + 2] = (unsigned char) Marshal::ReadByte(readData->Scan0, startIndex + 2);
			}
		}

		UnlockBits(temp, readData);

		if (IsNotRGB24)
			Free(temp);

		return buffer;
	}

	private: unsigned char* Buffer(int Length, unsigned char c)
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

	private: void Copy(unsigned char*& dst, unsigned char*& src, int Length)
	{
		memcpy(dst, src, Length * sizeof(unsigned char));
	}

	private: void Clip(unsigned char& variable, unsigned char minValue, unsigned char maxValue)
	{
		variable = max(minValue, variable);
		variable = min(maxValue, variable);
	}

	private: BitmapData^ LockBits(Bitmap^ bitmap)
	{
		if (bitmap != nullptr)
		{
			auto rect = System::Drawing::Rectangle(0, 0, bitmap->Width, bitmap->Height);
			auto bmpData = bitmap->LockBits(rect, ImageLockMode::ReadWrite, bitmap->PixelFormat);

			return bmpData;
		}

		return nullptr;
	}

	private: static void UnlockBits(Bitmap^ bitmap, BitmapData^ bmpData)
	{
		if (bitmap != nullptr && bmpData != nullptr)
			bitmap->UnlockBits(bmpData);
	}

	private: void WriteRGB(Bitmap^ bitmap, BitmapData^ bmpData, int x, int y, unsigned char R, unsigned char G, unsigned char B)
	{
		Clip(R, 0, 255);
		Clip(G, 0, 255);
		Clip(B, 0, 255);

		if (bitmap != nullptr)
		{
			auto Depth = Image::GetPixelFormatSize(bitmap->PixelFormat);
			auto Channels = Depth / 8;
			auto startIndex = y * bmpData->Stride + x * Channels;

			Marshal::WriteByte(bmpData->Scan0, startIndex, R);
			Marshal::WriteByte(bmpData->Scan0, startIndex + 1, G);
			Marshal::WriteByte(bmpData->Scan0, startIndex + 2, B);
		}
	}
	
	private: Bitmap^ WriteBitmap(unsigned char* src, int srcx, int srcy)
	{
		auto Channels = 3;

		auto bitmap = NewBitmap(srcx, srcy);

		auto writeData = LockBits(bitmap);

		for (auto y = 0; y < srcy; y++)
		{
			for (auto x = 0; x < srcx; x++)
			{
				auto index = (y * srcx + x) * Channels;
				
				auto R = src[index];
				auto G = src[index + 1];
				auto B = src[index + 2];

				WriteRGB(bitmap, writeData, x, y, R, G, B);
			}
		}

		UnlockBits(bitmap, writeData);

		return bitmap;
	}

	private: void ApplyFilters()
	{
		if (FilterProcessList.Count > 0)
		{
			ApplyFiltersButton->Enabled = false;

			typedef void(*FRelease)();
			typedef void(*FApply)(int, void**);
			typedef void(*FThreshold)(bool);
			typedef int(*FScaleX)();
			typedef int(*FScaleY)();
			typedef int(*FSizeX)();
			typedef int(*FSizeY)();
			typedef int(*FParameters)();
			typedef unsigned char*(*FImage)();
			
			auto bitmap = PrepareBitmap(InputBitmap);
			auto xdim = InputBitmap->Width;
			auto ydim = InputBitmap->Height;

			auto Channels = 3;

			for each(auto filter in FilterProcessList)
			{
				auto dllname = filter->DLL;

				auto FilterLibrary = LoadLibrary(WString(dllname).c_str());

				if (FilterLibrary)
				{
					auto _ScaleX = (FScaleX)GetProcAddress(FilterLibrary, "ScaleX");
					auto _ScaleY = (FScaleY)GetProcAddress(FilterLibrary, "ScaleY");
					auto _SizeX = (FSizeX)GetProcAddress(FilterLibrary, "SizeX");
					auto _SizeY = (FSizeY)GetProcAddress(FilterLibrary, "SizeY");
					auto _Apply = (FApply)GetProcAddress(FilterLibrary, "Apply");
					auto _Parameters = (FParameters)GetProcAddress(FilterLibrary, "Parameters");
					auto _Release = (FRelease)GetProcAddress(FilterLibrary, "Release");
					auto _Image = (FImage)GetProcAddress(FilterLibrary, "Image");
					auto _Threshold = (FThreshold)GetProcAddress(FilterLibrary, "Threshold");

					if (_ScaleX && _ScaleY && _SizeX && _SizeY && _Apply && _Image && _Release && _Threshold)
					{
						void* Params[] = { bitmap, &xdim, &ydim };
						
						_Threshold(filter->Threshold);

						_Apply(3, Params);

						auto scaled = _Image();
						
						xdim = _SizeX();
						ydim = _SizeY();

						auto length = xdim * ydim * Channels;

						free(bitmap);

						bitmap = Buffer(length, (unsigned char)0);
						
						Copy(bitmap, scaled, length);

						_Release();
					}

					FreeLibrary(FilterLibrary);
				}
			}

			Free(ScaledBitmap);

			ScaledBitmap = WriteBitmap(bitmap, xdim, ydim);

			free(bitmap);

			ScaledImageLabel->Text = gcnew String("Scaled Image (" + ScaledBitmap->Width + " x " + ScaledBitmap->Height + ")");

			RenderBitmap(ScaledBitmap, ScaledImage);

			ApplyFiltersButton->Enabled = true;

			MessageBox::Show("Filters Applied!", "Done");
		}
	}

	private: static Bitmap^ NewBitmap(int Width, int Height)
	{
		auto bitmap = gcnew Bitmap(Width, Height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);

		auto gr = Graphics::FromImage(bitmap);
		
		gr->Clear(Color::Transparent);

		delete gr;

		return bitmap;
	}
	
	private: void RenderBitmap(Bitmap ^%bitmap, PictureBox ^pictureBox)
	{
		if (pictureBox->Image != nullptr)
		{
			delete pictureBox->Image;
		}

		pictureBox->Image = bitmap->Clone(System::Drawing::Rectangle(0, 0, bitmap->Width, bitmap->Height), bitmap->PixelFormat);
	}

	private: System::Void PixelScalerForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		CleanShutdown();
	}

	private: Bitmap^ ConvertTo24bpp(Bitmap^ bitmap32)
	{
		auto bitmap24 = gcnew Bitmap(bitmap32->Width, bitmap32->Height, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
			
		auto graphics = Graphics::FromImage(bitmap24);
			
		graphics->DrawImage(bitmap32, System::Drawing::Rectangle(0, 0, bitmap32->Width, bitmap32->Height));
			
		delete graphics;

		return bitmap24;
	}

	private: void MoveOperationUp(int index, ListBox^ listbox, List<FilterPlugin^>% list)
	{
		if (index > 0 && index < listbox->Items->Count && index < list.Count)
		{
			auto itemListBox = listbox->Items[index - 1];
			auto item = list[index - 1];

			listbox->Items[index - 1] = listbox->Items[index];
			list[index - 1] = list[index];

			listbox->Items[index] = itemListBox;
			list[index] = item;

			listbox->SelectedIndex = index - 1;
		}
	}

	private: void MoveOperationDown(int index, ListBox^ listbox, List<FilterPlugin^>% list)
	{
		if (index >= 0 && index < listbox->Items->Count - 1 && index < list.Count - 1)
		{
			auto itemListBox = listbox->Items[index + 1];
			auto item = list[index + 1];

			listbox->Items[index + 1] = listbox->Items[index];
			list[index + 1] = list[index];

			listbox->Items[index] = itemListBox;
			list[index] = item;

			listbox->SelectedIndex = index + 1;
		}
	}

	private: System::Void FilterDetailsButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (PluginList.Count > 0 && FiltersList->SelectedIndex >= 0 && FiltersList->SelectedIndex < PluginList.Count)
		{
			char caption[100];
			char buffer[500];

			caption[0] = '\0';
			buffer[0] = '\0';

			auto filter = PluginList[FiltersList->SelectedIndex];
		
			#ifdef WIN32
				sprintf_s(caption, "About %s", filter->Name);
				sprintf_s(buffer, "Description: %s\n\nScale: %d x %d\n\nDLL: %s", filter->Description, filter->ScaleX, filter->ScaleY, filter->DLL);
			#else
				sprintf(caption, "About: %s", filter->Name);
				sprintf(buffer, "Description: %s\n\nScale: %d X\n\nDLL: %s", filter->Description, filter->Scale, filter->DLL);
			#endif

			MessageBox::Show(gcnew String(buffer), gcnew String(caption));
		}
	}
	
	private: System::Void AddToOperationsButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (PluginList.Count > 0 && FiltersList->SelectedIndex >= 0 && FiltersList->SelectedIndex < PluginList.Count)
		{
			auto filter = PluginList[FiltersList->SelectedIndex];
			
			FilterProcessList.Add(gcnew FilterPlugin(filter->DLL, filter->Name, filter->Description, filter->ID, filter->ScaleX, filter->ScaleY, filter->Parameters, filter->Threshold));

			OperationsList->Items->Add(gcnew String(filter->Name));
		}
	}
	
	private: System::Void RemoveFromOperationsButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (FilterProcessList.Count > 0 && OperationsList->SelectedIndex >= 0 && OperationsList->SelectedIndex < FilterProcessList.Count)
		{
			auto item = OperationsList->SelectedIndex;

			FilterProcessList.RemoveAt(item);

			OperationsList->Items->RemoveAt(item);

			if (FilterProcessList.Count > 0)
			{
				item = max(0, item - 1);

				OperationsList->SelectedIndex = item;

				UseThresholdMode->Checked = FilterProcessList[item]->Threshold;
			}
			else
			{
				UseThresholdMode->Checked = false;
			}
		}
	}

	private: System::Void OpenImageButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (OpenImageDialog->FileName != nullptr && OpenImageDialog->FileName->Length > 0)
		{
			OpenImageDialog->InitialDirectory = System::IO::Path::GetDirectoryName(OpenImageDialog->FileName);
		}
		
		if (OpenImageDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				Bitmap^ src = gcnew Bitmap(OpenImageDialog->FileName);

				Free(InputBitmap);

				InputBitmap = ConvertTo24bpp(src);

				Free(src);

				RenderBitmap(InputBitmap, InputImage);

				InputImageLabel->Text = gcnew String("Input Image (" + InputBitmap->Width + " x " + InputBitmap->Height + ")");

				if (FilterProcessList.Count > 0)
				{
					ApplyFilters();
				}

				System::GC::Collect();
				System::GC::WaitForPendingFinalizers();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error: Could not read file from disk. Original error: " + ex->Message);
			}
		}
	}

	private: System::Void ApplyFiltersButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ApplyFilters();
	}
	
	void SaveImage(Bitmap ^% bitmap, String^ type)
	{
		if (SaveImageDialog->FileName != nullptr && SaveImageDialog->FileName->Length > 0)
		{
			SaveImageDialog->InitialDirectory = System::IO::Path::GetDirectoryName(SaveImageDialog->FileName);
			SaveImageDialog->FileName = System::IO::Path::GetFileNameWithoutExtension(SaveImageDialog->FileName) + "-" + type;
		}
		else if (OpenImageDialog->FileName != nullptr && OpenImageDialog->FileName->Length > 0)
		{
			SaveImageDialog->InitialDirectory = System::IO::Path::GetDirectoryName(OpenImageDialog->FileName);
			SaveImageDialog->FileName = System::IO::Path::GetFileNameWithoutExtension(OpenImageDialog->FileName) + "-" + type;
		}
		else
		{
			SaveImageDialog->FileName = type;
		}

		if (SaveImageDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (bitmap != nullptr)
			{
				if (SaveImageDialog->FilterIndex == 1)
				{
					bitmap->Save(SaveImageDialog->FileName, System::Drawing::Imaging::ImageFormat::Png);
				}
				else if (SaveImageDialog->FilterIndex == 2)
				{
					bitmap->Save(SaveImageDialog->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
				}
				else if (SaveImageDialog->FilterIndex == 3)
				{
					bitmap->Save(SaveImageDialog->FileName, System::Drawing::Imaging::ImageFormat::Bmp);
				}
				else if (SaveImageDialog->FilterIndex == 4)
				{
					bitmap->Save(SaveImageDialog->FileName, System::Drawing::Imaging::ImageFormat::Tiff);
				}
				else if (SaveImageDialog->FilterIndex == 5)
				{
					bitmap->Save(SaveImageDialog->FileName, System::Drawing::Imaging::ImageFormat::Gif);
				}
				else
				{
					bitmap->Save(SaveImageDialog->FileName, System::Drawing::Imaging::ImageFormat::Png);
				}
			}
		}
	}

	private: void SmartZoom(Bitmap^ bitmap, PictureBox^ pictureBox, int x, int y)
	{
		auto bitmapArea = bitmap->Width * bitmap->Height;
		auto pictureBoxArea = pictureBox->Width * pictureBox->Height;

		if (bitmapArea > pictureBoxArea)
		{
			ResizeZoomWindow();

			ViewSelection(x, y, pictureBox, bitmap);

			auto p = Cursor->Position;

			DisplayZoomWindow(p.Y - (ZoomPictureBox->Height / 2), p.X + 20);
		}
	}

	private: System::Void SaveScaledImageButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SaveImage(ScaledBitmap, "scaled");
	}

	private: System::Void UseThresholdMode_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (OperationsList->SelectedIndex >= 0 && FilterProcessList.Count > 0 && OperationsList->SelectedIndex < FilterProcessList.Count)
		{
			FilterProcessList[OperationsList->SelectedIndex]->Threshold = UseThresholdMode->Checked;
		}
		else
		{
			UseThresholdMode->Checked = false;
		}
	}

	private: System::Void OperationsList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (OperationsList->SelectedIndex >= 0 && FilterProcessList.Count > 0 && OperationsList->SelectedIndex < FilterProcessList.Count)
		{
			UseThresholdMode->Checked = FilterProcessList[OperationsList->SelectedIndex]->Threshold;
		}
	}

	private: System::Void MoveOperationUpButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (OperationsList->SelectedIndex >= 0 && FilterProcessList.Count > 0 && OperationsList->SelectedIndex < FilterProcessList.Count)
		{
			MoveOperationUp(OperationsList->SelectedIndex, OperationsList, FilterProcessList);
		}
	}

	private: System::Void MoveOperationDownButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (OperationsList->SelectedIndex >= 0 && FilterProcessList.Count > 0 && OperationsList->SelectedIndex < FilterProcessList.Count)
		{
			MoveOperationDown(OperationsList->SelectedIndex, OperationsList, FilterProcessList);
		}
	}

	private: System::Void ScaledImage_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		SmartZoom(ScaledBitmap, ScaledImage, e->X, e->Y);
	}

	private: System::Void ScaledImage_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		HideZoomWindow();
	}

	private: System::Void InputImage_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		SmartZoom(InputBitmap, InputImage, e->X, e->Y);
	}

	private: System::Void InputImage_MouseLeave(System::Object^  sender, System::EventArgs^  e)
	{
		HideZoomWindow();
	}

	private: System::Void CrossHairColor_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ColorDialog^ MyDialog = gcnew ColorDialog;
		// Keeps the user from selecting a custom color.
		MyDialog->AllowFullOpen = true;
		// Allows the user to get help. (The default is false.)
		MyDialog->ShowHelp = true;
		// Sets the initial color select to the current text color.
		MyDialog->Color = CrossHairColor->ForeColor;

		// Update the text box color if the user clicks OK 
		if (MyDialog->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
		{
			CrossHairColor->ForeColor = MyDialog->Color;
		}
	}
};
}
