// gcc --std=c99 -Wall matrices.c -o matrices
// ./matrices < matrices.txt > out.txt
// diff matrices.txt out.txt

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./matrices < matrices.txt > out.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// correction  //

struct Matrix
{
	int nbrLigne;
	int nbrColonne;
	int **valeurs;
};
typedef struct Matrix Matrix;

struct MatrixArray
{
	int nbrmatrix;
	Matrix *matrix;
};

typedef struct MatrixArray MatrixArray;

void readMatrix(Matrix *matrix)
{
	/* 	int l, c; */
	scanf("%i %i", &matrix->nbrLigne, &matrix->nbrColonne);
	matrix->valeurs = calloc(matrix->nbrLigne, sizeof(int *));
	for (int i = 0; i < matrix->nbrLigne; i++)
	{
		matrix->valeurs[i] = calloc(matrix->nbrColonne, sizeof(int));
		for (int k = 0; k < (*matrix).nbrColonne; k++)
		{
			scanf("%i", &matrix->valeurs[i][k]);
		}
	}
}
void readMatrixArray(MatrixArray listeMatrice)
{
	for (int i = 0; i < listeMatrice.nbrmatrix; i++)
	{
		readMatrix(&listeMatrice.matrix[i]);
	}
}

void printMatrice(Matrix *matrice)
{
	printf("%d %d\n", matrice->nbrLigne, matrice->nbrColonne);
	for (int i = 0; i < matrice->nbrLigne; i++)
	{
		for (int j = 0; j < matrice->nbrColonne; j++)
		{
			if (j != 0)
			{
				printf(" ");
			};
			printf("%i", matrice->valeurs[i][j]);
			
		}
		printf("\n");
	}
}
void printArrayMatrice(MatrixArray listeMatrix)
{
	printf("%d\n", listeMatrix.nbrmatrix);
	for (int i = 0; i < listeMatrix.nbrmatrix; i++)
	{
		printMatrice(&listeMatrix.matrix[i]);
	}
}

void freeMatrix(Matrix *matrice)
{
	for (int i = 0; i < matrice->nbrLigne; i++)
	{
		free(matrice->valeurs[i]);
		matrice->valeurs[i] = NULL;
	}
	free(matrice->valeurs);
	matrice->valeurs = NULL;
}
void freeMatrixArray(MatrixArray listeMatrix)
{
	for (int i = 0; i < listeMatrix.nbrmatrix; i++)
	{
		freeMatrix(&listeMatrix.matrix[i]);
	};
	free(listeMatrix.matrix);
	listeMatrix.matrix = NULL;
};
int main(void)
{
	MatrixArray listeMatrix;
	scanf("%d", &listeMatrix.nbrmatrix);
	/*printf("%d", nbrMatrix);
	 	Matrix *matrice;
	readMatrix(matrice); */
	listeMatrix.matrix = calloc(listeMatrix.nbrmatrix, sizeof(Matrix));
	readMatrixArray(listeMatrix);
	printArrayMatrice(listeMatrix);
	freeMatrixArray(listeMatrix);

	return EXIT_SUCCESS;
}