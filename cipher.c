//
// Created by riccardo on 03/01/22.
//
#include "cipher.h"

/**
 * This procedure ciphers every character of a string 'str'
 * @param str string to cipher
 */
void cipherStr (char str[]){
    mirrorChar(strlen(str),str);

    /*    int i, strSize = strlen(str);

    for(i=0;i<strSize; i++){
        if(str[i] != ' ') {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = 'z' - (str[i] - 'a');
            else
                str[i] = 'Z' - (str[i] - 'A');
        }
    }*/
}
/**
 * This procedure deciphers a string 'str'
 * @param str string to decipher
 */
void decipherStr (char str[]) {
    mirrorChar(strlen(str),str);
    /*for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = 'z' - str[i] + 'a';
            else
                str[i] = 'Z' - str[i] + 'A';
        }
    }*/
}

void mirrorChar (int sizeStr, char str[]){
    while(sizeStr>=0){
        sizeStr--;
        if(str[sizeStr]) {
            if (str[sizeStr] >= 'A' && str[sizeStr] <= 'Z')
                str[sizeStr] = 'Z' - str[sizeStr] + 'A';
            else
                str[sizeStr] = 'z' - str[sizeStr] + 'a';
        }
    }
}