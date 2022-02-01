//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_FILEMANIPULATION_H
#define PROGETTOTNV_FILEMANIPULATION_H

#include "utilities.h"

#define DIM_VALUE_BUFFER 12 //! Dimension for the buffer
#define DIM_BEARD_BUFFER 28
#define DIM_ENUM_BUFFER 12
#define MODESIZE 3
#define EXTENSIONSIZE 4
#define FILENAMEMAX 255 - EXTENSIONSIZE

typedef enum { FP=-1, MP=-2 } ErrorType; // Error type constants
typedef enum { TXT, BIN } FileMode; // Write mode constants

void scanForFilename(char filename[]);
FILE *overwriteFile(char filename[],char mode[]);
void createNewFile(FILE **fp, char fileName[], FileMode fm);
void exitIfpNull(void *fp,ErrorType t);
void freadTxt(FILE *fp,RecordSoggetto *pPers);
void freadString(int bSize, char str[], FILE *fp);
double freadValue(FILE *fp);
void freadName(FILE *fp, RecordSoggetto *pRecord);
void freadSurname(FILE *fp, RecordSoggetto *pRecord);
void freadHeight(FILE *fp, RecordSoggetto *pRecord);
void freadWeight(FILE *fp, RecordSoggetto *pRecord);
void freadEyesColor(FILE *fp, RecordSoggetto *pRecord);
void freadHairColor(FILE *fp, RecordSoggetto *pRecord);
void freadHairLength(FILE *fp, RecordSoggetto *pRecord);
void freadBeard(FILE *fp, RecordSoggetto *pRecord);
void freadFingerprint(FILE *fp, RecordSoggetto *pRecord);
void freadResidency(FILE *fp, RecordSoggetto *pRecord);
void freadStatus(FILE *fp, RecordSoggetto *pRecord);
void fprintTxt(FILE *fp, RecordSoggetto *pRecord);
void fprintArray(int aSize, FILE *fp, char array[]);
void fprintEyesColor(FILE *fp, RecordSoggetto *pRecord);
void fprintHairColor(FILE *fp, RecordSoggetto *pRecord);
void fprintHairLength(FILE *fp, RecordSoggetto *pRecord);
void fprintBeard(FILE *fp, RecordSoggetto *pRecord);
void fprintFingerprint(FILE *fp, RecordSoggetto *pRecord);
void fprintStatus(FILE *fp, RecordSoggetto *pRecord);
#endif //PROGETTOTNV_FILEMANIPULATION_H
