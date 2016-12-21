#pragma once
#include "Snake.h"
#include <sstream>
#include <string>


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
			AfisareScore();

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
	private: System::Windows::Forms::Label^  nume1;
	private: System::Windows::Forms::Label^  scor1;
	private: System::Windows::Forms::Label^  nume2;
	private: System::Windows::Forms::Label^  scor2;
	private: System::Windows::Forms::Label^  nume9;

	private: System::Windows::Forms::Label^  nume8;

	private: System::Windows::Forms::Label^  nume7;

	private: System::Windows::Forms::Label^  nume6;
	private: System::Windows::Forms::Label^  nume5;
	private: System::Windows::Forms::Label^  nume4;
	private: System::Windows::Forms::Label^  nume3;
	private: System::Windows::Forms::Label^  nume10;
	private: System::Windows::Forms::Label^  scor10;

	private: System::Windows::Forms::Label^  scor9;

	private: System::Windows::Forms::Label^  scor8;

	private: System::Windows::Forms::Label^  scor7;

	private: System::Windows::Forms::Label^  scor6;
	private: System::Windows::Forms::Label^  scor5;
	private: System::Windows::Forms::Label^  scor4;
	private: System::Windows::Forms::Label^  scor3;

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
			this->nume1 = (gcnew System::Windows::Forms::Label());
			this->scor1 = (gcnew System::Windows::Forms::Label());
			this->nume2 = (gcnew System::Windows::Forms::Label());
			this->scor2 = (gcnew System::Windows::Forms::Label());
			this->nume9 = (gcnew System::Windows::Forms::Label());
			this->nume8 = (gcnew System::Windows::Forms::Label());
			this->nume7 = (gcnew System::Windows::Forms::Label());
			this->nume6 = (gcnew System::Windows::Forms::Label());
			this->nume5 = (gcnew System::Windows::Forms::Label());
			this->nume4 = (gcnew System::Windows::Forms::Label());
			this->nume3 = (gcnew System::Windows::Forms::Label());
			this->nume10 = (gcnew System::Windows::Forms::Label());
			this->scor10 = (gcnew System::Windows::Forms::Label());
			this->scor9 = (gcnew System::Windows::Forms::Label());
			this->scor8 = (gcnew System::Windows::Forms::Label());
			this->scor7 = (gcnew System::Windows::Forms::Label());
			this->scor6 = (gcnew System::Windows::Forms::Label());
			this->scor5 = (gcnew System::Windows::Forms::Label());
			this->scor4 = (gcnew System::Windows::Forms::Label());
			this->scor3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Titlu_Meniu
			// 
			this->Titlu_Meniu->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Titlu_Meniu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titlu_Meniu->ForeColor = System::Drawing::Color::YellowGreen;
			this->Titlu_Meniu->Location = System::Drawing::Point(74, 20);
			this->Titlu_Meniu->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Titlu_Meniu->Name = L"Titlu_Meniu";
			this->Titlu_Meniu->Size = System::Drawing::Size(129, 53);
			this->Titlu_Meniu->TabIndex = 1;
			this->Titlu_Meniu->Tag = L"";
			this->Titlu_Meniu->Text = L"Scor:";
			this->Titlu_Meniu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->Titlu_Meniu->Click += gcnew System::EventHandler(this, &Fereastra_Scor::Titlu_Meniu_Click);
			// 
			// nume1
			// 
			this->nume1->AutoSize = true;
			this->nume1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume1->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume1->Location = System::Drawing::Point(28, 84);
			this->nume1->Name = L"nume1";
			this->nume1->Size = System::Drawing::Size(52, 15);
			this->nume1->TabIndex = 2;
			this->nume1->Text = L"1. Nume";
			// 
			// scor1
			// 
			this->scor1->AutoSize = true;
			this->scor1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor1->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor1->Location = System::Drawing::Point(204, 84);
			this->scor1->Name = L"scor1";
			this->scor1->Size = System::Drawing::Size(47, 15);
			this->scor1->TabIndex = 3;
			this->scor1->Text = L"Scor: 1";
			// 
			// nume2
			// 
			this->nume2->AutoSize = true;
			this->nume2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume2->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume2->Location = System::Drawing::Point(28, 110);
			this->nume2->Name = L"nume2";
			this->nume2->Size = System::Drawing::Size(52, 15);
			this->nume2->TabIndex = 4;
			this->nume2->Text = L"2. Nume";
			// 
			// scor2
			// 
			this->scor2->AutoSize = true;
			this->scor2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor2->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor2->Location = System::Drawing::Point(204, 110);
			this->scor2->Name = L"scor2";
			this->scor2->Size = System::Drawing::Size(47, 15);
			this->scor2->TabIndex = 5;
			this->scor2->Text = L"Scor: 2";
			// 
			// nume9
			// 
			this->nume9->AutoSize = true;
			this->nume9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume9->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume9->Location = System::Drawing::Point(28, 295);
			this->nume9->Name = L"nume9";
			this->nume9->Size = System::Drawing::Size(52, 15);
			this->nume9->TabIndex = 6;
			this->nume9->Text = L"9. Nume";
			// 
			// nume8
			// 
			this->nume8->AutoSize = true;
			this->nume8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume8->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume8->Location = System::Drawing::Point(28, 270);
			this->nume8->Name = L"nume8";
			this->nume8->Size = System::Drawing::Size(52, 15);
			this->nume8->TabIndex = 7;
			this->nume8->Text = L"8. Nume";
			// 
			// nume7
			// 
			this->nume7->AutoSize = true;
			this->nume7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume7->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume7->Location = System::Drawing::Point(28, 243);
			this->nume7->Name = L"nume7";
			this->nume7->Size = System::Drawing::Size(52, 15);
			this->nume7->TabIndex = 8;
			this->nume7->Text = L"7. Nume";
			// 
			// nume6
			// 
			this->nume6->AutoSize = true;
			this->nume6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume6->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume6->Location = System::Drawing::Point(28, 216);
			this->nume6->Name = L"nume6";
			this->nume6->Size = System::Drawing::Size(52, 15);
			this->nume6->TabIndex = 9;
			this->nume6->Text = L"6. Nume";
			// 
			// nume5
			// 
			this->nume5->AutoSize = true;
			this->nume5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume5->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume5->Location = System::Drawing::Point(28, 188);
			this->nume5->Name = L"nume5";
			this->nume5->Size = System::Drawing::Size(52, 15);
			this->nume5->TabIndex = 10;
			this->nume5->Text = L"5. Nume";
			// 
			// nume4
			// 
			this->nume4->AutoSize = true;
			this->nume4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume4->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume4->Location = System::Drawing::Point(28, 163);
			this->nume4->Name = L"nume4";
			this->nume4->Size = System::Drawing::Size(52, 15);
			this->nume4->TabIndex = 11;
			this->nume4->Text = L"4. Nume";
			// 
			// nume3
			// 
			this->nume3->AutoSize = true;
			this->nume3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume3->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume3->Location = System::Drawing::Point(28, 136);
			this->nume3->Name = L"nume3";
			this->nume3->Size = System::Drawing::Size(52, 15);
			this->nume3->TabIndex = 12;
			this->nume3->Text = L"3. Nume";
			// 
			// nume10
			// 
			this->nume10->AutoSize = true;
			this->nume10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nume10->ForeColor = System::Drawing::Color::DarkViolet;
			this->nume10->Location = System::Drawing::Point(28, 319);
			this->nume10->Name = L"nume10";
			this->nume10->Size = System::Drawing::Size(59, 15);
			this->nume10->TabIndex = 13;
			this->nume10->Text = L"10. Nume";
			// 
			// scor10
			// 
			this->scor10->AutoSize = true;
			this->scor10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor10->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor10->Location = System::Drawing::Point(204, 319);
			this->scor10->Name = L"scor10";
			this->scor10->Size = System::Drawing::Size(54, 15);
			this->scor10->TabIndex = 14;
			this->scor10->Text = L"Scor: 10";
			// 
			// scor9
			// 
			this->scor9->AutoSize = true;
			this->scor9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor9->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor9->Location = System::Drawing::Point(204, 295);
			this->scor9->Name = L"scor9";
			this->scor9->Size = System::Drawing::Size(47, 15);
			this->scor9->TabIndex = 15;
			this->scor9->Text = L"Scor: 9";
			// 
			// scor8
			// 
			this->scor8->AutoSize = true;
			this->scor8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor8->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor8->Location = System::Drawing::Point(204, 270);
			this->scor8->Name = L"scor8";
			this->scor8->Size = System::Drawing::Size(47, 15);
			this->scor8->TabIndex = 16;
			this->scor8->Text = L"Scor: 8";
			// 
			// scor7
			// 
			this->scor7->AutoSize = true;
			this->scor7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor7->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor7->Location = System::Drawing::Point(204, 243);
			this->scor7->Name = L"scor7";
			this->scor7->Size = System::Drawing::Size(47, 15);
			this->scor7->TabIndex = 17;
			this->scor7->Text = L"Scor: 7";
			// 
			// scor6
			// 
			this->scor6->AutoSize = true;
			this->scor6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor6->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor6->Location = System::Drawing::Point(204, 216);
			this->scor6->Name = L"scor6";
			this->scor6->Size = System::Drawing::Size(47, 15);
			this->scor6->TabIndex = 18;
			this->scor6->Text = L"Scor: 6";
			// 
			// scor5
			// 
			this->scor5->AutoSize = true;
			this->scor5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor5->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor5->Location = System::Drawing::Point(204, 188);
			this->scor5->Name = L"scor5";
			this->scor5->Size = System::Drawing::Size(47, 15);
			this->scor5->TabIndex = 19;
			this->scor5->Text = L"Scor: 5";
			// 
			// scor4
			// 
			this->scor4->AutoSize = true;
			this->scor4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor4->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor4->Location = System::Drawing::Point(204, 163);
			this->scor4->Name = L"scor4";
			this->scor4->Size = System::Drawing::Size(47, 15);
			this->scor4->TabIndex = 20;
			this->scor4->Text = L"Scor: 4";
			// 
			// scor3
			// 
			this->scor3->AutoSize = true;
			this->scor3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor3->ForeColor = System::Drawing::Color::DarkViolet;
			this->scor3->Location = System::Drawing::Point(204, 136);
			this->scor3->Name = L"scor3";
			this->scor3->Size = System::Drawing::Size(47, 15);
			this->scor3->TabIndex = 21;
			this->scor3->Text = L"Scor: 3";
			// 
			// Fereastra_Scor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(286, 373);
			this->Controls->Add(this->scor3);
			this->Controls->Add(this->scor4);
			this->Controls->Add(this->scor5);
			this->Controls->Add(this->scor6);
			this->Controls->Add(this->scor7);
			this->Controls->Add(this->scor8);
			this->Controls->Add(this->scor9);
			this->Controls->Add(this->scor10);
			this->Controls->Add(this->nume10);
			this->Controls->Add(this->nume3);
			this->Controls->Add(this->nume4);
			this->Controls->Add(this->nume5);
			this->Controls->Add(this->nume6);
			this->Controls->Add(this->nume7);
			this->Controls->Add(this->nume8);
			this->Controls->Add(this->nume9);
			this->Controls->Add(this->scor2);
			this->Controls->Add(this->nume2);
			this->Controls->Add(this->scor1);
			this->Controls->Add(this->nume1);
			this->Controls->Add(this->Titlu_Meniu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"Fereastra_Scor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Score: 6";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void AfisareScore()
		{
			this->nume1->Text = gcnew String(Scoruri[0].Nume.c_str());
			this->scor1->Text = gcnew String((std::to_string(Scoruri[0].Scor).c_str()));

			this->nume2->Text = gcnew String(Scoruri[1].Nume.c_str());
			this->scor2->Text = gcnew String((std::to_string(Scoruri[1].Scor).c_str()));

			this->nume3->Text = gcnew String(Scoruri[2].Nume.c_str());
			this->scor3->Text = gcnew String((std::to_string(Scoruri[2].Scor).c_str()));

			this->nume4->Text = gcnew String(Scoruri[3].Nume.c_str());
			this->scor4->Text = gcnew String((std::to_string(Scoruri[3].Scor).c_str()));

			this->nume5->Text = gcnew String(Scoruri[4].Nume.c_str());
			this->scor5->Text = gcnew String((std::to_string(Scoruri[4].Scor).c_str()));

			this->nume6->Text = gcnew String(Scoruri[5].Nume.c_str());
			this->scor6->Text = gcnew String((std::to_string(Scoruri[5].Scor).c_str()));

			this->nume7->Text = gcnew String(Scoruri[6].Nume.c_str());
			this->scor7->Text = gcnew String((std::to_string(Scoruri[6].Scor).c_str()));

			this->nume8->Text = gcnew String(Scoruri[7].Nume.c_str());
			this->scor8->Text = gcnew String((std::to_string(Scoruri[7].Scor).c_str()));

			this->nume9->Text = gcnew String(Scoruri[8].Nume.c_str());
			this->scor9->Text = gcnew String((std::to_string(Scoruri[8].Scor).c_str()));

			this->nume10->Text = gcnew String(Scoruri[9].Nume.c_str());
			this->scor10->Text = gcnew String((std::to_string(Scoruri[9].Scor).c_str()));
		}
	
  

private: System::Void Titlu_Meniu_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
  