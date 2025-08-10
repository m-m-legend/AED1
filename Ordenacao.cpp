#include <stdio.h>

//Insertion Sort
void InsertionSort(int B[], int n){ 
	int j;
	if(n>1){
		InsertionSort(B, n-1);
		j = n-1;
		while(j>0 && B[j-1]>B[j]){
			int troca = B[j-1];
			B[j-1] = B[j];
			B[j] = troca;
			j--;
		
		}
		
}
}
//Merge Sort
void Merge(int B[], int inicio, int meio, int fim) {
    int tam = fim-inicio+1;int C[tam]; int i = inicio; int j = meio+1; 
    for(int k = 0;k < tam;k++){
    	if(j>fim || (i<=meio && B[i] <= B[j])){
    		C[k] = B[i];
    		i++;
		}
		else{
			C[k] = B[j];
			j++;
		}
		
	}
	for(int r = 0, p=inicio;r < tam;r++,p++){
			B[p] = C[r];
		}
    
}

void MergeSort(int B[], int inicio, int fim) {
    if (inicio < fim) {
        int m = (inicio + fim) / 2;
        MergeSort(B, inicio, m);
        MergeSort(B, m + 1, fim);
        Merge(B, inicio, m, fim);
    }
}

//Selection Sort
void SelectionSort(int B[], int n){
	int pmax,i;
	if(n>1){
		pmax = 0;
		for(i = 1;i<n;i++){
			if(B[pmax] < B[i]){
				pmax = i;
			}
		}
		int troca = B[pmax];
		B[pmax] = B[n-1];
		B[n-1] = troca;
		SelectionSort(B,n-1);
	}
}



void Imprime(int vet[], int n){
	for(int i = 0;i<n;i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}

int main(){
	int vet[5] = {3,9,1,2,7};
	int vet2[5] = {2,7,1,4,9};
	Imprime(vet,5);
	InsertionSort(vet,5);
	Imprime(vet,5);
	Imprime(vet2,5);
	MergeSort(vet2,0,4);
	Imprime(vet2,5);
	
	
	
	
	
	
	
	
	return 0;
}
