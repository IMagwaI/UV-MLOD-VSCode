
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
		char readLine[TAILLE_MAX];
		Liste listeMusic = NULL;
		while (fgets(readLine, TAILLE_MAX, fichier))
		{
			/* puts(readLine);*/
			char *line = strdup(readLine); //strdup utilise malloc implicite, pourquoi meme si je ne fais pas de free il y'a pas de fuite ?
			listeMusic = readInfoMusic(line, listeMusic);
		}
		//afficheListe_i(listeMusic);
		//afficheEnvers_r(listeMusic);

		afficheEnvers_r(trierParAnnee(listeMusic));
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