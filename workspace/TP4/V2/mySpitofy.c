
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"
#define TAILLE_MAX 1000
//  -D_GNU_SOURCE:  probleme de compilation  avec la fonction strdup    " warning: implicit declaration of function ‘strdup’; did you mean ‘strcmp’?" j'ai du prendre la définition




int main(void)
{

	char fichierListMusic[] = "music.csv";
	// Initialisation du pointeur.
	FILE *fichier = NULL;
	fichier = fopen(fichierListMusic, "r");
	if (fichier != NULL)
	{
		char buffer[TAILLE_MAX];
		Liste listeMusic;
		listeMusic = NULL;
		char *champs = fgets(buffer, TAILLE_MAX, fichier);
		printf("%s", champs);
		while (fgets(buffer, TAILLE_MAX, fichier))
		{
			char *line = strdup(buffer);  //strdup utilise malloc implicite, faut donc la free apres l'utilisation.
			listeMusic = readMusic(line, listeMusic);
		}
		afficheListe_i(listeMusic);
		afficheEnvers_r(listeMusic);

		detruire_r(listeMusic);
		fclose(fichier);

		//
	}
	else
	{
		printf("Impossible d'ouvrir le fichier music.csv");
	}
	return EXIT_SUCCESS;
}