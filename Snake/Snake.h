#pragma once

#include "resource.h"

#include <string>

using namespace std;

struct inregistrare{
	std::string Nume;
	int Scor = 0;
};

int matrice_ocupare[10][10];
inregistrare Scoruri[100];
int Numar_Scoruri = 0;
int Scor=0;
string Nume="Lonn";

void Inserare_Scor();
void Sortare_Scoruri();
void Citire_Scoruri();