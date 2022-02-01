//
// Created by riccardo on 03/01/22.
//
#include "extrafunctionalities.h"

/**
 * This procedure saves an array RecordSoggetto into a binary file
 * @param aSize size of the array
 * @param aRecord array to save
 * @param fileName name of the binary file [without extension]
 */
void saveBinArray(const int aSize, const RecordSoggetto aRecord[], char fileName[]) {
    FILE *fp;

    createNewFile(&fp, fileName, BIN);
    if(fp!=NULL) {
        fwrite(aRecord, sizeof(RecordSoggetto), aSize, fp);
        fclose(fp);
    } else
        printf("Errore! Impossibile creare il file scelto");
}
/**
 * This procedure saves an array RecordSoggetto into a txt file
 * @param aSize size of the array
 * @param aRecord array to save
 * @param fileName name of the txt file [without extension]
 */
void saveTxtArray(const int aSize, RecordSoggetto aRecord[], char fileName[]) {
    FILE *fp;
    int i;

    createNewFile(&fp, fileName, TXT);
    if(fp!=NULL) {
        for (i = 0; i < aSize; i++) {
            if (i != 0)
                fprintf(fp, "\n");
            fprintf(fp, "Soggetto n.%d", i + 1);
            fprintTxt(fp, &aRecord[i]);
            fprintf(fp, "\n");
        }
        fclose(fp);
    } else
        printf("Errore! Impossibile creare il file scelto");
}
/**
 * This function reads a content from a binary file and saves on an array RecordSoggetto
 * @param fileName name of the binary file [without extension]
 * @return pointer to an array RecordSoggetto
 */
RecordSoggetto* readBinArray(char fileName[]){
    RecordSoggetto *arrayPers;
    long fileSize;
    FILE *fp=fopen(fileName,"rb");

    if(fp!=NULL) {
        fseek(fp, 0, SEEK_END);
        fileSize = ftell(fp);
        rewind(fp);
        arrayPers = (RecordSoggetto *) malloc(fileSize);
        if(arrayPers!=NULL) {
            fread(arrayPers, sizeof(RecordSoggetto), fileSize / sizeof(RecordSoggetto), fp);
            fclose(fp);
            return arrayPers;
        } else
            printf("\nErrore nell'allocazione della memoria");
    } else
        printf("\nFile non trovato");
}
/**
 * This function reads a content from a text file and saves on an array RecordSoggetto
 * @param fileName name of the txt file [without extension]
 * @return pointer to an array RecordSoggetto
 */
RecordSoggetto* readTxtArray(char fileName[]){
    FILE *fp=fopen(fileName,"r");
    if(fp!=NULL) {
        RecordSoggetto *pRecord;
        int i;

        scanForFilename(fileName);
        pRecord = (RecordSoggetto *) malloc(sizeof(RecordSoggetto));
        if(pRecord!=NULL) {
            exitIfpNull(pRecord, MP);
            while (!feof(fp)) {
                fscanf(fp, "Soggetto n.%d", &i);
                if (i > 1) {
                    pRecord = (RecordSoggetto *) realloc(pRecord, i * sizeof(RecordSoggetto));
                    exitIfpNull(pRecord, MP);
                }
                i--;
                freadTxt(fp, &pRecord[i]);
            };
            fclose(fp);
            return pRecord;
        } else
            printf("\nErrore nell'allocazione della memoria");
    } else
        printf("\nFile non trovato");
}