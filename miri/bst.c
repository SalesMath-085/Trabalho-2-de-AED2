#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BST* bst_criar() {
    BST *arv = malloc(sizeof(BST));
    arv->raiz = NULL;
    return arv;
}

No* inserirNoBST(No *no, int valor) {
    if (no == NULL) {
        No *novo = malloc(sizeof(No));
        novo->chave = valor;
        novo->esq   = NULL;
        novo->dir   = NULL;
        return novo;
    }

    if (valor < no->chave)
        no->esq = inserirNoBST(no->esq, valor);
    else if (valor > no->chave)
        no->dir = inserirNoBST(no->dir, valor);

    return no;
}

void bst_inserir(BST *arv, int valor) {
    arv->raiz = inserirNoBST(arv->raiz, valor);
}

No* buscarNoBST(No *no, int valor) {
    if (no == NULL)         return NULL;
    if (valor == no->chave) return no;

    if (valor < no->chave)
        return buscarNoBST(no->esq, valor);
    else
        return buscarNoBST(no->dir, valor);
}

No* bst_buscar(BST *arv, int valor) {
    return buscarNoBST(arv->raiz, valor);
}

void preFixado(No *no) {
    if (no == NULL) return;
    printf("%d ", no->chave);
    preFixado(no->esq);
    preFixado(no->dir);
}

void central(No *no) {
    if (no == NULL) return;
    central(no->esq);
    printf("%d ", no->chave);
    central(no->dir);
}

void posFixado(No *no) {
    if (no == NULL) return;
    posFixado(no->esq);
    posFixado(no->dir);
    printf("%d ", no->chave);
}

void bst_preFixado(BST *arv) {
    printf("Pre-fixado : ");
    preFixado(arv->raiz);
    printf("\n");
}

void bst_central(BST *arv) {
    printf("Central    : ");
    central(arv->raiz);
    printf("\n");
}

void bst_posFixado(BST *arv) {
    printf("Pos-fixado : ");
    posFixado(arv->raiz);
    printf("\n");
}

int alturaNoBST(No *no) {
    if (no == NULL) return 0;

    int altEsq = alturaNoBST(no->esq);
    int altDir = alturaNoBST(no->dir);

    return 1 + (altEsq > altDir ? altEsq : altDir);
}

int bst_altura(BST *arv) {
    return alturaNoBST(arv->raiz);
}

void destruirNoBST(No *no) {
    if (no == NULL) return;
    destruirNoBST(no->esq);
    destruirNoBST(no->dir);
    free(no);
}

void bst_destruir(BST *arv) {
    destruirNoBST(arv->raiz);
    free(arv);
}