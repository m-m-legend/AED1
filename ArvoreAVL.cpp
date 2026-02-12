#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int e;
    int h;
    struct No* esq;
    struct No* dir;
} No;

int max(int a, int b) { return (a > b) ? a : b; }

int altura(No* n) {
    return (n == NULL) ? 0 : n->h;
}

No* novoNo(int v) {
    No* n = (No*)malloc(sizeof(No));
    n->e = v;
    n->esq = n->dir = NULL;
    n->h = 1;
    return n;
}

// Rotação direita
No* rotacaoDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->h = max(altura(y->esq), altura(y->dir)) + 1;
    x->h = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

// Rotação esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->h = max(altura(x->esq), altura(x->dir)) + 1;
    y->h = max(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

// Fator de balanceamento
int fator(No* n) {
    return (n == NULL) ? 0 : altura(n->esq) - altura(n->dir);
}

// Inserir AVL
No* inserir(No* raiz, int v) {
    if (raiz == NULL)
        return novoNo(v);

    if (v < raiz->e)
        raiz->esq = inserir(raiz->esq, v);
    else if (v > raiz->e)
        raiz->dir = inserir(raiz->dir, v);
    else
        return raiz; // sem duplicados

    raiz->h = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int f = fator(raiz);

    // Casos de balanceamento
    if (f > 1 && v < raiz->esq->e)
        return rotacaoDireita(raiz);

    if (f < -1 && v > raiz->dir->e)
        return rotacaoEsquerda(raiz);

    if (f > 1 && v > raiz->esq->e) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (f < -1 && v < raiz->dir->e) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

// Percurso em ordem
void emOrdem(No* raiz) {
    if (!raiz) return;
    emOrdem(raiz->esq);
    printf("%d ", raiz->e);
    emOrdem(raiz->dir);
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);

    printf("AVL em ordem: ");
    emOrdem(raiz);
}

