//
// Created by riccardo on 06/01/22.
//
#include "uimenus.h"
/**
 * This function executes an interactive menu for the manipulation of a dynamically allocated array RecordSoggetto
 */
void mainMenu(){
    RecordSoggetto *pRecord;
    int choice,indexA,indexB;
    int arraySize=0;
    _Bool lastModSaved=false;
    _Bool abortFlag;

    printMainMenu();

    do {
        printf("\nSeleziona una voce > ");
        choice=(int)scanValue(ZERO,NINE,UNITS,&abortFlag);

        switch (choice) {
            case ONE:
                if(inserisciRecordDynamic(&arraySize, &pRecord));
                    lastModSaved=false;
                break;
            case TWO:
                clearScreen();
                printf("\nInserisci la posizione del record da eliminare:\n> ");
                scanf("%d",&indexA);
                if(delRecordDynamic(indexA, &arraySize, pRecord))
                    lastModSaved=false;
                break;
            case THREE:
                clearScreen();
                printf("\nInserisci la posizione del primo record da confrontare:\n> ");
                scanf("%d",&indexA);
                printf("\nInserisci la posizione del secondo record da confrontare:\n> ");
                scanf("%d",&indexB);
                printf("La percentuale di similarità tra i due record selezionati e':\n> "
                       "%d", compElementArray(arraySize,indexA,indexB,pRecord));
                break;
            case FOUR:
                menuPrint(&choice,arraySize,pRecord,&abortFlag,&lastModSaved);
                break;
            case FIVE:
                menuLoadSave(&choice,arraySize,pRecord,&abortFlag,&lastModSaved);
                break;
            case SIX:
                menuCipher(&choice,arraySize,pRecord,&abortFlag,&lastModSaved);
                break;
            case SEVEN:
                ordinaAlfabeticamente(arraySize,pRecord);
                lastModSaved=false;
                break;
            case NINE:
                printMainMenu();
                break;
            case ZERO:
                exitProgramCheck(&lastModSaved,&choice);
                break;
            default:
                printf("\nInserisci una scelta corretta"
                       "\n[9 per ristampare il menu]");
        }
    } while (choice!=0);
}
/**
 * This procedure executes an interactive submenu for the printing functionalities
 * @param choice user's menu choice
 * @param aSize size of the 'arrayRecord'
 * @param arrayRecord dynamically allocated array RecordSoggetto
 * @param abortFlag exit flag
 * @param lastModSaved save status
 */
void menuPrint(int *choice, int aSize, RecordSoggetto arrayRecord[], _Bool *abortFlag, _Bool *lastModSaved){
    int index;
    _Bool previousMenuExit=false;

    printPrintMenu();

    do {
        printf("\nSeleziona una voce > ");
        *choice=(int)scanValue(ZERO,NINE,UNITS,abortFlag);

        switch(*choice){
            case ONE:
                printf("\nInserisci la posizione del record da stampare:\n> ");
                scanf("%d",&index);
                stampaRecord(&arrayRecord[index]);
                break;
            case TWO:
                stampaElencoCriminali(aSize,arrayRecord);
                break;
            case THREE:
                printMainMenu();
                previousMenuExit=true;
                break;
            case NINE:
                printPrintMenu();
                break;
            case ZERO:
                exitProgramCheck(lastModSaved,choice);
                break;
            default:
                printf("\nInserisci una scelta corretta"
                       "\n[9 per ristampare il menu]");
        }
    } while(!previousMenuExit);
}
/**
 * This procedure executes an interactive submenu for the load and save functionalities
 * @param choice user's menu choice
 * @param aSize size of the 'arrayRecord'
 * @param arrayRecord dynamically allocated array RecordSoggetto
 * @param abortFlag exit flag
 * @param lastModSaved save status
 */
void menuLoadSave(int *choice, int aSize, RecordSoggetto arrayRecord[], _Bool *abortFlag, _Bool *lastModSaved){
    _Bool previousMenuExit=false;
    char fileName[FILENAMEMAX+DIM_STRINGTERM];

    printMenuLoadSave();

    do {
        printf("\nSeleziona una voce > ");
        *choice=(int)scanValue(ZERO,NINE,UNITS,abortFlag);

        switch(*choice){
            case ONE:
                printf("\nInserisci il nome del file da caricare\n> ");
                scanForFilename(fileName);
                strcat(fileName,".txt");
                arrayRecord=readTxtArray(fileName);
                *lastModSaved=false;
                break;
            case TWO:
                printf("\nInserisci il nome del file da caricare\n> ");
                scanForFilename(fileName);
                strcat(fileName,".dat");
                arrayRecord=readBinArray(fileName);
                *lastModSaved=false;
            case THREE:
                printf("\nInserisci il nome del file da salvare\n> ");
                scanForFilename(fileName);
                strcat(fileName,".txt");
                saveTxtArray(aSize, arrayRecord, fileName);
                *lastModSaved=true;
                break;
            case FOUR:
                printf("\nInserisci il nome del file da salvare\n> ");
                scanForFilename(fileName);
                strcat(fileName,".dat");
                saveBinArray(aSize, arrayRecord, fileName);
                *lastModSaved=true;
                break;
            case FIVE:
                printMainMenu();
                previousMenuExit=true;
                break;
            case NINE:
                printMenuLoadSave();
                break;
            case ZERO:
                exitProgramCheck(lastModSaved,choice);
                break;
            default:
                printf("\nInserisci una scelta corretta"
                       "\n[9 per ristampare il menu]");
        }
    } while(!previousMenuExit);
}
/**
 * This procedure executes an interactive submenu for the ciphering and deciphering functionalities
 * @param choice user's menu choice
 * @param aSize size of the 'arrayRecord'
 * @param arrayRecord dynamically allocated array RecordSoggetto
 * @param abortFlag exit flag
 * @param lastModSaved save status
 */
void menuCipher(int *choice, int aSize, RecordSoggetto arrayRecord[], _Bool *abortFlag, _Bool *lastModSaved){
    _Bool previousMenuExit=false;
    char fileName[FILENAMEMAX];

    printMenuCipher();

    do {
        printf("\nSeleziona una voce > ");
        *choice=(int)scanValue(ZERO,NINE,UNITS,abortFlag);

        switch(*choice){
            case ONE:
                criptaVettore(aSize,arrayRecord);
                *lastModSaved=false;
                break;
            case TWO:
                decriptaVettore(aSize,arrayRecord);
                *lastModSaved=false;
                break;
            case FIVE:
                printMainMenu();
                previousMenuExit=true;
                break;
            case NINE:
                printMenuCipher();
                break;
            case ZERO:
                exitProgramCheck(lastModSaved,choice);
                break;
            default:
                printf("\nInserisci una scelta corretta"
                       "\n[9 per ristampare il menu]");
        }
    } while(!previousMenuExit);
}
/**
 * This function prints the main menu
 */
void printMainMenu(){
    clearScreen();
    printf("\nBenvenuti nel programma per la gestione dei ricercati:");
    printf("\n*1. Inserisci record");
    printf("\n*2. Elimina record");
    printf("\n*3. Confronta record 'x' con record 'y'");
    printf("\n*4. Stampa");
    printf("\n*5. Salva/Carica record");
    printf("\n*6. Cripta/Decripta lista record");
    printf("\n*7. Ordina lista alfabeticamente");
    printf("\n*9. Questo menu");
    printf("\n*0. Uscita");
}
/**
 * This function prints the print submenu
 */
void printPrintMenu(){
    clearScreen();
    printf("\nMenu di stampa:");
    printf("\n1. Stampa un record");
    printf("\n2. Stampa elenco record");
    printf("\n3. Menu precedente");
    printf("\n9. Questo menu");
    printf("\n0. Uscita");
}
/**
 * This function prints the load and save submenu
 */
void printMenuLoadSave(){
    clearScreen();
    printf("\nMenu di caricamento:");
    printf("\n1. Carica lista da documento");
    printf("\n2. Carica lista da file binario");
    printf("\n3. Salva lista in formato documento");
    printf("\n4. Salva lista in formato binario");
    printf("\n5. Menu precedente");
    printf("\n9. Questo menu");
    printf("\n0. Uscita");
}
/**
 * This function prints the ciphering and deciphering submenu
 */
void printMenuCipher(){
    clearScreen();
    printf("\nMenu di cifratura:");
    printf("\n1. Cripta l'intero elenco");
    printf("\n2. Decripta l'intero elenco");
    printf("\n5. Menu precedente");
    printf("\n9. Questo menu");
    printf("\n0. Uscita");
}
/**
 * This function asks the user for confirmation when the exit is selected
 * @param lastModSaved save status [false if last changes weren't saved]
 * @param choice user's menu choice
 */
void exitProgramCheck(_Bool *lastModSaved, int *choice){
    if(*lastModSaved)
        printf("Attenzione! Si e' scelto di chiudere il programma senza salvare!");
    else
        printf("\nE' stata selezionata l'uscita dal programma");
    printf("\n0 per confermare > ");
    scanf("%d", choice);
    emptyBuffer();
}