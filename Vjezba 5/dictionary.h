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

// briše cijeli rjeènik
void destroy(Dictionary dict);

//Funkcija prima rjeènik (lista ispunjena sa abecedno
//poredanim rijeèima i brojem pojavljivanja u tekstu)
//i pokazivaè na funkciju:
Dictionary filterDictionary(Dictionary indict, int (*filter)(Word* w));

int filter(Word* w);

//Funkcija filterDictionary() vraæa izmijenjenu indict listu koja sadrži
//samo rijeèi za koje je filter() funkcija vratila 1
//(sve druge rijeèi se oslobaðaju). Funkcija filter() vraæa 1 ako je
//broj pojavljivanja rijeèi izmeðu 5 i 10 i ako je rijeè duža od 3 znaka.


#endif