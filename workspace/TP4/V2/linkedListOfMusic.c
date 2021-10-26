#include "linkedListOfMusic.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ============
// Definitions of external functions
// ============


// Affichage de chaque variables d'un element Music*

void afficheElement(Element e)
{
    Music *uneMusic;
    uneMusic = (Music *)e;
    printf("%s,", uneMusic->Name);
    printf("%s,", uneMusic->Artist);
    printf("%s,", uneMusic->Album);
    printf("%s,", uneMusic->Genre);
    printf("%s,", uneMusic->NumberDisc);
    printf("%s,", uneMusic->NumberTrack);
    printf("%s", uneMusic->Year);
}

// supprimer un element Music
void detruireElement(Element e)
{
    free(e);
}

// compare deux elements
bool equalsElement(Element e1, Element e2)
{
    Music *uneMusic1;
    Music *uneMusic2;
    uneMusic1 = (Music *)e1;
    uneMusic2 = (Music *)e2;

    return (strcmp(uneMusic1->Name, uneMusic2->Name) == 0 && strcmp(uneMusic1->Artist, uneMusic2->Artist) == 0);
}

// ============
// Functions implementation
// ============


// lecture de chaque element de ligne en arrivant au séparateur

Liste readMusic(char* line,Liste liste){

    Music *music=malloc(sizeof(Music));
    music->Name=strsep(&line, ",");
    music->Artist=strsep(&line, ",");
    music->Album=strsep(&line, ",");
    music->Genre=strsep(&line, ",");
    music->NumberDisc=strsep(&line, ",");
    music->NumberTrack=strsep(&line, ",");
    music->Year=strsep(&line, ",");
    return ajoutTete(music,liste);
}
