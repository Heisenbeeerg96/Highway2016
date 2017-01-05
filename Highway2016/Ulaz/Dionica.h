#pragma once
#define _CRT_SECURE_NO_WARNINGS
typedef struct dionica { char name[10];char workBool[3]; char traficBool[3]; char limit[5]; }DIONICA;
void initDionica(char*, char*, char*,char*,DIONICA*);
