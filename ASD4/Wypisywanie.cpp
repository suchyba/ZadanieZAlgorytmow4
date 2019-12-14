#include "BCDstruct.h"
#include "BCD.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void porzadekKLP(wezelBST* wezel)
{
	if(wezel)
		cout << wezel->key <<  endl;
	if(wezel->lewy)
		porzadekKLP(wezel->lewy);
	if(wezel->prawy)
		porzadekKLP(wezel->prawy);
}
void porzadekKLP_tlumaczenia(wezelBST* wezel)
{
	if (wezel)
	{
		cout << wezel->key << "\t\t\t" << wezel->tlumaczenie->key << endl;

		if (wezel->lewy )
			porzadekKLP_tlumaczenia(wezel->lewy);
		if (wezel->prawy)
			porzadekKLP_tlumaczenia(wezel->prawy);
	}
	else
	{
		cout << "Drzewo jest puste!!!" << endl;
		return;
	}
}
void porzadekLKP(wezelBST* wezel)
{
	if (wezel->lewy)
		porzadekLKP(wezel->lewy);
	if (wezel)
		cout << wezel->key << endl;
	if (wezel->prawy)
		porzadekLKP(wezel->prawy);
}
void porzadekKLP_Plik(wezelBST* wezel, fstream* plik)
{
	if (wezel)
		(*plik) << wezel->key << "\t\n";
	if (wezel->lewy)
		porzadekKLP_Plik(wezel->lewy, plik);
	if (wezel->prawy)
		porzadekKLP_Plik(wezel->prawy, plik);
}