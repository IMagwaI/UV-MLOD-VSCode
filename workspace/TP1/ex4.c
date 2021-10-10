#include <stdio.h>

typedef short TypeEntier;
typedef unsigned long long TypeLong;

TypeEntier factorielle(TypeEntier);
TypeLong factorielleLong(TypeLong);
/////////////////////// Q4- a -  ///////////////////////////
TypeEntier factorielle(TypeEntier N)
{

    TypeEntier produit = 1;
    for (int i = 1; i <= N; i++)
    {
        produit *= i;
    }
    printf("%hd\n", produit);
    return produit;
}

/////////////////////// Q4- b -  ///////////////////////////
TypeEntier affichageFactorielle()
/*  Remarque : short étant codé sur 2 octets admet une valeur maximale 2^32 /2  à savoir environ 32 700 en valeur absolue */
{
    int N = 15;
    TypeEntier produit = 1;
    for (int i = 1; i <= N; i++)
    {
        produit *= i;
        printf("%hd!=%d\n", i, produit);
    }
    return produit;
}
/////////////////////// Q4- 3 -  ///////////////////////////
TypeLong factorielleLong(TypeLong N)
{
    TypeLong produit = 1;
    for (int i = 1; i <= N; i++)
    {
        produit *= i;
    }
    printf("%lld\n", produit);
    return produit;
}

int main(void)
{
    //Q4-a //

    TypeEntier N;
    printf("Saissir un nombre pour calculer son factorielle : ");
    scanf("%hd", &N);
    factorielle(N);

    // Q4-b //

    affichageFactorielle();

    //Q4-c //

    TypeLong F;
    printf("Saissir un nombre pour calculer son factorielle : ");
    scanf("%lld", &F);
    factorielleLong(F);
    return 0;
}