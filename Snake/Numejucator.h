#pragma once
#include <msclr\marshal_cppstd.h>

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Numejucator
	/// </summary>
	public ref class Numejucator : public System::Windows::Forms::Form
	{
		int game_mode;
	public:
		Numejucator(int game_mode)
		{

			this->game_mode = game_mode;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Numejucator()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  next;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Numejucator::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->next = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(107, 92);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(164, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Numejucator::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Marker Felt", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(91, 40);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 48);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nume Jucator";
			// 
			// next
			// 
			this->next->BackColor = System::Drawing::Color::Transparent;
			this->next->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->next->ForeColor = System::Drawing::Color::Black;
			this->next->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"next.Image")));
			this->next->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->next->Location = System::Drawing::Point(188, 140);
			this->next->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(188, 66);
			this->next->TabIndex = 6;
			this->next->Text = L"Continua";
			this->next->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->next->Click += gcnew System::EventHandler(this, &Numejucator::next_Click);
			// 
			// Numejucator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(379, 218);
			this->Controls->Add(this->next);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Numejucator";
			this->Text = L"Numejucator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {
				 msclr::interop::marshal_context context;
				 Nume1 = context.marshal_as<std::string>(textBox1->Text);
				 if (textBox1->Text->Length == 0)
					 Nume1 = "Player1";
				 if (game_mode == 0)
				 {
					 this->Visible = false;
					 Fereastra_Joc^ form = gcnew Fereastra_Joc(0);
					 form->ShowDialog();
					 this->Close();

				 }

				 if (game_mode == 2)
				 {
					 this->Visible = false;
					 Fereastra_Joc^ form = gcnew Fereastra_Joc(2);
					 form->ShowDialog();
					 this->Close();

				 }
	}
};
}
