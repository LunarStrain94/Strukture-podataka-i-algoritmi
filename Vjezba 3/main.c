#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

typedef struct
{
    float x;
    float y;
    float z;
}tocka;

typedef struct
{
    tocka normala;
    tocka vrh_a;
    tocka vrh_b;
    tocka vrh_c;
    unsigned short boja;
}trokut;

typedef struct
{
    int n;
    trokut* niz;
}objekt3d;

objekt3d* ispunjena()
{
    FILE* fp = fopen("primjerbin.stl", "rb");
    if (!fp)
        perror("greska!");
    fseek(fp, 80, SEEK_SET);
    objekt3d* nova = (objekt3d*)malloc(sizeof(objekt3d));
    int n = 0, i;
    fread(&n, sizeof(int), 1, fp);
    nova->n = n;
    trokut* tmp = (trokut*)malloc(nova->n * sizeof(trokut));
    for (i = 0; i < (nova->n); i++)
        fread(&(tmp[i]), 50, 1, fp);
    nova->niz = tmp;
    fclose(fp);
    return nova;
}

void napravi_txt(objekt3d* tekstualni)
{
    FILE* fp = fopen("objekttxt.stl", "wt");
    if (!fp)
        perror("greska");
    int i;
    fprintf(fp, "solid \n");
    for (i = 0; i < (tekstualni->n); i++)
    {
        fprintf(fp, "facet normal %f %f %f\n", tekstualni->niz[i].normala.x, tekstualni->niz[i].normala.y, tekstualni->niz[i].normala.z);
        fprintf(fp, "outer loop\n");
        fprintf(fp, "vertex %f %f %f\n", tekstualni->niz[i].vrh_a.x, tekstualni->niz[i].vrh_a.y, tekstualni->niz[i].vrh_a.z);
        fprintf(fp, "vertex %f %f %f\n", tekstualni->niz[i].vrh_b.x, tekstualni->niz[i].vrh_b.y, tekstualni->niz[i].vrh_b.z);
        fprintf(fp, "vertex %f %f %f\n", tekstualni->niz[i].vrh_c.x, tekstualni->niz[i].vrh_c.y, tekstualni->niz[i].vrh_c.z);
        fprintf(fp, "endloop\n");
        fprintf(fp, "endfacet\n");
    }
	fprintf(fp, "endsolid\n");
    fclose(fp);
}

void napravi_bin(objekt3d* binarni)
{
    FILE* fp = fopen("objektbin.stl", "wb");
    if (!fp)
        perror("greska");
    char buffer[80] = { 0 };
    fwrite(buffer, sizeof(char), 80, fp);
    fwrite(&(binarni->n), sizeof(int), 1, fp);
    int i;
    for (i = 0; i < binarni->n; i++)
    {
        fwrite(&(binarni->niz[i]), 50, 1, fp);
    }
    fclose(fp);
}

void izbrisi(objekt3d* objekti)
{
	free(objekti->niz);
	free(objekti);
}

int main(void)
{
    objekt3d* objects = ispunjena();
    napravi_bin(objects);
    napravi_txt(objects);
    izbrisi(objects);
    return 0;
}
