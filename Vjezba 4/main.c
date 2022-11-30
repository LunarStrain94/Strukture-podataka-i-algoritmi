#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* generiraj(int n)
{
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++)
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	return niz;
}

void shuffle(int* niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}

int* presjek(int* niz1, int* niz2, int n, int n2)
{
	n = max(n, n2);
	int* niz = (int*)malloc(sizeof(int) * n);
	int n1 = 0;
	for (int i = 0, k = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (niz1[i] == niz2[j])
			{
				niz[k] = niz1[i];
				++k;
				++n1;
			}
		}
	}
	niz = (int*)realloc(niz, sizeof(int) * n1);
	return niz;
}

int* presjek_jedan_sortiran(int* niz1, int* niz2, int n, int n2)
{
	n = max(n, n2);
	int* niz = (int*)malloc(sizeof(int) * n), pitem;
	int n1 = 0;
	qsort(niz2, n, sizeof(int), cmp);
	for (int i = 0, j = 0; i < n; ++i)
	{
		pitem = (int*)bsearch(&niz1[i], niz2, n, sizeof(int), cmp);
		if (pitem != NULL)
		{
			niz[j] = niz1[i];
			++j;
			++n1;
		}
	}
	niz = (int*)realloc(niz, sizeof(int) * n1);
	return niz;
}

/*int* presjek_oba_sortirana3(int* niz1, int* niz2, int n, int n2)
{
	n = max(n, n2);
	int* niz = (int*)malloc(sizeof(int) * n);
	int n1 = 0;
	qsort(niz1, n, sizeof(int), cmp);
	qsort(niz2, n, sizeof(int), cmp);
	for (int i = 0, k = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (niz1[i] == niz2[j])
			{
				niz[k] = niz1[i];
				++k;
				++n1;
				break;
			}
			if (niz1[i] < niz2[j])
				break;
		}
	}
	niz = (int*)realloc(niz, sizeof(int) * n1);
	return niz;
}


int* presjek_oba_sortirana2(int* niz1, int* niz2, int n, int n2)
{
	n = max(n, n2);
	int* niz = (int*)malloc(sizeof(int) * n);
	int n1 = 0;
	qsort(niz1, n, sizeof(int), cmp);
	qsort(niz2, n, sizeof(int), cmp);
	for (int i = 0, k = 0; i < n; ++i)
	{
		int j = i;
		if (niz1[i] == niz2[j])
		{
			niz[k] = niz1[i];
			++k;
			++n1;
			break;
		}
		else if (niz2[j] > niz1[i])
		{
			while (j >= 0 && j < n && niz2[j] >= niz1[i])
			{
				if (niz1[i] == niz2[j])
				{
					niz[k] = niz1[i];
					++k;
					++n1;
					break;
				}
				--j;
			}
		}
		else if (niz2[j] < niz1[i])
		{
			while (j >= 0 && j < n && niz2[j] <= niz1[i])
			{
				if (niz1[i] == niz2[j])
				{
					niz[k] = niz1[i];
					++k;
					++n1;
					break;
				}
				++j;
			}
		}
	}
	niz = (int*)realloc(niz, sizeof(int) * n1);
	return niz;
}*/

int* presjek_oba_sortirana(int* niz1, int* niz2, int n, int n2)
{
	n = max(n, n2);
	int* niz = (int*)malloc(sizeof(int) * n);
	int n1 = 0, i = 0, j = 0, k = 0;
	qsort(niz1, n, sizeof(int), cmp);
	qsort(niz2, n, sizeof(int), cmp);
	while (i < n && j < n)
	{
		if (niz1[i] == niz2[j])
		{
			niz[k] = niz1[i];
			++k;
			++n1;
			++i;
			++j;
		}
		else if (niz1[i] > niz2[j])
			++j;
		else if (niz1[i] < niz2[j])
			++i;
	}
	niz = (int*)realloc(niz, sizeof(int) * n1);
	return niz;
}


void print(int niz[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", niz[i]);
	printf("\n\n");
}

int main()
{
	clock_t start_t, end_t;
	double total_t;
	int n = 10000;
	int n1 = 0;

	printf("N = %d\n", n);

	int* niz1 = generiraj(n);
	int* niz2 = generiraj(n);
	shuffle(niz1, n);
	shuffle(niz2, n);

	start_t = clock();
	int* pres = presjek(niz1, niz2, n, n);
	end_t = clock();
	total_t = (double)(end_t - start_t);
	total_t = total_t / CLOCKS_PER_SEC;
	printf("Presjek: %lf\n", total_t);
	free(pres);

	start_t = clock();
	int* pres2 = presjek_jedan_sortiran(niz1, niz2, n, n);
	end_t = clock();
	total_t = (double)(end_t - start_t);
	total_t = total_t / CLOCKS_PER_SEC;
	printf("Presjek(jedan sortiran): %lf\n", total_t);
	free(pres2);

	start_t = clock();
	int* pres3 = presjek_oba_sortirana(niz1, niz2, n, n);
	end_t = clock();
	total_t = (double)(end_t - start_t);
	total_t = total_t / CLOCKS_PER_SEC;
	printf("Presjek(oba sortirana): %lf\n", total_t);
	free(pres3);

	while (n <= 310000)
	{
		n += 30000;
		printf("\nN = %d\n", n, n);

		niz1 = generiraj(n);
		niz2 = generiraj(n);
		shuffle(niz1, n);
		shuffle(niz2, n);

		start_t = clock();
		pres = presjek(niz1, niz2, n, n);
		end_t = clock();
		total_t = (double)(end_t - start_t);
		total_t = total_t / CLOCKS_PER_SEC;
		printf("Presjek: %lf\n", total_t);
		free(pres);

		start_t = clock();
		pres2 = presjek_jedan_sortiran(niz1, niz2, n, n);
		end_t = clock();
		total_t = (double)(end_t - start_t);
		total_t = total_t / CLOCKS_PER_SEC;
		printf("Presjek(jedan sortiran): %lf\n", total_t);
		free(pres2);

		start_t = clock();
		pres3 = presjek_oba_sortirana(niz1, niz2, n, n);
		end_t = clock();
		total_t = (double)(end_t - start_t);
		total_t = total_t / CLOCKS_PER_SEC;
		printf("Presjek(oba sortirana): %lf\n", total_t);
		free(pres3);
	}

	return 0;
}