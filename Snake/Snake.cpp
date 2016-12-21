#include "stdafx.h"
#include "Snake.h"
#include "Meniu.h"
#include <fstream>
#include <string.h>
using namespace Snake;
using namespace std;

void inserare();
void sortare();
void citire();

//void AfisareScore();

HINSTANCE Instanta_Curenta;


int Scor;
string Nume;


int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Instanta_Curenta = hInstance;
	citire();
	sortare();
	
	

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Meniu form;
	Application::Run(%form);

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SNAKE)), &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}


void inserare()
{
	ofstream g("Scor.txt", std::ios_base::app | std::ios_base::out);
	g << Nume << " " << Scor << "\n";


}

void citire()
{
	ifstream g("Scor.txt");

	while (!g.eof() && dimensiune<100)
	{
		g >> Scoruri[dimensiune].Nume;
		g >> Scoruri[dimensiune].Scor;
		dimensiune++;
	}

}

void sortare()
{
	int i, j;
	inregistrare aux;
	for (i = 0; i<dimensiune; i++)
	for (j = i + 1; j<dimensiune; j++)
	if (Scoruri[i].Scor<Scoruri[j].Scor)
	{
		aux = Scoruri[i];
		Scoruri[i] = Scoruri[j];
		Scoruri[j] = aux;
	}
}
