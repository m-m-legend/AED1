#include <stdio.h>
#include <stdlib.h>

// Lista simplesmente encadeada, não ordenada
typedef struct No {
    int E;
    struct No* Prox;
} No;

// INSERE no início
void Insere(No*& L, int e, int& n) {
    No* novo = (No*) malloc(sizeof(No));
    novo->E = e;
    novo->Prox = L;
    L = novo;
    n++;
}

// REMOVE elemento
void Remove(No*& L, int e, int& n) {
    if (L == NULL) return; // lista vazia

    No* p = L;
    No* pAnt = NULL;

    // procura elemento
    while (p != NULL && p->E != e) {
        pAnt = p;
        p = p->Prox;
    }

    if (p == NULL) return; // não achou

    if (pAnt == NULL) { // é o primeiro elemento
        L = p->Prox;
    } else {
        pAnt->Prox = p->Prox;
    }

    free(p);
    n--;
}

// BUSCA elemento
int Busca(No* L, int e) {
    No* p = L;
    while (p != NULL) {
        if (p->E == e) return 1;
        p = p->Prox;
    }
    return 0;
}

// IMPRIME lista
void Imprime(No* L) {
    No* p = L;
    while (p != NULL) {
        printf("[%d]", p->E);
        p = p->Prox;
        if (p != NULL) printf(" -> ");
    }
    printf("\n");
}

int main() {
    No* lista = NULL;
    int n = 0;

    Insere(lista, 15, n);
    Insere(lista, 10, n);
    Insere(lista, 5, n);

    printf("Lista inicial:\n");
    Imprime(lista);

    printf("Busca 12: %d\n", Busca(lista, 12));
    printf("Busca 15: %d\n", Busca(lista, 15));

    Remove(lista, 10, n);
    printf("Após remover 10:\n");
    Imprime(lista);

    Remove(lista, 5, n);
    printf("Após remover 5:\n");
    Imprime(lista);

    return 0;
}

