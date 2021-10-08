#include <stdio.h>

void parfait(int p)
{
    int sum = 0;
   /*  double divi[100]; */
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
    parfait(28);
    return 0;
}