#pragma once
#include "Snake.h"

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Gameover
	/// </summary>
	public ref class Gameover1 : public System::Windows::Forms::Form
	{

		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Gameover1::typeid));
		int game_mode;
	public:
		Gameover1(int game_mode)
		{
			this->game_mode = game_mode;
			InitializeComponent();
			Setarenumescor();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Gameover1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Titlu_Meniu;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
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

		void Setarenumescor()
		{
			this->label2->Text = L"Nume: " + gcnew String(Nume1.c_str());
			this->label1->Text = L"Scor: " + Scor1;

			this->label3->Text = L"Nume: " + gcnew String(Nume2.c_str());
			this->label4->Text = L"Scor: " + Scor2;
			if (Scor1>Scor2)
			  this->label5->Text = gcnew String(Nume2.c_str()) + L" a pierdut jocul ";
			if (Scor2>Scor1)
				this->label5->Text = gcnew String(Nume1.c_str()) + L" a pierdut jocul ";
			if (Scor1==Scor2)
				this->label5->Text =  L" Joc egal ";

		}

		

		void InitializeComponent(void)
		{
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackgroundImage2")));
			this->Titlu_Meniu = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Titlu_Meniu
			// 
			this->Titlu_Meniu->BackColor = System::Drawing::Color::Transparent;
			this->Titlu_Meniu->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Titlu_Meniu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titlu_Meniu->ForeColor = System::Drawing::Color::YellowGreen;
			this->Titlu_Meniu->Location = System::Drawing::Point(47, 31);
			this->Titlu_Meniu->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Titlu_Meniu->Name = L"Titlu_Meniu";
			this->Titlu_Meniu->Size = System::Drawing::Size(262, 53);
			this->Titlu_Meniu->TabIndex = 1;
			this->Titlu_Meniu->Text = L"Game Over";
			this->Titlu_Meniu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(180, 169);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 53);
			this->label1->TabIndex = 2;
			this->label1->Text = L"scor1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(0, 169);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 53);
			this->label2->TabIndex = 3;
			this->label2->Text = L"nume1";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &Gameover1::label2_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(-9, 222);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 53);
			this->label3->TabIndex = 4;
			this->label3->Text = L"nume2";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Click += gcnew System::EventHandler(this, &Gameover1::label3_Click);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(165, 222);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 53);
			this->label4->TabIndex = 5;
			this->label4->Text = L"scor2";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(33, 93);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(262, 53);
			this->label5->TabIndex = 6;
			this->label5->Text = L"situatiejoc";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Gameover1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			
			this->ClientSize = System::Drawing::Size(347, 333);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Titlu_Meniu);
			this->Name = L"Gameover1";
			this->Text = L"Gameover1";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
