//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_UTILITIES_H
#define PROGETTOTNV_UTILITIES_H

#include "checks.h"
#include <math.h>

typedef enum { MIN } ComparisonType; // Comparison type constants

void copyArray(const int size, char dest[], const char src[]);
void copyRecord (RecordSoggetto *pDest, RecordSoggetto *pSrc);
void swapRecord(RecordSoggetto *pFstRecord, RecordSoggetto *pSecRecord);
_Bool strToValue (const char str[], double *pValue );
_Bool compFullName(ComparisonType type, RecordSoggetto *pFstElm, RecordSoggetto *pSecElm);
int emptyBuffer();
void clearScreen();
#endif //PROGETTOTNV_UTILITIES_H
