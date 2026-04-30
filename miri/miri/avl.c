#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

AVL* avl_criar() {
    AVL *arv = malloc(sizeof(AVL));
    arv->raiz = NULL;
    return arv;
}

int alturaNo(NoAVL *no) {
    if (no == NULL) return 0;
    return no->altura;
}

int maximo(int a, int b) {
    return a > b ? a : b;
}

int fatorBalanceamento(NoAVL *no) {
    if (no == NULL) return 0;
    return alturaNo(no->esq) - alturaNo(no->dir);
}

NoAVL* rotacaoDireita(NoAVL *y) {
    NoAVL *x  = y->esq;
    NoAVL *t2 = x->dir;

    x->dir = y;
    y->esq = t2;

    y->altura = 1 + maximo(alturaNo(y->esq), alturaNo(y->dir));
    x->altura = 1 + maximo(alturaNo(x->esq), alturaNo(x->dir));

    return x;
}

NoAVL* rotacaoEsquerda(NoAVL *x) {
    NoAVL *y  = x->dir;
    NoAVL *t2 = y->esq;

    y->esq = x;
    x->dir = t2;

    x->altura = 1 + maximo(alturaNo(x->esq), alturaNo(x->dir));
    y->altura = 1 + maximo(alturaNo(y->esq), alturaNo(y->dir));

    return y;
}

NoAVL* inserirNo(NoAVL *no, int valor) {
    if (no == NULL) {
        NoAVL *novo = malloc(sizeof(NoAVL));
        novo->chave  = valor;
        novo->altura = 1;
        novo->esq    = NULL;
        novo->dir    = NULL;
        return novo;
    }

    if (valor < no->chave)
        no->esq = inserirNo(no->esq, valor);
    else if (valor > no->chave)
        no->dir = inserirNo(no->dir, valor);
    else
        return no;

    no->altura = 1 + maximo(alturaNo(no->esq), alturaNo(no->dir));

    int fb = fatorBalanceamento(no);

    if (fb > 1 && valor < no->esq->chave)
        return rotacaoDireita(no);

    if (fb < -1 && valor > no->dir->chave)
        return rotacaoEsquerda(no);

    if (fb > 1 && valor > no->esq->chave) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (fb < -1 && valor < no->dir->chave) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

void avl_inserir(AVL *arv, int valor) {
    arv->raiz = inserirNo(arv->raiz, valor);
}

NoAVL* buscarNo(NoAVL *no, int valor) {
    if (no == NULL)          return NULL;
    if (valor == no->chave)  return no;

    if (valor < no->chave)
        return buscarNo(no->esq, valor);
    else
        return buscarNo(no->dir, valor);
}

NoAVL* avl_buscar(AVL *arv, int valor) {
    return buscarNo(arv->raiz, valor);
}

int avl_altura(AVL *arv) {
    return alturaNo(arv->raiz);
}

void destruirNo(NoAVL *no) {
    if (no == NULL) return;
    destruirNo(no->esq);
    destruirNo(no->dir);
    free(no);
}

void avl_destruir(AVL *arv) {
    destruirNo(arv->raiz);
    free(arv);
}