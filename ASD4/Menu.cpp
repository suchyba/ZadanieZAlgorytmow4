#include <iostream>
#include <conio.h>

using namespace std;

int mainMenu()
{
	int wybranaOpcja = 0;
	int klawisz = -1;
	while (true)
	{
		system("cls");
		cout << "\t\tProgram do obslugi slownika realizowanego drzewem BST" << endl;
		cout << "\t######################################################################" << endl;
		cout << "[" << (wybranaOpcja == 0 ? 'X' : ' ') << "] Start" << endl;
		cout << "[" << (wybranaOpcja == 1 ? 'X' : ' ') << "] Wypisz slownik (w KLP)" << endl;
		cout << "[" << (wybranaOpcja == 2 ? 'X' : ' ') << "] Znajdz slowo" << endl;
		cout << "[" << (wybranaOpcja == 3 ? 'X' : ' ') << "] Dodaj slowo" << endl;
		cout << "[" << (wybranaOpcja == 4 ? 'X' : ' ') << "] Usun slowo" << endl;

		klawisz = _getch();

		switch (klawisz)
		{
			case 80:		// dol
			{
				if (++wybranaOpcja > 4)
					wybranaOpcja = 0;
				break;
			}
			case 72:		// gora
			{
				if (--wybranaOpcja < 0)
					wybranaOpcja = 4;
				break;
			}
			case 13:		// enter
			{
				return wybranaOpcja;
				break;
			}
			case 27:		// esc
			{
				return -1;
				break;
			}
		}
	}
}
int menuZnajdzSlowo(string *szukane)
{
	int wybranaOpcja = 0;
	int klawisz = 0;
	while (true)
	{
		system("cls");
		cout << "\t\tZnajdz slowo" << endl;
		cout << "\t############################" << endl;
		cout << "[" << (wybranaOpcja == 0 ? 'X' : ' ') <<"] Polskie" << endl;
		cout <<"[" << (wybranaOpcja == 1 ? 'X' : ' ') << "] Angielskie" << endl;

		klawisz = _getch();

		switch (klawisz)
		{
			case 80:		// dol
			{
				if (++wybranaOpcja > 1)
					wybranaOpcja = 0;
				break;
			}
			case 72:		// gora
			{
				if (--wybranaOpcja < 0)
					wybranaOpcja = 1;
				break;
			}
			case 13:		// enter
			{
				cout << "Podaj slowo ktorego szukasz: ";

				cin >> (*szukane);

				return wybranaOpcja;
				break;
			}
			case 27:		// esc
			{
				return -1;
				break;
			}
		}
	}
}
int menuStart()
{
	int wybranaOpcja = 0;
	int klawisz = 0;
	while (true)
	{
		system("cls");
		cout << "\t\tInicjalizacja danych" << endl;
		cout << "\t###################################" << endl;
		cout << "[" << (wybranaOpcja == 0 ? 'X' : ' ') << "] Tylko angielskie slowa z tekstu" << endl;
		cout << "[" << (wybranaOpcja == 1 ? 'X' : ' ') << "] Angielskie slowa z tlumaczeniem" << endl;
		klawisz = _getch();

		switch (klawisz)
		{
			case 80:		// dol
			{
				if (++wybranaOpcja > 1)
					wybranaOpcja = 0;
				break;
			}
			case 72:		// gora
			{
				if (--wybranaOpcja < 0)
					wybranaOpcja = 1;
				break;
			}
			case 13:		// enter
			{
				return wybranaOpcja;
				break;
			}
			case 27:		// esc
			{
				return -1;
				break;
			}
		}
	}
}
int menuWypisywanie()
{
	int wybranaOpcja = 0;
	int klawisz = 0;
	while (true)
	{
		system("cls");
		cout << "\t\tWypisywanie slownika" << endl;
		cout << "\t####################################" << endl;
		cout << "[" << (wybranaOpcja == 0 ? 'X' : ' ') << "] Angielsko-polski" << endl;
		cout << "[" << (wybranaOpcja == 1 ? 'X' : ' ') << "] Polsko-angielski" << endl;
		klawisz = _getch();

		switch (klawisz)
		{
			case 80:		// dol
			{
				if (++wybranaOpcja > 1)
					wybranaOpcja = 0;
				break;
			}
			case 72:		// gora
			{
				if (--wybranaOpcja < 0)
					wybranaOpcja = 1;
				break;
			}
			case 13:		// enter
			{
				return wybranaOpcja;
				break;
			}
			case 27:		// esc
			{
				return -1;
				break;
			}
		}
	}
}
int menuUsun(string* szukane)
{
	int wybranaOpcja = 0;
	int klawisz = 0;
	while (true)
	{
		system("cls");
		cout << "\t\tUsuwanie slowa" << endl;
		cout << "\t##############################" << endl;
		cout << "[" << (wybranaOpcja == 0 ? 'X' : ' ') << "] Polskie" << endl;
		cout << "[" << (wybranaOpcja == 1 ? 'X' : ' ') << "] Angielskie" << endl;

		klawisz = _getch();

		switch (klawisz)
		{
			case 80:		// dol
			{
				if (++wybranaOpcja > 1)
					wybranaOpcja = 0;
				break;
			}
			case 72:		// gora
			{
				if (--wybranaOpcja < 0)
					wybranaOpcja = 1;
				break;
			}
			case 13:		// enter
			{
				cout << "Podaj slowo ktore chcesz usunac: ";
	
				cin >> (*szukane);
	
				return wybranaOpcja;
				break;
			}
			case 27:		// esc
			{
				return -1;
				break;
			}
		}
	}
}