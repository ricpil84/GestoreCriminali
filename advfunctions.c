//
// Created by riccardo on 03/01/22.
//
#include "advfunctions.h"

/**
 * This procedure prints the content of an arr RecordSoggetto
 * @param size size of the array 'arr'
 * @param arr array RecordSoggetto
 */
void stampaElencoCriminali (const int aSize, const RecordSoggetto arr[]) {
    int i;

    if(arr!=NULL) {
        for (i = 0; i < aSize; i++) {
            printf("\nStampa soggetto n%d", i + 1);
            stampaRecord(&arr[i]);
        }
    } else
        printf("\nLista record non trovata");
}
/**
 * This procedure deletes [setting all its members to 0] a field of an array RecordSoggetto 'arr' given its index
 * @param index Position to delete
 * @param aSize dimension of the array 'arr'
 * @param arr array RecordSoggetto
 */
void eliminaCriminale (int index, int *aSize, RecordSoggetto arr[]){
    RecordSoggetto eRecord = {0}; // initializes a var eRecord to 0
    int i;

    index--;

    if(index < *aSize && index >= 0) {
        copyRecord(&arr[index], &eRecord);
        (*aSize)--;
    }
    else
        printf("\nE' stato inserito un indice inesistente");
}
/**
 * This procedure randomly generates an array RecordSoggetto 'arr'
 * @param d dimension of the array 'arr'
 * @param arr array RecordSoggetto
 */
void generaDati (const int aSize, RecordSoggetto arr[]){
    int i;

    for(i=0;i<aSize;i++)
        arr[i] = generaRecord();
}
/**
 * This procedure calls the procedure heapSort [source: https://en.wikipedia.org/wiki/Heapsort] to sort an array
 * RecordSoggetto 'aRecord' alphabetically
 * @param aRecord array RecordSoggetto
 */
void ordinaAlfabeticamente (const int aSize, RecordSoggetto aRecord[]){
    if(aRecord!=NULL)
        heapSort(aSize, aRecord);
    else
        printf("\nLista record non trovata");
}
/**
 * This procedure ciphers every field's member name and surname of an array RecordSoggetto 'arr'
 * @param aSize dimension of the array 'aRecord'
 * @param aRecord array RecordSoggetto
 */
void criptaVettore (const int aSize, RecordSoggetto aRecord[]){
    int i=aSize;
    if(aRecord!=NULL) {
        while (i >= 0) {
            cipherStr(aRecord[i].name);
            cipherStr(aRecord[i].surname);
            i--;
        }
    } else
        printf("\nLista record non trovata!");
}
/**
 * This procedure deciphers every field's member name and surname of an array RecordSoggetto 'arr'
 * @param aSize dimension of the array 'aRecord'
 * @param aRecord array RecordSoggetto
 */
void decriptaVettore (const int aSize, RecordSoggetto aRecord[]){
    int i=aSize;

    if(aRecord!=NULL) {
        while (i >= 0) {
            decipherStr(aRecord[i].name);
            decipherStr(aRecord[i].surname);
            i--;
        }
    } else
        printf("\nLista record non trovata");
}