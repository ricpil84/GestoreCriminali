//
// Created by riccardo on 03/01/22.
//
#include "checks.h"

/**
 * This function checks if a char 'c' is [a-f], [A-F] or [0-9]
 * @param c character to check
 * @return True when 'c' is [a-f][A-F][0-9]
 */
_Bool isNumHex(const char c) {
    if(c >= 'a' && c <= 'f') // true when 'c' is [a-f]
        return true;
    else if(c >= 'A' && c <= 'F') // true when 'c' is [A-F]
        return true;
    else if(isNumDec(c))
        return true;
    else
        return false;
}
/**
 * This function checks if a char 'c' is [0-9]
 * @param c character to check
 * @return true when 'c' is [0-9]
 */
_Bool isNumDec(const char c) {
    if(c >= '0' && c <= '9') // true when the 'c' is [0-9]
        return true;
    else
        return false;
}
/**
 * This function checks if a char 'c' is [a-z] or [A-Z]
 * @param c character to check
 * @return true when 'c' is [a-z][A-Z]
 */
_Bool isAlpha(const char c) {
    if(c >= 'a' && c <= 'z') // true when 'c' is [a-z]
        return true;
    else if(c >= 'A' && c <= 'Z') // true when 'c' is [A-Z]
        return true;
    else
        return false;
}
/**
 * This function checks if a char 'c' is a space ' '
 * @param c character to check
 * @return true when 'c' is a space ' '
 */
_Bool isSpace(const char c){
    if(c==' ') // true when 'c' is a space
        return true;
    else
        return false;
}
/**
 * This function checks if a char 'c' is [a-z], [A-Z] or [0-9]
 * @param c character to check
 * @return true when 'c' is [a-z][A-Z][0-9]
 */
_Bool isAlphanum(const char c){
    if(isAlpha(c)||isNumDec(c))
        return true;
    else
        return false;
}
/**
 * This function checks if a char 'c' is a '.' (decimal separator)
 * @param c character to check
 * @return true when 'c' is a '.' (decimal separator)
 */
_Bool isPoint(const char c){
    if(c=='.') // true when 'c' is a point '.' (decimal separator)
        return true;
    else
        return false;
}
/**
 * This function checks if a value 'v' is a StatoSoggetto value (defined in basedata.h)
 * @param v value to check
 * @return true if 'v' is not a StatoSoggetto value
 */
_Bool checkStatusValue(const int v){
    switch(v){
        case LIBERO:
            return false;
        case IN_ARRESTO:
            return false;
        case RICERCATO:
            return false;
        case EVASO:
            return false;
        default:
            return true;
    }
}
/**
 * This function checks if a value 'v' is a BeardValue (defined in basedata.h)
 * @param v value to check
 * @return true if 'v' is not a BeardValue value
 */
_Bool checkBeardValue(const int v){
    switch(v) {
        case TRUE:
            return false;
        case FALSE:
            return false;
        default:
            return true;
    }
}
/**
 * This function checks if a value 'v' is a TipoCapelli value (defined in basedata.h)
 * @param v value to check
 * @return true if 'v' is not a TipoCapelli value
 */
_Bool checkHairType(const int v){
    switch(v) {
        case CORTI:
            return false;
        case MEDI:
            return false;
        case LUNGHI:
            return false;
        case ALTRO:
            return false;
        default:
            return true;
    }
}
/**
 * Questa funzione verifica che la stringa inserita dall'utente sia compatibile con il tipo richiesto
 * @param dim la dimensione della stringa da verificare
 * @param stringa la stringa sulla quale verra' effettuata la verifica
 * @param tipoCarattere valore corrispondente al tipo di caratteri che la stringa dovra' contenere..
 *                      ..TipoCarattere definito in stampaeacquisizione.h
 * @return vero quando la stringa inserita risulta coerente col tipo richiesto
 */
_Bool checkString(int s, char str[], CharType t){
    int i;

    switch (t) { // Check the string type and selects the test
        case HEX:
            for (i = 0; i < s; i++) { // every char in the string is checked with isNumHex()
                if (!isNumHex(str[i]))
                    return false;
            }
            return true;
        case ALPHA_SP:
            for (i = 0; i < s; i++) { // every char in the string is checked with isAlpha() and isSpace()
                if (!isAlpha(str[i])&&!isSpace(str[i]))
                    return false;
            }
            return true;
        case ALPHANUM_NSP:
            for (i = 0; i < s - 1; i++) { // // every char in the string is checked with isAlphanum()
                if (!isAlphanum(str[i]))
                    return false;
            }
            return true;
        case ALPHANUM_SP:
            for (i = 0; i < s - 1; i++) { // every char in the string is checked with isAlphanum() and isSpace()
                if (!isAlphanum(str[i])&&!isSpace(str[i]))
                    return false;
            }
            return true;
        default:
            exitError("enum non definita");
    };
}
/**
 * This function checks if a spaces and '\0' (end of string character) have to be allowed in a format
 * @param type constant representing the type of characters allowed
 * @param endStr allows the end of string '\0'
 * @return true when spaces are allowed
 */
_Bool checkFormat (CharType type, _Bool *isString ) {
    switch(type){
        case HEX:
        case ALPHANUM_NSP:
            *isString=false;
            return false;
        case ALPHA_SP:
        case ALPHANUM_SP:
            return true;
        default:
            exitError("enum non definita");
    };
}
/**
 * This function checks if a string can be converted into a value and counts its integer and decimal parts
 * @param decPlaces counter for the decimal part of the value
 * @param intPlaces counter for the integer part of the value
 * @param str string to convert
 * @return true when the string can be converted
 */
_Bool isStrConvertible(int *decPlaces, int *intPlaces, _Bool *isNumNegative, const char str[]){
    int i=0,j;

    if(str[0]=='-') {
        *isNumNegative=true;
        i=1;
    } else
        *isNumNegative = false;

    /* initialize counters and scans the elements of the string searching for allowed values */
    for(*intPlaces=0, *decPlaces=0; str[i] != '\0'; i++) {

        if(isPoint(str[i])) { // when finds the decimal separator starts to count the decimal places
            for(j=i+1; str[j] != '\0'; j++)
                if(isNumDec(str[j]))
                    (*decPlaces)++;
            i=j;
        }
        else if(isNumDec(str[i])) // counts the integer places
            (*intPlaces)++;
        else if(!isNumDec(str[i])) // if the char is not a number the string can't be converted
            return false;
    }
    return true;
}