#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h> 

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
 
int randomize(int lower, int upper, 
                             int count)
{
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return num;
    }
}
 
int main()
{
	printf("Sorteando...");
	int nVoos = randomize(20, 64, 1); 	
	
	srand((unsigned)time(NULL));
	int nAprox = randomize(10, 32, 1);

	int isValid = 0;
	while(isValid == 0){
		if (nAprox > nVoos){
			nAprox = randomize(10, 32, 1);
		}
		else {
			isValid = 1;
		}
	}

	int nDecolagens = nVoos - nAprox;
    
    printf("\n %d \n %d \n %d \n", nVoos, nAprox, nDecolagens);

    printf("Abastecendo aviões...");
    
    int combA[nAprox];
    int i;
    
    for (i = 0; i < nAprox; i++){
    	combA[i] = randomize(0, 12, 1);
    }
	
	for (i = 0; i < nAprox; i++){
		printf("combA[%d]: %d \n", i, combA[i]);
    }
 	
    int vooOuDecolagem[nVoos];

    for(i = 0; i < nVoos; i++){
    	vooOuDecolagem = randomize(0, 1, 0);
    }

    return 0;
}
