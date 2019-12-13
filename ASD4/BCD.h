#pragma once

#include <string>
#include "BCD.h"

using namespace std;

struct wezelBST;

wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST* poprzednik = NULL);
void usun(wezelBST* korzen, string element);
void dodaj(wezelBST* korzen, wezelBST* element);
wezelBST* znajdzNastepnika(wezelBST* wezel);