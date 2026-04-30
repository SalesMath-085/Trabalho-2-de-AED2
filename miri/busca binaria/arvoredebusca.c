#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *esq;
    struct No *dir;
}No;

No* criaNo (int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->chave=valor;
        novo->dir=NULL;
        novo->esq=NULL;
    }
    return novo;
}

No* inserir(No* raiz, int valor){
    if(raiz==NULL){
        return criaNo(valor);
    }
    if(valor<raiz->chave){
        raiz->esq=inserir(raiz->esq,valor);
    }else if (valor>raiz->chave){
        raiz->dir=inserir(raiz->dir,valor);
    }
    return raiz;
}

void prefixado(No* raiz){
    if(raiz){
        printf(" %d", raiz->chave);
        prefixado(raiz->esq);
        prefixado(raiz->dir);
    }
}

void central(No* raiz){
    if(raiz){
        prefixado(raiz->esq);
        printf(" %d", raiz->chave);
        prefixado(raiz->dir);
    }
}

void pos_fixado(No* raiz) {
    if (raiz) {
        pos_fixado(raiz->esq);
        pos_fixado(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

void liberar_arvore(No* raiz) {
    if (raiz) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

int main(){
    No* raiz=NULL;
    int valores[]={50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45, 55, 65, 75, 85, 10, 22, 38, 42, 90};
    
    for(int i=0;i<20;i++){
        raiz=inserir(raiz,valores[i]);
    }

    prefixado(raiz);

}