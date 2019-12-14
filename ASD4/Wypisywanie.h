#pragma once
#include "BCDstruct.h"
#include "BCD.h"
#include <string>
#include <fstream>

using namespace std;

void porzadekKLP(wezelBST* wezel);
void porzadekLKP(wezelBST* wezel);
void porzadekKLP_Plik(wezelBST* wezel, fstream* plik);
void porzadekKLP_tlumaczenia(wezelBST* wezel);