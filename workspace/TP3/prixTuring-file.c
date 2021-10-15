#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *scanLine()
{
    int maxLineSize = 255;
    char c, *line = calloc(maxLineSize + 1, sizeof(char));
    scanf("%250[^\n]", line);
    if ((c = getchar()) != '\n')
    {
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

struct Winner
{
    int year;
    char *name;
    char *description;
};

void readWinners(int nbGagnants, struct Winner winners[])
{
    for (int i = 0; i < nbGagnants; i++)
    {
        int year = scanLineAsInt();
        // printf("%d \n", year);
        winners[i].year = year;
        char *name = scanLine();
        // printf("%s \n", name);
        winners[i].name = name;
        char *description = scanLine();
        // printf("%s \n", description);
        winners[i].description = description;
    }
}

void printWinners(int nbGagnants, struct Winner winners[])
{
    for (int i = 0; i < nbGagnants; i++)
    {
        printf("%d \n", winners[i].year);
        printf("%s \n", winners[i].name);
        printf("%s \n", winners[i].description);
    }
}

void infosAnnee(int annee, struct Winner winners[])
{
    for (int i = 0; i < 50; i++)
    {
        if (winners[i].year == annee)
        {
            printf("L'année %d, le(s) gagnant(s) ont été : %s \nNature des travaux : %s \n", winners[i].year, winners[i].name, winners[i].description);
            return;
        }
    }
}

int main(void)
{
    f = *FILE


    return EXIT_SUCCESS;
}