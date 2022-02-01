//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_GENERATION_H
#define PROGETTOTNV_GENERATION_H

#include "basedata.h"
#include "checks.h"

void genName(RecordSoggetto *pRecord);
void genSurname(RecordSoggetto *pRecord);
void genHeight(RecordSoggetto *pRecord);
void genWeight(RecordSoggetto *pRecord);
void genEyesColor(RecordSoggetto *pRecord);
void genHairColor(RecordSoggetto *pRecord);
void genHairLength(RecordSoggetto *pRecord);
void genBeard(RecordSoggetto *pRecord);
void genFingePrint(RecordSoggetto *pRecord);
void genResidency(RecordSoggetto *pRecord);
void genGpsPos(RecordSoggetto *pRecord);
void genStatus(RecordSoggetto *pRecord);
double genValue(double vMin, double vMax, Precision p);
void genArray(int aSize, char arr[], CharType c);

#endif //PROGETTOTNV_GENERATION_H
