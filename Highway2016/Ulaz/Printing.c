#include "Printing.h"
#include <time.h>
void printing(char d1,int i,char d2)
{
	time_t now = time(0);
	
	if (file = fopen("potvrde.txt", "a"))
	{
		fprintf(file, "=====   =======   ==========   =========================\n");
		fprintf(file, "SIFRA   DIONICA   KATEGORIJA   VRIJEME ULASKA\n");
		fprintf(file, "=====   =======   ==========   =========================\n\n");
		fprintf(file, "%05d   %7c   %10c   ", i, d1, d2);
		fprintf(file, ctime(&now)); //ubacuje trenutno sistemsko vrijeme i datum
		fprintf(file, "\n=====   =======   ==========   =========================\n\n\n");
	}
}