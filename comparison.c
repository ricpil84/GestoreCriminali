//
// Created by riccardo on 03/01/22.
//
#include "comparison.h"

/**
 * Compares the name members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the names are equal, 0 if different
 */
float compName(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(!strcmp(pFstRecord->name, pSecRecord->name))
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the surname members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the surnames are equal, 0 if different
 */
float compSurname(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(!strcmp(pFstRecord->surname, pSecRecord->surname))
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the height members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the heights are equal, 0 if different
 */
float compHeight(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(pFstRecord->height == pSecRecord->height)
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the weight members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the weights are equal, 0 if different
 */
float compWeight(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(pFstRecord->weight == pSecRecord->weight)
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the eye color members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the eye colors are equal, 0 if different
 */
float compEyesColor(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(!strcmp(pFstRecord->eyesColor, pSecRecord->eyesColor))
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the hair color members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the hair colors are equal, 0 if different
 */
float compHairColor(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(!strcmp(pFstRecord->hairColor, pSecRecord->hairColor))
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the hair length members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the hair lengths are equal, 0 if different
 */
float compHairLength(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(pFstRecord->HairLength == pSecRecord->HairLength)
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the beard members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the beards are equal, 0 if different
 */
float compBeard(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(pFstRecord->beard == pSecRecord->beard)
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the fingerprint members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the fingerprints are equal, 0 if different
 */
float compFingerprint(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(!strcmp(pFstRecord->fingerprint, pSecRecord->fingerprint))
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the residency members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the residencies are equal, 0 if different
 */
float compResidency(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord){
    if(!strcmp(pFstRecord->residency, pSecRecord->residency))
        return (float)MEMBER_PERC_VALUE;
    else
        return 0;
}
/**
 * Compares the Position members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the Position is the same, 0 if different
 */
float compPosition(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord) {
    if (pFstRecord->Position.lat == pSecRecord->Position.lat) {
        if (pFstRecord->Position.lon == pSecRecord->Position.lon)
            return (float) MEMBER_PERC_VALUE;
    } else
        return 0;
}
/**
 * Compares the Status members of two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return percent value if the Status are equal, 0 if different
 */
float compStatus(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord) {
    if (pFstRecord->Status == pSecRecord->Status)
        return (float) MEMBER_PERC_VALUE;
    else
        return 0;
}
