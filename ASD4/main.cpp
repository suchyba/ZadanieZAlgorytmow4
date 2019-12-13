#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "BCD.h"

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
	}

	plikIn.close();
	plikOut.close();
	return 0;
}

