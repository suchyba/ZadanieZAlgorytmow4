#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct wezelBST
{
	string key;
	wezelBST* lewy;
	wezelBST* prawy;
	wezelBST* tlumaczenie;
};

wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST* poprzednik = NULL);
void usun(wezelBST* korzen, string element);
void dodaj(wezelBST* korzen, wezelBST *element);
wezelBST* znajdzNastepnika(wezelBST* wezel);

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
	}

	plikIn.close();
	plikOut.close();
	return 0;
}

void dodaj(wezelBST* korzen, wezelBST* element)
{
	wezelBST* obecny = korzen;
	wezelBST* poprzedni = korzen;
	int prawaLewa = -1;				// 1 - prawa, 2 - lewa
	while (obecny)
	{
		string dluzszy = element->key.size() > obecny -> key.size() ? element->key : obecny -> key;
		for (int i = 0; i < dluzszy.size(); ++i)
		{
			if (i >= element->key.size() || element->key[i] > obecny->key[i])
			{
				poprzedni = obecny;
				obecny = obecny->prawy;
				prawaLewa = 1;
				break;
			}
			else if(i >= obecny->key.size() || obecny->key[i] > element->key[i])
			{
				poprzedni = obecny;
				obecny = obecny->lewy;
				prawaLewa = 2;
				break;
			}
		}
	}
	if (prawaLewa == 1)
		poprzedni->prawy = element;
	else if (prawaLewa == 2)
		poprzedni->lewy = element;
	else
		cout << "BLAD!!! ELEMENTY SA JEDNAKOWE" << endl;
}
void usun(wezelBST* korzen, string element)
{
	wezelBST* poprzedni = NULL;
	wezelBST* wyszukany = szukaj(korzen, element, poprzedni);
	if (wyszukany == NULL)
		return;

	if (wyszukany->prawy == NULL && wyszukany->lewy == NULL)
	{
		if (poprzedni->lewy == wyszukany)
			poprzedni->lewy = NULL;
		else
			poprzedni->prawy = NULL;
	}
	else if (wyszukany->prawy != NULL && wyszukany->lewy != NULL)
	{
		wezelBST* nastepnik = znajdzNastepnika(wyszukany);
		if (nastepnik->prawy != NULL)
		{
			wezelBST* prawy = nastepnik->prawy;
			usun(korzen, nastepnik->key);
		}
	}
	else if (wyszukany->prawy != NULL || wyszukany->lewy != NULL)
	{
		if (poprzedni->lewy->key == wyszukany->key)
			poprzedni->lewy = wyszukany->prawy != NULL ? wyszukany->prawy : wyszukany->lewy;
		else
			poprzedni->prawy = wyszukany->prawy != NULL ? wyszukany->prawy : wyszukany->lewy;
	}
}
wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST* poprzednik = NULL)
{
	wezelBST* obecny = korzen;
	wezelBST* poprzedni = korzen;
	bool rozniaSie = false;
	while (obecny)
	{
		string dluzszy = wyraz.size() > obecny->key.size() ? wyraz : obecny->key;
		for (int i = 0; i < dluzszy.size(); ++i)
		{
			if (i >= wyraz.size()|| wyraz[i] > obecny->key[i])
			{
				poprzedni = obecny;
				obecny = obecny->prawy;
				rozniaSie = true;
				break;
			}
			else if (i >= obecny->key.size() || obecny->key[i] > wyraz[i])
			{
				poprzedni = obecny;
				obecny = obecny->lewy;
				rozniaSie = true;
				break;
			}
		}
		if (!rozniaSie)
		{
			poprzednik = poprzedni;
			return obecny;
		}
	}
	poprzednik = poprzedni;
	return obecny;
}

wezelBST* znajdzNastepnika(wezelBST* wezel)
{
	if (wezel->lewy != NULL)
		return znajdzNastepnika(wezel->lewy);

	return wezel;

	if (wezel->prawy != NULL)
		return znajdzNastepnika(wezel->prawy);
}

