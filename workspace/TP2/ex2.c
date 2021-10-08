#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[], int length)
{
    int nbrChange =0;
    for(int i =0;i<length;i++){
        if (tab[i] != tab[i+1]){
            nbrChange++;
            return nbrChange<=2;
        }
    }
}
/* 
bool estConvexe(bool tab[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (tab[i] != tab[i + 1])
        {
            if (i == 0 && tab[0] == tab[-1])
            {
                continue;
            }
            printf("no c");
            return false;
        }
    }
    printf("ye");
    return true;
} */
int main(void)
{
    bool T1[5] = {false, true, true, false, false};
    estConvexe(T1, 5);
    return 0;
}