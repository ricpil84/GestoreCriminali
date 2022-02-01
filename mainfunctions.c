//
// Created by riccardo on 03/01/22.
//
#include "mainfunctions.h"
/**
 * This function randomly generates the members of a variable RecordSoggetto
 * @return variable RecordSoggetto
 */
RecordSoggetto generaRecord(){
    RecordSoggetto newPerson;

    genName(&newPerson);
    genSurname(&newPerson);
    genHeight(&newPerson);
    genWeight(&newPerson);
    genEyesColor(&newPerson);
    genHairColor(&newPerson);
    genHairLength(&newPerson);
    genBeard(&newPerson);
    genFingePrint(&newPerson);
    genResidency(&newPerson);
    genGpsPos(&newPerson);
    genStatus(&newPerson);

    return newPerson;
}
/**
 * This procedure prints the members of a variable RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 */
void stampaRecord(const RecordSoggetto *pRecord){
    if(pRecord!=NULL) {
        printf("\nNome: %s", pRecord->name);
        printf("\nCognome: %s", pRecord->surname);
        printf("\nAltezza: %d", pRecord->height);
        printf("\nPeso: %.2f", pRecord->weight);
        printArray(sizeof(pRecord->eyesColor), "\nColore occhi: ", pRecord->eyesColor);
        printArray(sizeof(pRecord->hairColor), "\nColore capelli: ", pRecord->hairColor);
        printHairLength(pRecord->HairLength);
        printBeard(pRecord->beard);
        printArray(sizeof(pRecord->fingerprint), "\nImpronta digitale: ", pRecord->fingerprint);
        printf("\nResidenza: %s", pRecord->residency);
        printf("\nPosizione: LAT %.6lf LON %.6lf", pRecord->Position.lat, pRecord->Position.lon);
        printStatus(pRecord->Status);
    } else
        printf("\nRecord non presente");

}
/**
 * This procedure scans the input for every member of a variable RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 */
void inserisciRecord(RecordSoggetto *pRecord){
    _Bool abortFlag=false;
    int i;

    for(i=NAME;i>STATUS&&!abortFlag;i++) {
        switch (i) {
            case NAME:
                scanName(pRecord, &abortFlag);
                break;
            case SURNAME:
                scanSurname(pRecord, &abortFlag);
                break;
            case HEIGHT:
                scanHeight(pRecord, &abortFlag);
                break;
            case WEIGHT:
                scanWeight(pRecord, &abortFlag);
                break;
            case EYESC:
                scanEyesColor(pRecord, &abortFlag);
                break;
            case HAIRC:
                scanHairColor(pRecord, &abortFlag);
                break;
            case LENGTH:
                scanHairLength(pRecord, &abortFlag);
                break;
            case BEARD:
                scanBeard(pRecord, &abortFlag);
                break;
            case FINGPRINT:
                scanFingerprint(pRecord, &abortFlag);
                break;
            case RESID:
                scanResidency(pRecord, &abortFlag);
                break;
            case POSITION:
                scanPosition(pRecord, &abortFlag);
                break;
            case STATUS:
                scanStatus(pRecord, &abortFlag);
                break;
            default:
                exitError("Campo RecordSoggetto non definito");
        }
    }
    if(abortFlag) {
        printf("\nInserimento cancellato. Premere un tasto per continuare...");
        waitForUser();
        clearScreen();
        emptyBuffer();
    }
}
/**
 * This function compares two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable RecordSoggetto
 * @param pSecRecord pointer to the second variable RecordSoggetto
 * @return similarity between the two variables RecordSoggetto
 */
int confrontaRecord(const RecordSoggetto *pFstRecord, const RecordSoggetto *pSecRecord ){
    float similarity=0;

    similarity+=compName(pFstRecord, pSecRecord);
    similarity+=compSurname(pFstRecord, pSecRecord);
    similarity+=compHeight(pFstRecord, pSecRecord);
    similarity+=compWeight(pFstRecord, pSecRecord);
    similarity+=compEyesColor(pFstRecord, pSecRecord);
    similarity+=compHairColor(pFstRecord, pSecRecord);
    similarity+=compHairLength(pFstRecord, pSecRecord);
    similarity+=compBeard(pFstRecord, pSecRecord);
    similarity+=compFingerprint(pFstRecord, pSecRecord);
    similarity+=compResidency(pFstRecord, pSecRecord);
    similarity+=compPosition(pFstRecord, pSecRecord);
    similarity+=compStatus(pFstRecord, pSecRecord);

    return (int) similarity;
}