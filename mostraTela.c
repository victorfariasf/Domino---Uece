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

void imprimeLadoEsquerdo(struct peca pecaJogada, struct peca *mesaL1, struct peca *mesaL2){

    if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito == -1){
        printf("|%d|%d| - ", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
    }
    else if(mesaL1->ladoDireito != -1 && mesaL2->ladoDireito == -1){
        printf("|%d|%d| - |%d|%d| -", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito, mesaL1->ladoEsquerdo, mesaL1->ladoDireito);
    }
    else if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito != -1){
            printf("|%d|%d| - |%d|%d| -", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
    }
    else if(mesaL1->ladoDireito != -1 && mesaL2->ladoEsquerdo != -1){
            printf("|%d|%d| - |%d|%d| - |%d|%d|", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito, mesaL1->ladoEsquerdo, mesaL1->ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
    }

}

void imprimeLadoDireito(struct peca pecaJogada, struct peca *mesaL1, struct peca *mesaL2){

    if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito == -1){
        printf("|%d|%d| - ", pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
    }
    else if(mesaL1->ladoDireito != -1 && mesaL2->ladoDireito == -1){
        printf("|%d|%d| - |%d|%d| -", mesaL1->ladoEsquerdo, mesaL1->ladoDireito, pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
    }
    else if(mesaL1->ladoDireito == -1 && mesaL2->ladoDireito != -1){
            printf("|%d|%d| - |%d|%d| -", mesaL2->ladoEsquerdo, mesaL2->ladoDireito, pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
    }
    else if(mesaL1->ladoDireito != -1 && mesaL2->ladoEsquerdo != -1){
            printf("|%d|%d| - |%d|%d| - |%d|%d|", mesaL1->ladoEsquerdo, mesaL1->ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito, pecaJogada.ladoEsquerdo, pecaJogada.ladoDireito);
    }

}



/*void imprimeMesa(struct peca pecaJogada, struct peca *mesaL1, struct peca *mesaL2, int qualLado){
    // 1 - esquerdo e 2 - direito
    //system("cls");
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

}*/

void imprimeSimples(struct peca *mesaL1, struct peca *mesaL2){


    if(mesaL1->ladoDireito == -1 & mesaL2->ladoDireito == -1){
        printf(" - \n");
    }
    else if(mesaL1->ladoDireito != -1 & mesaL2->ladoDireito == -1){
        printf("|%d|%d| - \n", mesaL1->ladoEsquerdo, mesaL1->ladoDireito);
    }
    else if(mesaL2->ladoDireito != -1 && mesaL1->ladoDireito == -1){
        printf(" - |%d|%d|\n", mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
    }
    else if(mesaL1->ladoDireito != -1 & mesaL2->ladoDireito != -1){
        printf("|%d|%d| - |%d|%d|\n", mesaL1->ladoEsquerdo, mesaL1->ladoDireito, mesaL2->ladoEsquerdo, mesaL2->ladoDireito);
    }

}
 void imprimirMesa(struct mesa *jogoMesa){

    int i;

    for(i=0;i>60;i++){
        if(jogoMesa->pecas[i]->ladoDireito == -1){
            continue;
        }else{
            printf("|%d|%d| - ", jogoMesa->pecas[i]->ladoEsquerdo, jogoMesa->pecas[i]->ladoDireito);
        }
        printf("\n");
    }


 }
