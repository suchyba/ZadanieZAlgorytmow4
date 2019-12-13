#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "BCD.h"
#include "main.h"
#include "BCDstruct.h"
#include "Wypisywanie.h"

using namespace std;


int main()
{
	fstream plikIn, plikOut;
	plikIn.open("In0402.txt");
	plikOut.open("Out0402.txt");

	wezelBST *ang = NULL, *pol = NULL;

	while (!plikIn.eof())
	{
		string ciag;
		plikIn >> ciag;

		if (!ang)
		{
			ang = new wezelBST;
			ang->key = ciag;
		}
		else
		{
			wezelBST* w = new wezelBST();
			w->key = ciag;

			dodaj(ang, w);
		}
	}
	porzadekKLP_Plik(ang, &plikOut);

	plikIn.close();
	plikOut.close();
	return 0;
}

