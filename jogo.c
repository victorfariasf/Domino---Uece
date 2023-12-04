#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


#include "estruturaJogo.h"
#include "jogo.h"
#include "mostrarTela.h"
#include "estruturaPeca.h"
#include "basicoJogo.h"

struct peca;
struct jogador;
struct mesa;

int menuDeJogadas(struct jogador jogadorRodada[], int qualJogador, struct peca todasPecas, int numPecas, struct mesa *mesaJogo){

    int opcao, deuCerto;
    printf("1 - Jogar Peça\n2 - Comprar Peça\n3 - Passar Vez\n");
    scanf("%d", &opcao);

    while(1){
        switch(opcao){

    case 1:
        rodada();
        break;

    case 2:
        comprarPeça();
        break;

    case 3:
        return qualJogador;
        break;

    default:
        printf("opção inválida\n");
        break;
        }
    }


}

int rodada(struct jogador *jogadorDaVez, struct mesa *mesaJogo){

    int jogadaPermitida, girar, qualLado;
    struct peca pecaEscolhida;

    int i;

    while(jogadaPermitida != 1){

        pecaEscolhida = decidirPeca(&jogadorDaVez);

        qualLado = podeJogarLado(&jogadorDaVez->mao[pecaEscolhida], &mesaJogo);

        jogarNaMesa(qualLado, &jogadorDaVez->mao[pecaEscolhida], &mesaJogo);

        imprimirMesa(&mesaJogo);

    }

}

void jogarNaMesa(int qualLado, struct peca *pecaEscolhida, struct mesa *mesaJogo){

    int ED;

    if(qualLado == 1){
        ladoEsquerdo(qualLado, &pecaEscolhida, &mesaJogo);
    }
    else if(qualLado == 2){
        ladoDireito(qualLado, &pecaEscolhida, &mesaJogo);
    }
    else if(qualLado == 3){
        printf("Deseja colocar em qual lado?\n");
        printf("ESQUERDO - 1\nDIREITO - 2\n");
        scanf("%d", &ED);
        while(ED != 1 && ED != 2){
            if(ED == 1){
                ladoEsquerdo(qualLado, &pecaEscolhida, &mesaJogo);
            }
            else if(ED == 2){
                ladoDireito(qualLado, &pecaEscolhida, &mesaJogo);
            }
            else{
                printf("Insira 1 ou 2\n");
            }
        }
    }

}

void ladoDireito(int qualLado, struct peca *pecaEscolhida, struct mesa *mesaJogo){

    printf("Lado Direito\n");

    for(i = 60; i > 30; i--){
        if(mesaJogo->pecas[i]->ladoDireito == -1){
            continue;
        }
        else{
            mesaJogo->pecas[i] = *pecaEscolhidaJogador;
        }
    }

}

void ladoEsquerdo(int qualLado, struct peca *pecaEscolhida, struct mesa *mesaJogo){

    printf("Lado Esquerdo\n");
    for(i = 0; i < 30; i++){
        if(mesaJogo->pecas[i]->ladoDireito == -1){
            continue;
        }
        else{
            mesaJogo->pecas[i] = *pecaEscolhidaJogador;
            }
    }
}

/*int rodada(struct jogador *jogadorRodada[], int *qualJogador, struct mesa *mesaJogo){

    int jogadaPermitida, i, girar, qualLado;
    struct peca pecaEscolhida;

    while(jogadaPermitida != 1){

        pecaEscolhida = jogarPeca(&jogadorRodada, &mesaJogo);

        printf("Girar peça?\n1 - Sim\n2 - Não\n");
        scanf("%d", &girar);

        if(girar == 1){
            giraPeca(&pecaEscolhida);
        }

        qualLado = podeJogarLado(&pecaEscolhida, &mesaJogo);

        }

}*/

/*int jogo(struct jogador jogadorRodada[], int qualJogador, struct peca todasPecas[], int numPecas, struct peca *mesaL1, struct peca *mesaL2, struct mesa *mesaJogo){

  int jogadaPermitida, quemVaiJogar, comprou, comprar, qualLado, girar;
  int duasPecasLado, i;
  struct peca primeiraPeca, pecaEscolhidaJogador, ladoEscolhido;


  //imprimeSimples(&mesaL1, &mesaL2);//imprime apenas as peças sozinhas, sem ter a do player

  while(jogadaPermitida != 1){

    pecaEscolhidaJogador = jogarPeca(jogadorRodada, qualJogador);

    printf("Quer girar a peça?\n");
    printf("Sim - 1\nNão - 2\n");
    scanf("%d", &girar);

    if(girar == 1){
        giraPeca(&pecaEscolhidaJogador);
    }

    qualLado = podeJogar(ladoEscolhido &mesaJogo);//lado 1 - esquerdo e 2 - direito

    if(qualLado == 1){
        printf("Lado Esquerdo\n");
        for(i = 0; i < 30; i++){
            if(mesaJogo->pecas[i]->ladoDireito == -1){
                continue;
            }
            else{
                mesaJogo->pecas[i] = pecaEscolhidaJogador;
            }
        }
        return qualJogador;

    }else if(qualLado == 2){

        printf("Lado Direito\n");
        for(i = 60; i > 30 ; i--){
            if(mesaJogo->pecas[i]->ladoDireito == -1){
                continue;
            }
            else{
                mesaJogo->pecas[i] = pecaEscolhidaJogador;
            }
        }
        return qualJogador;
    }
    else if(qualLado == 3){
        printf("A peça pode ser jogada nos dois lados\n");

        while(duasPecasLado != 1 && duasPecasLado != 2){

            printf("Em qual lado você deseja jogar?\n1 - lado esquerdo\n2 - lado direito\n");
            scanf("%d", &duasPecasLado);

            if(duasPecasLado == 1){
                printf("Lado Esquerdo\n");
                for(i = 0; i < 30; i++){
                    if(mesaJogo->pecas[i]->ladoDireito == -1){
                        continue;
                    }
                    else{
                        mesaJogo->pecas[i] = pecaEscolhidaJogador;
                    }
                }
                return qualJogador;
            }

            else if(duasPecasLado == 2){

                printf("Lado Direito\n");
                for(i = 60; i > 30; i--){
                    if(mesaJogo->pecas[i]->ladoDireito == -1){
                        continue;
                    }
                    else{
                        mesaJogo->pecas[i] = pecaEscolhidaJogador;
                    }
                }
                return qualJogador;
            }
            else{
                printf("Opção inválida\n");
            }

        }
    }
    else{
        printf("Não pode escolher essa peça\n");
        printf("Deseja comprar uma peça?\nSim - 1\nNão - 0");
        scanf("%d", &comprar);
        if(comprar == 1){
            comprou = compraPeca(jogadorRodada, qualJogador, todasPecas, numPecas);
            printf("Peça comprada\n");
            return quemVaiJogar;
        }
        else{
            jogadaPermitida = 0;
        }
    }
    }

    imprimirMesa(&mesaJogo);
    return quemVaiJogar;
}*/


