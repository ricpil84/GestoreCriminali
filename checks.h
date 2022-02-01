//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_CHECKS_H
#define PROGETTOTNV_CHECKS_H

#include "basedata.h"
#include "stdbool.h"

typedef enum { HEX, ALPHA_SP, ALPHANUM_NSP, ALPHANUM_SP } CharType; // Char type constants

_Bool isNumHex(const char c);
_Bool isNumDec(const char c);
_Bool isAlpha(const char c);
_Bool isSpace(const char c);
_Bool isPoint(const char c);
_Bool isAlphanum(const char c);
_Bool checkStatusValue(const int v);
_Bool checkBeardValue(const int v);
_Bool checkHairType(const int v);
_Bool checkString(int s, char str[], CharType type);
_Bool checkFormat (CharType type, _Bool *isString );
_Bool isStrConvertible(int *decPlaces, int *intPlaces, _Bool *isNumNegative, const char str[]);
#endif //PROGETTOTNV_CHECKS_H
