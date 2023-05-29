/*
 * Tannenbaum.h
 *
 *  Created on: 13.01.2023
 *      Author: student
 */

#ifndef TANNENBAUM_H_
#define TANNENBAUM_H_
#include <string.h>
#include <stdlib.h>
#include "Konfiguration.h"
#include "Cursor.h"

struct Tannenbaum
{
    char bild[MAX_AUSDEHNUNG][MAX_AUSDEHNUNG];
    int breite;
    int hoehe;
};

typedef struct Tannenbaum Tannenbaum;

/* Aufgabe 1a */
Tannenbaum* Tannenbaum_erzeugen(int breite, int hoehe)
{
	Tannenbaum* t_ptr = (Tannenbaum*) malloc(sizeof(Tannenbaum));

	if(t_ptr == NULL){
    return NULL;
	}

	if(breite >= (MAX_AUSDEHNUNG - 1))
	{
		t_ptr->breite = (MAX_AUSDEHNUNG - 1);
	}
	else{
		t_ptr->breite = breite;
	}

	if(hoehe >= (MAX_AUSDEHNUNG - 1))
	{
		t_ptr->hoehe = (MAX_AUSDEHNUNG - 1);
	}
	else{
		t_ptr->hoehe = hoehe;
	}

	return t_ptr;
}
/* Aufgabe 1b */

void Tannenbaum_init(Tannenbaum* t_ptr)
{
	for(int x = 0; x < t_ptr->breite; x++)
	{
		for(int y = 0; y < t_ptr->hoehe; y++)
		{
			t_ptr->bild[x][y] = SYMBOL_LEER;
		}
	}

	int mid = t_ptr->breite / 2;

	for(int y = 0; y < t_ptr->hoehe - 2; y++)
	{
		for(int x = mid - y; x <= mid + y; x++)
		{
			t_ptr->bild[x][y] = SYMBOL_NADEL;
		}
	}

    for (int x = mid - 1; x <= mid + 1; x++)
    {
        for (int y = t_ptr->hoehe - 2; y < t_ptr->hoehe; y++)
        {
            t_ptr->bild[x][y] = SYMBOL_STAMM;
        }
    }
}

/* Aufgabe 1c */
void Tannenbaum_schmuecken(Tannenbaum* t_ptr, int prozent)
{
	for(int x = 0; x < t_ptr->breite; x++)
	{
		for(int y = 0; y < t_ptr->hoehe; y++)
		{
			if(t_ptr->bild[x][y] == SYMBOL_NADEL)
			{
				if(rand()%100 < prozent)
				{
					t_ptr->bild[x][y] = SYMBOL_KUGEL;
				}
			}
		}
	}
}

/* Aufgabe 1d */
void Tannenbaum_ausgabe(Tannenbaum* t_ptr)
{
	for(int x = 0; x < t_ptr->breite; x++)
	{
		for(int y = 0; y < t_ptr->hoehe; y++)
		{
			if(t_ptr->bild[x][y] == SYMBOL_NADEL)
			{
				cursor_setze_farbe(farben[GRUEN]);
			}
			else if(t_ptr->bild[x][y] == SYMBOL_STAMM)
			{
				cursor_setze_farbe(farben[BRAUN]);
			}
			else if(t_ptr->bild[x][y] == SYMBOL_KUGEL)
			{
				cursor_setze_farbe(farben[ZUFALL]);
			}

			cursor_zeichne_punkt(x + OFFSET, y + OFFSET, t_ptr->bild[x][y]);
		}
	}
}

#endif /* TANNENBAUM_H_ */
