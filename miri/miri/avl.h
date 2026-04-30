#ifndef AVL_H
#define AVL_H

typedef struct NoAVL {
    int chave;
    int altura;
    struct NoAVL *esq;
    struct NoAVL *dir;
} NoAVL;

typedef struct {
    NoAVL *raiz;
} AVL;

AVL*   avl_criar();
void   avl_inserir(AVL *arv, int valor);
NoAVL* avl_buscar(AVL *arv, int valor);
int    avl_altura(AVL *arv);
void   avl_destruir(AVL *arv);

#endif