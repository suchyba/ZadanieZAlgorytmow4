#pragma once

#include <string>
#include "BCD.h"
#include "BCDstruct.h"

using namespace std;

wezelBST* szukaj(wezelBST* korzen, string wyraz, wezelBST** poprzednik);
wezelBST* szukaj(wezelBST* korzen, string wyraz);
int usun(wezelBST* korzen, string element);
void dodaj(wezelBST* korzen, wezelBST* element);
wezelBST* znajdzNastepnika(wezelBST* wezel);
wezelBST* usunKorzen(wezelBST* korzenw);
wezelBST* znajdzNajmniejszy(wezelBST* wezel);