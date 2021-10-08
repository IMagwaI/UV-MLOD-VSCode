#include <stdio.h>

int prix_plein_tarif = 50;
int age = 11;

int main(void)
{
    if (age < 2)
    {
        printf("%f", 0.1 * prix_plein_tarif);
        return 0;
    }
    else if (age < 12)
    {
        printf("%f", 0.5 * prix_plein_tarif);
        return 0;
    }
    printf("%d", prix_plein_tarif);
    return 0;
}