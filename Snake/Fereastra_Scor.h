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

	public ref class Fereastra_Scor : public System::Windows::Forms::Form
	{
		System::ComponentModel::Container ^components;
		array<Label^>^ Label_Nume;
		array<Label^>^ Label_Scoruri;
		private: System::Windows::Forms::Label^  Titlu_Meniu;
	
		public: Fereastra_Scor(void)
		{
			Label_Scoruri = gcnew array<Label^>(10);
			
			Label_Nume = gcnew array<Label^>(10);
			InitializeComponent();
			for (int i = 0; i < Label_Scoruri->Length; i++)
			{
				Creare_Nume(i);
				Creare_Scor(i);
			}
			AfisareScore();
		}

		protected:~Fereastra_Scor()
		{
			if (components)
			{
				delete components;
			}
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Fereastra_Scor::typeid));
			this->Titlu_Meniu = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Titlu_Meniu
			// 
			this->Titlu_Meniu->BackColor = System::Drawing::Color::Transparent;
			this->Titlu_Meniu->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Titlu_Meniu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titlu_Meniu->ForeColor = System::Drawing::Color::YellowGreen;
			this->Titlu_Meniu->Location = System::Drawing::Point(74, 20);
			this->Titlu_Meniu->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Titlu_Meniu->Name = L"Titlu_Meniu";
			this->Titlu_Meniu->Size = System::Drawing::Size(129, 53);
			this->Titlu_Meniu->TabIndex = 0;
			this->Titlu_Meniu->Text = L"Scor:";
			this->Titlu_Meniu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Fereastra_Scor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(286, 373);
			this->Controls->Add(this->Titlu_Meniu);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"Fereastra_Scor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);

		}

		void Creare_Scor(int nr)
		{
			this->Label_Scoruri[nr] = (gcnew System::Windows::Forms::Label());

			this->Label_Scoruri[nr]->AutoSize = true;
			this->Label_Scoruri[nr]->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Scoruri[nr]->ForeColor = System::Drawing::Color::MidnightBlue;
			this->Label_Scoruri[nr]->Location = System::Drawing::Point(225, 85 + 25*nr);
			this->Label_Scoruri[nr]->Size = System::Drawing::Size(50, 20);
			this->Label_Scoruri[nr]->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->Label_Scoruri[nr]);
		}

		void Creare_Nume(int nr)
		{
			
			this->Label_Nume[nr] = (gcnew System::Windows::Forms::Label());

			this->Label_Nume[nr]->AutoSize = true;
			this->Label_Nume[nr]->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label_Nume[nr]->ForeColor = System::Drawing::Color::MidnightBlue;
			this->Label_Nume[nr]->Location = System::Drawing::Point(25, 85 + 25 * nr);
			this->Label_Nume[nr]->Size = System::Drawing::Size(50, 20);
			this->Label_Nume[nr]->BackColor = System::Drawing::Color::Transparent;

			this->Controls->Add(this->Label_Nume[nr]);
		}

		void AfisareScore()
		{
			for (int i = 0; i < Label_Nume->Length; i++)
			{
				if (Scoruri[i].Scor != 0)
				{
					this->Label_Nume[i]->Text = (i+1) + ". " + gcnew String(Scoruri[i].Nume.c_str());
					this->Label_Scoruri[i]->Text = gcnew String((std::to_string(Scoruri[i].Scor).c_str()));
				}
				else
				{
					this->Label_Nume[i]->Text = (i+1) + ". ---";
				}
			}
		}
};
}
  