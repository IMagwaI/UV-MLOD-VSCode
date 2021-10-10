#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[], int length)
{
    int nbrChange =0;
    for(int i =0;i<length;i++){
        if (tab[i] != tab[i+1]){
            nbrChange++;
            if(nbrChange>=2){
                printf("non convexe\n");
                return false;
            }
        }else{
            nbrChange=0;
        }
    }
    printf("convexe\n");
    return true;
}

int main(void)
{
    bool T1[5] = {false, true, true, false, false};
    bool T2[5] = {false, true, true, false, true};

    estConvexe(T1, 5);
    estConvexe(T2, 5);
    return 0;
}