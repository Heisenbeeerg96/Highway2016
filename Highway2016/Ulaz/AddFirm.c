#include "AddFirm.h"

void add_maintanceWorker(char d)
{
	FILE* file;
	PERSON w;
	FIRM f;
	char temp[1];
	temp[0] = d;
	int n, i;
	char naziv_f[20];
	printf("Unesite naziv firme:");
	scanf("%s", naziv_f);
	strcpy(f.name, naziv_f);
	printf("Unesite broj zaposlenih:");
	scanf("%d", &n);
	f.num_work = n;
	temp[0] = d;
	file = fopen("firma.txt", "a");
	if (file)
	{
		for (i = 0; i < f.num_work; i++)
		{
			initWorkPerson(&w);
			fputc(d, file);
			fprintf(file, "\n%-15s\n%-15s\n%-23s\n", f.name, w.name, w.surname);
		}
	}
	fclose(file);
}
