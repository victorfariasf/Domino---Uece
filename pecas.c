#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <domino.h>

// Criação de struct em formato peça
typedef struct{//Cima == Lado Direito e Baixo == Lado Esquerdo
    int ladoDireito;
    int ladoEsquerdo;
} peca;

// Criação de struct que representa um jogador
typedef struct {
    char nome[50];
    peca mao[7];
}jogador;


void iniciandoPecas(peca pecas[], int numPecas){

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


void identificarJogador(jogador jogadoresMain[], int numJogadores){

    //jogadores[numJogadores];

    int i, j;

    for(i = 0; i < 2; i++){
        printf("insira o nome do jogador %d:\n", i + 1);
        fgets(jogadoresMain[i].nome, 50, stdin);
        fflush(stdin);
    }

}


void distribuirPecas(peca pecas[], int numPecas, jogador jogadores[], int numJogadores){


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

        }
    }

}
