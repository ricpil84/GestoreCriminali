//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_MAINFUNCTIONS_H
#define PROGETTOTNV_MAINFUNCTIONS_H

#include "basedata.h"
#include "generation.h"
#include "printing.h"
#include "comparison.h"
#include "userinput.h"

typedef enum { NAME, SURNAME, HEIGHT, WEIGHT, EYESC, HAIRC,                      //! Constant values for the members...
               LENGTH, BEARD, FINGPRINT, RESID, POSITION, STATUS} RecSogMembers; //! ... of the struct RecordSoggetto

RecordSoggetto generaRecord();
void stampaRecord(const RecordSoggetto *pRecord);
void inserisciRecord(RecordSoggetto *pRecord);
int confrontaRecord(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord );
#endif //PROGETTOTNV_MAINFUNCTIONS_H
