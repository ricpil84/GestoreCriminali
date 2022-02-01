//
// Created by riccardo on 03/01/22.
//
#ifndef PROGETTOTNV_BASEDATA_H
#define PROGETTOTNV_BASEDATA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM_NAME 63 //! Max dimension of the 'name' member of the struct RecordSoggetto
#define DIM_SURNAME 63 //! Max dimension of the 'surname' member of the struct RecordSoggetto
#define DIM_EYESC 6 //! Max dimension of the 'eyecolor' member of the struct RecordSoggetto
#define DIM_HAIRC 6 //! Max dimension of the 'haircolor' member of the struct RecordSoggetto
#define DIM_FINGPRINT 16 //! Max dimension of the 'fingerprint' member of the struct RecordSoggetto
#define DIM_RESIDENCY 512 //! Max dimension of the 'residency' member of the struct RecordSoggetto
#define DIM_STRINGTERM 1 //! Dimension for '\0'
#define HEIGHT_MIN 0 //! Min value allowed for the 'height' member of the struct RecordSoggetto
#define HEIGHT_MAX 250 //! Max value allowed for the 'height' member of the struct RecordSoggetto
#define WEIGHT_MIN 0 //! Min value allowed for the 'weight' member of the struct RecordSoggetto
#define WEIGHT_MAX 200 //! Max value allowed for the 'weight' member of the struct RecordSoggetto
#define LAT_MIN -90 //! Min value allowed for the 'latitude' member of the struct PosizioneGPS
#define LAT_MAX 90 //! Max value allowed for the 'latitude' member of the struct PosizioneGPS
#define LON_MIN -180 //! Min value allowed for the 'longitude' member of the struct PosizioneGPS
#define LON_MAX 180 //! Max value allowed for the 'longitude' member of the struct PosizioneGPS
#define FST_HAIR_VAL CORTI //! first TipoCapelli value
#define LST_HAIR_VAL ALTRO //! last TipoCapelli value
#define FST_STATUS_VAL LIBERO //! first StatoSoggetto value
#define LST_STATUS_VAL EVASO //! last StatoSoggetto value
#define FST_BEARD_VAL FALSE //! first value for beard
#define LST_BEARD_VAL TRUE //! last value for beard

typedef enum { FALSE, TRUE } BeardValue; //! Beard value constants
typedef enum { CORTI, MEDI, LUNGHI, ALTRO } TipoCapelli; //! Hair type constants
typedef enum { LIBERO, RICERCATO, IN_ARRESTO, EVASO } StatoSoggetto; //! Status constants
typedef enum { UNITS=1, CENTI=100, MICRO=1000000 } Precision; //! Decimal precision constants

typedef struct {
    double lat; // latitude
    double lon; // longitude
} PosizioneGPS;
typedef struct {
    char name[DIM_NAME + DIM_STRINGTERM];
    char surname[DIM_SURNAME + DIM_STRINGTERM];
    int height;
    float weight;
    char eyesColor[DIM_EYESC];
    char hairColor[DIM_HAIRC];
    TipoCapelli HairLength;
    _Bool beard;
    char fingerprint[DIM_FINGPRINT];
    char residency[DIM_RESIDENCY];
    PosizioneGPS Position;
    StatoSoggetto Status;
} RecordSoggetto;

void exitError(char error[]);
void waitForUser();

#endif //PROGETTOTNV_BASEDATA_H
