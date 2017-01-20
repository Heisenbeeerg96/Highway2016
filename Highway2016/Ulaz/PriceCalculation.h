#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "PasswordFinder.h"
#define MAX 50
typedef struct node { int indeks; char *name; }NODE;
typedef struct { int n; float **ms; NODE *array; }GRAF; //ms-matrica susjednosti,n-broj dionica
typedef struct { int speed; float factor,workOnRoad, availability; }ROADDATA;
typedef struct { char category[2]; int price; } VehicleCatPrice; // Sluzi za cucitavanje cjene kategorije vozila!

void floyd(GRAF *, int[][MAX], float[][MAX]);
void path(int, int, GRAF *, int[][MAX]); //pronalazi najkrace rasotanje izmedju dionica
void search(GRAF *, char *, char *, int *, int *); //provjerava da li postoje te dionice
void search_dfs(int, GRAF *, char *, char *, int *, int *, int[MAX]);
void load(FILE *, GRAF *); //ucitavanje
void init(GRAF *, int[][MAX], ROADDATA[][MAX]); //inicializacija matrica prethodnika T
void loadWorkOnRoads(FILE *, ROADDATA[][MAX], GRAF *); //ucitavanje radova na putu
int loadVehicleCatPrice(FILE *, char *);
void finallprice(BILL *, char *);