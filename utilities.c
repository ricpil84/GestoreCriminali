//
// Created by riccardo on 03/01/22.
//
#include "utilities.h"
/**
 * This procedure copies a char array 'src' into a new char array 'dest'
 * @param size size of the arrays
 * @param src Source array
 * @param dest Destination array
 */
void copyArray(const int size, char dest[], const char src[]) {
    int i;
    for(i=0; i < size; i++)
        dest[i]=src[i];
}
/**
 * This procedure copies a variable RecordSoggetto 'pSrc' into a variable RecordSoggetto 'pDest'
 * @param pDest pointer to the destination variable
 * @param pSrc pointer to the source variable
 */
void copyRecord (RecordSoggetto *pDest, RecordSoggetto *pSrc){
    strcpy(pDest->name, pSrc->name);
    strcpy(pDest->surname, pSrc->surname);
    pDest->height=pSrc->height;
    pDest->weight=pSrc->weight;
    copyArray(sizeof(pDest->eyesColor), pDest->eyesColor, pSrc->eyesColor);
    copyArray(sizeof(pDest->hairColor), pDest->hairColor, pSrc->hairColor);
    pDest->HairLength=pSrc->HairLength;
    pDest->beard=pSrc->beard;
    copyArray(sizeof(pDest->fingerprint), pDest->fingerprint, pSrc->fingerprint);
    strcpy(pDest->residency, pSrc->residency);
    pDest->Position.lat=pSrc->Position.lat;
    pDest->Position.lon=pSrc->Position.lon;
    pDest->Status=pSrc->Status;
}
/**
 * This procedure swaps two variables RecordSoggetto
 * @param pFstRecord pointer to the first variable
 * @param pSecRecord pointer to the second variable
 */
void swapRecord(RecordSoggetto *pFstRecord, RecordSoggetto *pSecRecord){
    RecordSoggetto temp;

    copyRecord(&temp, pFstRecord);
    copyRecord(pFstRecord, pSecRecord);
    copyRecord(pSecRecord, &temp);
}
/**
 * This function converts a string into a value
 * @param str string to convert
 * @param pValue pointer to the variable that will contain the converted value
 * @return true when the string can be converted
 */
_Bool strToValue (const char str[], double *pValue ){
    int i, j;
    int decPlaces, intPlaces; //! counters to decimal and integer places of the value
    _Bool isNumNegative;

    *pValue=0; //! initialises the value variable

    /*! converts a string into a value !*/
    if(isStrConvertible(&decPlaces,&intPlaces,&isNumNegative,str)){
        if(isNumNegative)
            i=1;
        else
            i=0;
        for (j=intPlaces; i < intPlaces; i++) { //! for every integer sets the corresponding value
            *pValue += (pow(10, j - 1) * (str[i] - '0'));
            j--;
        }
        for (i = intPlaces + 1, j = 1; i <= decPlaces + intPlaces; j++, i++) //! for every decimal place sets the...
            *pValue += (pow(10, -j) * (str[i] - '0'));                       //! ... corresponding value

        if(isNumNegative)
            *pValue *= -1;
        return true;
    } else
        return false;
}
/**
 * This function compares the surname and name members of two variables RecordSoggetto
 * @param type ComparisonType [at this stage of development '\<' (MIN) is the only value implemented]
 * @param pFstElm pointer to the first variable
 * @param pSecElm pointer to the second variable
 * @return true when the condition ('pFstElm' comp 'pSecElm') checked is true
 */
_Bool compFullName(ComparisonType type, RecordSoggetto *pFstElm, RecordSoggetto *pSecElm) {
    int i=0;

    switch (type) {
        case MIN:
            /*! it will consider empty strings the biggest value !*/
            if(pSecElm->surname[0]=='\0')
                return true;
            else if(pFstElm->surname[0]=='\0')
                return false;

            while (pFstElm->surname[i] == pSecElm->surname[i] && pFstElm->surname[i + 1] != '\0')
                i++;

            if (pFstElm->surname[i] < pSecElm->surname[i])
                return true;
            else if (pFstElm->surname[i + 1] == '\0') {
                i = 0;
                while (pFstElm->name[i] == pSecElm->name[i] && pFstElm->name[i + 1] != '\0')
                    i++;

                if (pFstElm->name[i] < pSecElm->name[i])
                    return true;
            }
            return false;
    }
}
/**
 * This function clears the stdin buffer
 * @return the number of unread characters
 */
int emptyBuffer () {
    int c = 0;
    while(getchar()!='\n') //! stops when getchar() finds '\n'
        c++;
    return c;
}
/**
 * This procedure executes the command to clear the terminal
 */
void clearScreen(){
#ifdef __linux__
    system("clear");
#elif __APPLE__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}