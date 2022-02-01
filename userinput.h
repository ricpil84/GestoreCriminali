//
// Created by riccardo on 03/01/22.
//

#ifndef PROGETTOTNV_USERINPUT_H
#define PROGETTOTNV_USERINPUT_H

#define DIM_FORMAT_SP 10 + DIM_STRINGTERM //! String dimension for the format that allows spaces
#define DIM_FORMAT_NSP 5 + DIM_STRINGTERM //! String dimension for the format that doesn't allow spaces
#define DIM_BUFFER_VALUE 9 //! String dimension for the string containing the value before conversion

#include "utilities.h"

void scanCharArray(int aSize, char aChars[], int fSize, CharType t, _Bool *abortFlag);
double scanValue(const double min, const double max, Precision p, _Bool *abortFlag);
void scanName(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanSurname(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanHeight(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanWeight(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanEyesColor(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanHairColor(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanHairLength(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanBeard(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanFingerprint(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanResidency(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanPosition(RecordSoggetto *pRecord, _Bool *abortFlag);
void scanStatus(RecordSoggetto *pRecord, _Bool *aborFlag);
void setFormat (const int size, char format[], const _Bool haveSpace );

#endif //PROGETTOTNV_USERINPUT_H
