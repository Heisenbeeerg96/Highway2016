#include "Person.h"
void initPerson(PERSON* p)
{
	printf("Unesite ime:");
	scanf("%s",p->name);
	printf("Unesite prezime:");
	scanf("%s", p->surname);
	printf("Unesite datum rodjenja(dd.mm.yy):");
	scanf("%d.%d.%d", &p->birth.dd, &p->birth.mm, &p->birth.yy);
	printf("Unesite JMBG:");
	scanf("%s", p->JMBG);
}