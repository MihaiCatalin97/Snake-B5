#pragma once

#include "resource.h"
#include <string>

using namespace std;

struct inregistrare{
	std::string Nume;
	int Scor = 0;
};

inregistrare Scoruri[100];
int dimensiune = 0;
