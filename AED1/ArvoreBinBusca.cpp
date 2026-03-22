#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int e;
    struct No* esq;
    struct No* dir;
} No;

// Criar nó
No* novoNo(int v) {
    No* n = (No*)malloc(sizeof(No));
    n->e = v;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// Inserir na BST
No* inserir(No* raiz, int v) {
    if (raiz == NULL) return novoNo(v);

    if (v < raiz->e)
        raiz->esq = inserir(raiz->esq, v);
    else
        raiz->dir = inserir(raiz->dir, v);

    return raiz;
}

// Buscar
No* busca(No* raiz, int v) {
    if (raiz == NULL || raiz->e == v)
        return raiz;

    if (v < raiz->e)
        return busca(raiz->esq, v);
    return busca(raiz->dir, v);
}

// Menor valor (para remoção)
No* minimo(No* raiz) {
    while (raiz->esq != NULL)
        raiz = raiz->esq;
    return raiz;
}

// Remover
No* remover(No* raiz, int v) {
    if (raiz == NULL) return NULL;

    if (v < raiz->e)
        raiz->esq = remover(raiz->esq, v);
    else if (v > raiz->e)
        raiz->dir = remover(raiz->dir, v);
    else {
        // 0 ou 1 filho
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        }
        if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // 2 filhos
        No* temp = minimo(raiz->dir);
        raiz->e = temp->e;
        raiz->dir = remover(raiz->dir, temp->e);
    }
    return raiz;
}

// Percurso em ordem
void emOrdem(No* raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esq);
    printf("%d ", raiz->e);
    emOrdem(raiz->dir);
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 10);
    inserir(raiz, 5);
    inserir(raiz, 20);
    inserir(raiz, 1);
    inserir(raiz, 7);

    printf("Em ordem: ");
    emOrdem(raiz);

    printf("\nRemovendo 10\n");
    raiz = remover(raiz, 10);

    printf("Em ordem: ");
    emOrdem(raiz);

    No* f = busca(raiz, 7);
    if (f) printf("\nEncontrado: %d\n", f->e);

    return 0;
}

