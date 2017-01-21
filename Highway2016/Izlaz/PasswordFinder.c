#include "PasswordFinder.h"

BILL findPassword(char *pw) //pw-password
{
	FILE *fp = NULL;
	char temp[100];
	BILL object, tempObject;
	object.day = object.year = object.sek = object.hh = object.min = 0;
	tempObject.year = -1;//koristim kao uslov!

	if ((fp = fopen("potvrde.txt", "r")) != NULL)
	{
		do
		{
			fgets(temp, 100, fp);
			fgets(temp, 100, fp);
			fgets(temp, 100, fp);

			while (fscanf(fp,"%s %s %s %s %s %d %d:%d:%d %d\n", &object.password, &object.checkpoint,&object.vehicleCategory,&object.daychar,
				&object.month, &object.day, &object.hh, &object.min, &object.sek, &object.year) == 10)
			{
				if (strcmp(object.password, pw) == 0) //ako postoji sifra vraca se iz funkcije
				{
					printf("Postoji ta sifra\n"); //Ibacit ovo kasnije!
					tempObject = object;
					return object;
				}
			}
			fgets(temp, 100, fp);

		} while (!feof(fp));

		if (tempObject.year == -1) //ako slucajno ne nadje sifru onda vraca year=-1 i mainu trazi da se onovo unese sifra!
			return tempObject;
	}
	else
	{
		printf("Greska pri otvaranju,dadoteke za sifre!\n");
	}

}
