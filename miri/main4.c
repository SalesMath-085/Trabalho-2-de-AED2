#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "avl.h"

#define TAMANHO  1000000
#define REPETICOES 10
#define BUSCAS   30

int main() {
    srand(42);

    int *valores = malloc(sizeof(int) * TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
        valores[i] = rand();

    int busca[BUSCAS];
    for (int i = 0; i < BUSCAS; i++)
        busca[i] = valores[rand() % TAMANHO];

    printf("=== Tempo de criacao ===\n");
    printf("%-5s %-15s %-15s %-10s %-10s\n",
           "Exec", "BST (ms)", "AVL (ms)", "Alt BST", "Alt AVL");

    for (int i = 0; i < REPETICOES; i++) {

        clock_t ini = clock();
        BST *bst = bst_criar();
        for (int j = 0; j < TAMANHO; j++)
            bst_inserir(bst, valores[j]);
        clock_t fim = clock();
        double tempoBST = (double)(fim - ini) / CLOCKS_PER_SEC * 1000;

        ini = clock();
        AVL *avl = avl_criar();
        for (int j = 0; j < TAMANHO; j++)
            avl_inserir(avl, valores[j]);
        fim = clock();
        double tempoAVL = (double)(fim - ini) / CLOCKS_PER_SEC * 1000;

        printf("%-5d %-15.2f %-15.2f %-10d %-10d\n",
               i + 1,
               tempoBST,
               tempoAVL,
               bst_altura(bst),
               avl_altura(avl));

        bst_destruir(bst);
        avl_destruir(avl);
    }

    printf("\n=== Tempo de busca ===\n");

    BST *bst = bst_criar();
    AVL *avl = avl_criar();
    for (int i = 0; i < TAMANHO; i++) {
        bst_inserir(bst, valores[i]);
        avl_inserir(avl, valores[i]);
    }

    printf("%-8s %-15s %-15s\n", "Busca", "BST (us)", "AVL (us)");

    double totalBST = 0, totalAVL = 0;

    for (int i = 0; i < BUSCAS; i++) {

        clock_t ini = clock();
        bst_buscar(bst, busca[i]);
        clock_t fim = clock();
        double tempoBST = (double)(fim - ini) / CLOCKS_PER_SEC * 1000000;

        ini = clock();
        avl_buscar(avl, busca[i]);
        fim = clock();
        double tempoAVL = (double)(fim - ini) / CLOCKS_PER_SEC * 1000000;

        totalBST += tempoBST;
        totalAVL += tempoAVL;

        printf("%-8d %-15.4f %-15.4f\n", i + 1, tempoBST, tempoAVL);
    }

    printf("\nMedia BST: %.4f us\n", totalBST / BUSCAS);
    printf("Media AVL: %.4f us\n", totalAVL / BUSCAS);

    bst_destruir(bst);
    avl_destruir(avl);
    free(valores);

    return 0;
}
