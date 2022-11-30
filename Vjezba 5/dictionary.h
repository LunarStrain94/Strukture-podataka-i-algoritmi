#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Word {
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct Word *next; 
} Word;

typedef Word* Dictionary;

// kreira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);

// bri�e cijeli rje�nik
void destroy(Dictionary dict);

//Funkcija prima rje�nik (lista ispunjena sa abecedno
//poredanim rije�ima i brojem pojavljivanja u tekstu)
//i pokaziva� na funkciju:
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));

int filter(Word* w);

//Funkcija filterDictionary() vra�a izmijenjenu indict listu koja sadr�i
//samo rije�i za koje je filter() funkcija vratila 1
//(sve druge rije�i se osloba�aju). Funkcija filter() vra�a 1 ako je
//broj pojavljivanja rije�i izme�u 5 i 10 i ako je rije� du�a od 3 znaka.


#endif