/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */

struct Winners
{

    int annee;
    char *nom;
    char *commentaire;
};

typedef struct Winners Winners;
char *scanLine()
{
    int maxLineSize = 255;
    char c, *line = calloc(maxLineSize + 1, sizeof(char));

    scanf("%250[^\n]", line);

    if ((c = getchar()) != '\n')
    {
        /* we did not get all the line */
        line[250] = '[';
        line[251] = line[252] = line[253] = '.';
        line[254] = ']';
        // line[255] = '\0'; // useless because already initialized by calloc

        // let's skip all chars untli the end of line
        while (((c = getchar()) != '\n') && c != EOF)
            ;
    }

    return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt()
{
    int buf;
    scanf("%i\n", &buf);
    return buf;
}
void readWinners(int nbrGagnants, Winners winners[])
{
    for (int i = 0; i < nbrGagnants; i++)
    {
        winners[i].annee = scanLineAsInt();
        winners[i].nom = scanLine();
        winners[i].commentaire = scanLine();
    }
}

void printWinners(int nbrGagnants, Winners winners[])
{
    for (int i = 0; i < nbrGagnants; i++)
    {
        printf("%d\n", winners[i].annee);
        printf("%s\n", winners[i].nom);
        printf("%s\n", winners[i].commentaire);
    }
}

void infoAnnee(int nbGagnants, Winners winners[], int anneeR)
{
    for (int i = 0; i < nbGagnants; i++)
    {
        if (winners[i].annee == anneeR)
        {
            printf("%d\n", winners[i].annee);
            printf("%s\n", winners[i].nom);
            printf("%s\n", winners[i].commentaire);
        }
    }
}
int main(void)
{

    int nbGagnants = scanLineAsInt();
    printf("%i\n", nbGagnants);
    Winners winners[nbGagnants];
    readWinners(nbGagnants, winners);
    printWinners(nbGagnants, winners);
    /*      infoAnnee(nbGagnants, winners, 2003); */
    return EXIT_SUCCESS;
}
