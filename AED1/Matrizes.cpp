#include <stdio.h>
#include <locale.h>

// IMPRIME MATRIZ
void ImprimeMatriz(int M[][100], int l, int c){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			printf("[%d]", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// SOMA DE MATRIZES
void Soma(int A[][100], int B[][100], int R[][100], int l, int c){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			R[i][j] = A[i][j] + B[i][j];
		}
	}
}

// MULTIPLICAÇÃO DE MATRIZES
void Multiplica(int A[][100], int B[][100], int R[][100], int lA, int cA, int cB){
	for(int i = 0; i < lA; i++){
		for(int j = 0; j < cB; j++){
			R[i][j] = 0;
			for(int k = 0; k < cA; k++){
				R[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

// TRANSPOSTA
void Transposta(int A[][100], int T[][100], int l, int c){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			T[j][i] = A[i][j];
		}
	}
}

// BUSCA EM MATRIZ
int Busca(int M[][100], int l, int c, int x){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			if(M[i][j] == x){
				return 1; // encontrou
			}
		}
	}
	return 0; // não encontrou
}

// SOMA DOS ELEMENTOS
int SomaElementos(int M[][100], int l, int c){
	int soma = 0;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			soma += M[i][j];
		}
	}
	return soma;
}

int main(){
	setlocale(LC_ALL, "");

	int A[100][100] = {
		{1,2,3},
		{4,5,6}
	};

	int B[100][100] = {
		{7,8,9},
		{1,2,3}
	};

	int R[100][100];
	int T[100][100];

	int l = 2, c = 3;

	printf("Matriz A:\n");
	ImprimeMatriz(A, l, c);

	printf("Matriz B:\n");
	ImprimeMatriz(B, l, c);

	// Soma
	Soma(A, B, R, l, c);
	printf("Soma A + B:\n");
	ImprimeMatriz(R, l, c);

	// Transposta de A
	Transposta(A, T, l, c);
	printf("Transposta de A:\n");
	ImprimeMatriz(T, c, l);

	// Busca
	int valor = 5;
	if(Busca(A, l, c, valor)){
		printf("Valor %d encontrado na matriz A\n", valor);
	}else{
		printf("Valor %d NAO encontrado\n", valor);
	}

	// Soma dos elementos
	printf("Soma dos elementos de A: %d\n", SomaElementos(A, l, c));

	// Multiplicação (exemplo compatível)
	int C[100][100] = {
		{1,2},
		{3,4},
		{5,6}
	};

	int R2[100][100];

	printf("\nMultiplicacao A x C:\n");
	Multiplica(A, C, R2, 2, 3, 2);
	ImprimeMatriz(R2, 2, 2);

	return 0;
}