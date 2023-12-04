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


struct jogador;
struct peca;
struct mesa;

int jogada1(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas, struct peca *mesaL1, struct peca *mesaL2){
//declaração de variáveis

  int jogadaPermitida, quemVaiJogar, comprou, comprar, qualLado;
  struct peca primeiraPeca, pecaEscolhidaJogador;
  struct peca pecaEsquerda, pecaDireita;

  // --- funçao começa aqui

  quemVaiJogar = primeiraJogada(jogadoresMesa, numJogadores, primeiraPeca);
  printf("Jogador %s, começa\n", jogadoresMesa[quemVaiJogar]);

  return quemVaiJogar;
}
// qual a maior peça? - tem que fazer!;

int primeiraJogada(struct jogador jogadoresMain[], int numJogadores, struct peca pecaEscolhida){

  struct peca maiorCarrossel1, maiorCarrossel2;
  int soma1, soma2;

  maiorCarrossel1 = carrossel(jogadoresMain[0]);
  maiorCarrossel2 = carrossel(jogadoresMain[1]);

  if(maiorCarrossel1.ladoDireito == -1 && maiorCarrossel2.ladoDireito == -1){

    soma1 = calcularSomaPecas(jogadoresMain[0]);
    soma2 = calcularSomaPecas(jogadoresMain[1]);

    if(soma1 > soma2){
      printf("%s\nComeça com a maior soma...\n", jogadoresMain[0].nome);
      return 0;
    }else{
      printf("%s\nComeça com a maior soma...\n", jogadoresMain[1].nome);
      return 1;
    }

  }
  else{
    if(maiorCarrossel1.ladoDireito > maiorCarrossel2.ladoDireito){
      printf("%s\nPossui o maior carrossel - |%d|%d| \n", jogadoresMain[0].nome, maiorCarrossel1.ladoEsquerdo, maiorCarrossel1.ladoDireito);
      return 0;
    }
    else{
      printf("%s\nPossui o maior carrossel - |%d|%d| \n", jogadoresMain[1].nome, maiorCarrossel2.ladoEsquerdo, maiorCarrossel2.ladoDireito);
    return 1;
    }
  }
}


int decidirPeca(struct jogador *jogadorDaVez){

  int pecaJogada, i;

  printf("Mão do jogador: %s\n", jogadorDaVez->nome);

  for(i = 0; i < 7; i++){
    printf("|%d|%d| - Peça %d\n", jogadorDaVez->mao[i]->ladoEsquerdo, jogadorDaVez->mao[i]->ladoDireito, i);

  }

  printf("\nQual peça você deseja jogar?\n");
  scanf("%d", &pecaJogada);
  
      printf("Girar peça?\n1 -  Sim\n2 - Não\n");
      scanf("%d", &girar);
      
      if(girar == 1){
      giraPeca(&jogadorDaVez->mao[pecaJogada])
      }
      
      return pecaJogada;

}

// --------- confirmação de jogada -------------

int podeJogarLado(struct peca *pecaEscolhidaJogador, struct mesa *pecaMesa){

    int i, ladoE = 0, ladoD = 0;
    for(i = 0; i < 30 i++){
        if(pecaMesa->pecas[i] == -1){
            continue;
        }
        else if(pecaMesa->pecas[i]->ladoEsquerdo == pecaEscolhidaJogador->ladoDireito){
            lado = 1;
        }
    }

    int i;
    for(i = 60; i > 30; i--){
        if(pecaMesa->pecas[i] == -1){
            continue;
        }
        else if(pecaMesa->pecas[i]->ladoDireito == pecaEscolhidaJogador->ladoEsquerdo){
            ladoD = 2;
        }
    }

    if(ladoE == 1 && ladoD == 2){
        return 3;
    }
    else if(ladoE == 1){
        return 1;
    }
    else if(ladoD == 2){
        return 2;
    }

    return 0;
}


/*int podeJogar(struct peca pecaEscolhidaJogador, struct peca *mesaL1, struct peca *mesaL2){

    if(mesaL1->ladoDireito != -1 && mesaL2->ladoDireito != -1){
        if(pecaEscolhidaJogador.ladoDireito == mesaL1->ladoEsquerdo){
            if(pecaEscolhidaJogador.ladoEsquerdo == mesaL2->ladoDireito){
                //printf("A peça pode ser jogada nos dois lados\n");
                return 3;
            }
        }
        else{
            //printf("A peça só pode ser jogada no lado esquerdo\n");
            return 1;
        }
    }
    else if(mesaL1->ladoEsquerdo == -1){
        if(pecaEscolhidaJogador.ladoEsquerdo == mesaL2->ladoDireito){
            //printf("A peça pode ser jogada nos dois lados\n");
            return 2;
        }
        else{
            //printf("A peça pode ser jogada no lado esquerdo\n");
            return 1;
        }
    }
    else if(mesaL2->ladoDireito == -1){
        if(pecaEscolhidaJogador.ladoDireito == mesaL1->ladoEsquerdo){
            //printf("A peça pode ser jogada nos dois lados\n");
            return 3;
        }
        else{
            //printf("A peça só pode ser jogada no lado direito\n");
            return 2;
        }
    }

    //printf("A peça não pode ser jogada...Escolha outra\n");
    return 0;

}*/

void giraPeca(struct peca *pecaEscolhidaJogador){

    int aux;
    struct peca pecaInvertida;

    pecaEscolhidaJogador->ladoDireito = aux;
    pecaEscolhidaJogador->ladoDireito = pecaEscolhidaJogador->ladoEsquerdo;
    pecaEscolhidaJogador->ladoEsquerdo = aux;

}

// ----------- somar a quantidade diponível das peças -------------
int calcularSomaPecas(struct jogador jogador){
    int soma = 0;
    for (int i = 0; i < 7; ++i) {
        soma = soma + (jogador.mao[i].ladoEsquerdo) + (jogador.mao[i].ladoDireito);
    }
    return soma;
}

int jogoAcabou(struct jogador players[], int numPlayers){

  int i, j;
  for( i = 0; i < numPlayers; i ++){
    for(j = 0; j < players[i].contadorDePecas; j++){
      if(players[i].contadorDePecas == 0){
        printf("fim de jogo. Jogador %s venceu!\n", players[i].nome);
        return 1;
      }
    }
  }
  return 0;
}
