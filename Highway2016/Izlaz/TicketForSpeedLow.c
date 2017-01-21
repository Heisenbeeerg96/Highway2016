#include "TicketForSpeedLow.h"

void speedTicket(BILL *ob, char *dionica)
{
	FILE *fp = NULL;
	GRAF graf;
	ROADDATA roads[MAX][MAX];
	int curr_time, curr_hh, curr_min, curr_sec;
	float d[MAX][MAX];
	int  t[MAX][MAX];

	load(fp, &graf); //ucitava graf
	loadWorkOnRoads(fp, roads, &graf); //uctava radove na putu


	for (int i = 0; i<graf.n; i++)
		for (int j = 0; j<graf.n; j++)
		{
			if ((i != j && graf.ms[i][j] == 0) || roads[i][j].availability == 0)
				d[i][j] = INFINITY;

			else
				d[i][j] = graf.ms[i][j];
		}
	init(&graf, t, roads);

	floyd(&graf, t, d);

	int kord1, kord2, counter = 0, arrayOfKord[MAX];
	float speedXfactor = 0; //speedXfactor prom koja ce cuvat brzina * koeficijent(isto kao kod nalazenja minimu cjene puta)
	kord1 = kord2 = -1;

	search(&graf, ob->checkpoint, dionica, &kord1, &kord2);
	pathforTicket(kord1 - 1, kord2 - 1, &graf, t, &counter, arrayOfKord);


	int i = 0;
	counter--;
	while (counter>0) //sa ovim dobijamo ukupnu brzinu puta faktor
	{
		speedXfactor += roads[arrayOfKord[i]][arrayOfKord[i + 1]].speed*roads[arrayOfKord[i]][arrayOfKord[i + 1]].factor;
		i++;
		counter--;
	}


	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);


	 int dataInSeconds = 0;// pretvaramo vrijeme u sekunde(vrijeme sa ulaza,,kada je vozac usao na put" + brzina*koeficijent!
	 dataInSeconds = ob->sek + ob->min * 60 + ob->hh * 3600 + (int)speedXfactor;
	 printf("%d", dataInSeconds);
	 if (dataInSeconds < (timeinfo->tm_sec + timeinfo->tm_min * 60 + timeinfo->tm_hour * 3600))//ukoliko je manje od izlaznog vremena pise se kazna(szo znaci vozac je isao prebrzo!)
	 {
		 if ((fp = fopen("PotvrdeZaMUP.txt", "a"))!=NULL)
		 {
			 fprintf(fp, "=======================================================================================================\n");
			 fprintf(fp, "                                              POTVRDE ZA MUP                                           \n");
			 fprintf(fp, "=======================================================================================================\n");
			 fprintf(fp, "Osoba sa potvrdom %s koja je dosla na ulaz %s na vrijeme %s %s %d %d:%d:%d %d mora da plati kaznu.\n", ob->password, ob->checkpoint, ob->daychar,
				 ob->month, ob->day, ob->hh, ob->min, ob->sek, ob->year);
			 fprintf(fp, "=======================================================================================================\n\n");
		 }
		 else
			 printf("Greska pri otvaranju dadoteke za MUP!\n");
		 fclose(fp);
	 }

}

void pathforTicket(int i, int j, GRAF *graf, int t[][MAX], int *counter, int arrayOfKord[MAX])
{
	if (i == j)
	{
		arrayOfKord[*counter] = i;
		*counter = *counter + 1;
	}
	else if (t[i][j] == -1)
		printf("Nepostoji putanja!\n");
	else
	{
		pathforTicket(i, t[i][j], graf, t, counter, arrayOfKord);
		arrayOfKord[*counter] = j;
		*counter = *counter + 1;
	}
}
