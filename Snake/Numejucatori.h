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
	/// Summary for Numejucatori
	/// </summary>
	public ref class Numejucatori : public System::Windows::Forms::Form
	{
	public:
		Numejucatori(void)
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
		~Numejucatori()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Numejucatori::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->next = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(96, 76);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(96, 166);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(157, 22);
			this->textBox2->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Marker Felt", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(51, 121);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 42);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nume Jucator 2";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Marker Felt", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label2->Location = System::Drawing::Point(51, 26);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(252, 47);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nume Jucator 1";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// next
			// 
			this->next->BackColor = System::Drawing::Color::Transparent;
			this->next->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->next->ForeColor = System::Drawing::Color::Black;
			this->next->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"next.Image")));
			this->next->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->next->Location = System::Drawing::Point(175, 206);
			this->next->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(188, 66);
			this->next->TabIndex = 5;
			this->next->Text = L"Continua";
			this->next->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->next->Click += gcnew System::EventHandler(this, &Numejucatori::label3_Click);
			// 
			// Numejucatori
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(379, 294);
			this->Controls->Add(this->next);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Numejucatori";
			this->Text = L"Numejucatori";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 msclr::interop::marshal_context context;
			 Nume1 = context.marshal_as<std::string>(textBox1->Text);
			 if (textBox1->Text->Length == 0)
				 Nume1 = "Player1";
			 Nume2 = context.marshal_as<std::string>(textBox2->Text);
			 if (textBox2->Text->Length == 0)
				 Nume2 = "Player2";
			 this->Visible = false;
			 Fereastra_Joc^ form = gcnew Fereastra_Joc(1);
			 form->ShowDialog();
			 this->Close();
}
};
}
