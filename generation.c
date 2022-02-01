//
// Created by riccardo on 03/01/22.
//
#include "generation.h"

/**
 * This procedure randomly selects a string from an array 'nameDB' and copies it
 * on a 'name' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genName(RecordSoggetto *pRecord){
    char namesDB[][DIM_NAME]={"Riccardo","Andrea","Salvatore","Maria","Giorgia"};

    strcpy(pRecord->name, namesDB[rand() % (sizeof(namesDB) / DIM_NAME)]);
}
/**
 * This procedure randomly selects a string from an array 'surnameDB' and copies it
 * on a 'surname' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genSurname(RecordSoggetto *pRecord) {
    char surnamesDB[][DIM_SURNAME]={"Pilloni","Nandez","Del Piero","Riva","Baggio"};

    strcpy(pRecord->surname, surnamesDB[rand() % (sizeof(surnamesDB) / DIM_SURNAME)]);
}
/**
 * This procedure generates the 'height' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genHeight(RecordSoggetto *pRecord){
    pRecord->height=(int) genValue(HEIGHT_MIN, HEIGHT_MAX, UNITS);
}
/**
 * This procedure generates the 'weight' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genWeight(RecordSoggetto *pRecord){
    pRecord->weight=(float) genValue(WEIGHT_MIN, WEIGHT_MAX, CENTI);
}
/**
 * This procedure generates the 'eyesColor' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genEyesColor(RecordSoggetto *pRecord){
    genArray(DIM_EYESC, pRecord->eyesColor,HEX);
}
/**
 * This procedure generates the 'hairColor' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genHairColor(RecordSoggetto *pRecord){
    genArray(DIM_HAIRC, pRecord->hairColor,HEX);
}
/**
 * This procedure generates the 'fingerprint' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genFingePrint(RecordSoggetto *pRecord){
    genArray(DIM_FINGPRINT, pRecord->fingerprint,ALPHANUM_NSP);
}
/**
 * This function generates a number between 'valMin' and 'valMax' of a 'p' Precision (defined in basedata.h)
 * @param vMin Minimum value generated
 * @param vMax Maximum value generated
 * @param p Decimal precision
 * @return value generated
 */
double genValue(double vMin, double vMax, Precision p){
    return ((long int) (vMin * p) + rand() % (long int) ((vMax - vMin) * p + 1)) / (double) p;
}
/**
 * This procedure fills an array 'arr' with randomly generated values
 * @param aSize Dimension of the array 'arr'
 * @param arr Array to fill
 * @param c type of char allowed
 */
void genArray(int aSize, char arr[], CharType c) {
    int i;
    char rndChar; // random char

    switch(c){
        case HEX:
            for(i=0; i < aSize;) {
                rndChar = '0' + rand() % 'z'; // Generates a random char between '0' and 'z'
                if (isNumHex(rndChar)) {
                    arr[i] = rndChar;
                    i++;
                }
            }
            break;
        case ALPHANUM_NSP:
            for(i=0; i < aSize;) {
                rndChar = '0' + rand() % 'z'; // Generates arr random char between '0' and 'z'
                if (isAlphanum(rndChar)) {
                    arr[i] = rndChar;
                    i++;
                }
            }
            break;
        default:
            printf("Tipo carattere non ammesso in un array");
            break;
    }
}
/**
 * This procedure generates the 'HairLength' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genHairLength(RecordSoggetto *pRecord){
    int rndVal;

    do{ // at this stage this program allows just two values for the beard
        rndVal=(int)genValue(FST_HAIR_VAL, LST_HAIR_VAL,UNITS);
    } while (checkStatusValue(rndVal));

    pRecord->Status=rndVal;
}
/**
 * This procedure randomly generates the 'beard' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genBeard(RecordSoggetto *pRecord){
    int rndVal;

    do{ // at this stage this program allows just two values for the beard
        rndVal=(int)genValue(FST_BEARD_VAL, LST_BEARD_VAL,UNITS);
    } while (checkStatusValue(rndVal));

    pRecord->Status=rndVal;
}
/**
 * This procedure randomly selects a string from an array 'residencyDB' and copies it
 * on a 'residency' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genResidency(RecordSoggetto *pRecord){
    char residencyDB[][DIM_RESIDENCY]={"Via Gramsci 84 09100 Cagliari",
                                       "Via della resistenza 45 20100 Milano",
                                       "Piazza Primo Maggio 68 00199 Roma",
                                       "Largo Berlinguer 50 07100 Sassari",
                                       "Corso Grazia Deledda 74 08100 Nuoro"};

    strcpy(pRecord->residency, residencyDB[rand() % (sizeof(residencyDB) / DIM_RESIDENCY)]);
}
/**
 * This procedure randomly generates the 'Position' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genGpsPos(RecordSoggetto *pRecord){
    pRecord->Position.lat=genValue(LAT_MIN, LAT_MAX, MICRO); // Generates the latitude
    pRecord->Position.lon=genValue(LON_MIN, LON_MAX, MICRO); // Generates the longitude
}
/**
 * This procedure randomly generates the 'Status' member of a variable RecordSoggetto
 * @param pRecord Pointer to a variable RecordSoggetto
 */
void genStatus(RecordSoggetto *pRecord){
    int rndVal;

    do{
        rndVal=(int)genValue(FST_STATUS_VAL, LST_STATUS_VAL,UNITS);
    } while (checkStatusValue(rndVal));

    pRecord->Status=rndVal;
}