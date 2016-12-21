#include "stdafx.h"
#include "Snake.h"
#include "Meniu.h"
#include <fstream>
#include <string.h>

using namespace Snake;
using namespace std;

HINSTANCE Instanta_Curenta;

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Instanta_Curenta = hInstance;
	
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


void Inserare_Scor()
{
	ofstream g("Scor.txt", std::ios_base::app | std::ios_base::out);
	g << Nume << " " << Scor << "\n";
}

void Citire_Scoruri()
{
	ifstream g("Scor.txt");

	while (!g.eof() && Numar_Scoruri<100)
	{
		g >> Scoruri[Numar_Scoruri].Nume;
		g >> Scoruri[Numar_Scoruri].Scor;
		Numar_Scoruri++;
	}

}

void Sortare_Scoruri()
{
	int i, j;
	inregistrare aux;
	for (i = 0; i<Numar_Scoruri; i++)
		for (j = i + 1; j<Numar_Scoruri; j++)
			if (Scoruri[i].Scor<Scoruri[j].Scor)
			{
				aux = Scoruri[i];
				Scoruri[i] = Scoruri[j];
				Scoruri[j] = aux;
			}
}
