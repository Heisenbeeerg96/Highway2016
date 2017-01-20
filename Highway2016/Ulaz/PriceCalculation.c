#include "PriceCalculation.h"

void floyd(GRAF *graf, int t[][MAX], float d[][MAX]) //matrica najkracih rastojanja D,matrica prethodnika T
{
	for (int k = 0; k<graf->n; k++)
		for (int i = 0; i<graf->n; i++)
			for (int j = 0; j<graf->n; j++)
			{
				if (d[i][j]>d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					t[i][j] = t[k][j];
				}
			}
}

void path(int i, int j, GRAF *graf, int t[][MAX])
{
	if (i == j)
	{
		printf("%s ", graf->array[i].name);
	}
	else if (t[i][j] == -1)
		printf("Nepostoji putanja!\n");
	else
	{
		path(i, t[i][j], graf, t);
		printf("%s ", graf->array[j].name);

	}
}

void search_dfs(int u, GRAF *graf, char *dion1, char *dion2, int *kord1, int *kord2, int visited[MAX])
{
	int v;
	visited[u] = 1;
	if (strcmp(dion1, graf->array[u].name) == 0)
		*kord1 = graf->array[u].indeks;
	if (strcmp(dion2, graf->array[u].name) == 0)
		*kord2 = graf->array[u].indeks;

	for (v = 0; v < graf->n; v++)
		if (!visited[v] && graf->ms[u][v])
			search_dfs(v, graf, dion1, dion2, kord1, kord2, visited);
}

void search(GRAF *graf, char *dion1, char *dion2, int *kord1, int *kord2)
{
	int visited[MAX] = {0};
	search_dfs(0, graf, dion1, dion2, kord1, kord2, visited);
}


void load(FILE *fp, GRAF *graf)
{
	int i, j;
	char c, name[MAX] = {0};
	if ((fp = fopen("Prices.txt", "r")) != NULL)
	{
		fscanf(fp, "%d", &graf->n);
		graf->ms = (float**)malloc(graf->n * sizeof(float*));
		graf->array = (NODE *)malloc(graf->n * sizeof(NODE));
		for (i = 0; i<graf->n; i++)
		{
			graf->ms[i] = (float*)malloc(graf->n * sizeof(float));
			graf->array[i].indeks = i + 1;
		}
		for (i = 0; i<graf->n; i++)
			for (j = 0; j<graf->n; j++)
			{
				fscanf(fp, "%f\n", &graf->ms[i][j]);
			}
		i = 0; j = 0;
		while ((c = fgetc(fp)) != EOF)
		{
			if (c != '\n')
			{
				name[i] = c;
				i++;
			}
			else
			{
				name[i] = '\0';
				graf->array[j].name = (char*)calloc(strlen(name) + 1, sizeof(char));
				strcpy(graf->array[j].name, name);
				i = 0; j++;
			}
		}
	}
	else
		printf("Greska pri otvranju!\n");
	fclose(fp);

}

void init(GRAF *graf, int t[][MAX], ROADDATA mat[][MAX])
{
	for (int i = 0; i<graf->n; i++)
		for (int j = 0; j<graf->n; j++)
		{
			if ((i == j || graf->ms[i][j] == 0) || mat[i][j].availability == 0)
				t[i][j] = -1;
			else
				t[i][j] = i;
		}
}

void loadWorkOnRoads(FILE *fp, ROADDATA road[][MAX], GRAF *graf)
{
	if ((fp = fopen("WorkOnRoads.txt", "r")) != NULL)
	{
		char temp[150];

		fgets(temp, 150, fp);
		fgets(temp, 150, fp);
		fgets(temp, 150, fp);

		for (int i = 0; i<graf->n; i++)
			for (int j = 0; j<graf->n; j++)
			{
				fscanf(fp, "%d %f %f %f", &road[i][j].speed,&road[i][j].factor,&road[i][j].workOnRoad,&road[i][j].availability);
			}
	}
	else
		printf("Greska pri otvaranju dadoteke o Radovima na putu!\n");
	fclose(fp);
}

int loadVehicleCatPrice(FILE *fp,char *category)
{
	VehicleCatPrice ob;
	if ((fp = fopen("CjenaKategorijeVozila.txt", "r")) != NULL)
	{
		while (fscanf(fp,"%s %d\n", &ob.category, &ob.price) == 2)
		{
			if (strcmp(category, ob.category) == 0)
				return ob.price;
		}
	}
	else
		printf("Greska pri otvaranju dadoteke o Kateogriji vozila!\n");
	fclose(fp);
}

void finallprice(BILL *ob,char *dion2)
{
	FILE *fp = NULL;
	GRAF graf;
	int i, j, t[MAX][MAX];
	float d[MAX][MAX];
	float roadWork[MAX][MAX];
	ROADDATA roads[MAX][MAX];
	load(fp, &graf);
	loadWorkOnRoads(fp, roads, &graf);


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

	int kord1, kord2;
	kord1 = kord2 = -1;

	search(&graf, ob->checkpoint, dion2, &kord1, &kord2);
	path(kord1 - 1, kord2 - 1, &graf, t);
	printf("\nUkupna cjena izmedju dionica iznosi:\n%f\nA vozilo je kategorije:%s\n", d[kord1 - 1][kord2 - 1]*(float)loadVehicleCatPrice(fp,ob->vehicleCategory),ob->vehicleCategory);
}
