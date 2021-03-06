
#include <stdio.h>
#include <stdlib.h>
#include "qsortH.h"

typedef struct country {char n[50]; long m;} Country;

static int cmp(const void *a, const void *b)
{
	if ( ((Country *)a)-> m < ((Country *)b)-> m)
		return 0;
	else
		return 1;
}

int main(void)
{
	FILE *f, *o;
	Country gdpRank[195];

	int i, j;

	if(!(o =fopen("out.dat", "w") ) )
		fprintf(stderr,"file couldn't opened %d", __LINE__);

	if(!(f =fopen("GDP.dat", "r") ) )
		fprintf(stderr,"file couldn't opened %d", __LINE__);

	for(i =0; !feof(f); i++)
		fscanf(f, "%s%d" ,gdpRank[i].n, &gdpRank[i].m);
	
	qsortH(gdpRank,0, i, sizeof(Country), cmp);

	//source : http://databank.worldbank.org/data/download/GDP.pdf

	fprintf(o,"\n\n%s\n\n","---------------Gross Domestic Product 2015---------------");
	fprintf(o,"\n%s%11s%40s\n\n\n","Rank"," Economy", "(millions of Economy US dollars)");

	for(j =0; j <i; j++)		
		fprintf(o,"%-7d %-27s %d\n", j, gdpRank[j].n, gdpRank[j].m);

	fclose(o);
	fclose(f);

	return 0;
}
