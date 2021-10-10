#include <stdio.h>

int prix_plein_tarif = 50;
int age = 11;

int calculePrix()
{
    int price;
    int age;
    printf("Saissez le prix de tarif: ");
    scanf("%d", &price);
    printf("Saissez votre age: ");
    scanf("%d", &age);
    if (age < 2)
    {
        printf("Votre nouveau prix de tarif : %f ", 0.1 * price);
        return 0;
    }
    else if (age < 12)
    {
        printf("Votre nouveau prix de tarif : %f  ", 0.5 * price);
        return 0;
    }
    printf(" Votre prix de tarif n'a pas changé  : %d  ", price);
    return 0;
}

int main(void)
{
    calculePrix();
    return 0;
}