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

//afin de lire chaque attribut d'une musique obtenue dans une ligne apres fgets et l'ajouté au tableau des musiques
Liste readInfoMusic(char *uneMusic, Liste liste);

// trier les musiques par l'attribut Year
Liste trierParAnnee(Liste l);

