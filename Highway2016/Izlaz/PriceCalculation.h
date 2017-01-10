#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 50
typedef struct node { int indeks; char *name; }NODE;
typedef struct { int n; float **ms; NODE *array; }GRAF; //ms-matrica susjednosti,n-broj dionica

void floyd(GRAF *, int[][MAX], float[][MAX]);
void path(int, int, GRAF *, int[][MAX]); //pronalazi najkrace rasotanje izmedju dionica
void search(GRAF *, char *, char *, int *, int *); //provjerava da li postoje te dionice
void search_dfs(int, GRAF *, char *, char *, int *, int *, int[MAX]);
void load(FILE *, GRAF *); //ucitavanje
void init(GRAF *, int[][MAX], float[][MAX]); //inicializacija matrica prethodnika T
void loadWorkOnRoads(FILE *, float[][MAX], GRAF *); //ucitavanje radova na putu
void finallprice(char *, char *);