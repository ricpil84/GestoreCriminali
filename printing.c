//
// Created by riccardo on 03/01/22.
//
#include "printing.h"

/**
 * This procedure prints an array 'arr'
 * @param aSize size of 'arr'
 * @param header header
 * @param arr array to print
 */
void printArray(const int aSize , const char header[], const char arr[]){
    int i;

    printf("%s", header);
    for(i=0; i < aSize; i++)
        printf("%c", arr[i]);
}
/**
 * This procedure prints a string for the constant 't' defined in TipoCapelli
 * @param t TipoCapelli constant
 */
void printHairLength(TipoCapelli t) {
    switch (t) {
        case CORTI:
            printf("\nTipo capelli: Corti");
            break;
        case MEDI:
            printf("\nTipo capelli: Medi");
            break;
        case LUNGHI:
            printf("\nTipo capelli: Lunghi");
            break;
        case ALTRO:
            printf("\nTipo capelli: Altro");
            break;
        default:
            printf("Stampa non definita");
            break;
    }
}
/**
 * This procedure prints a string for the constant 'b' defined in BeardValue
 * @param b BeardValue constant
 */
void printBeard(BeardValue b){
    switch(b){
        case FALSE:
            printf("\nIl soggetto ha la barba: no");
            break;
        case TRUE:
            printf("\nIl soggetto ha la barba: si");
            break;
        default:
            printf("Stampa non definita");
    }
}
/**
 * This procedure prints a string for the constant 's' defined in StatoSoggetto
 * @param s StatoSoggetto constant
 */
void printStatus(StatoSoggetto s){
    switch(s) {
        case LIBERO:
            printf("\nStato attuale: Libero");
            break;
        case RICERCATO:
            printf("\nStato attuale: Ricercato");
            break;
        case IN_ARRESTO:
            printf("\nStato attuale: In arresto");
            break;
        case EVASO:
            printf("\nStato attuale: Evaso");
            break;
        default:
            printf("Stampa non definita");
    }
}
