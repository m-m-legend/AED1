#include <stdio.h>
#include <locale.h>
// Lista sequencial ordenada
int BuscaB(int L[], int n, int x){
	int i,j,m;
	i = 0; j = n-1;
	while(i<=j){
		m = i + (j-i)/2;
		if(L[m] == x){
			return m;
		}
		else if(L[m]<x){
			i = m+1;
		}
		else{
			j = m-1;
		}
	} return -1;
}
//INSERE
void Insere(int L[], int &n, int x){
	int pos;
	int i = 0;
	while(i<n && L[i]<x){
		i++;	
	}
	for(int j = n;j>i;j--){
		L[j] = L[j-1]; //L[n] = L[n-1]
	}
	L[i] = x;
	n++;
}
//IMPRIME
void Imprime(int L[], int n){ //T(n)
	for(int i = 0;i<n;i++){
		printf("[%d]", L[i]); 
	}
	printf("\n");
}


int main(){
	int V[1000] = {15,20,25,30,35,40}; 
	int n = 6;
	Insere(V,n,10);
	Insere(V,n,33);
	Insere(V,n,50);
	Imprime(V,n);
	
	
	
	
	
}
