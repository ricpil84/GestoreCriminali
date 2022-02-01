//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_COMPARISON_H
#define PROGETTOTNV_COMPARISON_H

#include "basedata.h"

#define MEMBERS_RECORDSOGGETTO 12 // Members of the struct RecordSoggetto
#define MEMBER_PERC_VALUE 100.00/MEMBERS_RECORDSOGGETTO // Percent value for a member of RecordSoggetto

float compName(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compSurname(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compHeight(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compWeight(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compEyesColor(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compHairColor(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compHairLength(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compBeard(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compFingerprint(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compResidency(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compPosition(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);
float compStatus(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord);

#endif //PROGETTOTNV_COMPARISON_H
