#include <stdio.h>
#include <stdlib.h>

struct No {
	int E;
	No * Prox;
};

//Lista encadeada com ordenação

void insere_ord(No * &L, int &n, int x) {
	No * Novo = (No *)malloc(sizeof(No));
	Novo->E = x;
	if (L == NULL || L->E > x) {
		Novo->Prox = L;
		L = Novo;
		return;
	}
	No * aux = L;
	while (aux->Prox != NULL && aux->Prox->E < x) {
		aux = aux->Prox;
	}
	Novo->Prox = aux->Prox;
	aux->Prox = Novo;
	n++;
}

void ordena(No * &L, int n) {
	No * atual = L;
	int aux;
	if (n > 1) {
		for (int i = 0; i < n; i++) {
			atual = L;
			for (int j = 0; j < n-i-1; j++) {
				if (atual->E > atual->Prox->E) {
					aux = atual->E;
					atual->E = atual->Prox->E;
					atual->Prox->E = aux;
				}
				atual = atual->Prox;
			}
		}
	}
}

int busca(No* L, int x) {
    No* aux = L;
    int pos = 0;
    while (aux != NULL) {
        if (aux->E == x) return pos;
        aux = aux->Prox;
        pos++;
    }
    return -1;
}

void remove_valor(No* &L, int &n, int x) {
    while (L != NULL && L->E == x) { // Remove do início
        No* temp = L;
        L = L->Prox;
        free(temp);
        n--;
    }

    No* aux = L;
    while (aux != NULL && aux->Prox != NULL) {
        if (aux->Prox->E == x) {
            No* temp = aux->Prox;
            aux->Prox = temp->Prox;
            free(temp);
            n--;
        } else {
            aux = aux->Prox;
        }
    }
}


void insere_depois(No * &L, int &n, int x) {
	No * aux = L, * Novo = (No *)malloc(sizeof(No));
	Novo->E = x;
	Novo->Prox = NULL;
	while (aux->Prox != NULL) {
		aux = aux->Prox;
	}
	aux->Prox = Novo;
	n++;
}

void insere_antes(No * &L, int &n, int x) {
	No * Novo = (No *)malloc(sizeof(No));
	Novo->E = x;
	Novo->Prox = L;
	L = Novo;
	n++;
}

void imprime(No * L) {
	No * aux = L;
	while (aux != NULL) {
		printf("[%d] ", aux->E);
		aux = aux->Prox;
	}
	printf("\n");
}

int main() {
	No* L = NULL;
	int n = 0;
	insere_antes(L, n, 3);
	insere_antes(L, n, 2);
	insere_antes(L, n, 1);
	insere_depois(L, n, 0);
	insere_depois(L, n, 0);
	insere_depois(L, n, 0);
	insere_depois(L, n, 10);
	insere_depois(L, n , -1);
	imprime(L);
	ordena(L, n);
	imprime(L);
	insere_ord(L, n, -3);
	insere_ord(L, n, 5);
	insere_ord(L, n, 2);
	imprime(L);
	
	return 0;
}
