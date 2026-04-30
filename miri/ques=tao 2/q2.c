#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    int dado;
    struct No *esq;
    struct No *dir;
}No;

No* criaNo (int valor,int dado){
    No* novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->chave=valor;
        novo->dado=dado;
        novo->dir=NULL;
        novo->esq=NULL;
    }
    return novo;
}

No* inserir(No* raiz, int valor,int dado){
    if(raiz==NULL){
        return criaNo(valor,dado);
    }
    if(valor<raiz->chave){
        raiz->esq=inserir(raiz->esq,valor,dado);
    }else if (valor>raiz->chave){
        raiz->dir=inserir(raiz->dir,valor,dado);
    }
    return raiz;
}

void ler_ordenado(No* raiz,FILE *arq){
    if(raiz!=NULL){
        ler_ordenado(raiz->esq);
        printf(" %d\n", raiz->dado);
        fprintf(arg,"%d",raiz->dado);
        ler_ordenado(raiz->dir);
    }
}

void ler_arquivo(char *questao2.txt){
    FILE *arq = fopen(questao2.txt,"r");
    if(arq==NULL){
    printf("Erro ao criar arquivo\n");
    return
    }
    char c;
    while ((c=fgetc(arq))!=EOF){
        printf("%c",c);
    }
    printf("\n");
    fclose(arq);
}


int main(){
    No* raiz=NULL;
    int i=0;
    int idmalas[]={1,2,3,4,5,6,7,8,9,9};
    int dadomalas[]={1,2,3,4,5,6,7,8,9,10};
    while (i<10)
    {
        raiz=inserir(raiz,idmalas[i],dadomalas[i]);
        i++;
    }

    


    FILE *arq=fopen("questao2.txt","w");
    if(arq==NULL){
        printf("Erro ao criar arquivo\n");
        return 1;
    }

    ler_ordenado(raiz,arq);
    fclose(arq);
    printf("Arquivo Gerado com Sucesso\n");

    ler_arquivo("questao2");
}