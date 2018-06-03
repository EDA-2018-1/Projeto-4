#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h> 
#include <string.h>

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
 
int randomize(int lower, int upper, int count){
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
	srand((unsigned)time(NULL));

	int nVoos = randomize(20, 64, 1); 	
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
    
    printf("\n Total: %d \n Aprox: %d \n Decol: %d \n", nVoos, nAprox, nDecolagens);

    printf("Abastecendo aviões...\n");
    
    int combA[nAprox];
    int i;
    
    for (i = 0; i < nAprox; i++){
    	combA[i] = randomize(0, 12, 1);
    }
	
	for (i = 0; i < nAprox; i++){
		printf("combA[%d]: %d \n", i, combA[i]);
    }
 	
char codAvioes[64][7] = {"VG3001", "JJ4404", "LN7001", "TG1501", 
							"GL7602", "TT1010", "AZ1009", "AZ1008", 
							"AZ1010", "TG1506", "VG3002", "JJ4402", 
							"GL7603", "RL7880", "AL0012", "TT4544", 
							"TG1505", "VG3003", "JJ4403", "JJ4401", 
							"LN7002", "AZ1002", "AZ1007", "GL7604", 
							"AZ1006", "TG1503", "AZ1003", "JJ4403", 
							"AZ1001", "LN7003", "AZ1004", "TG1504", 
							"AZ1005", "TG1502", "GL7601", "TT4500", 
							"RL7801", "JJ4410", "GL7607", "AL0029", 
							"VV3390", "VV3392", "GF4681", "GF4690", 
							"AZ1020", "JJ4435", "VG3010", "LF0920", 
							"AZ1065", "LF0978", "RL7867", "TT4502", 
							"GL7645", "LF0932", "JJ4434", "TG1510", 
							"TT1020", "AZ1098", "BA2312", "VG3030", 
							"BA2304", "KL5609", "KL5610", "KL5611"};

    char* voosDecolagem = (char*)calloc(sizeof(char)*nDecolagens);
    // char voosAprox[nAprox][7];

    for (i = 0; i < 1; i++){
		printf("%d \n", i);
    	int temp = randomize(0, 64, 1);
    	int isValid = 0;
		strcpy(voosDecolagem[i], codAvioes[temp]); 

    	for(int j = 0; j < nDecolagens; j++){
    		printf("%s\n", voosDecolagem[j]);
	    	if(strcmp(voosDecolagem[j], codAvioes[temp]) == 0){ 
				temp = randomize(0, 64, 1);	  
				strcpy(voosDecolagem[j], codAvioes[temp]); 
	    	}
    	}
    }

    for (i = 0; i < nDecolagens; i++){
    	printf("decolagem[%d] %s\n", i+1, voosDecolagem[i]);
    }

    return 0;
}