#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct aviao{
    char codAviao[7];
    char tipo;          // P = pouso, D = decolagem
    int qtdCombustivel; // entre 0-12, 0 = prioridade maxima de pouso
} Aviao;

typedef struct lista{
    int qtdAvioes;      // entre 10 e 64, gerados aleatoriamente
    clock_t tempoInicio;
    struct lista* prox;
} Lista;

typedef struct filaPouso{
    Lista *ini;
    Lista *fim;
} FilaPouso;

typedef struct filaDecolagem{
    Lista *ini;
    Lista *fim;
} FilaDecolagem;

int main(){

    // FILE *fp;
    // char nomeArquivo[] = "lista_voos.txt";

    // fp = fopen(nomeArquivo, "r");
    // if (fp == NULL) {
    //     printf("Falha ao abrir o arquivo.\n");
    //     exit(1);
    // }

    // while (!feof(fp)) {
    //     //
    // }

    // fclose(fp);
    // return 0;

    int c;
    FILE *file;
    file = fopen("lista_voos.txt", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
}