#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Lista simplesmente encadeada, circular
typedef struct No {
    int E;
    struct No* Prox;
} No;

// BUSCA
int Busca(No* L, int x) {
    if (L == NULL) return 0;
    No* p = L;
    do {
        if (p->E == x) return 1;
        p = p->Prox;
    } while (p != L);
    return 0;
}

// IMPRIME
void Imprime(No* L) {
    if (L == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No* p = L;
    do {
        printf("[%d]", p->E);
        p = p->Prox;
        if (p != L) printf(" -> ");
    } while (p != L);
    printf("\n\n");
}

// INSERE NO INÍCIO
void Insere(No** L, int x, int* n) {
    No* novo = (No*)malloc(sizeof(No));
    novo->E = x;

    if (*L == NULL) { // primeira inserção
        novo->Prox = novo;
        *L = novo;
    } else {
        No* ult = *L;
        while (ult->Prox != *L) ult = ult->Prox; // acha o último
        novo->Prox = *L;
        ult->Prox = novo;
        *L = novo; // novo é o primeiro
    }
    (*n)++;
}

// REMOVE UM ELEMENTO
void Remove(No** L, int x, int* n) {
    if (*L == NULL) return;

    No *p = *L, *pAnt = NULL;

    // busca do nó a remover
    do {
        if (p->E == x) break;
        pAnt = p;
        p = p->Prox;
    } while (p != *L);

    if (p->E != x) return; // não achou

    if (p == *L && p->Prox == *L) { // único elemento
        *L = NULL;
    }
    else if (p == *L) { // removendo primeiro
        No* ult = *L;
        while (ult->Prox != *L) ult = ult->Prox;
        *L = (*L)->Prox;
        ult->Prox = *L;
    }
    else { // removendo do meio ou fim
        pAnt->Prox = p->Prox;
    }

    free(p);
    (*n)--;
}

// PROGRAMA PRINCIPAL
int main() {
    No* lista = NULL;
    int n = 0;

    Insere(&lista, 10, &n);
    Insere(&lista, 15, &n);
    Insere(&lista, 20, &n);

    printf("Lista inicial:\n");
    Imprime(lista);

    Remove(&lista, 10, &n);
    printf("Após remover 10:\n");
    Imprime(lista);

    printf("Busca 15: %s\n", Busca(lista, 15) ? "Encontrado" : "Não encontrado");
    printf("Busca 50: %s\n", Busca(lista, 50) ? "Encontrado" : "Não encontrado");

    return 0;
}

