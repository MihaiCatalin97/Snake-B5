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
			array<PictureBox^>^ sarpe1;
			array<PictureBox^>^ sarpe2;
			int Mutare_Urmatoare;

			 System::ComponentModel::ComponentResourceManager^  resourcesx;

			 PictureBox^ Mancare;
			 int game_mode, dimensiune_sarpe2 = 2, directie2 = 0,dimensiune_sarpe1 = 2, directie1 = 0;
			 Timer^ TimerID;

			 System::Windows::Forms::Label^  label_Nume;
			 System::Windows::Forms::Label^  label_Scor;
			 System::ComponentModel::Container ^components;

			 void Gasire_Mutari()
			 {
				 int Destinatie_I = (Mancare->Location.Y - 75) / 50;
				 int Destinatie_J = (Mancare->Location.X) / 50;

				 int i = (sarpe2[0]->Location.Y - 75) / 50;
				 int j = (sarpe2[0]->Location.X) / 50;
				 bool adaugat = false;

					 if (Destinatie_I != i)
					 {
						 if (Destinatie_I - i < (min(i, Destinatie_I) + 10 - max(i, Destinatie_I))*(Destinatie_I<i ? -1 : 1) && matrice_ocupare[j][((i + 1)<10 ? i + 1 : 0)] != 1)
						 {
							 Mutare_Urmatoare = 3;
							 adaugat = true;
							 i++;
						 }

						 else if (Destinatie_I - i >= (min(i, Destinatie_I) + 10 - max(i, Destinatie_I))*(Destinatie_I<i ? -1 : 1) && matrice_ocupare[i][((i - 1) >= 0 ? i - 1 : 9)] != 1)
						 {
							 Mutare_Urmatoare = 1;
							 adaugat = true;
							 i--;
						 }

					 }
					 if (Destinatie_J != j)
					 {
						 if (Destinatie_J - j < (min(j, Destinatie_J) + 10 - max(j, Destinatie_J))*(Destinatie_J<j ? -1 : 1) && matrice_ocupare[((j + 1)<10 ? j + 1 : 0)][i] != 1)
						 {
							 Mutare_Urmatoare = 2;
							 adaugat = true;
							 j++;
						 }

						 else if (Destinatie_J - j >= (min(j, Destinatie_J) + 10 - max(j, Destinatie_J))*(Destinatie_J<j ? -1 : 1) && matrice_ocupare[(j - 1) >= 0 ? j - 1 : 9][i] != 1)
						 {
							 Mutare_Urmatoare = 0;
							 adaugat = true;
							 j--;
						 }

					 }

					 if (!adaugat)
					 {
						 if (Destinatie_I != i)
						 {
							 if (matrice_ocupare[j][((i + 1)<10 ? i + 1 : 0)] != 1)
							 {
								 Mutare_Urmatoare = 3;
								 adaugat = true;
								 i++;
							 }

							 else if (matrice_ocupare[i][((i - 1) >= 0 ? i - 1 : 9)] != 1)
							 {
								 Mutare_Urmatoare = 1;
								 adaugat = true;
								 i--;
							 }

						 }
						 if (Destinatie_J != j)
						 {
							 if (matrice_ocupare[((j + 1)<10 ? j + 1 : 0)][i] != 1)
							 {
								 Mutare_Urmatoare = 2;
								 adaugat = true;
								 j++;
							 }

							 else if (matrice_ocupare[(j - 1) >= 0 ? j - 1 : 9][i] != 1)
							 {
								 Mutare_Urmatoare = 0;
								 adaugat = true;
								 j--;
							 }
						 }
					 }

			 }

			 void Initializare_Custom()
			 {
				 System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Fereastra_Joc::typeid));
				 resourcesx = resources;

				 sarpe1 = (gcnew array<System::Windows::Forms::PictureBox^>(100));
				 Creare_Sarpe(sarpe1);

				 if (game_mode > 0)
				 {
					 sarpe2 = (gcnew array<System::Windows::Forms::PictureBox^>(100));
					 Creare_Sarpe(sarpe2);
				 }
					 
				 for (int i = 0; i<10; i++)
					for (int j = 0; j<10; j++)
						matrice_ocupare[i][j] = 0;

				 TimerID = gcnew System::Windows::Forms::Timer();
				 TimerID->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer1_Tick);
				 TimerID->Interval = 500;
				 TimerID->Enabled = true;

				 InitializeComponent();
				 this->KeyPreview = true;
				 this->KeyPress += gcnew KeyPressEventHandler(this, &Fereastra_Joc::Fereastra_Joc_KeyPress);

				 Mancare = (gcnew System::Windows::Forms::PictureBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(Mancare))->BeginInit();
				 Mancare->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body1.BackgroundImage")));
				 Mancare->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				 Mancare->Size = System::Drawing::Size(50, 50);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(Mancare))->EndInit();

				 this->Controls->Add(Mancare);
				 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Fereastra_Joc::Joc_Closing);

				 plaseaza_Mancare();
			 }

			 void Creare_Sarpe(array<PictureBox^>^ sarpe)
			 {

				 sarpe[0] = (gcnew System::Windows::Forms::PictureBox());
				 sarpe[1] = (gcnew System::Windows::Forms::PictureBox());

				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[0]))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[1]))->BeginInit();

				 sarpe[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Head" + (1+(sarpe==sarpe2)) + ".BackgroundImage")));
				 sarpe[0]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				 sarpe[0]->Size = System::Drawing::Size(50, 50);

				 sarpe[1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body" + (1 + (sarpe == sarpe2)) + ".BackgroundImage")));
				 sarpe[1]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				 sarpe[1]->Size = System::Drawing::Size(50, 50);

				 if (sarpe == sarpe1)
				 {
					 sarpe[0]->Location = System::Drawing::Point(100, 125);
					 sarpe[1]->Location = System::Drawing::Point(100, 75);

					 matrice_ocupare[2][0] = 1;
					 matrice_ocupare[2][1] = 1;
				 }
				 else
				 {
					 sarpe[0]->Location = System::Drawing::Point(350, 125);
					 sarpe[1]->Location = System::Drawing::Point(350, 75);

					 matrice_ocupare[7][0] = 1;
					 matrice_ocupare[7][1] = 1;
				 }
				 

				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[0]))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[1]))->EndInit();

				 this->Controls->Add(sarpe[1]);
				 this->Controls->Add(sarpe[0]);

			 }

			 public: Fereastra_Joc(int game_mode)
			{
				this->game_mode = game_mode;
				Initializare_Custom();
			}

			 void plaseaza_Mancare()
			 {
				 bool ok;
				 int x;
				 int y;
				 Point rez;
				 do
				 {
					 ok = true;
					 x = rand() % 10;
					 y = rand() % 10;
					 rez.X = x * 50;
					 rez.Y = 75 + y * 50;

					 if (matrice_ocupare[x][y] != 0)
						 ok = false;

				 } while (!ok);
				 
				 Mancare->Location = rez;
				 matrice_ocupare[x][y] = 2;
			 }

			~Fereastra_Joc()
			{
				if (components)
				{
					delete components;
				}
			}

			void InitializeComponent(void)
			{
				this->label_Nume = (gcnew System::Windows::Forms::Label());
				this->label_Scor = (gcnew System::Windows::Forms::Label());

				this->SuspendLayout();
				// 
				// label_Nume
				// 
				this->label_Nume->Location = System::Drawing::Point(25, 25);
				this->label_Nume->Name = L"label_Nume";
				this->label_Nume->Size = System::Drawing::Size(400, 25);
				this->label_Nume->TabIndex = 9;


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

				this->ResumeLayout(false);
			}

			void Refresh_Score()
			{
				this->label_Nume->Text = L"Nume: " + gcnew String(Nume.c_str());
				this->label_Scor->Text = L"Scor: " + Scor;
			}

			void Miscare_Sarpe(array<PictureBox^>^ bucati_sarpe, int dimensiune, int directie)
			{
				
				//muta toate segmentele inafara capului, 
				//astfel ultimul segment ajunge in locul penultimului si primul in locul capului
				bool crescut = bucati_sarpe[dimensiune - 1]->Location == bucati_sarpe[dimensiune - 2]->Location;

				if (!crescut)
					matrice_ocupare[bucati_sarpe[dimensiune - 1]->Location.X / 50][(bucati_sarpe[dimensiune - 1]->Location.Y - 75) / 50] = 0;

				for (int i = dimensiune - 1 - crescut; i > 0; i--)
				{
					bucati_sarpe[i]->Location = bucati_sarpe[i - 1]->Location;
				}

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

				if (matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] == 1)
				{
					End_Game();
					//this->Close();
				}

				if (matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] == 2)
				{
					Crestere_Dimensiune(bucati_sarpe, dimensiune);
					Refresh_Score();
					plaseaza_Mancare();
				}

				bucati_sarpe[0]->Location = System::Drawing::Point(Next_Location);
				matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] = 1;
			}

			void Fereastra_Joc::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
			{
				if (game_mode == 2)
				{
					Miscare_Sarpe(sarpe1, dimensiune_sarpe1, directie1);
					Mutare_Computer();
				}
				else
				{
					Miscare_Sarpe(sarpe1, dimensiune_sarpe1, directie1);
					
					if (game_mode==1)
						Miscare_Sarpe(sarpe2, dimensiune_sarpe2, directie2);
				}
			}

			void Mutare_Computer()
			{
				Gasire_Mutari();
				Miscare_Sarpe(sarpe2, dimensiune_sarpe2, Mutare_Urmatoare);
			}

			void Fereastra_Joc_KeyPress(Object^ sender, KeyPressEventArgs^ e) // se apeleaza la apasare de tasta
			{
				//detecteaza apasarea de taste
				if (e->KeyChar == 'W' || e->KeyChar == 'w' && directie1 != 3)
					directie1 = 1;
				else if (e->KeyChar == 'D' || e->KeyChar == 'd' && directie1 != 0)
					directie1 = 2;
				else if (e->KeyChar == 'A' || e->KeyChar == 'a' && directie1 != 2)
					directie1 = 0;
				else if (e->KeyChar == 'S' || e->KeyChar == 's' && directie1 != 1)
					directie1 = 3;

				if (game_mode == 1)
				{
					if (e->KeyChar == '8' && directie2 != 3)
						directie2 = 1;
					else if (e->KeyChar == '6' && directie2 != 0)
						directie2 = 2;
					else if (e->KeyChar == '4' && directie2 != 2)
						directie2 = 0;
					else if (e->KeyChar == '5' && directie2 != 1)
						directie2 = 3;
				}
			}



			void Crestere_Dimensiune(array<PictureBox^>^ sarpe, int dimensiune)
			{
				//creare segment nou sarpe
				sarpe[dimensiune] = (gcnew System::Windows::Forms::PictureBox());
				sarpe[dimensiune]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"Snake_Body" + (1 + (sarpe == sarpe2)) + ".BackgroundImage")));
				sarpe[dimensiune]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				sarpe[dimensiune]->Location = sarpe[dimensiune - 1]->Location;
				sarpe[dimensiune]->Size = System::Drawing::Size(50, 50);
				this->Controls->Add(sarpe[dimensiune]);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[dimensiune]))->EndInit();

				Scor++;
				if (sarpe == sarpe1)
					dimensiune_sarpe1++;
				else if (sarpe == sarpe2)
					dimensiune_sarpe2++;
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
