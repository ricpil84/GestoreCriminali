//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_ADVFUNCTIONS_H
#define PROGETTOTNV_ADVFUNCTIONS_H

#include "mainfunctions.h"
#include "sorting.h"
#include "cipher.h"

void stampaElencoCriminali (const int aSize, const RecordSoggetto arr[]);
void eliminaCriminale(int index, int *aSize, RecordSoggetto arr[]);
void generaDati (const int aSize, RecordSoggetto arr[] );
void ordinaAlfabeticamente(const int aSize, RecordSoggetto aRecord[] );
void criptaVettore (const int aSize, RecordSoggetto aRecord[] );
void decriptaVettore (const int aSize, RecordSoggetto aRecord[] );
#endif //PROGETTOTNV_ADVFUNCTIONS_H
