#pragma once

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class Fereastra_Joc :public Form
	{

	public:
		Fereastra_Joc(void)
		{
			InitializeComponent();
		}

	protected:
		~Fereastra_Joc()
		{
			if (components)
			{
				delete components;
			}
		}
	private: PictureBox^  pictureBox1;
	private: PictureBox^  pictureBox11;
	private: PictureBox^  pictureBox12;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			ComponentResourceManager^  resources = (gcnew ComponentResourceManager(Fereastra_Joc::typeid));
			this->pictureBox1 = (gcnew PictureBox());
			this->pictureBox11 = (gcnew PictureBox());
			this->pictureBox12 = (gcnew PictureBox());
			(cli::safe_cast<ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<ISupportInitialize^>(this->pictureBox12))->BeginInit();
			this->SuspendLayout();

			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = ImageLayout::Zoom;
			this->pictureBox1->ErrorImage = (cli::safe_cast<Image^>(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->InitialImage = (cli::safe_cast<Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = Point(326, 258);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackgroundImage = (cli::safe_cast<Image^>(resources->GetObject(L"pictureBox11.BackgroundImage")));
			this->pictureBox11->BackgroundImageLayout = ImageLayout::Zoom;
			this->pictureBox11->ErrorImage = (cli::safe_cast<Image^>(resources->GetObject(L"pictureBox11.ErrorImage")));
			this->pictureBox11->InitialImage = (cli::safe_cast<Image^>(resources->GetObject(L"pictureBox11.InitialImage")));
			this->pictureBox11->Location = System::Drawing::Point(270, 258);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(50, 50);
			this->pictureBox11->TabIndex = 10;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.BackgroundImage")));
			this->pictureBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox12->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.ErrorImage")));
			this->pictureBox12->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.InitialImage")));
			this->pictureBox12->Location = System::Drawing::Point(214, 258);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(50, 50);
			this->pictureBox12->TabIndex = 11;
			this->pictureBox12->TabStop = false;
			// 
			// Fereastra_Joc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 553);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Fereastra_Joc";
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = L"Play!";
			(cli::safe_cast<ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<ISupportInitialize^>(this->pictureBox12))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
