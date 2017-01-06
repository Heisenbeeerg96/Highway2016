#include "Printing.h"
#include <time.h>
void printing(char d1)
{
	time_t now = time(0);

	if (file = fopen("potvrda.txt", "w"))
	{
		fprintf(file, "**********HIGHWAY2016************\n\n\nUlazak na dionici: %c\nPotvrda stampana u: ", d1);
		fprintf(file, ctime(&now)); //ubacuje trenutno sistemsko vrijeme i datum
	}
}