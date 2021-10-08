#include <stdio.h>


void possibiliter(int p){
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                if (i + j + k == p)
                {
                    printf("%d%d%d\n", i, j, k);
                }
            }
        }
    }
}
int main(void)
{
    possibiliter(5);
    return 0;

}