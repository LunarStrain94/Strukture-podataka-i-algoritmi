#include "dictionary.h"

Dictionary create()
{
	Dictionary w = (Dictionary)malloc(sizeof(Word));
	w->word = " ";
	w->count = 0;
	w->next = NULL;
	return w;
}
// briše cijeli rjeènik
void destroy(Dictionary dict)
{
	Dictionary tmp = dict;
	while (tmp->next != NULL)
	{
		Dictionary del = tmp->next;
		tmp->next = tmp->next->next;
		free(del->word);
		free(del);
	}
}
// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict)
{
	Dictionary s = dict;
	s = s->next;
	while (s != NULL)
	{
		printf("%s", s->word);
		printf(" %d\n", s->count);
		s = s->next;
	}
}
// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char* str)
{
	Dictionary q = dict;
	while (q->next != NULL)
	{
		if (strcmp(str, q->next->word) < 0)
		{
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = strdup(str);
			novi->count = 1;
			novi->next = q->next;
			q->next = novi;
			return;
		}
		else if (strcmp(str, q->next->word) == 0)
		{
			q->next->count++;
			return;
		}
		q = q->next;
	}
	q->next = (Dictionary)malloc(sizeof(Word));
	q->next->word = strdup(str);
	q->next->count = 1;
	q->next->next = NULL;
}
int filter(Word* w)
{
	if (w->count >= 5 && w->count <= 10 && strlen(w->word) > 3)
		return 1;
	else
		return 0;
}
Dictionary filterDictionary(Dictionary indict, int(*filter)(Word* w))
{
	Dictionary tmp = indict;
	if (tmp->next == NULL)
	{
		return NULL;
	}
	while (tmp->next != NULL)
	{
		if (filter(tmp->next) == 1)
		{
			tmp = tmp->next;
		}
		else
		{
			Dictionary del = tmp->next;
			tmp->next = tmp->next->next;
			free(del->word);
			free(del);
		}
	}
	return indict;
}
