#include "Printing.h"
#include <time.h>
void printing(char d1,int i)
{
	time_t now = time(0);
	
	if (file = fopen("potvrde.txt", "a"))
	{
		fprintf(file, "=====   =======   =========================\n");
		fprintf(file, "SIFRA   DIONICA   VRIJEME ULASKA\n");
		fprintf(file, "=====   =======   =========================\n\n");
		fprintf(file, "%05d   %7c   ", i, d1);
		fprintf(file, ctime(&now)); //ubacuje trenutno sistemsko vrijeme i datum
		fprintf(file, "\n=====   =======   =========================\n\n\n");
	}
}