//
// Created by riccardo on 06/01/22.
//
#ifndef PROGETTOTNV_UIMENUS_H
#define PROGETTOTNV_UIMENUS_H

#include "advfunctions.h"
#include "extrafunctionalities.h"

typedef enum { ZERO=0,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE } MenuChoices; // Constant for menu's user choices

void mainMenu();
void menuPrint(int *choice, int aSize, RecordSoggetto arrayRecord[], _Bool *abortFlag, _Bool *lastModSaved);
void menuLoadSave(int *choice, int aSize, RecordSoggetto arrayRecord[], _Bool *abortFlag, _Bool *lastModSaved);
void menuCipher(int *choice, int aSize, RecordSoggetto arrayRecord[], _Bool *abortFlag, _Bool *lastModSaved);
void printMainMenu();
void printPrintMenu();
void printMenuLoadSave();
void printMenuCipher();
void exitProgramCheck(_Bool *lastModSaved, int *choice);
#endif //PROGETTOTNV_UIMENUS_H
