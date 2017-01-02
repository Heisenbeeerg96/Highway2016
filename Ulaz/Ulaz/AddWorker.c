#include "AddWorker.h"
void addWorker()
{
	FILE* file;
	PERSON p;
	initPerson(&p);
	file = fopen("zaposleni.txt", "a");
	if (file)
	{
		fprintf(file, "%-10s  %-7s  %-13s  %d.%d.%d\n", p.name, p.surname, p.JMBG, p.birth.dd, p.birth.mm, p.birth.yy);
	}
}