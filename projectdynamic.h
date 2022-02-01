//
// Created by riccardo on 05/01/22.
//

#ifndef PROGETTOTNV_PROJECTDYNAMIC_H
#define PROGETTOTNV_PROJECTDYNAMIC_H

#include "generation.h"
#include "printing.h"
#include "comparison.h"
#include "userinput.h"
#include "filemanipulation.h"
#include "advfunctions.h"

struct ListRecordSoggetto {
    RecordSoggetto RecordSoggetto;
    struct ListRecordSoggetto *next;
};
typedef struct ListRecordSoggetto ListRecordSoggetto;

RecordSoggetto * genArrayRecordDynamic (int nElements);
RecordSoggetto * genRecordDynamic();
_Bool inserisciRecordDynamic(int *pArraySize, RecordSoggetto **pRecord);
_Bool delRecordDynamic (int index, int *aSize, RecordSoggetto aRecord[]);
int compElementArray(const int aSize, const int fstElement, const int secElement, const RecordSoggetto aRecord[]);
ListRecordSoggetto * scanRecordList (ListRecordSoggetto *head);
ListRecordSoggetto * addElementList (ListRecordSoggetto *head, RecordSoggetto *newElement);
ListRecordSoggetto * genRecordList (int nElements);
ListRecordSoggetto * delElementList(int posElement, ListRecordSoggetto *headRef);
void printList (ListRecordSoggetto *head);
int compareElementsList (int fstElmPos, int secElmPos, ListRecordSoggetto *head);
ListRecordSoggetto * mergeSortList(ListRecordSoggetto *head);
ListRecordSoggetto * mergeSortedLists(ListRecordSoggetto *left, ListRecordSoggetto *right);
void cipherList (ListRecordSoggetto *list);
void decipherList (ListRecordSoggetto *list);
#endif //PROGETTOTNV_PROJECTDYNAMIC_H
