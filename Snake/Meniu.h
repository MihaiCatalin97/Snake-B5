#pragma once

#include "Fereastra_Joc.h"
#include "Fereastra_Scor.h"
#include "Numejucator.h"
#include "Numejucatori.h"



namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class Meniu : public System::Windows::Forms::Form
	{
	public:
		Meniu(void)
		{
			InitializeComponent();
		}

	protected:
		~Meniu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Titlu_Meniu;
	private: System::Windows::Forms::Label^  singleplayer;
	private: System::Windows::Forms::Label^  exit;
	private: System::Windows::Forms::Label^  doubleplayer;
	private: System::Windows::Forms::Label^  versuscomputer;
	private: System::Windows::Forms::Label^  scor;






		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Meniu::typeid));
			this->Titlu_Meniu = (gcnew System::Windows::Forms::Label());
			this->singleplayer = (gcnew System::Windows::Forms::Label());
			this->exit = (gcnew System::Windows::Forms::Label());
			this->doubleplayer = (gcnew System::Windows::Forms::Label());
			this->versuscomputer = (gcnew System::Windows::Forms::Label());
			this->scor = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Titlu_Meniu
			// 
			this->Titlu_Meniu->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Titlu_Meniu->AutoSize = true;
			this->Titlu_Meniu->BackColor = System::Drawing::Color::Transparent;
			this->Titlu_Meniu->Font = (gcnew System::Drawing::Font(L"Komika Axis", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titlu_Meniu->ForeColor = System::Drawing::Color::YellowGreen;
			this->Titlu_Meniu->Location = System::Drawing::Point(63, 28);
			this->Titlu_Meniu->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Titlu_Meniu->Name = L"Titlu_Meniu";
			this->Titlu_Meniu->Size = System::Drawing::Size(182, 67);
			this->Titlu_Meniu->TabIndex = 0;
			this->Titlu_Meniu->Tag = L"";
			this->Titlu_Meniu->Text = L"Snake!";
			this->Titlu_Meniu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// singleplayer
			// 
			this->singleplayer->BackColor = System::Drawing::Color::Transparent;
			this->singleplayer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->singleplayer->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->singleplayer->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->singleplayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"singleplayer.Image")));
			this->singleplayer->Location = System::Drawing::Point(83, 127);
			this->singleplayer->Name = L"singleplayer";
			this->singleplayer->Size = System::Drawing::Size(151, 41);
			this->singleplayer->TabIndex = 5;
			this->singleplayer->Text = L"Single Player";
			this->singleplayer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->singleplayer->Click += gcnew System::EventHandler(this, &Meniu::singleplayer_Click);
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::Transparent;
			this->exit->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit.Image")));
			this->exit->Location = System::Drawing::Point(82, 359);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(151, 41);
			this->exit->TabIndex = 6;
			this->exit->Text = L"Exit";
			this->exit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->exit->Click += gcnew System::EventHandler(this, &Meniu::exit_Click);
			// 
			// doubleplayer
			// 
			this->doubleplayer->BackColor = System::Drawing::Color::Transparent;
			this->doubleplayer->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->doubleplayer->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->doubleplayer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"doubleplayer.Image")));
			this->doubleplayer->Location = System::Drawing::Point(83, 185);
			this->doubleplayer->Name = L"doubleplayer";
			this->doubleplayer->Size = System::Drawing::Size(151, 41);
			this->doubleplayer->TabIndex = 7;
			this->doubleplayer->Text = L"Double Player";
			this->doubleplayer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->doubleplayer->Click += gcnew System::EventHandler(this, &Meniu::doubleplayer_Click);
			// 
			// versuscomputer
			// 
			this->versuscomputer->BackColor = System::Drawing::Color::Transparent;
			this->versuscomputer->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->versuscomputer->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->versuscomputer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"versuscomputer.Image")));
			this->versuscomputer->Location = System::Drawing::Point(83, 245);
			this->versuscomputer->Name = L"versuscomputer";
			this->versuscomputer->Size = System::Drawing::Size(151, 41);
			this->versuscomputer->TabIndex = 8;
			this->versuscomputer->Text = L"Versus Computer";
			this->versuscomputer->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->versuscomputer->Click += gcnew System::EventHandler(this, &Meniu::versuscomputer_Click);
			// 
			// scor
			// 
			this->scor->BackColor = System::Drawing::Color::Transparent;
			this->scor->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scor->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->scor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"scor.Image")));
			this->scor->Location = System::Drawing::Point(82, 301);
			this->scor->Name = L"scor";
			this->scor->Size = System::Drawing::Size(151, 41);
			this->scor->TabIndex = 9;
			this->scor->Text = L"Scor";
			this->scor->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->scor->Click += gcnew System::EventHandler(this, &Meniu::scor_Click);
			// 
			// Meniu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(300, 447);
			this->Controls->Add(this->scor);
			this->Controls->Add(this->versuscomputer);
			this->Controls->Add(this->doubleplayer);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->singleplayer);
			this->Controls->Add(this->Titlu_Meniu);
			this->ForeColor = System::Drawing::Color::Gold;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"Meniu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Main Menu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Meniu::Meniu_Closing);
			this->Load += gcnew System::EventHandler(this, &Meniu::Meniu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	System::Void Meniu_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		Application::Exit();
	}
private: System::Void Meniu_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void singleplayer_Click(System::Object^  sender, System::EventArgs^  e) {
			 Numejucator^ form = gcnew Numejucator(0);
			 form->ShowDialog();
}
private: System::Void doubleplayer_Click(System::Object^  sender, System::EventArgs^  e) {
			 Numejucatori form;
			 form.ShowDialog();

}
private: System::Void versuscomputer_Click(System::Object^  sender, System::EventArgs^  e) {
			 Numejucator^ form = gcnew Numejucator(2);
			 form->ShowDialog();

}
private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
}
private: System::Void scor_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < 100; i++)
				 Scoruri[i].Scor = 0;
			 Numar_Scoruri = 0;

			 Citire_Scoruri();
			 Sortare_Scoruri();
			 Fereastra_Scor form;
			 form.ShowDialog();

}
};
}
