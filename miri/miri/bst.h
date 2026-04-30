#ifndef BST_H
#define BST_H

typedef struct No {
    int chave;
    struct No *esq;
    struct No *dir;
} No;

typedef struct {
    No *raiz;
} BST;

BST* bst_criar();
void bst_inserir(BST *arv, int valor);
No*  bst_buscar(BST *arv, int valor);

void bst_preFixado(BST *arv);
void bst_central(BST *arv);
void bst_posFixado(BST *arv);

int  bst_altura(BST *arv);
void bst_destruir(BST *arv);

#endif