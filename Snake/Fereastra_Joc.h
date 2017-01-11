#include <Windows.h>
#include "Snake.h"
#include "Gameover1.h"
#include "Gameover2.h"
#include <msclr\marshal_cppstd.h>
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
		array<PictureBox^>^ bonusuri;
		array<int>^ Ordine_Sarpe1;
		array<int>^ Ordine_Sarpe2;
		int Mutare_Urmatoare;

		System::ComponentModel::ComponentResourceManager^  resourcesx;

		PictureBox^ Mancare;
		int game_mode, directie2 = 0, directie1 = 0, ultima_directie1 = 0, ultima_directie2 = 0;
		Timer^ Timer_Sarpe1;
		Timer^ Timer_Sarpe2;
		Timer^ Timer_Bonusuri;
		Timer^ Timer_Speed_Bonus;

		System::Windows::Forms::Label^  label_Nume;
		System::Windows::Forms::Label^  label_Scor;
		System::ComponentModel::Container ^components;

		void Consume_Bonus(int x, array<PictureBox^>^ sarpe)
		{
			if (x == 0)
			{
				if (sarpe == sarpe1)
					Scor1 = Scor1*(game_mode > 0 ? 2 : 1.5) + 1;
				else
					Scor2 = Scor2*(game_mode > 0 ? 2 : 1.5) + 1;

				Refresh_Score();
			}
			else if (x == 1)
			{
				if (sarpe == sarpe1)
				{
					Scor1++;
					Timer_Sarpe1->Interval = 250;
				}
				else
				{
					Scor2++;
					Timer_Sarpe2->Interval = 250;
				}

				Refresh_Score();
				Timer_Speed_Bonus->Enabled = false;
				Timer_Speed_Bonus->Enabled = true;
			}
			else if (x == 2)
			{
				if (sarpe == sarpe1)
				{
					Timer_Sarpe1->Interval = 1000;
				}
				else
				{
					Timer_Sarpe2->Interval = 1000;
				}


				Timer_Speed_Bonus->Enabled = false;
				Timer_Speed_Bonus->Enabled = true;
			}
			else if (x == 3)
			{
				if (sarpe == sarpe1)
					Scor1 = Scor1 / 2;
				else
					Scor2 = Scor2 / 2;

				Refresh_Score();
			}
		}

		void Gasire_Mutari()
		{
			int Destinatie_I = (Mancare->Location.Y - 75) / 50;
			int Destinatie_J = (Mancare->Location.X) / 50;

			int i = (sarpe2[0]->Location.Y - 75) / 50;
			int j = (sarpe2[0]->Location.X) / 50;
			bool adaugat = false;
			Mutare_Urmatoare = -1;

			if (Destinatie_I != i)
			{
				if (Destinatie_I - i < (min(i, Destinatie_I) + 10 - max(i, Destinatie_I))*(Destinatie_I < i ? -1 : 1) && matrice_ocupare[j][((i + 1) < 10 ? i + 1 : 0)] != 1)
				{
					Mutare_Urmatoare = 3;
					adaugat = true;
				}

				else if (Destinatie_I - i >= (min(i, Destinatie_I) + 10 - max(i, Destinatie_I))*(Destinatie_I < i ? -1 : 1) && matrice_ocupare[j][((i - 1) >= 0 ? i - 1 : 9)] != 1)
				{
					Mutare_Urmatoare = 1;
					adaugat = true;
				}
			}

			if (Destinatie_J != j && !adaugat)
			{
				if (Destinatie_J - j < (min(j, Destinatie_J) + 10 - max(j, Destinatie_J))*(Destinatie_J < j ? -1 : 1) && matrice_ocupare[((j + 1) < 10 ? j + 1 : 0)][i] != 1)
				{
					Mutare_Urmatoare = 2;
					adaugat = true;
				}

				else if (Destinatie_J - j >= (min(j, Destinatie_J) + 10 - max(j, Destinatie_J))*(Destinatie_J < j ? -1 : 1) && matrice_ocupare[(j - 1) >= 0 ? j - 1 : 9][i] != 1)
				{
					Mutare_Urmatoare = 0;
					adaugat = true;
				}
			}

			if (!adaugat)
			{
				if (Destinatie_I != i)
				{
					if (matrice_ocupare[j][((i + 1) < 10 ? i + 1 : 0)] != 1)
					{
						Mutare_Urmatoare = 3;
						adaugat = true;
					}
					else if (matrice_ocupare[j][((i - 1) >= 0 ? i - 1 : 9)] != 1)
					{
						Mutare_Urmatoare = 1;
						adaugat = true;
					}

				}
				if (Destinatie_J != j && !adaugat)
				{
					if (matrice_ocupare[((j + 1) < 10 ? j + 1 : 0)][i] != 1)
					{
						Mutare_Urmatoare = 2;
						adaugat = true;
					}

					else if (matrice_ocupare[(j - 1) >= 0 ? j - 1 : 9][i] != 1)
					{
						Mutare_Urmatoare = 0;
						adaugat = true;
					}
				}
			}
		}

		void Initializare_Custom()
		{
			Scor1 = 0;
			Scor2 = 0;
			dimensiune_sarpe1 = dimensiune_sarpe2 = 2;

			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Fereastra_Joc::typeid));
			resourcesx = resources;

			sarpe1 = (gcnew array<System::Windows::Forms::PictureBox^>(100));
			bonusuri = (gcnew array<System::Windows::Forms::PictureBox^>(4));
			Ordine_Sarpe1 = gcnew array<int>(100);
			Ordine_Sarpe1[0] = 1;
			Creare_Sarpe(sarpe1);

			if (game_mode > 0)
			{
				sarpe2 = (gcnew array<System::Windows::Forms::PictureBox^>(100));
				Ordine_Sarpe2 = gcnew array<int>(100);
				Ordine_Sarpe2[0] = 1;
				Creare_Sarpe(sarpe2);
			}

			if (game_mode == 2)
				Nume2 = "Optimus Prime";

			for (int i = 0; i < 10; i++)
			for (int j = 0; j<10; j++)
				matrice_ocupare[i][j] = 0;

			Timer_Sarpe1 = gcnew System::Windows::Forms::Timer();
			Timer_Sarpe1->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer1_Tick);
			Timer_Sarpe1->Interval = 500;
			Timer_Sarpe1->Enabled = true;

			if (game_mode>0)
			{
				Timer_Sarpe2 = gcnew System::Windows::Forms::Timer();
				Timer_Sarpe2->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer2_Tick);
				Timer_Sarpe2->Interval = 500;
				Timer_Sarpe2->Enabled = true;
			}

			Timer_Bonusuri = gcnew System::Windows::Forms::Timer();
			Timer_Bonusuri->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer_bonusuri_Tick);
			Timer_Bonusuri->Interval = 5000;
			Timer_Bonusuri->Enabled = true;

			Timer_Speed_Bonus = gcnew System::Windows::Forms::Timer();
			Timer_Speed_Bonus->Tick += gcnew System::EventHandler(this, &Fereastra_Joc::timer_speed_Tick);
			Timer_Speed_Bonus->Interval = 3100;
			Timer_Speed_Bonus->Enabled = false;

			InitializeComponent();
			this->KeyPreview = true;
			this->KeyPress += gcnew KeyPressEventHandler(this, &Fereastra_Joc::Fereastra_Joc_KeyPress);

			Mancare = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(Mancare))->BeginInit();
			Mancare->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"apple")));
			Mancare->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			Mancare->Size = System::Drawing::Size(50, 50);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(Mancare))->EndInit();

			for (int i = 0; i < bonusuri->Length; i++)
			{
				bonusuri[i] = (gcnew System::Windows::Forms::PictureBox());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(bonusuri[i]))->BeginInit();
				bonusuri[i]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
				bonusuri[i]->Size = System::Drawing::Size(50, 50);
				bonusuri[i]->Visible = false;
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(bonusuri[i]))->EndInit();
				this->Controls->Add(bonusuri[i]);
			}

			bonusuri[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"double_score")));
			bonusuri[1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"bonus_speed")));
			bonusuri[2]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"slow")));
			bonusuri[3]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"half_Score")));

			bonusuri_plasate[0] = 0;
			bonusuri_plasate[1] = 0;
			bonusuri_plasate[2] = 0;
			bonusuri_plasate[3] = 0;

			this->Controls->Add(Mancare);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Fereastra_Joc::Joc_Closing);

			Refresh_Score();
			plaseaza_Mancare();
		}

		void Creare_Sarpe(array<PictureBox^>^ sarpe)
		{

			sarpe[0] = (gcnew System::Windows::Forms::PictureBox());
			sarpe[1] = (gcnew System::Windows::Forms::PictureBox());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[0]))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[1]))->BeginInit();

			sarpe[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (sarpe==sarpe2)) + "head3")));
			sarpe[0]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			sarpe[0]->Size = System::Drawing::Size(50, 50);

			sarpe[1]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (sarpe==sarpe2)) + "tail1")));
			sarpe[1]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
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
				Mancare->Location = getRandomPoint(2);
			}

		Point getRandomPoint(int type)
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
				matrice_ocupare[x][y] = type;

				return rez;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Fereastra_Joc::typeid));
			this->label_Nume = (gcnew System::Windows::Forms::Label());
			this->label_Scor = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label_Nume
			// 
			this->label_Nume->BackColor = System::Drawing::Color::Transparent;
			this->label_Nume->Location = System::Drawing::Point(25, 25);
			this->label_Nume->Name = L"label_Nume";
			this->label_Nume->Size = System::Drawing::Size(400, 25);
			this->label_Nume->TabIndex = 9;
			// 
			// label_Scor
			// 
			this->label_Scor->BackColor = System::Drawing::Color::Transparent;
			this->label_Scor->Location = System::Drawing::Point(400, 25);
			this->label_Scor->Name = L"label_Scor";
			this->label_Scor->Size = System::Drawing::Size(100, 25);
			this->label_Scor->TabIndex = 10;
			this->label_Scor->Text = L"Scor: 0";
			// 
			// Fereastra_Joc
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
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
				this->label_Nume->Text = L"Nume: " + gcnew String(Nume1.c_str());
				this->label_Scor->Text = L"Scor: " + Scor1;

				if (game_mode > 0)
				{
					this->label_Nume->Text += "\n" + L"Nume: " + gcnew String(Nume2.c_str());
					this->label_Scor->Text += "\n" + L"Scor: " + Scor2;
				}
			}

		void Miscare_Sarpe(array<PictureBox^>^ bucati_sarpe, int* dimensiune, int directie, array<int>^ ordine, int ultima_directie, int* scor)
			{
				bool crescut = (*dimensiune) > 2 && bucati_sarpe[ordine[(*dimensiune) - 2]]->Location == bucati_sarpe[ordine[(*dimensiune) - 3]]->Location;

				if (!crescut)
					matrice_ocupare[bucati_sarpe[ordine[(*dimensiune) - 2]]->Location.X / 50][(bucati_sarpe[ordine[*dimensiune - 2]]->Location.Y - 75) / 50] = 0;

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

				bool ok = true;

				if (matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] == 1)
				{
					ok = false;
					End_Game();
					this->Close();
				}
				else if (matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] != 0)
				{
					if (matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] == 2)
					{
						Crestere_Dimensiune(bucati_sarpe, dimensiune,ordine, scor);
						Refresh_Score();
						plaseaza_Mancare();
					}
					else
					{
						int bonus_number = matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] - 3;
						Consume_Bonus(bonus_number, bucati_sarpe);
						bonusuri[bonus_number]->Visible = false;
						bonusuri_plasate[bonus_number] = 0;
					}
				}

				if (ok)
				{	
					//modificare a pozitiei ultimului element si modificarea vectorului de ordine a segmentelor
					bucati_sarpe[ordine[*dimensiune - 2]]->Location = bucati_sarpe[0]->Location;
					int aux = ordine[*dimensiune - 2];
					for (int i = *dimensiune - 2; i >= 1; i--)
					{
						ordine[i] = ordine[i - 1];
					}
					ordine[0] = aux;

					bucati_sarpe[0]->Location = Next_Location;
					matrice_ocupare[Next_Location.X / 50][(Next_Location.Y - 75) / 50] = 1;

					//schimbare imagini sarpe
					Point Locatie_Precedent_Cap = bucati_sarpe[ordine[1]]->Location;

					if (*dimensiune > 2)
					{
						if (Next_Location.X == Locatie_Precedent_Cap.X)
							bucati_sarpe[ordine[0]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe==sarpe2)) + "straight2")));
						else if (Next_Location.Y == Locatie_Precedent_Cap.Y)
							bucati_sarpe[ordine[0]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "straight1")));
						else if ((ultima_directie == 0 && directie == 3) || (ultima_directie == 1 && directie == 2))
							bucati_sarpe[ordine[0]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "curved2")));
						else if ((ultima_directie == 0 && directie == 1) || (ultima_directie == 3 && directie == 2))
							bucati_sarpe[ordine[0]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "curved1")));
						else if ((ultima_directie == 2 && directie == 1) || (ultima_directie == 3 && directie == 0))
							bucati_sarpe[ordine[0]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "curved0")));
						else if ((ultima_directie == 1 && directie == 0) || (ultima_directie == 2 && directie == 3))
							bucati_sarpe[ordine[0]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "curved3")));

					}

					Point Locatie_Coada = bucati_sarpe[ordine[*dimensiune - 2]]->Location;
					Point Locatie_Segment_Precedent;

					if (*dimensiune > 2)
						Locatie_Segment_Precedent = bucati_sarpe[ordine[*dimensiune - 3]]->Location;
					else
						Locatie_Segment_Precedent = bucati_sarpe[0]->Location;

					if (Locatie_Coada.X == Locatie_Segment_Precedent.X)
					{
						if ((Locatie_Coada.Y < Locatie_Segment_Precedent.Y || (Locatie_Coada.Y == 525 && Locatie_Segment_Precedent.Y == 75)) && !(Locatie_Coada.Y == 75 && Locatie_Segment_Precedent.Y == 525))
							bucati_sarpe[ordine[*dimensiune - 2]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "tail1")));
						else
							bucati_sarpe[ordine[*dimensiune - 2]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "tail3")));
					}
					else
					{
						if ((Locatie_Coada.X < Locatie_Segment_Precedent.X || (Locatie_Coada.X == 450 && Locatie_Segment_Precedent.X == 0)) && !(Locatie_Coada.X == 0 && Locatie_Segment_Precedent.X == 450))
							bucati_sarpe[ordine[*dimensiune - 2]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "tail0")));
						else
							bucati_sarpe[ordine[*dimensiune - 2]]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "tail2")));
					}

					bucati_sarpe[0]->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resourcesx->GetObject(L"snake" + (1 + (bucati_sarpe == sarpe2)) + "head" + directie)));
				}
			}

	void Fereastra_Joc::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Miscare_Sarpe(sarpe1, &dimensiune_sarpe1, directie1, Ordine_Sarpe1, ultima_directie1, &Scor1);
		ultima_directie1 = directie1;
	}

	void Fereastra_Joc::timer2_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (game_mode == 2)
		{
			Mutare_Computer();
		}
		else if (game_mode == 1)
		{
			Miscare_Sarpe(sarpe2, &dimensiune_sarpe2, directie2, Ordine_Sarpe2, ultima_directie2, &Scor2);
			ultima_directie2 = directie2;
		}
	}

	void Fereastra_Joc::timer_bonusuri_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		bool bonus_plasat = false;
		int i;
		for (i = 0; i < bonusuri->Length && !bonus_plasat; i++)
		if (bonusuri_plasate[i] == 1)
			bonus_plasat = true;

		if (!bonus_plasat)
		{
			int numar_Bonus = rand() % (bonusuri->Length);
			bonusuri_plasate[numar_Bonus] = 1;
			bonusuri[numar_Bonus]->Location = getRandomPoint(3 + numar_Bonus);
			bonusuri[numar_Bonus]->Visible = true;
		}
		else
		{
			bonusuri_plasate[i - 1] = 0;
			bonusuri[i - 1]->Visible = false;
			matrice_ocupare[bonusuri[i - 1]->Location.X / 50][(bonusuri[i - 1]->Location.Y - 75) / 50] = 0;
		}
	}

	void Fereastra_Joc::timer_speed_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		Timer_Sarpe1->Interval = 500;

		if (game_mode>0)
			Timer_Sarpe2->Interval = 500;

		Timer_Speed_Bonus->Enabled = false;
	}

	void Mutare_Computer()
	{
		Gasire_Mutari();
		Miscare_Sarpe(sarpe2, &dimensiune_sarpe2, Mutare_Urmatoare, Ordine_Sarpe2, ultima_directie2, &Scor2);
		ultima_directie2 = Mutare_Urmatoare;
	}

	void Fereastra_Joc_KeyPress(Object^ sender, KeyPressEventArgs^ e) // se apeleaza la apasare de tasta
	{
		//detecteaza apasarea de taste
		if (e->KeyChar == 'W' || e->KeyChar == 'w' && ultima_directie1 != 3)
			directie1 = 1;
		else if (e->KeyChar == 'D' || e->KeyChar == 'd' && ultima_directie1 != 0)
			directie1 = 2;
		else if (e->KeyChar == 'A' || e->KeyChar == 'a' && ultima_directie1 != 2)
			directie1 = 0;
		else if (e->KeyChar == 'S' || e->KeyChar == 's' && ultima_directie1 != 1)
			directie1 = 3;

		if (game_mode == 1)
		{
			if (e->KeyChar == '8' && ultima_directie2 != 3)
				directie2 = 1;
			else if (e->KeyChar == '6' && ultima_directie2 != 0)
				directie2 = 2;
			else if (e->KeyChar == '4' && ultima_directie2 != 2)
				directie2 = 0;
			else if (e->KeyChar == '5' && ultima_directie2 != 1)
				directie2 = 3;
		}
	}

	void Crestere_Dimensiune(array<PictureBox^>^ sarpe, int* dimensiune, array<int>^ ordine, int* scor)
	{
		//creare segment nou sarpe
		sarpe[*dimensiune] = (gcnew System::Windows::Forms::PictureBox());
		sarpe[*dimensiune]->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		sarpe[*dimensiune]->Location = sarpe[ordine[(*dimensiune) - 2]]->Location;
		sarpe[*dimensiune]->Size = System::Drawing::Size(50, 50);
		this->Controls->Add(sarpe[*dimensiune]);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(sarpe[*dimensiune]))->EndInit();

		ordine[(*dimensiune) - 1] = *dimensiune;
		(*dimensiune)++;
		(*scor) += (game_mode>0)+1;
	}

	System::Void Joc_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		if (Timer_Sarpe1->Enabled)
		{
			End_Game();
		}
	}

	void End_Game()
	{
		Inserare_Scor(1);

		if (game_mode == 1)
			Inserare_Scor(2);

		Timer_Sarpe1->Enabled = false;
		Timer_Speed_Bonus->Enabled = false;
		Timer_Bonusuri->Enabled = false;
		this->Visible = false;

		if (game_mode>0)
			Timer_Sarpe2->Enabled = false;

		if (game_mode == 0 || game_mode == 2)
		{
			Gameover2 form;
			form.ShowDialog();
		}

		if (game_mode == 1)
		{
			Gameover1^ form = gcnew Gameover1(1);
			form->ShowDialog();
		}
	}
};
}

