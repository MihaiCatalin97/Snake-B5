#pragma once

#include "resource.h"

#include <string>

using namespace std;

struct inregistrare{
	std::string Nume;
	int Scor = 0;
};

int matrice_ocupare[10][10];
int bonusuri_plasate[4], dimensiune_sarpe2 = 2, dimensiune_sarpe1=2;
inregistrare Scoruri[100];
int Numar_Scoruri = 0;
int Scor1=0, Scor2=0;
string Nume1="Lonn", Nume2="Bianca";

void Inserare_Scor(int x);
void Sortare_Scoruri();
void Citire_Scoruri();