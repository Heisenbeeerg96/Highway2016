#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
	char password[6], checkpoint[2], daychar[4], month[4]; //password-sifra koju treba naci,checkpoint-dionica
	int sek, min, hh, day, year;
}BILL;

BILL findPassword(char *); //pronalazi sifru potvrde!