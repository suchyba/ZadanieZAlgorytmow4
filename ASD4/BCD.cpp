#include <iostream>
#include <string>
#include "BCDstruct.h"

using namespace std;



void dodaj(wezelBST* korzen, wezelBST* element);
int usun(wezelBST* korzen, string element);
wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST** poprzednik);
wezelBST* znajdzNastepnika(wezelBST* wezel);
wezelBST* usunKorzen(wezelBST* korzenw);
wezelBST* znajdzNajmniejszy(wezelBST* wezel);



void dodaj(wezelBST* korzen, wezelBST* element)
{
	wezelBST* obecny = korzen;
	wezelBST* poprzedni = korzen;
	int prawaLewa = -1;				// 1 - prawa, 2 - lewa
	bool jednakowe = false;
	while (obecny)
	{
		string dluzszy = element->key.size() > obecny->key.size() ? element->key : obecny->key;
		for (int i = 0; i < dluzszy.size(); ++i)
		{
			if (element->key.size() == obecny->key.size() && i + 1 >= obecny->key.size() && obecny->key[i] == element->key[i])
			{
				jednakowe = true;
				prawaLewa = -1;
				break;
			}
			else if (i >= obecny->key.size() || element->key[i] > obecny->key[i])
			{
				poprzedni = obecny;
				obecny = obecny->prawy;
				prawaLewa = 1;
				break;
			}
			else if (i >= element->key.size() || obecny->key[i] > element->key[i])
			{
				poprzedni = obecny;
				obecny = obecny->lewy;
				prawaLewa = 2;
				break;
			}
		}
		if (jednakowe)
			break;
	}
	if (prawaLewa == 1)
		poprzedni->prawy = element;
	else if (prawaLewa == 2)
		poprzedni->lewy = element;
	/*else
		cout << "BLAD!!! ELEMENTY SA JEDNAKOWE" << endl;*/
}

int usun(wezelBST* korzen, string element)
{
	wezelBST** poprzedniW = new wezelBST*;
	(*poprzedniW) = NULL;
	wezelBST* wyszukany = szukaj(korzen, element, poprzedniW);
	wezelBST* poprzedni = *poprzedniW;
	if (wyszukany == NULL)
		return -1;
	if (!poprzedni)
	{
		//cout << "Nie mozna usunac korzenia!" << endl;
		return -2;
	}

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

		usun(korzen, nastepnik->key);

		if (poprzedni->lewy && poprzedni->lewy->key == wyszukany->key)
			poprzedni->lewy = nastepnik;
		else
			poprzedni->prawy = nastepnik;						

		nastepnik->lewy = wyszukany->lewy;					
		nastepnik->prawy = wyszukany->prawy;				
	}
	else if (wyszukany->prawy != NULL || wyszukany->lewy != NULL)
	{
		if (poprzedni->lewy && poprzedni->lewy->key == wyszukany->key)
			poprzedni->lewy = (wyszukany->prawy != NULL ? wyszukany->prawy : wyszukany->lewy);
		else if(poprzedni ->prawy && poprzedni->prawy->key == wyszukany->key)
			poprzedni->prawy = (wyszukany->prawy != NULL ? wyszukany->prawy : wyszukany->lewy);
	}
	return 0;
}

wezelBST* usunKorzen(wezelBST* korzen)
{
	if (korzen->prawy == NULL && korzen->lewy == NULL)
	{
		return NULL;
	}
	else if (korzen->prawy != NULL && korzen->lewy != NULL)			
	{
		wezelBST* nastepnik = znajdzNastepnika(korzen);

		usun(korzen, nastepnik->key);	
		
		nastepnik->lewy = korzen->lewy;
		nastepnik->prawy = korzen->prawy;
		return nastepnik;
	}
	else if (korzen->prawy != NULL || korzen->lewy != NULL)
	{
		return (korzen->prawy != NULL ? korzen->prawy : korzen->lewy);
	}	   	 
}

wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST** poprzednik)
{
	wezelBST* obecny = korzen;
	wezelBST* poprzedni = NULL;
	bool rozniaSie = false;
	while (obecny)
	{
		rozniaSie = false;
		string dluzszy = wyraz.size() > obecny->key.size() ? wyraz : obecny->key;
		for (int i = 0; i < dluzszy.size(); ++i)
		{
			if (i >= obecny->key.size() || wyraz[i] > obecny->key[i])
			{
				poprzedni = obecny;
				obecny = obecny->prawy;
				rozniaSie = true;
				break;
			}
			else if (i >= wyraz.size() || obecny->key[i] > wyraz[i])
			{
				poprzedni = obecny;
				obecny = obecny->lewy;
				rozniaSie = true;
				break;
			}
		}
		if (!rozniaSie)
		{
			(*poprzednik) = poprzedni;
			return obecny;
		}
	}
	(*poprzednik) = poprzedni;
	return obecny;
}
wezelBST* szukaj(wezelBST* korzen, string wyraz)
{
	wezelBST* obecny = korzen;
	bool rozniaSie = false;
	while (obecny)
	{
		rozniaSie = false;
		string dluzszy = wyraz.size() > obecny->key.size() ? wyraz : obecny->key;
		for (int i = 0; i < dluzszy.size(); ++i)
		{
			if (i >= obecny->key.size() || wyraz[i] > obecny->key[i])
			{
				obecny = obecny->prawy;
				rozniaSie = true;
				break;
			}
			else if (i >= wyraz.size() || obecny->key[i] > wyraz[i])
			{
				obecny = obecny->lewy;
				rozniaSie = true;
				break;
			}
		}
		if (!rozniaSie)
		{
			return obecny;
		}
	}
	return obecny;
}
wezelBST* znajdzNastepnika(wezelBST* wezel)
{
	if (wezel->prawy)
		return znajdzNajmniejszy(wezel->prawy);
	else
		return NULL;
}
wezelBST* znajdzNajmniejszy(wezelBST* wezel)
{
	if (wezel->lewy)
		return znajdzNajmniejszy(wezel->lewy);

	return wezel;	
}