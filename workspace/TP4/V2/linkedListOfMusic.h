#pragma once
#include "linkedList.h"

typedef struct
{
    char *Name;
    char *Artist;
    char *Album;
    char *Genre;
    char *Disc;
    char *NumberDisc;
    char *Track;
    char *NumberTrack;
    char *Year;

} Music;


//les fonctions nécessaires pour manipuler des listes de Music

Liste readMusic(char *uneMusic, Liste liste);
