//  pour compiler :   gcc -W -Wall -std=c99 -D_GNU_SOURCE linkedList.c linkedListOfMusic.c mySpitofy.c   -o mySpitofy
//  pour executer : ./mySpitofy > music.txt
//  -D_GNU_SOURCE:  probleme de compilation  avec la fonction strdup    " warning: implicit declaration of function ‘strdup’; did you mean ‘strcmp’?" vu strdup n'est pas une fonction standard
//	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy       * contient de fuite , pas pu les réperés*

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"
#define TAILLE_MAX 1000

int main(void)
{
	char fichierListMusic[] = "music.csv";
	FILE *fichier = NULL;
	fichier = fopen(fichierListMusic, "r");
	char *line = NULL;

	if (fichier != NULL)
	{
		char readLine[TAILLE_MAX];
		Liste listeMusic = NULL;
		while (fgets(readLine, TAILLE_MAX, fichier))
		{
			/* puts(readLine);*/
			line = strdup(readLine); //strdup utilise malloc implicite
			listeMusic = readInfoMusic(line, listeMusic);
		}
		//afficheListe_i(listeMusic);
		//afficheEnvers_r(listeMusic);

		afficheEnvers_r(trierParAnnee(listeMusic));
		free(line);
		detruire_r(listeMusic);
		fclose(fichier);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier music.csv");
	}
	return EXIT_SUCCESS;
}