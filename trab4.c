#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

typedef struct no No;
struct no{
    char* nome;
    char tipo;          // P = pouso, D = decolagem
    int comb;           //  entre 0-12, 0 = prioridade maxima de pouso
    No* prox;
};

typedef struct head Head;
struct head{
    No* inicio;
    No* fim;
};

// typedef struct aviao{
//     char codAviao[7];
//     char tipo;          // P = pouso, D = decolagem
//     int qtdCombustivel; // entre 0-12, 0 = prioridade maxima de pouso
// } Aviao;

// typedef struct lista{
//     int qtdAvioes;      // entre 10 e 64, gerados aleatoriamente
//     clock_t tempoInicio;
//     struct lista* prox;
// } Lista;

// typedef struct filaPouso{
//     Lista *ini;
//     Lista *fim;
// } FilaPouso;

// typedef struct filaDecolagem{
//     Lista *ini;
//     Lista *fim;
// } FilaDecolagem;

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

    printf("\nAbastecendo aviões...\n\n");

	// char codAvioes[64][7] = {"VG3001", "JJ4404", "LN7001", "TG1501",
	// 						"GL7602", "TT1010", "AZ1009", "AZ1008",
	// 						"AZ1010", "TG1506", "VG3002", "JJ4402",
	// 						"GL7603", "RL7880", "AL0012", "TT4544",
	// 						"TG1505", "VG3003", "JJ4403", "JJ4401",
	// 						"LN7002", "AZ1002", "AZ1007", "GL7604",
	// 						"AZ1006", "TG1503", "AZ1003", "JJ4403",
	// 						"AZ1001", "LN7003", "AZ1004", "TG1504",
	// 						"AZ1005", "TG1502", "GL7601", "TT4500",
	// 						"RL7801", "JJ4410", "GL7607", "AL0029",
	// 						"VV3390", "VV3392", "GF4681", "GF4690",
	// 						"AZ1020", "JJ4435", "VG3010", "LF0920",
	// 						"AZ1065", "LF0978", "RL7867", "TT4502",
	// 						"GL7645", "LF0932", "JJ4434", "TG1510",
	// 						"TT1020", "AZ1098", "BA2312", "VG3030",
	// 						"BA2304", "KL5609", "KL5610", "KL5611"};

    char codAvioes[64][7] = {"01", "02", "03", "04",
							"05", "06", "07", "08",
							"09", "10", "11", "12",
							"13", "14", "15", "16",
							"17", "18", "19", "20",
							"21", "22", "23", "24",
							"25", "26", "27", "28",
							"29", "30", "31", "32",
							"33", "34", "35", "36",
							"37", "38", "39", "40",
							"41", "42", "43", "44",
							"45", "46", "47", "48",
                            "49", "50", "51", "52",
                            "53", "54", "55", "56",
                            "57", "58", "59", "60",
                            "61", "62", "63", "64"};

    int i;
	No* lista = NULL;
	Head* head = (Head*)malloc(sizeof(Head));
	head->inicio = NULL;
	head->fim = NULL;

	for (i = 0; i < nAprox; i++){
        No* aux = head->inicio;
        int nomeRandom = randomize(0,63,1);
        int combRandom = randomize(0,12,1);

        char* name = (char*)malloc(sizeof(name));
        strcpy(name,codAvioes[nomeRandom]);
        No* novo = (No*)malloc(sizeof(No));
        novo->nome = name;
        novo->tipo = 'A';
        novo->comb = combRandom;
        novo->prox = NULL;

        while(aux != NULL){
            // para verificar se o nome é igual, não pode ter nome repetido
            if(strcmp(aux->nome,novo->nome) == 0){
                int nomeRandom = randomize(0,63,1);
                strcpy(name,codAvioes[nomeRandom]);
                novo->nome = name;
                novo->prox = NULL;
            }
            aux = aux->prox;
        }

        if(head->fim == NULL){
            head->inicio = novo;
            head->fim = novo;
        }else{
            head->fim->prox = novo;
            head->fim = novo;
        }

        printf("Código voo: %s    Tipo: %c    Combustível: %d\n", 
                head->fim->nome, head->fim->tipo, head->fim->comb);
    }

    return 0;
}
