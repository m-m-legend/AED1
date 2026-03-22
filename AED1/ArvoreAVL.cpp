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

// Rota��o direita
No* rotacaoDireita(No* y) {
    No* x = y->esq;
    No* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->h = max(altura(y->esq), altura(y->dir)) + 1;
    x->h = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

// Rota��o esquerda
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

// Menor valor da subárvore
No* menorNo(No* n) {
    No* atual = n;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

// Remoção AVL
No* remover(No* raiz, int v) {
    if (raiz == NULL)
        return raiz;

    // Remoção padrão BST
    if (v < raiz->e)
        raiz->esq = remover(raiz->esq, v);
    else if (v > raiz->e)
        raiz->dir = remover(raiz->dir, v);
    else {
        // Nó com 1 ou 0 filhos
        if (raiz->esq == NULL || raiz->dir == NULL) {
            No* temp = raiz->esq ? raiz->esq : raiz->dir;

            // Sem filho
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                // Um filho
                *raiz = *temp;
            }

            free(temp);
        } else {
            // Nó com 2 filhos
            No* temp = menorNo(raiz->dir);

            raiz->e = temp->e;

            raiz->dir = remover(raiz->dir, temp->e);
        }
    }

    // Se a árvore ficou vazia
    if (raiz == NULL)
        return raiz;

    // Atualiza altura
    raiz->h = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int f = fator(raiz);

    // Rebalanceamento (mesmos 4 casos)

    // LL
    if (f > 1 && fator(raiz->esq) >= 0)
        return rotacaoDireita(raiz);

    // LR
    if (f > 1 && fator(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // RR
    if (f < -1 && fator(raiz->dir) <= 0)
        return rotacaoEsquerda(raiz);

    // RL
    if (f < -1 && fator(raiz->dir) > 0) {
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

// Impressão
void imprimirArvore(No* raiz, int espaco) {
    if (raiz == NULL)
        return;

    espaco += 5;

    imprimirArvore(raiz->dir, espaco);

    printf("\n");
    for (int i = 5; i < espaco; i++)
        printf(" ");
    printf("%d\n", raiz->e);

    imprimirArvore(raiz->esq, espaco);
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

    printf("\nRemovendo 40...\n");
    raiz = remover(raiz, 40);

    printf("AVL em ordem: ");
    emOrdem(raiz);

    printf("\n\nEstrutura da AVL:\n");
    imprimirArvore(raiz, 0);
}

