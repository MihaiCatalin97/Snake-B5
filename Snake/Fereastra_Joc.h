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
	private: static array<PictureBox^>^ sarpe1;
	private: static array<PictureBox^>^ sarpe2;

			 System::ComponentModel::ComponentResourceManager^  resourcesx;

			 bool crescut = false;
			 bool doubleplayer = false;

			 int game_mode;
			 Timer^ TimerID;
			 int x = 0;
			 int dimensiune_sarpe2 = 2;
			 int directie2 = 0;
			 int dimensiune_sarpe1 = 2;
			 int directie1 = 0;

			 System::Windows::Forms::Label^  label_Nume;
			 System::Windows::Forms::Label^  label_Scor;
			 System::ComponentModel::Container ^components;

	public: Fereastra_Joc(int game_mode)
	{
				if (game_mode>0)
                  doubleplayer = true;

				sarpe1 = (gcnew array<System::Windows::Forms::PictureBox^>(100));
				sarpe2 = (gcnew array<System::Windows::Forms::PictureBox^>(100));

				TimerID = gcnew System::Windows::Forms::Timer();
				TimerID->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer1_Tick);
				TimerID->Interval = 500;
				TimerID->Enabled = true;
				InitializeComponent();
				Creare_Sarpe_Initial();
				if (doubleplayer == true)
					Creare_Sarpe_2();
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
				this->sarpe1[0] = (gcnew System::Windows::Forms::PictureBox());
				this->sarpe1[1] = (gcnew System::Windows::Forms::PictureBox());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe1[0]))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe1[1]))->BeginInit();

				this->sarpe1[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Head.BackgroundImage")));
				this->sarpe1[0]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				this->sarpe1[0]->Location = System::Drawing::Point(100, 125);
				this->sarpe1[0]->Size = System::Drawing::Size(50, 50);

				this->sarpe1[1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
				this->sarpe1[1]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				this->sarpe1[1]->Location = System::Drawing::Point(100, 75);
				this->sarpe1[1]->Size = System::Drawing::Size(50, 50);

				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe1[0]))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe1[1]))->EndInit();

				this->Controls->Add(this->sarpe1[1]);
				this->Controls->Add(this->sarpe1[0]);
			}

			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Fereastra_Joc::typeid));
				resourcesx = resources;






				this->KeyPreview = true;
				this->KeyPress += gcnew KeyPressEventHandler(this, &Fereastra_Joc::Fereastra_Joc_KeyPress);

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
				this->label_Nume->Text = L"Nume: " + gcnew String(Nume.c_str());

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

			void Miscare_Sarpe(array<PictureBox^>^ bucati_sarpe, int dimensiune, int directie)
			{
				//muta toate segmentele inafara capului, 
				//astfel ultimul segment ajunge in locul penultimului si primul in locul capului
				for (int i = dimensiune - 1 - crescut; i > 0; i--)
				{
					bucati_sarpe[i]->Location = bucati_sarpe[i - 1]->Location;
				}
				crescut = false;

				//calculeaza noua pozitie a capului in functie de directie
				Point Next_Location = bucati_sarpe[0]->Location;

				switch (directie)
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

				bucati_sarpe[0]->Location = System::Drawing::Point(Next_Location);

				if (bucati_sarpe == sarpe1 && Verifica_Coliziune(bucati_sarpe, dimensiune, sarpe2, dimensiune_sarpe2))
				{
					End_Game();
					this->Close();
				}
				else if (bucati_sarpe == sarpe2 && Verifica_Coliziune(bucati_sarpe, dimensiune, sarpe1, dimensiune_sarpe1))
				{
					End_Game();
					this->Close();
				}
			}

			bool Verifica_Coliziune(array<PictureBox^>^ bucati_sarpe, int dimensiune, array<PictureBox^>^ bucati_sarpe2, int dimensiune2)
			{

		    	for (int i = 1; i < dimensiune; i++)

			    	if (bucati_sarpe[i]->Location == bucati_sarpe[0]->Location)
				     	return true;



				    if (doubleplayer)
				       for (int i = 0; i < dimensiune2; i++)
				           if (bucati_sarpe[0]->Location == bucati_sarpe2[i]->Location)
					            return true;
 


				return false;

			}

			void Fereastra_Joc::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			{
				if (doubleplayer == true)
					Miscare_Sarpe(sarpe2, dimensiune_sarpe2, directie2);
				Miscare_Sarpe(sarpe1, dimensiune_sarpe1, directie1);

				if (x == 4)
				{
					Crestere_Dimensiune();
					if (doubleplayer == true)
						Crestere_DimensiuneSarpe2();
					x = 0;
				}
				else
					x++;
			}

			void Fereastra_Joc_KeyPress(Object^ sender, KeyPressEventArgs^ e) // se apeleaza la apasare de tasta
			{
				//detecteaza apasarea de taste
				if (e->KeyChar == 'W' || e->KeyChar == 'w')
					directie1 = 1;
				else if (e->KeyChar == 'D' || e->KeyChar == 'd')
					directie1 = 2;
				else if (e->KeyChar == 'A' || e->KeyChar == 'a')
					directie1 = 0;
				else if (e->KeyChar == 'S' || e->KeyChar == 's')
					directie1 = 3;


				if (e->KeyChar == '8')
					directie2 = 1;
				else if (e->KeyChar == '6')
					directie2 = 2;
				else if (e->KeyChar == '4')
					directie2 = 0;
				else if (e->KeyChar == '5')
					directie2 = 3;
			}



			void Crestere_Dimensiune()
			{
				//creare segment nou sarpe
				this->sarpe1[dimensiune_sarpe1] = (gcnew System::Windows::Forms::PictureBox());
				this->sarpe1[dimensiune_sarpe1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
				this->sarpe1[dimensiune_sarpe1]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				this->sarpe1[dimensiune_sarpe1]->Location = this->sarpe1[dimensiune_sarpe1 - 1]->Location;
				this->sarpe1[dimensiune_sarpe1]->Size = System::Drawing::Size(50, 50);
				this->Controls->Add(this->sarpe1[dimensiune_sarpe1]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe1[dimensiune_sarpe1]))->EndInit();

				dimensiune_sarpe1++;
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


	private: System::Void Fereastra_Joc_Load(System::Object^  sender, System::EventArgs^  e) {
	}



			 void Creare_Sarpe_2()
			 {
				 this->sarpe2[0] = (gcnew System::Windows::Forms::PictureBox());
				 this->sarpe2[1] = (gcnew System::Windows::Forms::PictureBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe2[0]))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe2[1]))->BeginInit();

				 this->sarpe2[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Head.BackgroundImage")));
				 this->sarpe2[0]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				 this->sarpe2[0]->Location = System::Drawing::Point(200, 225);
				 this->sarpe2[0]->Size = System::Drawing::Size(50, 50);

				 this->sarpe2[1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
				 this->sarpe2[1]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				 this->sarpe2[1]->Location = System::Drawing::Point(200, 175);
				 this->sarpe2[1]->Size = System::Drawing::Size(50, 50);

				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe2[0]))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe2[1]))->EndInit();

				 this->Controls->Add(this->sarpe2[1]);
				 this->Controls->Add(this->sarpe2[0]);
			 }





			 //calculeaza pozitia daca sarpele a iesit in afara ecranului



			 void Crestere_DimensiuneSarpe2()
			 {
				 //creare segment nou sarpe
				 this->sarpe2[dimensiune_sarpe2] = (gcnew System::Windows::Forms::PictureBox());
				 this->sarpe2[dimensiune_sarpe2]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
				 this->sarpe2[dimensiune_sarpe2]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				 this->sarpe2[dimensiune_sarpe2]->Location = this->sarpe2[dimensiune_sarpe2 - 1]->Location;
				 this->sarpe2[dimensiune_sarpe2]->Size = System::Drawing::Size(50, 50);
				 this->Controls->Add(this->sarpe2[dimensiune_sarpe2]);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sarpe2[dimensiune_sarpe2]))->EndInit();

				 dimensiune_sarpe2++;
				 Scor += 1;
				 this->label_Scor->Text = L"Scor: " + Scor;
				 crescut = true; //cand sarpele a crescut ultimul segment nu se misca (cel nou adaugat)
			 }



	};
}
