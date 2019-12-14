#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "BCD.h"
#include "main.h"
#include "BCDstruct.h"
#include "Wypisywanie.h"
#include "Menu.h"
#include <conio.h>
using namespace std;


int main()
{
	fstream plikIn, plikOut;

	wezelBST* ang = NULL, * pol = NULL;

	bool koniec = false;

	while (!koniec)
	{
		switch (mainMenu())
		{
			case 0:						// ustawianie stanow poczatkowych
			{
				switch (menuStart())
				{
					case 0:				// wypelnianie pliku angielskimu slowkami
					{
						plikIn.open("In0402.txt");
						plikOut.open("Out0402.txt");

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

						cout << "\nTeraz uzupelnij plik Out0402.txt o polskie tluamczenia." << endl;
						cout << "Nacisnij dowolny klawisz by kontynuowac..." << endl;
						_getch();

						plikIn.close();
						plikOut.close();
						break;
					}
					case 1:						// wczytywanie obu slownikow
					{
						plikIn.open("Out0402.txt");

						while (!plikIn.eof())
						{
							string angielskie, polskie;
							plikIn >> angielskie >> polskie;

							wezelBST* wang = new wezelBST();
							wezelBST* wpol = new wezelBST();

							wang->key = angielskie;
							wpol->key = polskie;
							wang->tlumaczenie = wpol;
							wpol->tlumaczenie = wang;

							if (!ang)
							{
								ang = wang;
							}
							else
							{
								dodaj(ang, wang);
							}

							if (!pol)
							{
								pol = wpol;
							}
							else
							{
								dodaj(pol, wpol);
							}
						}

						cout << "\nWczytano!" << endl;
						cout << "Nacisnij dowolny klawisz by kontynuowac..." << endl;
						_getch();

						plikIn.close();
						break;
					}
					case -1:
					{
						break;
					}
				}

				
				break;
			}
			case 1:					//wyswietlanie w porzadku KLP
			{
				switch (menuWypisywanie())
				{
					case 0:
					{
						system("cls");
						cout << "\t\tSlownik angielsko-polski w porzadku KLP" << endl;
						cout << "\t#######################################################" << endl;
						porzadekKLP_tlumaczenia(ang);
						break;
					}
					case 1:
					{
						system("cls");
						cout << "\t\tSlownik polsko-angielski w porzadku KLP" << endl;
						cout << "\t#######################################################" << endl;
						porzadekKLP_tlumaczenia(pol);
						break;
					}
					case -1:
					{
						break;
					}
				}
				
				cout << "\nNacisnij dowolny klawisz by kontynuowac..." << endl;
				_getch();
				break;
			}
			case 2:					// wyszukiwanie w s³owniku
			{
				string szukane;
				switch (menuZnajdzSlowo(&szukane))
				{
					case -1:
					{
						break;
					}
					case 0:
					{
						// polskie
						wezelBST* slowo = szukaj(pol, szukane);
						if (slowo)
						{
							cout << "\nZnaleziono slowo: " << szukane << endl;
							cout << "Jego tlumaczenie to: " << slowo->tlumaczenie->key << endl;
						}
						else
						{
							cout << "Nie ma takiego slowa w slowniku" << endl;
						}
						break;
					}
					case 1:
					{
						// angielskie
						wezelBST* slowo = szukaj(ang, szukane);
						if (slowo)
						{
							cout << "\nZnaleziono slowo: " << szukane << endl;
							cout << "Jego tlumaczenie to: " << slowo->tlumaczenie->key << endl;
						}
						else
						{
							cout << "Nie ma takiego slowa w slowniku" << endl;
						}
						break;
					}
				}
				cout << "\nNacisnij dowolny klawisz by kontynuowac..." << endl;
				_getch();
				break;
			}
			case 3:				// Dodawanie slowa do slownika
			{
				string angielskie, polskie;
				cout << "\t\tDodawanie slowa do slownika" << endl;
				cout << "\t############################################" << endl;
				cout << "Podaj angielskie slowo: ";
				cin >> angielskie;
				cout << "Podaj polskie slowo: ";
				cin >> polskie;

				wezelBST* wang = new wezelBST();
				wezelBST* wpol = new wezelBST();

				wang->key = angielskie;
				wpol->key = polskie;
				wang->tlumaczenie = wpol;
				wpol->tlumaczenie = wang;

				if (!ang)
				{
					ang = wang;
				}
				else
				{
					dodaj(ang, wang);
				}

				if (!pol)
				{
					pol = wpol;
				}
				else
				{
					dodaj(pol, wpol);
				}

				break;
			}
			case 4:				// Usuwanie slowa ze slownika
			{
				string angielskie;
				
				int jezyk = menuUsun(&angielskie);
				
				switch (jezyk)
				{
					case 1:													// angielskie		
					{
						wezelBST* znalezione = szukaj(ang, angielskie);
						if (!znalezione)
						{
							cout << "Podane slowo nie istnieje!!!" << endl;
						}
						else
						{
							wezelBST* znalezioneTlum = znalezione->tlumaczenie;

							int tmpAng = usun(ang, angielskie);
							if (tmpAng == -1)
								cout << "Podane slowo nie istnieje!!!" << endl;
							else if (tmpAng == -2)
							{
								wezelBST* cpy = ang;
								ang = usunKorzen(cpy);
							}

							int tmpPol = usun(pol, znalezioneTlum->key);
							if (tmpPol == -1)
								cout << "Podane slowo nie istnieje!!!" << endl;
							else if (tmpPol == -2)
							{
								wezelBST* cpy = pol;
								pol = usunKorzen(cpy);
							}
						}
						break;
					}
					case 0:											//	polskie
					{
						wezelBST* znalezione = szukaj(pol, angielskie);
						if (!znalezione)
						{
							cout << "Podane slowo nie istnieje!!!" << endl;
						}
						else
						{
							wezelBST* znalezioneTlum = znalezione->tlumaczenie;

							int tmpPol = usun(pol, angielskie);
							if (tmpPol == -1)
								cout << "Podane slowo nie istnieje!!!" << endl;
							else if (tmpPol == -2)
							{
								wezelBST* cpy = pol;
								pol = usunKorzen(cpy);
							}

							int tmpAng = usun(ang, znalezioneTlum->key);
							if (tmpAng == -1)
								cout << "Podane slowo nie istnieje!!!" << endl;
							else if (tmpAng == -2)
							{
								wezelBST* cpy = ang;
								ang = usunKorzen(cpy);
							}
						}
						break;
					}
				}

				
				cout << "\nNacisnij dowolny klawisz by kontynuowac..." << endl;
				_getch();
				break;
			}
			case -1:
			{
				koniec = true;
				break;
			}
		}
	}


	return 0;
}

