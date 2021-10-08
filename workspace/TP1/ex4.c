#include <stdio.h>

typedef short TypeEntier;

TypeEntier factorielle(int N){
    int produit =1;
    for (int i=0;i<N;i++){
        produit*=i;
    }
    printf("%d",produit);
    return produit;
}

int main(void)
{
    
    return factorielle(5);
}