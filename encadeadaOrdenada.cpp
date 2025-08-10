#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista simplesmente encadeada, ordenada
typedef struct No {
    int e;
    struct No* prox;
} No;

void inserir(No** L, int v) {
    No* n = (No*)malloc(sizeof(No));
    n->e = v;
    n->prox = NULL;

    if (*L == NULL || v <= (*L)->e) {
        n->prox = *L;
        *L = n;
        return;
    }

    No* anterior = *L;
    No* atual = (*L)->prox;

    while (atual != NULL && atual->e < v) {
        anterior = atual;
        atual = atual->prox;
    }

    n->prox = atual;
    anterior->prox = n;
}

void remover(No** L, int v) {
    if (*L == NULL) return;

    while (*L != NULL && (*L)->e == v) {
        No* temp = *L;
        *L = (*L)->prox;
        free(temp);
    }

    No* atual = *L;
    while (atual != NULL && atual->prox != NULL) {
        if (atual->prox->e == v) {
            No* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

No* busca(No* L, int v) {
    while (L != NULL) {
        if (L->e == v) return L;
        L = L->prox;
    }
    return NULL;
}

void printList(No* head) {
    No* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->e);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void insertingRandoms(No** head, int min, int max, int count) {
    for (int i = 0; i < count; i++) {
        int rd_num = rand() % (max - min + 1) + min;
        inserir(head, rd_num);
    }
}

int main() {
    srand(time(NULL));

    No* head = NULL;

    inserir(&head, 1);
    inserir(&head, 2);
    inserir(&head, 3);
    inserir(&head, 6);
    inserir(&head, 5);
    inserir(&head, -1);
    inserir(&head, 0);

    printList(head);

    remover(&head, 2);
    remover(&head, -1);

    printList(head);

    No* found = busca(head, 6);
    if (found) printf("Encontrado: %d\n", found->e);
    else printf("Não encontrado\n");

    return 0;
}

