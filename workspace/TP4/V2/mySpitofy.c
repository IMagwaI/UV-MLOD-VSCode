
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"
#define TAILLE_MAX 1000
//  -D_GNU_SOURCE:  probleme de compilation  avec la fonction strdup    " warning: implicit declaration of function ‘strdup’; did you mean ‘strcmp’?" j'ai du prendre la définition

void lectureFichierMusics()
{
	char fichierListMusic[] = "music.csv";
	// Initialisation du pointeur.
	FILE *fichier = NULL;
	fichier = fopen(fichierListMusic, "r");

	if (fichier != NULL)
	{
		char buffer[TAILLE_MAX];
		Liste listeMusic = NULL;
		while (fgets(buffer, TAILLE_MAX, fichier))
		{
			/* puts(buffer);*/
			char *line = strdup(buffer); //strdup utilise malloc implicite, pourquoi meme si je ne fais pas de free il y'a pas de fuite ?
			listeMusic = readMusic(line, listeMusic);
		}
		//afficheListe_i(listeMusic);   
		afficheEnvers_r(listeMusic);

		detruire_r(listeMusic);
		fclose(fichier);

	}
	else
	{
		printf("Impossible d'ouvrir le fichier music.csv");
	}
}

int main(void)
{
	lectureFichierMusics();

	return EXIT_SUCCESS;
}