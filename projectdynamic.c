//
// Created by riccardo on 05/01/22.
//
#include "projectdynamic.h"

/**
 * This function fills the member of an array RecordSoggetto with randomly generated values
 * @param nElements number of elements of the array
 * @return pointer to an array RecordSoggetto
 */
RecordSoggetto* genArrayRecordDynamic (int nElements){
    RecordSoggetto *newArray=(RecordSoggetto *) malloc(nElements * sizeof(RecordSoggetto));
    RecordSoggetto *newRecord;
    int i;

    for(i=0;i<nElements;i++) {
        newRecord=genRecordDynamic();
        copyRecord(&newArray[i],newRecord);
        free(newRecord);
    }

    return newArray;
}
/**
 * This function fills the member of a variable RecordSoggetto with randomly generated values
 * @return pointer to variable RecordSoggetto
 */
RecordSoggetto* genRecordDynamic() {
    RecordSoggetto *newPerson = (RecordSoggetto *) malloc(sizeof(RecordSoggetto));

    if(newPerson!=NULL) {
        genName(newPerson);
        genSurname(newPerson);
        genHeight(newPerson);
        genWeight(newPerson);
        genEyesColor(newPerson);
        genHairColor(newPerson);
        genHairLength(newPerson);
        genBeard(newPerson);
        genFingePrint(newPerson);
        genResidency(newPerson);
        genGpsPos(newPerson);
        genStatus(newPerson);
    } else
        printf("Errore nell'allocazione della memoria");
    return newPerson;
}
/**
 * This function scans the input for every member of a struct RecordSoggetto and saves
 * the data in an array RecordSoggetto
 * @param pArraySize size of the array
 * @param pRecord pointer to the array RecordSoggetto
 * @return true if the entry was successful
 */
_Bool inserisciRecordDynamic(int *pArraySize, RecordSoggetto **pRecord) {
    *pRecord= (RecordSoggetto *) malloc(sizeof(RecordSoggetto));
    exitIfpNull(*pRecord,MP);
    _Bool abortFlag=false;
    int i;

    for(i=NAME;i<STATUS&&!abortFlag;i++) {
        switch (i) {
            case NAME:
                scanName(*pRecord, &abortFlag);
                break;
            case SURNAME:
                scanSurname(*pRecord, &abortFlag);
                break;
            case HEIGHT:
                scanHeight(*pRecord, &abortFlag);
                break;
            case WEIGHT:
                scanWeight(*pRecord, &abortFlag);
                break;
            case EYESC:
                scanEyesColor(*pRecord, &abortFlag);
                break;
            case HAIRC:
                scanHairColor(*pRecord, &abortFlag);
                break;
            case LENGTH:
                scanHairLength(*pRecord, &abortFlag);
                break;
            case BEARD:
                scanBeard(*pRecord, &abortFlag);
                break;
            case FINGPRINT:
                scanFingerprint(*pRecord, &abortFlag);
                break;
            case RESID:
                scanResidency(*pRecord, &abortFlag);
                break;
            case POSITION:
                scanPosition(*pRecord, &abortFlag);
                break;
            case STATUS:
                scanStatus(*pRecord, &abortFlag);
                break;
            default:
                exitError("Campo RecordSoggetto non definito");
        }
    }
    if(abortFlag) { //! when abortFlag is set true exits the function
        printf("\nPremere un tasto per continuare...");
        waitForUser();
        clearScreen();
        emptyBuffer();
        return false;
    } else
        *pArraySize += 1;

    return true;
}
/**
 * This function deletes a member of a dynamically allocated array RecordSoggetto
 * @param index index of the member to delete
 * @param aSize size of 'aRecord'
 * @param aRecord array RecordSoggetto
 * @return true if the element was successfully removed
 */
_Bool delRecordDynamic (int index, int *aSize, RecordSoggetto aRecord[]) {
    RecordSoggetto *newArray = (RecordSoggetto *) malloc(((*aSize) - 1) * sizeof(RecordSoggetto));
    int i;

    if(newArray!=NULL) {
        index--;

        if (index < *aSize && index >= 0) {
            (*aSize)--;
            for (i = 0; i < *aSize; i++) {
                if (i < index)
                    copyRecord(&newArray[i], &aRecord[i]);
                else
                    copyRecord(&newArray[i - 1], &aRecord[i]);
            }
            return true;
        } else
            printf("\nE' stato inserito un indice inesistente");
    } else
        printf("\nErrore nell'allocazione della memoria");

    return false;
}
/**
 * This function compares two elements of an array RecordSoggetto
 * @param aSize size of the array
 * @param fstElement first element to compare
 * @param secElement second element to compare
 * @param aRecord array RecordSoggetto
 * @return the percent value of similarity
 */
int compElementArray(const int aSize, const int fstElement, const int secElement, const RecordSoggetto aRecord[]) {
    if(fstElement==secElement){
        printf("\nHai scelto di confrontare un elemento con se stesso!");
    } else if(fstElement<aSize-1&&fstElement>=0){
        if(secElement<aSize-1&&secElement>=0){
            return confrontaRecord(&aRecord[fstElement],&aRecord[secElement]);
        } else
            printf("Elemento 'y' inesistente!");
    } else
        printf("Elemento 'x' inesistente!");
    return 0;
}
/**
 * This function scans from the stdin the members of a struct RecordSoggetto and saves it in
 * an element of a list ListRecordSoggetto
 * @param head head of the list
 * @return the pointer to the head of the list
 */
ListRecordSoggetto* scanRecordList (ListRecordSoggetto* head){
    ListRecordSoggetto *newElement;
    RecordSoggetto *pNewRecord = (RecordSoggetto *) malloc(sizeof(RecordSoggetto));
    exitIfpNull(pNewRecord, MP);
    inserisciRecord(pNewRecord);

    if(head==NULL) {
        head = (ListRecordSoggetto *) malloc(sizeof(ListRecordSoggetto));
        exitIfpNull(head,MP);
        copyRecord(&head->RecordSoggetto, pNewRecord);
        head->next=NULL;
        free(pNewRecord);
        return head;
    }

    newElement = (ListRecordSoggetto *) malloc(sizeof(ListRecordSoggetto));
    exitIfpNull(newElement,MP);
    copyRecord(&newElement->RecordSoggetto, pNewRecord);
    newElement->next=head;
    free(pNewRecord);
    return newElement;
}
/**
 * This function adds an element to an existing list ListRecordSoggetto
 * @param head pointer to the list
 * @param newElement element RecordSoggetto to add to the list
 * @return the head of the list
 */
ListRecordSoggetto* addElementList (ListRecordSoggetto *head, RecordSoggetto *newElement){
    ListRecordSoggetto *newHead=NULL;

    if(head==NULL) {
        head = (ListRecordSoggetto *) malloc(sizeof(ListRecordSoggetto));
        exitIfpNull(head,MP);
        copyRecord(&head->RecordSoggetto,newElement);
        head->next=NULL;
        free(newElement);
        return head;
    } else {
        newHead = (ListRecordSoggetto *) malloc(sizeof(ListRecordSoggetto));
        exitIfpNull(newHead,MP);
        copyRecord(&newHead->RecordSoggetto, newElement);
        newHead->next = head;
        free(newElement);
        return newHead;
    }
}
/**
 * This function generates with random values a list ListRecordSoggetto
 * @param nElements number of elements in the list
 * @return the pointer to the head of the list
 */
ListRecordSoggetto* genRecordList (int nElements){
    ListRecordSoggetto *head=NULL;
    RecordSoggetto *pNewRecord=NULL;

    int i;

    for(i=0;i<nElements;i++) {
        pNewRecord= genRecordDynamic();
        head = addElementList(head, pNewRecord);
    }

    return head;
}
/**
 * This function deletes an element from a list ListRecordSoggetto
 * @param posElement position of the element to delete
 * @param headRef head of the list
 * @return pointer to the head of the list
 */
ListRecordSoggetto* delElementList(int posElement, ListRecordSoggetto *headRef){
    ListRecordSoggetto *midElement, *selElement, *head=headRef;
    int elmIndex=0;

    if(head != NULL) {
        for (selElement = head; selElement != NULL; selElement = selElement->next, elmIndex++) {
            if (elmIndex == posElement - 1) {
                midElement = selElement;
                head = selElement->next;
                free(midElement);
                break;
            } else if (elmIndex + 1 == posElement - 1) {
                midElement = selElement->next;
                selElement->next = selElement->next->next;
                free(midElement);
                break;
            }
        }
    } else
        printf("\nErrore! La lista risulta vuota");

    return head;
}
/**
 * This procedure prints a list ListRecordSoggetto
 * @param head pointer to the head of the list
 */
void printList (ListRecordSoggetto *head){
    ListRecordSoggetto *selElement=head;
    int i = 1;

    while(selElement != NULL){ //! scans the list until it finds the last element
        if(i>1)
            printf("\n");
        printf("\nSoggetto n.%d", i);
        stampaRecord(&selElement->RecordSoggetto);
        selElement = selElement->next;
        i++;
    }
    printf("\n");
}
/**
 * This function compares two elements of a list ListRecordSoggetto
 * @param fstElmPos position of the first element
 * @param secElmPos position of the second element
 * @param head pointer to the head of the list
 * @return percent value of similarity
 */
int compareElementsList (int fstElmPos, int secElmPos, ListRecordSoggetto *head){
    ListRecordSoggetto *fstElm;
    ListRecordSoggetto *secElm;
    ListRecordSoggetto *temp=head;
    int i=1;

    while(temp!=NULL){ //! scans the list to find the elements for the comparison
        if(i==fstElmPos)
            fstElm=temp;
        if(i==secElmPos)
            secElm=temp;
        temp=temp->next;
    }

    return confrontaRecord(&fstElm->RecordSoggetto,&secElm->RecordSoggetto);
}
/**
 * This function sorts a list alphabetically
 * @param head pointer to the head of the list
 * @return the head of the list sorted
 */
ListRecordSoggetto *mergeSortList(ListRecordSoggetto *head){
    ListRecordSoggetto *left,*right;

    /*! check if the list contains mora than one element !*/
    if (head != NULL && head->next != NULL) {

        /*! Split head into 'left' and 'right' lists !*/
        left=head;
        right=head->next;

        while(right!=NULL){
            right=right->next;
            if(right!=NULL){
                left=left->next;
                right=right->next;
            }
        }

        left=head;
        right=left->next;
        left->next=NULL;

        left= mergeSortList(left);
        right= mergeSortList(right);

        head=mergeSortedLists(left, right);
    }
    return head;
}
/**
 * This function merges two lists into a new list alphabetically sorted
 * @param left pointer to the 'left' list
 * @param right pointer to the 'right' list
 * @return the head of the list alphabetically sorted
 */
ListRecordSoggetto *mergeSortedLists(ListRecordSoggetto *left, ListRecordSoggetto *right){
    ListRecordSoggetto *result = NULL;

    if (left == NULL)       //! if left points to NULL returns the right element...
        return right;
    else if (right == NULL) //! ...and viceversa
        return left;

    /*! adds the elements to  'result' in an alphabetical order !*/
    if (compFullName(MIN, &(left->RecordSoggetto), &(right->RecordSoggetto))) {
        result = left;
        result->next = mergeSortedLists(left->next, right);
    } else {
        result = right;
        result->next = mergeSortedLists(left, right->next);
    }

    return result;
}
/**
 * This procedure deciphers every name and surname member in a RecordSoggetto variable of a ListRecordSoggetto
 * @param head head of the list
 */
void cipherList (ListRecordSoggetto *head){
    ListRecordSoggetto *selElement = head;

    while(selElement!=NULL){
        cipherStr(selElement->RecordSoggetto.name);
        cipherStr(selElement->RecordSoggetto.surname);
        selElement=selElement->next;
    }
}
/**
 * This procedure deciphers every name and surname member in a RecordSoggetto variable of a ListRecordSoggetto
 * @param head head of the list
 */
void decipherList (ListRecordSoggetto *head){
    ListRecordSoggetto *selElement = head;

    while(selElement!=NULL){
        decipherStr(selElement->RecordSoggetto.name);
        decipherStr(selElement->RecordSoggetto.surname);
        selElement=selElement->next;
    }
}

