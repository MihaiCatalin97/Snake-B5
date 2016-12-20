#pragma once

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Fereastra_Scor
	/// </summary>
	public ref class Fereastra_Scor : public System::Windows::Forms::Form
	{
	public:
		Fereastra_Scor(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Fereastra_Scor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Titlu_Meniu;
	protected:

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
			this->Titlu_Meniu = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Titlu_Meniu
			// 
			this->Titlu_Meniu->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Titlu_Meniu->Font = (gcnew System::Drawing::Font(L"Marker Felt", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titlu_Meniu->ForeColor = System::Drawing::Color::YellowGreen;
			this->Titlu_Meniu->Location = System::Drawing::Point(120, 30);
			this->Titlu_Meniu->Name = L"Titlu_Meniu";
			this->Titlu_Meniu->Size = System::Drawing::Size(130, 65);
			this->Titlu_Meniu->TabIndex = 1;
			this->Titlu_Meniu->Tag = L"";
			this->Titlu_Meniu->Text = L"Scor:";
			this->Titlu_Meniu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Fereastra_Scor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 478);
			this->Controls->Add(this->Titlu_Meniu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Fereastra_Scor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Score";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
