#include <Windows.h>
#include "Snake.h"
using namespace std;

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Fereastra_Joc : public System::Windows::Forms::Form
	{
		private: static array<PictureBox^>^ pictures;	
		System::ComponentModel::ComponentResourceManager^  resourcesx;

		bool crescut = false;

		Timer^ TimerID;
		int x=0;
		int dimensiune_sarpe = 2;
		int direction = 0;

		System::Windows::Forms::Label^  label_Nume;
		System::Windows::Forms::Label^  label_Scor;
		System::ComponentModel::Container ^components;

		public: Fereastra_Joc(void)
		{
			pictures = (gcnew array<System::Windows::Forms::PictureBox^>(100));

			TimerID = gcnew System::Windows::Forms::Timer();
			TimerID->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer1_Tick);
			TimerID->Interval = 500;
			TimerID->Enabled = true;
			InitializeComponent();
			Creare_Sarpe_Initial();
		}

		~Fereastra_Joc()
		{
			if (components)
			{
				delete components;
			}
		}

		void Creare_Sarpe_Initial()
		{
			this->pictures[0] = (gcnew System::Windows::Forms::PictureBox());
			this->pictures[1] = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[0]))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[1]))->BeginInit();

			this->pictures[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Head.BackgroundImage")));
			this->pictures[0]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictures[0]->Location = System::Drawing::Point(100, 125);
			this->pictures[0]->Size = System::Drawing::Size(50, 50);

			this->pictures[1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
			this->pictures[1]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictures[1]->Location = System::Drawing::Point(100, 75);
			this->pictures[1]->Size = System::Drawing::Size(50, 50);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[0]))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[1]))->EndInit();

			this->Controls->Add(this->pictures[1]);
			this->Controls->Add(this->pictures[0]);
		}

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Fereastra_Joc::typeid));
			resourcesx = resources;

			this->KeyPreview = true;
			this->KeyPress +=
				gcnew KeyPressEventHandler(this, &Fereastra_Joc::Fereastra_Joc_KeyPress);

			this->label_Nume = (gcnew System::Windows::Forms::Label());
			this->label_Scor = (gcnew System::Windows::Forms::Label());
			
			this->SuspendLayout();
			// 
			// label_Nume
			// 
			this->label_Nume->Location = System::Drawing::Point(25, 25);
			this->label_Nume->Name = L"label_Nume";
			this->label_Nume->Size = System::Drawing::Size(100, 25);
			this->label_Nume->TabIndex = 9;
			this->label_Nume->Text = L"Nume: " + gcnew String((Nume.c_str()));

			this->label_Scor->Location = System::Drawing::Point(400, 25);
			this->label_Scor->Name = L"label_Scor";
			this->label_Scor->Size = System::Drawing::Size(100, 25);
			this->label_Scor->TabIndex = 10;
			this->label_Scor->Text = L"Scor: 0";

			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(500, 575);
			this->Controls->Add(this->label_Scor);
			this->Controls->Add(this->label_Nume);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Fereastra_Joc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Fereastra_Joc";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Fereastra_Joc::Joc_Closing);
			this->ResumeLayout(false);
		}

		void Miscare_Sarpe()
		{
			//muta toate segmentele inafara capului, 
			//astfel ultimul segment ajunge in locul penultimului si primul in locul capului
			for (int i = dimensiune_sarpe - 1 - crescut; i>0; i--)
			{
				pictures[i]->Location = pictures[i - 1]->Location;
			}
			crescut = false;

			//calculeaza noua pozitie a capului in functie de directie
			Point Next_Location = this->pictures[0]->Location;
			
			switch (direction)
			{
				case 0:
				{
						  Next_Location.X -= 50;
						  break;
				}
				case 1:
				{
						  Next_Location.Y -= 50;
						  break;
				}
				case 2:
				{
						  Next_Location.X += 50;
						  break;
				}
				case 3:
				{
						  Next_Location.Y += 50;
						  break;
				}
				default:
					break;
			}

			//calculeaza pozitia daca sarpele a iesit in afara ecranului
			if (Next_Location.X < 0)
				Next_Location.X = 500 + Next_Location.X;
			if (Next_Location.Y < 50)
				Next_Location.Y = 525;
			if (Next_Location.X >= 500)
				Next_Location.X %= 500;
			if (Next_Location.Y >= 575)
				Next_Location.Y = 75;

			this->pictures[0]->Location = System::Drawing::Point(Next_Location);

			if (Verifica_Coliziune())
			{
				End_Game();
				this->Close();
			}
				
		}

		bool Verifica_Coliziune()
		{
			for (int i = 1; i < dimensiune_sarpe;i++)
				if (pictures[i]->Location == pictures[0]->Location)
					return true;
			return false;
		}

		void Fereastra_Joc::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			Miscare_Sarpe();

			if (x == 4)
			{
				Crestere_Dimensiune();
				x = 0;
			}
			else
				x++;
		}

		void Fereastra_Joc_KeyPress(Object^ sender, KeyPressEventArgs^ e) // se apeleaza la apasare de tasta
		{
			//detecteaza apasarea de taste
			if (e->KeyChar == 'W' || e->KeyChar == 'w')
				direction = 1;
			else if (e->KeyChar == 'D' || e->KeyChar == 'd')
				direction = 2;
			else if (e->KeyChar == 'A' || e->KeyChar == 'a')
				direction = 0;
			else if (e->KeyChar == 'S' || e->KeyChar == 's')
				direction = 3;
		}

		void Crestere_Dimensiune()
		{
			//creare segment nou sarpe
			this->pictures[dimensiune_sarpe] = (gcnew System::Windows::Forms::PictureBox());
			this->pictures[dimensiune_sarpe]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
			this->pictures[dimensiune_sarpe]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictures[dimensiune_sarpe]->Location = this->pictures[dimensiune_sarpe-1]->Location;
			this->pictures[dimensiune_sarpe]->Size = System::Drawing::Size(50, 50);
			this->Controls->Add(this->pictures[dimensiune_sarpe]);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictures[dimensiune_sarpe]))->EndInit();

			dimensiune_sarpe++;
			Scor += 1;
			this->label_Scor->Text = L"Scor: " + Scor;
			crescut = true; //cand sarpele a crescut ultimul segment nu se misca (cel nou adaugat)
		}

		System::Void Joc_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		{
			End_Game();
		}

		void End_Game()
		{
			Inserare_Scor();
			TimerID->Enabled = false;
		}
	};
}
