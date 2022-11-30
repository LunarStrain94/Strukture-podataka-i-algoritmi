#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float x;
    float y;
}Tocka;

typedef struct
{
    int n;
    Tocka *tniz;
}Poligon;

//void upisNiza(int* niz, int n)
//{
//    int i;
//    printf("Unesite clanove niza: \n");
//    niz = (int*)malloc((n)*sizeof(int));
//    for (i = 0; i < n; i++)
//    {
//        printf(">>");
//        scanf("%d", &niz[i]);
//    }
//}

void ispisNiza(int niz[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", niz[i]);
}

int* podniz(int *niz, int start, int stop)
{
    int t, i, j = 0, *niz2;
    //Provjerit
    if (stop < start)
    {
        t = stop;
        stop = start;
        start = t;
    }
    niz2 = (int*)malloc((stop - start + 1)*sizeof(int));
    for (i = start; i <= stop; ++i)
    {
        niz2[j] = niz[i];
        j++;
    }
    return niz2;
}

int* filtriraj(int *niz, int n, int th, int *nth)
{
    int i, j = 0, br = 0;
    for (i = 0; i < n; ++i)
    {
        if (niz[i] < th)
            br++;
    }
    *nth = br;
    int *niz2 = (int*)malloc(br * sizeof(int));
    for (i = 0; i < n; ++i)
    {
        if (niz[i] < th)
        {
            niz2[j] = niz[i];
            j++;
        }
    }
    return niz2;
}

int **podijeli(int *niz, int n)
{
	int n1 = n / 2;
	int n2 = n - n1;
	int *prvi  = (int*)malloc(n1 * sizeof(int));
	int *drugi = (int*)malloc(n2 * sizeof(int));
	int i, j, k;
	for (i = 0; i < n1; i++)
		prvi[i] = niz[i];
	//ispisNiza(prvi, n1);
	//printf("\n\n");
	for (j = 0; j < n2; j++)
		drugi[j] = niz[j + n1];
	//ispisNiza(drugi, n2);
	int **nniz = (int**)malloc(2 * sizeof(int*));
	nniz[0] = prvi;
	nniz[1] = drugi;
	return nniz;
}

Poligon *novi_poligon(float *niz_x, float *niz_y, int n)
{
    //if (n < 3)
    //    return 0;
    Poligon *novi = (Poligon*)malloc(sizeof(Poligon));
    novi->tniz = (Tocka*)malloc(n * sizeof(Tocka));
	for (int i = 0; i < n; i++)
	{
		novi->tniz[i].x = niz_x[i];
		novi->tniz[i].y = niz_y[i];
	}
	return novi;
}

Tocka** pozitivni(Poligon *p, int *pc)
{
	Tocka** plus;
	plus = (Tocka*)malloc(p->n * sizeof(Tocka*));
	int broj = 0;
	for (int i = 0; i < p->n; i++)
	{
		if (p->tniz[i].x > 0 && p->tniz[i].y > 0)
			broj++;
	}
	plus = (Tocka*)realloc(plus, broj * sizeof(Tocka*));
	for (int i = 0; i < p->n; i++)
	{
		if (p->tniz[i].x > 0 && p->tniz[i].y > 0)
		{
			plus[broj] = &p->tniz[i];
			//printf("%d\n", &p->tniz[i]);
			//printf("%f\n", p->tniz[i].x);
			//printf("%f\n\n", p->tniz[i].y);
			broj++;
		}
	}
	*pc = broj;
	return plus;
}

int main()
{
    int n = 10, niz1[] = {1, 2, 3, 9, 5, 6, 7, 8, 7, 6};
    int* niz2, nth;
    //printf("Unesite velicinu niza: ");
    //scanf("%d", &n);
    //upisNiza(&niz1, n);
    ispisNiza(niz1, n);
    printf("\n\n");

    niz2 = podniz(niz1, 2, 5);
    ispisNiza(niz2, 4);
    free(niz2);
    printf("\n\n");

    niz2 = filtriraj(&niz1, n, 7, &nth);
    ispisNiza(niz2, nth);
    free(niz2);
    printf("\n\n");

    int **niz3 = podijeli(niz1, n);
	for (int i = 0; i < 2; i++)
		printf("%d\n", niz3[i]);
	free(niz3);
	printf("\n");

	float niz_x[5] = { 1, 2, 3, 4, 5};
	float niz_y[5] = { 1, 2, 3, 4, 5};
	n = 5;
	Poligon *pol = novi_poligon(niz_x, niz_y, n);
	for (int i = 0; i < n; i++)
	{
		printf("%f ", pol->tniz[i].x);
		printf("%f\n", pol->tniz[i].y);
	}
	free(pol);
	printf("\n");

	Poligon *pp = (Poligon*)malloc(sizeof(Poligon));
	pp->n = 5;
	pp->tniz = (Tocka*)malloc(pp->n * sizeof(Tocka));
	pp->tniz[0].x = 1;
	pp->tniz[0].y = 2;
	pp->tniz[1].x = 3;
	pp->tniz[1].y = 4;
	pp->tniz[2].x = -1;
	pp->tniz[2].y = 2;
	pp->tniz[3].x = -1;
	pp->tniz[3].y = -2;
	pp->tniz[4].x = 5;
	pp->tniz[4].y = -6;
	int d;
	int i;
	Tocka** pluss = pozitivni(pp, &d);
	for (i = 0; i < d; i++)
		printf("%d\n", pluss[i]);
	free(pluss);
	return 0;
}
