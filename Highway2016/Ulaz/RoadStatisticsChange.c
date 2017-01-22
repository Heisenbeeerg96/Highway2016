#include "RoadStatisticsChange.h"

int changeStat(char *dion1, char *dion2)
{
	FILE *fp=NULL;
	GRAF graf;
	load(fp, &graf);

	int kord1 = *dion1; //prebacujemo string u int
	int kord2 = *dion2;
	kord1 -= 65; //time dobijam dionice kao i/j(dimenzije matrice)
	kord2 -= 65;
	if (graf.ms[kord1][kord2] == 0)
	{
		do
		{
			printf("Ne postoji direkna veza izmedju te dve dionice,unesite ih opet:\n");
			scanf("%s %s", dion1, dion2);
			kord1 = *dion1;
			kord2 = *dion2;

			kord1 -= 65;
			kord2 -= 65;
		} while (graf.ms[kord1][kord2] == 0);
	}

	ROADDATA roads[MAX][MAX];
	loadWorkOnRoads(fp, roads, &graf);
	int tem=0;
	int opcion,data;
	float decimalData;
	printf("Sta zelite da promjenite na auto putu:\n1.Brzinu\n2.Koeficijent\n3.Radov na putu\n4.Mogucnost koristenja puta\n5.Exit\n");
	scanf("%d", &opcion);
	
	while (opcion != 5)
	{
		if (opcion == 1)
		{
			printf("\nUnesite novu dozvoljenu brzinu izmedju te dve dionice:\n");
			scanf("%d", &data);
			roads[kord1][kord2].speed = data;
		}
		else if (opcion == 2)
		{
			printf("\nUnesite novi koeficijent izmedju te dve dionice:\n");
			scanf("%f", &decimalData);
			roads[kord1][kord2].factor = decimalData;
		}
		else if (opcion == 3)
		{
			printf("\nUnesite novo stanje na putu(promjena stanje radova na putu) izmedju te dve dionice(0.0 ili 1.0):\n");
			scanf("%f", &decimalData);
			tem =(int) decimalData;
			roads[kord1][kord2].workOnRoad = decimalData;
		}
		else if (opcion == 4)
		{
			printf("\nUnesite novo stanje na putu(da li je moguc saobracaj izmedju dionica) izmedju te dve dionice(0 ili 1):\n");
			scanf("%f", &decimalData);
			roads[kord1][kord2].availability = decimalData;
		}
		else
		{
			printf("\nIzabrali ste ne postojecu opciju!\n");
		}
		printf("Sta zelite da promjenite na auto putu:\n1.Brzinu\n2.Koeficijent\n3.Radov na putu\n4.Mogucnost koristenja puta\n5.Exit\n");
		scanf("%d", &opcion);
	}

	roads[kord2][kord1] = roads[kord1][kord2];//Ako izvrsimo promjene od A do B te promjene se isto dogadjaju na putu B do A!

	if ((fp = fopen("WorkOnRoads.txt", "w")) != NULL)
	{
		fprintf(fp, "=======================================================================================================================================\n");
		fprintf(fp, "BRZINA | KOEFICIJENT PUTA | RADOV NA PUTU | MOGUCNOST ODRZAVANJA SAOBRACAJA\n");
		fprintf(fp, "=======================================================================================================================================\n");

		for (int i = 0; i < graf.n; i++, fprintf(fp, "\n"))
			for (int j = 0; j < graf.n; j++)
			{
				fprintf(fp, "%d %.2f %.2f %.2f   ", roads[i][j].speed, roads[i][j].factor, roads[i][j].workOnRoad, roads[i][j].availability);
			}
		fprintf(fp, "=======================================================================================================================================\n");
	}
	else
	{
		printf("Greska pri upisu u dadoteku Radovima na putu!\n");
	}
	fclose(fp);
	return tem;

}
void printRoadStat()
{	
	printf("Slijedi matrica puta:\nNAPOMENA:Elementi matrice oznacavaju putanje, tako da je prvi element putanja A->A,drugi A->B ...\nRedoslijed osobina su sljedece(Napomena:1-da,0-ne):\n");
	FILE* f = fopen("WorkOnRoads.txt", "r");
	char s[250];
	if (f)
	{
		while(fgets(s, 100, f)!=NULL)
		printf("%s", s);
	}
}
