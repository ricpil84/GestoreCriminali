//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_EXTRAFUNCTIONALITIES_H
#define PROGETTOTNV_EXTRAFUNCTIONALITIES_H

#include "filemanipulation.h"
#include "uimenus.h"

void saveBinArray(const int aSize, const RecordSoggetto aRecord[], char fileName[]);
void saveTxtArray(const int aSize, RecordSoggetto aRecord[], char fileName[]);
RecordSoggetto* readBinArray(char fileName[]);
RecordSoggetto* readTxtArray(char fileName[]);

#endif //PROGETTOTNV_EXTRAFUNCTIONALITIES_H
