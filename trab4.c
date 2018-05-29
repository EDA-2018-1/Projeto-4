#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct aviao{
    char[7] codAviao;
    char tipo;
    int qtdCombustivel;
} Aviao;

typedef struct lista{
    int qtdAvioes;
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

