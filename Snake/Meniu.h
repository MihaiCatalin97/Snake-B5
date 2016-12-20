#pragma once

#include "Fereastra_Joc.h"
#include "Fereastra_Scor.h"

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Meniu : public System::Windows::Forms::Form
	{
	public:
		Meniu(void)
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
		~Meniu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Titlu_Meniu;
	private: System::Windows::Forms::Button^  button_singleplayer;
	private: System::Windows::Forms::Button^  button_double_player;
	private: System::Windows::Forms::Button^  button_scor;
	private: System::Windows::Forms::Button^  button_exit;







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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Meniu::typeid));
			this->Titlu_Meniu = (gcnew System::Windows::Forms::Label());
			this->button_singleplayer = (gcnew System::Windows::Forms::Button());
			this->button_double_player = (gcnew System::Windows::Forms::Button());
			this->button_scor = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Titlu_Meniu
			// 
			this->Titlu_Meniu->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Titlu_Meniu->AutoSize = true;
			this->Titlu_Meniu->Font = (gcnew System::Drawing::Font(L"Komika Axis", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Titlu_Meniu->ForeColor = System::Drawing::Color::YellowGreen;
			this->Titlu_Meniu->Location = System::Drawing::Point(87, 18);
			this->Titlu_Meniu->Name = L"Titlu_Meniu";
			this->Titlu_Meniu->Size = System::Drawing::Size(224, 82);
			this->Titlu_Meniu->TabIndex = 0;
			this->Titlu_Meniu->Tag = L"";
			this->Titlu_Meniu->Text = L"Snake!";
			this->Titlu_Meniu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_singleplayer
			// 
			this->button_singleplayer->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_singleplayer.BackgroundImage")));
			this->button_singleplayer->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_singleplayer->CausesValidation = false;
			this->button_singleplayer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_singleplayer->Font = (gcnew System::Drawing::Font(L"Marker Felt", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_singleplayer->ForeColor = System::Drawing::Color::White;
			this->button_singleplayer->Location = System::Drawing::Point(115, 141);
			this->button_singleplayer->Margin = System::Windows::Forms::Padding(0);
			this->button_singleplayer->Name = L"button_singleplayer";
			this->button_singleplayer->Size = System::Drawing::Size(160, 50);
			this->button_singleplayer->TabIndex = 1;
			this->button_singleplayer->Text = L"Single Player";
			this->button_singleplayer->UseVisualStyleBackColor = false;
			this->button_singleplayer->Click += gcnew System::EventHandler(this, &Meniu::button_singleplayer_Click);
			// 
			// button_double_player
			// 
			this->button_double_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_double_player.BackgroundImage")));
			this->button_double_player->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_double_player->CausesValidation = false;
			this->button_double_player->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_double_player->Font = (gcnew System::Drawing::Font(L"Marker Felt", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_double_player->ForeColor = System::Drawing::Color::White;
			this->button_double_player->Location = System::Drawing::Point(115, 210);
			this->button_double_player->Name = L"button_double_player";
			this->button_double_player->Size = System::Drawing::Size(160, 50);
			this->button_double_player->TabIndex = 2;
			this->button_double_player->Text = L"Double Player";
			this->button_double_player->UseVisualStyleBackColor = true;
			this->button_double_player->Click += gcnew System::EventHandler(this, &Meniu::button_double_player_Click);
			// 
			// button_scor
			// 
			this->button_scor->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_scor.BackgroundImage")));
			this->button_scor->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_scor->CausesValidation = false;
			this->button_scor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_scor->Font = (gcnew System::Drawing::Font(L"Marker Felt", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_scor->ForeColor = System::Drawing::Color::White;
			this->button_scor->Location = System::Drawing::Point(115, 279);
			this->button_scor->Name = L"button_scor";
			this->button_scor->Size = System::Drawing::Size(160, 50);
			this->button_scor->TabIndex = 3;
			this->button_scor->Text = L"Scor";
			this->button_scor->UseVisualStyleBackColor = true;
			this->button_scor->Click += gcnew System::EventHandler(this, &Meniu::button_scor_Click);
			// 
			// button_exit
			// 
			this->button_exit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_exit.BackgroundImage")));
			this->button_exit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button_exit->CausesValidation = false;
			this->button_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Marker Felt", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_exit->ForeColor = System::Drawing::Color::White;
			this->button_exit->Location = System::Drawing::Point(115, 346);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(160, 50);
			this->button_exit->TabIndex = 4;
			this->button_exit->Text = L"Exit";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Meniu::button_exit_Click);
			// 
			// Meniu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 478);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_scor);
			this->Controls->Add(this->button_double_player);
			this->Controls->Add(this->button_singleplayer);
			this->Controls->Add(this->Titlu_Meniu);
			this->ForeColor = System::Drawing::Color::Gold;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Meniu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Main Menu";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Meniu::Meniu_Closing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_singleplayer_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Fereastra_Joc form;
		form.ShowDialog();
	}

	private: System::Void button_double_player_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Fereastra_Joc form;
		form.ShowDialog();
	}
	private: System::Void button_scor_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Fereastra_Scor form;
		form.ShowDialog();
	}
	private: System::Void button_exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Application::Exit();
	}

	System::Void Meniu_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		Application::Exit();
	}
};
}
