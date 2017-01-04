#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
typedef struct person { char name[20];char surname[20]; char JMBG[20]; DATE birth; }PERSON;
void initPerson(PERSON*);