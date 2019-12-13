#pragma once

#include <string>
#include "BCD.h"
#include "BCDstruct.h"

using namespace std;

wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST* poprzednik = NULL);
void usun(wezelBST* korzen, string element);
void dodaj(wezelBST* korzen, wezelBST* element);
wezelBST* znajdzNastepnika(wezelBST* wezel);