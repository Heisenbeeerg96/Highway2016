#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "PasswordFinder.h"
#include "PriceCalculation.h"
void speedTicket(BILL *, char *); //za pisanje kazne
void pathforTicket(int, int, GRAF *, int[][MAX], int *, int[MAX]);//pronalazi proizvod brzina puta koeficijent
