#include <stdio.h>
#include <locale.h>
// Lista sequencial não ordenada

void Insere(int L[], int &n, int x){//T(1)
	L[n] = x;
	n++;
}
//BUSCA
int Busca(int L[], int n, int x){ //O(n)
	for(int i = 0;i<n;i++){
		if(L[i] == x){
			return i;
		}
	} return -1;
}
//REMOVE
void Remove(int L[], int &n, int x){ //O(n)
	if(Busca(L,n,x) != -1){
		for(int j = Busca(L,n,x);j<n;j++){
			L[j] = L[j+1];
		}
		n--;
		}
	else{
		printf("Seu elemento não foi encontrado. \n");
	}
	}	
//IMPRIME
void Imprime(int L[], int n){ //T(n)
	for(int i = 0;i<n;i++){
		printf("[%d]", L[i]); 
	}
	printf("\n");
}

//ORDENA
void Ordena(int L[], int n) { //O(n²) - bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (L[j] > L[j + 1]) {
                int troca = L[j];
                L[j] = L[j + 1];
                L[j + 1] = troca;
            }
        }
    }
}



int main(){
	setlocale(LC_ALL,"Portuguese");
	int V[1000]; int n = 0;
	Insere(V,n,10); //n = 1;
	Insere(V,n,15);
	Insere(V,n,18);
	Insere(V,n,12);  
	Imprime(V,n);//[10][15][18][12];
	printf("%d\n", Busca(V,n,15)); // retornar 1;
	Remove(V,n,15);
	Imprime(V,n);//[10][18][12];
	Insere(V,n,11);
	Insere(V,n,9);
	Insere(V,n,-2);
	Insere(V,n,5);
	
	Ordena(V,n);
	Imprime(V,n);
	
	
	
	
	
	
	
	
	
	
	
	
}
