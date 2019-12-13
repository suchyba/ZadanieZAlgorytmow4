#pragma once
#include <string>

using namespace std;

struct wezelBST
{
	string key;
	wezelBST* lewy = NULL;
	wezelBST* prawy = NULL;
	wezelBST* tlumaczenie = NULL;
};