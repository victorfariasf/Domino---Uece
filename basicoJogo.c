#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "estruturaJogo.h"
#include "jogo.h"
#include "estruturaJogo.h"
#include "estruturaPeca.h"
#include "basicoJogo.h"

struct peca;
struct jogador;

void identificarJogador (struct jogador jogadoresMain[], int numJogadores){

    //jogadores[numJogadores];

    int i, j;

    for(i = 0; i < 2; i++){
        printf("insira o nome do jogador %d:\n", i + 1);
        fgets(jogadoresMain[i].nome, 50, stdin);
        fflush(stdin);
    }

}

// ----------------- criação das peças --------------------
void iniciandoPecas(struct peca pecas[], int numPecas){

    // Iniciar as peças com suas combinações possíveis

    int pieceI = 0, j, i, embaralharIndice;

    for(i = 0; i < 7; i++){
        for(j = i; j < 7; j++){
            pecas[pieceI].ladoDireito = i;
            pecas[pieceI].ladoEsquerdo = j;
            pieceI++;
        }
    }

}

// ----------- distribuição automática das peças -------------
void distribuirPecas(struct peca pecas[], int numPecas, struct jogador jogadores[], int numJogadores){

    // Embaralhar as peças e dar as peças ao jogador

    int i, j, embaralharIndice;

    srand(time(NULL));

    for(i = 0; i < 2; i++){
        for(j = 0; j < 7; j++){

            embaralharIndice = rand() % 27;
            jogadores[i].mao[j] = pecas[embaralharIndice];

            //---- Deixa NULL o valor da peça que foi passada para o jogador
            //fazendo com que ela fique inutilizada --------

            pecas[embaralharIndice].ladoDireito = NULL;
            pecas[embaralharIndice].ladoEsquerdo = NULL;


            jogadores[i].contadorDePecas++;
        }

    }
}
