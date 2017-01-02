#include "Dionica.h"
#include <string.h>
void initDionica(char* name, char* workBool, char* traficBool,char* limit,DIONICA* d)
{
	strcpy(d->name, name);
	strcpy(d->workBool, workBool);
	strcpy(d->traficBool, traficBool);
	strcpy(d->limit, limit);
}