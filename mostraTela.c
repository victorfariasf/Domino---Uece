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

void imprimeMesa(struct peca pecaJogada, struct peca *mesaL1, struct peca *mesaL2, int qualLado){
    // 1 - esquerdo e 2 - direito
    system("cls");
    if(qualLado == 1){
        if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito >= 0){
            printf("|%d|%d| - |%d|%d|\n", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
        }else if(mesaL2->ladoDireito == -1 && mesaL1->ladoDireito >= 0){
            printf("|%d|%d| - |%d|%d|\n", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito, mesaL1->ladoEsquerdo, mesaL1->ladoDireito);
        }else if(mesaL1->ladoDireito >= 0 && mesaL2->ladoEsquerdo >= 0){
            printf("|%d|%d| - |%d|%d| - |%d|%d|\n", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito, mesaL1->ladoEsquerdo, mesaL1->ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
        }
    }else{
        if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito >= 0){
            printf("|%d|%d| - |%d|%d|\n", mesaL2->ladoEsquerdo, mesaL2->ladoDireito, pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
        }else if(mesaL2->ladoDireito == -1 && mesaL1->ladoDireito >= 0){
            printf("|%d|%d| - |%d|%d|\n", mesaL1->ladoEsquerdo, mesaL1->ladoDireito, pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito );
        }else if(mesaL1->ladoDireito >= 0 && mesaL2->ladoEsquerdo >= 0){
            printf("|%d|%d| - |%d|%d| - |%d|%d|\n", mesaL1->ladoEsquerdo, mesaL1->ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito, pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
        }

    }

}

void imprimeSimples(struct peca *mesaL1, struct peca *mesaL2){

    if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito >= 0){
        printf("sem peça do lado esquerdo - |%d|%d|\n", mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
    }else if(mesaL2->ladoDireito == -1 && mesaL1->ladoDireito >= 0){
        printf("|%d|%d| - sem peça do lado direito\n", mesaL1->ladoEsquerdo, mesaL1->ladoDireito);
    }else if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito == -1){
        printf("sem peça na mesa\n");
    }

}
