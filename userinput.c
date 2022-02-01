//
// Created by riccardo on 03/01/22.
//
#include "userinput.h"
/**
 * This procedure reads an array of chars from the stdin
 * @param aSize size of the 'aChars'
 * @param aChars array of chars
 * @param fSize size of the format
 * @param t type of chars allowed in the string
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanCharArray(int aSize, char aChars[], int fSize, CharType t, _Bool *abortFlag) {
    char format[fSize]; // format of the string to read
    char buffer[aSize]; // user input
    _Bool isInsWrong = true;
    _Bool isString = true;
    _Bool setSpace = checkFormat(t, &isString); // sets setSpace and endStr

    setFormat(aSize, format, setSpace);

    /* scans a string from the stdin while it'll contain values not allowed */
    do {
        printf("\n> ");
        scanf(format,buffer);
        emptyBuffer();

        if(strcmp(buffer,"exit")!=0){
            if(isString) // check if '\0' is needed and sets string's dimension
                aSize = strlen(buffer);
            if(checkString(aSize, buffer, t))
                isInsWrong=false;
            else
                printf("\nAttenzione la serie di caratteri inserita non e' ammessa"
                       "\nriprova oppure inserisci \"exit\" per uscire");
        } else {
            printf("\nInserimento cancellato, uscita...");
            *abortFlag=true;
            isInsWrong=false;
        }
    } while(isInsWrong);

    if(!*abortFlag)
        copyArray(aSize + isString, (char *) aChars, (char *) buffer); // copies buffer into string
}
/**
 * This function reads a string from the stdin and returns a corresponding value
 * @param min min value allowed
 * @param max max value allowed
 * @param p decimal precision of the value
 * @param abortFlag sets a flag for the abortion of the data entry
 * @return the converted value
 */
double scanValue(const double min, const double max, Precision p, _Bool *abortFlag) {
    double value=0;
    char buffer[DIM_BUFFER_VALUE];
    _Bool isInsWrong;

    /*! scans a string from the stdin while it'll contain values not allowed !*/
    do {
        isInsWrong = true;
        printf("\n> ");
        scanf("%s", buffer);
        emptyBuffer();

        /*! if the user typed "exit" stops the iteration !*/
        if(strcmp(buffer,"exit")!=0) {
            if (strToValue(buffer, &value)) { //! true when buffer can be converted into a value
                if ((int) (value * p) > (int) (max * p)) //! checks if values are allowed
                    printf("E' stato inserito un valore non ammesso\n\"exit\" per annullare l'inserimento");
                else if ((int) (value * p) < (int) (min * p))
                    printf("E' stato inserito un valore non ammesso\n\"exit\" per annullare l'inserimento");
                else
                    isInsWrong = false;
            } else
                printf("\nAttenzione valore inserito non e' ammesso"
                       "\nriprova oppure inserisci \"exit\" per uscire");
        } else {
            printf("\nInserimento cancellato, uscita...");
            *abortFlag=true;
            return 0;
        }
    } while(isInsWrong);

    return value;
}
/**
 * This procedure reads a string from the stdin and saves it in the 'name' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanName(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci il nome: [Max %d caratteri]"
           "\noppure inserisci \"exit\" per uscire", DIM_NAME);
    scanCharArray(DIM_NAME, pRecord->name, DIM_FORMAT_SP, ALPHA_SP, abortFlag);
}
/**
 * This procedure reads a string from the stdin and saves it in the 'surname' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanSurname(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci il cognome: [Max %d caratteri]"
           "\noppure inserisci \"exit\" per uscire", DIM_SURNAME);
    scanCharArray(DIM_SURNAME, pRecord->surname, DIM_FORMAT_SP, ALPHA_SP, abortFlag);
}
/**
 * This procedure reads a value from the stdin and saves it in the 'height' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanHeight(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci l'altezza: [Min: %d|Max: %d - I decimali saranno scartati]"
           "\noppure inserisci \"exit\" per uscire",HEIGHT_MIN,HEIGHT_MAX);
    pRecord->height=(int) scanValue(HEIGHT_MIN, HEIGHT_MAX, UNITS, abortFlag);
}
/**
 * This procedure reads a value from the stdin and saves it in the 'weight' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanWeight(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci il peso: [Min: %0.2f|Max: %0.2f]"
           "\noppure inserisci \"exit\" per uscire",(float)WEIGHT_MIN,(float)WEIGHT_MAX); // explict cast to float
    pRecord->weight=(float) scanValue(WEIGHT_MIN, WEIGHT_MAX, CENTI, abortFlag);
}
/**
 * This procedure reads a string from the stdin and saves it in the 'eyesColor' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanEyesColor(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci il colore degli occhi: [%d valori hex]"
           "\noppure inserisci \"exit\" per uscire", DIM_EYESC);
    scanCharArray(DIM_EYESC, pRecord->eyesColor, DIM_FORMAT_NSP, HEX, abortFlag);
}
/**
 * This procedure reads a string from the stdin and saves it in the 'hairColor' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanHairColor(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci il colore dei capelli: [%d valori hex]"
           "\noppure inserisci \"exit\" per uscire", DIM_HAIRC);
    scanCharArray(DIM_HAIRC, pRecord->hairColor, DIM_FORMAT_NSP, HEX, abortFlag);
}
/**
 * This procedure reads a value from the stdin and saves it in the 'HairLength' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanHairLength(RecordSoggetto *pRecord, _Bool *abortFlag) {
    _Bool isInsWrong;
    int type;

    *abortFlag=false;

    printf("\nInserisci un valore per la lunghezza dei capelli:" // prints the menu
           "\n%d\tper corti"
           "\n%d\tper medi"
           "\n%d\tper lunghi"
           "\n%d\tper altro"
           "\n\"exit\" per uscire", CORTI, MEDI, LUNGHI, ALTRO);

    /* scans a value from the stdin while it'll be a value not allowed */
    do {
        type=(int)scanValue(CORTI,ALTRO,UNITS,abortFlag);
        isInsWrong=checkHairType(type);

        if(isInsWrong&&*abortFlag)
            printf("\nAttenzione il valore inserito non e' stato definito"
                   "\nriprova oppure inserisci \"exit\" per uscire");
    } while(isInsWrong);

    if(!*abortFlag)
        pRecord->HairLength=type;
}
/**
 * This procedure reads a value from the stdin and saves it in the 'beard' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanBeard(RecordSoggetto *pRecord, _Bool *abortFlag) {
    _Bool isInsWrong;
    int beard;

    printf("\nInserisci un valore per la barba:" // prints a menu
           "\n%d\tper soggetto senza barba"
           "\n%d\tper soggetto con barba"
           "\n\"exit\" per uscire", false, true);

    /* scans a value from the stdin while it'll be a value not allowed */
    do {
        beard= (int) scanValue(FALSE,TRUE,UNITS,abortFlag);
        isInsWrong=checkBeardValue(beard);
        if(isInsWrong&&*abortFlag)
            printf("\nAttenzione valore inserito non e' stato definito"
                   "\nriprova oppure inserisci \"exit\" per uscire");
    } while(isInsWrong);

    pRecord->beard=beard;
}
/**
 * This procedure reads a string from the stdin and saves it in the 'fingerprint' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanFingerprint(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci l'impronta digitale: [%d caratteri alfanumerici]"
           "\noppure inserisci \"exit\" per uscire", DIM_FINGPRINT);
    scanCharArray(DIM_FINGPRINT, pRecord->fingerprint, DIM_FORMAT_NSP, ALPHANUM_NSP, abortFlag);
}
/**
 * This procedure reads a string from the stdin and saves it in the 'residency' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanResidency(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci la residenza: [Max %d caratteri]"
           "\noppure inserisci \"exit\" per uscire",DIM_RESIDENCY);
    scanCharArray(DIM_RESIDENCY, pRecord->residency, DIM_RESIDENCY, ALPHANUM_SP, abortFlag);
}
/**
 * This procedure reads two values from the stdin and saves them in the 'Position' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanPosition(RecordSoggetto *pRecord, _Bool *abortFlag) {
    printf("\nInserisci la latitudine: [Min: %.6f|Max: %.6f]"
           "\noppure inserisci \"exit\" per uscire",(double)LAT_MIN,(double)LAT_MAX);
    pRecord->Position.lat= scanValue(LAT_MIN, LAT_MAX, MICRO, abortFlag); //! scans a value for the latitude
    printf("\nInserisci la longitudine: [Min: %.6f|Max: %.6f]"
           "\noppure inserisci \"exit\" per uscire",(double)LON_MIN,(double)LON_MAX);
    pRecord->Position.lon= scanValue(LON_MIN, LON_MAX, MICRO, abortFlag); //! scans a value for the longitude
}
/**
 * This procedure reads a value from the stdin and saves it in the 'status' member of a struct RecordSoggetto
 * @param pRecord pointer to a variable RecordSoggetto
 * @param abortFlag sets a flag for the abortion of the data entry
 */
void scanStatus(RecordSoggetto *pRecord, _Bool *abortFlag) {
    _Bool isInsWrong;
    int status;

    printf("\nStato:" // prints a menu
           "\n%d\tper libero"
           "\n%d\tper ricercato"
           "\n%d\tper in arresto"
           "\n%d\tper evaso"
           "\n\"exit\" per uscire", LIBERO, RICERCATO, IN_ARRESTO, EVASO);

    /* scans a value from the stdin while it'll be a value not allowed */
    do {
        status=(int) scanValue(LIBERO,EVASO,UNITS,abortFlag);
        isInsWrong=checkStatusValue(status);
        if(isInsWrong&&*abortFlag)
            printf("\nAttenzione il valore inserito non e' stato definito"
                   "\nriprova oppure inserisci \"exit\" per uscire");
    } while(isInsWrong);

    pRecord->Status=status;
}
/**
 * This procedure sets a format for the acquisition of the strings
 * @param size size of the strings to scan
 * @param format format of the string
 * @param haveSpace true if spaces are admitted
 */
void setFormat (const int size, char format[], const _Bool haveSpace ) {
    if(haveSpace) // check if spaces are allowed
        sprintf(format, "%%%d[^\n]haveSpace", size);
    else
        sprintf(format, "%%%ds", size);
}
