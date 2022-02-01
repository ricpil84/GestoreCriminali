//
// Created by riccardo on 03/01/22.
//
#include "filemanipulation.h"

/**
 * This procedure reads the stdin for a filename
 * @param filename filename entered
 */
void scanForFilename(char filename[]){
    _Bool isTooLong;

    printf("\nInserisci il nome del file da salvare");
    do {
        isTooLong=false;
        printf("\n> ");
        scanf("%s",filename);
        if(strlen(filename) > FILENAMEMAX) {
            isTooLong = true;
            printf("\nIl nome del file inserito contiene troppi caratteri");
        }
    } while(isTooLong);
}
/**
 * This function asks the user for overwrite confirmation when a filename exist
 * @param filename name of the file
 * @param mode file opening mode
 * @return file pointed to
 */
FILE *overwriteFile(char filename[],char mode[]){
    FILE *fp;
    _Bool isInsWrong;
    char ins;

    printf("\nIl file selezionato e' esistente, vuoi sovrascrivere? [S/n]\n> ");
    do{
        scanf("%c",&ins);
        emptyBuffer();
        if(ins=='S'||ins=='s') {
            fp=fopen(filename, mode);
            isInsWrong = false;
        } else if(ins=='N'||ins=='n') {
            printf("\nSi e' scelto di non sovrascrivere il file");
            isInsWrong = false;
            return NULL;
        } else
            printf("\ninserisci una risposta corretta\n> ");
    }while(isInsWrong);
    return fp;
}
/**
 * This procedure creates a new file text or binary
 * @param fp pointer to a file pointer
 * @param fileName name of the file
 * @param fm type of file [TXT,BIN]
 */
void createNewFile(FILE **fp, char fileName[], FileMode fm) {
    char openmode[MODESIZE];
    char writemode[MODESIZE];

    switch(fm){
        case TXT:
            strcpy(openmode,"r");
            strcpy(writemode,"w");
            break;
        case BIN:
            strcpy(openmode,"rb");
            strcpy(writemode,"wb");
            break;
        default:
            exitError("!!!Modalita' lettura/scrittura file non riconosciuta");
    };

    if(NULL!=fopen(fileName,openmode)) // true if the filename exist
        *fp=overwriteFile(fileName,writemode);
    else {
        *fp=fopen(fileName,writemode);
    }
}
/**
 * This procedure exits the program when a pointer is NULL
 * @param p pointer
 * @param t type of pointer
 */
void exitIfpNull(void *p,ErrorType t){
    if(p==NULL) {
        printf("\n!!!USCITA DEL PROGRAMMA!!!");
        switch (t) {
            case FP:
                printf("\nImpossibile aprire il file");
                break;
            case MP:
                printf("\nImpossibile allocare la memoria");
                break;
            default:
                printf("\nProblema non identificato");
                break;
        };
        exit(-1);
    }
}
/**
 * This function asks for overwrite confirmation when a file exist
 * @param filename name of the file
 * @param mode write mode
 * @return pointer to the file to manipulate
 */
void freadTxt(FILE *fp,RecordSoggetto *pPers){
    freadName(fp,pPers);
    freadSurname(fp,pPers);
    freadHeight(fp,pPers);
    freadWeight(fp,pPers);
    freadEyesColor(fp,pPers);
    freadHairColor(fp,pPers);
    freadHairLength(fp,pPers);
    freadBeard(fp,pPers);
    freadFingerprint(fp,pPers);
    freadResidency(fp,pPers);
    fscanf(fp, "\nPosizione: LAT %lf LON %lf", &pPers->Position.lat, &pPers->Position.lon);
    freadStatus(fp,pPers);
    fscanf(fp,"\n");
}
/**
 * This procedure reads a string from a file and saves it in a array of chars
 * @param bSize size of the array 'str'
 * @param str array of chars
 * @param fp pointer to the file to read
 */
void freadString(int bSize, char str[], FILE *fp){
    char buffer[bSize];
    fscanf(fp, "%[^\n]%*c", buffer);
    strcpy(str, buffer);
}
/**
 * This procedure reads a value from a file and saves it on a variable
 * @param fp pointer to the file to read
 * @return returns the value read
 */
double freadValue(FILE *fp){
    char buffer[DIM_VALUE_BUFFER];
    double value;
    fscanf(fp,"%[^\n]%*c",buffer);
    strToValue(buffer,&value);
    return value;
}
/**
 * This procedure reads the name member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadName(FILE *fp, RecordSoggetto *pRecord){
    fscanf(fp, "\nNome: ");
    freadString(sizeof(pRecord->name), pRecord->name, fp);
}
/**
 * This procedure reads the surname member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadSurname(FILE *fp, RecordSoggetto *pRecord){
    fscanf(fp, "\nCognome: ");
    freadString(sizeof(pRecord->surname), pRecord->surname, fp);
}
/**
 * This procedure reads the height member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadHeight(FILE *fp, RecordSoggetto *pRecord){
    fscanf(fp, "\nAltezza: ");
    pRecord->height=(int)freadValue(fp);
}
/**
 * This procedure reads the weight member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadWeight(FILE *fp, RecordSoggetto *pRecord){
    fscanf(fp, "\nPeso: ");
    pRecord->weight=(float)freadValue(fp);
}
/**
 * This procedure reads the eyesColor member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadEyesColor(FILE *fp, RecordSoggetto *pRecord){
    int i;
    fscanf(fp, "\nColore occhi: ");
    for(i=0;i<DIM_EYESC;i++)
        fscanf(fp,"%c",&pRecord->eyesColor[i]);
}
/**
 * This procedure reads the hairColor member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadHairColor(FILE *fp, RecordSoggetto *pRecord) {
    int i;
    fscanf(fp, "\nColore capelli: ");
    for(i=0;i<DIM_HAIRC;i++)
        fscanf(fp,"%c",&pRecord->hairColor[i]);
}
/**
 * This procedure reads the hairLength member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadHairLength(FILE *fp,RecordSoggetto *pRecord){
    char buffer[DIM_ENUM_BUFFER];

    fscanf(fp, "\nLunghezza capelli: ");
    fscanf(fp, "%[^\n]%*c", buffer);
    if(!strcmp(buffer, "lunghi"))
        pRecord->HairLength=LUNGHI;
    else if(!strcmp(buffer, "medi"))
        pRecord->HairLength=MEDI;
    else if(!strcmp(buffer, "corti"))
        pRecord->HairLength=CORTI;
    else if(!strcmp(buffer, "altro"))
        pRecord->HairLength=ALTRO;
    else
        exitError("\n!!! Il tipo letto non e' stato definito");
}
/**
 * This procedure reads the beard member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadBeard(FILE *fp, RecordSoggetto *pRecord){
    char buffer[DIM_BEARD_BUFFER];
    fscanf(fp, "%[^\n]%*c", buffer);
    if(!strcmp(buffer, "Il soggetto non ha la barba"))
        pRecord->beard=false;
    else if(!strcmp(buffer, "Il soggetto ha la barba"))
        pRecord->beard=true;
    else
        exitError("\n!!!Il tipo letto non e' stato definito");
}
/**
 * This procedure reads the fingerprint member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadFingerprint(FILE *fp, RecordSoggetto *pRecord){
    int i;
    fscanf(fp, "\nImpronta digitale: ");
    for(i=0;i<DIM_FINGPRINT;i++)
        fscanf(fp,"%c",&pRecord->fingerprint[i]);

}
/**
 * This procedure reads the residency member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadResidency(FILE *fp, RecordSoggetto *pRecord){
    fscanf(fp, "\nResidenza: ");
    freadString(sizeof(pRecord->residency), pRecord->residency, fp);
}
/**
 * This procedure reads the status member of a struct RecordSoggetto from a file and
 * saves it on a variable RecordSoggetto
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void freadStatus(FILE *fp, RecordSoggetto *pRecord){
    char buffer[DIM_ENUM_BUFFER];

    fscanf(fp,"\nStato soggetto: ");
    fscanf(fp, "%[^\n]%*c", buffer);
    if(!strcmp(buffer, "libero"))
        pRecord->Status=LIBERO;
    else if(!strcmp(buffer, "ricercato"))
        pRecord->Status=RICERCATO;
    else if(!strcmp(buffer, "in arresto"))
        pRecord->Status=IN_ARRESTO;
    else if(!strcmp(buffer, "evaso"))
        pRecord->Status=EVASO;
    else
        exitError("\n!!!Il tipo letto non e' stato definito");
}
/**
 * This reads a struct RecordSoggetto and saves its members on a file
 * @param fp pointer to the file
 * @param pRecord pointer to a struct RecordSoggetto
 */
void fprintTxt(FILE *fp, RecordSoggetto *pRecord){
    fprintf(fp, "\nNome: %s", pRecord->name);
    fprintf(fp, "\nCognome: %s", pRecord->surname);
    fprintf(fp, "\nAltezza: %d", pRecord->height);
    fprintf(fp, "\nPeso: %.2f", pRecord->weight);
    fprintEyesColor(fp, pRecord);
    fprintHairColor(fp, pRecord);
    fprintHairLength(fp, pRecord);
    fprintBeard(fp, pRecord);
    fprintFingerprint(fp, pRecord);
    fprintf(fp, "\nResidenza: %s", pRecord->residency);
    fprintf(fp, "\nPosizione: LAT %.6lf LON %.6lf", pRecord->Position.lat, pRecord->Position.lon);
    fprintStatus(fp, pRecord);
}
/**
 * This procedure reads an array of chars and saves it on a file
 * @param aSize 'array' size
 * @param fp pointer to the file
 * @param array array to read
 */
void fprintArray(int aSize, FILE *fp, char array[]){
    int i;
    for(i=0;i<aSize;i++){
        fprintf(fp,"%c",array[i]);
    }
}
/**
 * This procedure reads the eyesColor member of a struct RecordSoggetto and saves it on a file
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void fprintEyesColor(FILE *fp, RecordSoggetto *pRecord){
    fprintf(fp,"\nColore occhi: ");
    fprintArray(DIM_EYESC, fp, pRecord->eyesColor);
}
/**
 * This procedure reads the hairColor member of a struct RecordSoggetto and saves it on a file
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void fprintHairColor(FILE *fp, RecordSoggetto *pRecord){
    fprintf(fp,"\nColore capelli: ");
    fprintArray(DIM_HAIRC, fp, pRecord->hairColor);
}
/**
 * This procedure reads the hairLength member of a struct RecordSoggetto and saves it on a file
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void fprintHairLength(FILE *fp, RecordSoggetto *pRecord){
    switch(pRecord->HairLength){
        case LUNGHI:
            fprintf(fp,"\nLunghezza capelli: lunghi");
            break;
        case MEDI:
            fprintf(fp,"\nLunghezza capelli: medi");
            break;
        case CORTI:
            fprintf(fp,"\nLunghezza capelli: corti");
            break;
        case ALTRO:
            fprintf(fp,"\nLunghezza capelli: altro");
            break;
        default:
            exitError("\n!!! Il tipo letto non e' stato definito");
    };
}
/**
 * This procedure reads the beard member of a struct RecordSoggetto and saves it on a file
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void fprintBeard(FILE *fp, RecordSoggetto *pRecord){
    switch((BeardValue)pRecord->beard) {
        case FALSE:
            fprintf(fp,"\nIl soggetto ha la barba");
            break;
        case TRUE:
            fprintf(fp,"\nIl soggetto non ha la barba");
            break;
        default:
            exitError("\n!!!Il tipo letto non e' stato definito");
    };
}
/**
 * This procedure reads the fingerprint member of a struct RecordSoggetto and saves it on a file
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void fprintFingerprint(FILE *fp, RecordSoggetto *pRecord){
    fprintf(fp,"\nImpronta digitale: ");
    fprintArray(DIM_FINGPRINT, fp, pRecord->fingerprint);
}
/**
 * This procedure reads the status member of a struct RecordSoggetto and saves it on a file
 * @param fp pointer to the file
 * @param pRecord pointer to the variable RecordSoggetto
 */
void fprintStatus(FILE *fp, RecordSoggetto *pRecord){
    switch(pRecord->Status){
        case LIBERO:
            fprintf(fp,"\nStato soggetto: libero");
            break;
        case RICERCATO:
            fprintf(fp,"\nStato soggetto: ricercato");
            break;
        case IN_ARRESTO:
            fprintf(fp,"\nStato soggetto: in arresto");
            break;
        case EVASO:
            fprintf(fp,"\nStato soggetto: evaso");
            break;
        default:
            exitError("\n!!!Il tipo letto non e' stato definito");
    };
}