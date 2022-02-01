//
// Created by riccardo on 03/01/22.
//
#include "basedata.h"

/**
 * This procedure prints an error message and exits the program
 * @param error error message
 */
void exitError(char error[]){
    printf("\n!!!Uscita!!!\n%s\n", error);
    exit(-1);
}
/**
 * This procedure waits for any input from the stdin
 */
void waitForUser(){
    scanf("%[^\n]s");
}