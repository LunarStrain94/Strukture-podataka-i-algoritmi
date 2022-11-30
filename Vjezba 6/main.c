#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 10000

typedef struct {
	void *p;
	int prioritet;
}clan;

typedef struct {
	clan *niz;
	int br;
}gomila;

gomila *create() {
	gomila *niz = (gomila*)malloc(sizeof(gomila));
	niz->niz = (clan*)malloc(N * sizeof(clan));
	niz->br = 0;
	return niz;
}

void obrisi(gomila *s) {
	free(s->niz);
	free(s);
}

void popravi_prema_vrhu(gomila *s, int n) {
	int r = (n - 1) / 2;
	if (s->niz[r].prioritet < s->niz[n].prioritet) {
		clan temp = s->niz[r];
		s->niz[r] = s->niz[n];
		s->niz[n] = temp;
		popravi_prema_vrhu(s, r);
	}
}

void dodaj(gomila *s, int element) {
	s->niz[s->br].prioritet = element;
	popravi_prema_vrhu(s, s->br);
	s->br++;
}

void popravi_prema_dnu(gomila *s, int n) {
	int l = 2 * n + 1;
	int d = 2 * n + 2;
	if (l >= s->br && d >= s->br)
		return;
	if (l < s->br && d >= s->br) {
		if (s->niz[n].prioritet < s->niz[l].prioritet) {
			clan temp = s->niz[l];
			s->niz[l] = s->niz[n];
			s->niz[n] = temp;
			popravi_prema_dnu(s, l);
		}
	}
	else if (s->niz[n].prioritet < s->niz[l].prioritet || s->niz[n].prioritet < s->niz[d].prioritet) {
		if (s->niz[l].prioritet > s->niz[d].prioritet) {
			clan temp = s->niz[l];
			s->niz[l] = s->niz[n];
			s->niz[n] = temp;
			popravi_prema_dnu(s, l);
		}
		else if (s->niz[d].prioritet > s->niz[l].prioritet) {
			clan temp = s->niz[n];
			s->niz[n] = s->niz[d];
			s->niz[d] = temp;
			popravi_prema_dnu(s, d);
		}
	}
}

void ukloni(gomila *s) {
	int temp = s->niz[s->br-1].prioritet;
	s->niz[0].prioritet = temp;
	s->br--;
	popravi_prema_dnu(s, 0);
}

void main() {
	gomila *arr = create();
	
	dodaj(arr, 5555);
	dodaj(arr, 1342);
	dodaj(arr, 11);
	dodaj(arr, 27);
	dodaj(arr, 9);
	dodaj(arr, 5);
	dodaj(arr, 1);
	dodaj(arr, 2);
	dodaj(arr, 6);
	dodaj(arr, 3);
	/*ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);
	ukloni(arr);*/
	for (int i = 0; i < arr->br; i++)
		printf("%d\n", arr->niz[i].prioritet);
	obrisi(arr);
}