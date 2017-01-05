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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(186, 130);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Numejucator::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(80, 75);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(124, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Numejucator::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::YellowGreen;
			this->label1->Location = System::Drawing::Point(64, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Nume Jucator";
			// 
			// Numejucator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 177);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Numejucator";
			this->Text = L"Numejucator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 msclr::interop::marshal_context context;
				 Nume1 = context.marshal_as<std::string>(textBox1->Text);

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
