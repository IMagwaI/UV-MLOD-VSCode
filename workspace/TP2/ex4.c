#include <stdio.h>
#include <stdbool.h>

enum Mois
{
    jan = 1,
    fev,
    mars,
    avr,
    mai,
    juin,
    juil,
    aout,
    sept,
    oct,
    nov,
    dec
};
struct Date
{
    int jour;
    enum Mois mois;
    int annee;
};

typedef enum Mois Mois;
typedef struct Date Date;

void afficheDate(Date *d)
{
    char *Mois;
    switch (d->mois)
    {
    case 1:
        Mois = "Janvier";
        break;

    case 2:
        Mois = "Février";
        break;
    case 3:
        Mois = "Mars";
        break;
    case 4:
        Mois = "Avril";
        break;
    case 5:
        Mois = "Mai";
        break;
    case 6:
          Mois = "Juin";
        break;
    case 7:
        Mois = "Juillet";
        break;
    case 8:
        Mois = "Aout";
        break;
    case 9:
        Mois = "Septembre";
        break;
    case 10:
        Mois = "Octobre";
        break;
    case 11:
        Mois = "Novembre";
        break;
    case 12:
        Mois = "Décembre";
        break;

    default:
        break;
    }
}

void initialiseDate(Date *d)
{
    
    printf("Saisir jour: ");
    scanf("%i", &d->jour);
    // d -> equiv  (*d).jour
    printf("Saisir mois: ");
    scanf("%i", (int *)&d->mois);
    printf("Saisir année: ");
    scanf("%i", &d->annee);
}
int main(void)
{
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
}