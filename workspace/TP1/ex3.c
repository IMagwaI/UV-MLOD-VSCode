#include <stdio.h>

void parfait()
{
    int sum = 0;
    int p;
    printf("Saissir un nombre pour vérifier s'il est parfait : ");
    scanf("%d", &p);
    for (int i = 1; i < p; i++)
    {
        if (p % i == 0)
        {
            sum += i;
            printf("%d  est un diviseur \n ", i);
        }
    }
    if (sum == p)
    {
        printf("%d  est  parfait \n", p);
    }
    else
    {
        printf("%d  n'est pas parfait \n", p);
    }
}
int main(void)
{
    parfait();
    return 0;
}