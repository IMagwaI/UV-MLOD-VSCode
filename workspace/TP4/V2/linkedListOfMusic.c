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

Liste readInfoMusic(char *line, Liste liste)
{
    Music *music = malloc(sizeof(Music));
    /* 
    music->Name=strok(line, ",");
    while(strsep(&line,"," != NULL)){
    } */
    music->Name = strsep(&line, ",");
    music->Artist = strsep(&line, ",");
    music->Album = strsep(&line, ",");
    music->Genre = strsep(&line, ",");
    music->NumberDisc = strsep(&line, ",");
    music->NumberTrack = strsep(&line, ",");
    music->Year = strsep(&line, ",");
    return ajoutTete(music, liste);
}

/*
marche pas !
 Liste trierParAnnee(Liste l)
{
    Liste p = l;
    Liste *temp;
    while (!estVide(p) && !estVide(p->suiv))
    {
        while (((Music *)p->val)->Year > ((Music *)p->suiv->val)->Year)
        {
            temp = p->val;
            (p->val) = (p->suiv->val);
            (p->suiv->val) = temp;
            p = p->suiv;
        }
    }
    return l;

} */

Liste trierParAnnee(Liste l)  
// bizarrement quelques element au milieu  ne sont pas trié correctement d'autres non vers la ligne suivante :  Dead Joe,The Birthday Party,Junkyard,Alternative,,3,1982
 
{
    Liste temp = NULL;
    Liste element=NULL; 
    Liste tempvar;
    element=l;
    while(element != NULL)   
    {
        temp=element; 
        while (temp->suiv !=NULL) // boucle de passage sur tout les elements
        {
           if(atoi((((Music *)temp->val)->Year)) > atoi(((Music *)temp->suiv->val)->Year )) // ici l'attribut Year est un char* j'ai besoin donc de la convertir pour que la comparaison soit juste, j'ai définie le tout comme char* pour ne pas se débrouiller avec strsep à la lecture x)
            {
              tempvar = temp->val;
              temp->val = temp->suiv->val;
              temp->suiv->val = tempvar;
            }
         temp = temp->suiv;    // on passe à l element suivant
        }
        element = element->suiv;    
    }
    return l;

}
