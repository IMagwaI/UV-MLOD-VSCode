#include <stdint.h>
#include <stdlib.h>

void mult_matrice(int mat1[5][5], int mat2[5][5],  int matR[5][5]){
    for(int i =0 ; i<5; i++){
        for( int j=0; j<5; j++){
            int sum =0;
            for(int k=0, m =0;k<5,m<5;k++){
                sum += mat1[i][m]*mat2[m][i];
                m++;
                matR[i][j]=sum;
            }

        }
    }
    return matR;
}



int main(void) {
//matrices en ligne * colonne
int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
int64_t matriceResultat[5][5];
mult_matrice(matriceResultat,matrice1,matrice2);
/* affiche_matrice(matriceResultat);
 */return EXIT_SUCCESS;
}