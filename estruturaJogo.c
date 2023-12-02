#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "estruturaJogo.h"
#include "jogo.h"
#include "mostraTela.h"
#include "estruturaPeca.h"
#include "basicoJogo.h"


struct jogador;
struct peca;

int jogada1(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas, struct peca *mesaL1, struct peca *mesaL2){
//declaração de variáveis

  int quemVaiJogar, comprou, comprar, qualLado;
  struct peca primeiraPeca, pecaEscolhidaJogador, pecaMesa1, pecaMesa2;
  struct peca pecaEsquerda, pecaDireita;

  //primeiraPeca é uma struct de comparação. Como não existe outras peças na primeira rodada ela serve de base.
  pecaMesa1.ladoDireito = -1;
  pecaMesa1.ladoEsquerdo = -1;
  *mesaL1 = pecaMesa1;

  pecaMesa2.ladoEsquerdo = -1;
  pecaMesa2.ladoDireito = -1;
  *mesaL2 = pecaMesa2;

  primeiraPeca.ladoDireito = -1;
  primeiraPeca.ladoEsquerdo = -1;

  // --- funçao começa aqui

  quemVaiJogar = primeiraJogada(jogadoresMesa, numJogadores, primeiraPeca);
  printf("Jogador %s, começa", jogadoresMesa[quemVaiJogar]);

  //se for um carrosel mesaL1 recebe essa peça
  *mesaL1 = primeiraPeca;

  return quemVaiJogar;
}

int jogoAcabou(struct jogador players[], int numPlayers){

  int i, j;
  for( i = 0; i < numPlayers; i ++){
    for(j = 0; j < players[i].contadorDePecas; j++){
      if(players[i].contadorDePecas == 0){
        printf("fim de jogo. Jogador %d venceu!\n", i);
        return 1;
      }
    }
  }
  return 0;
}

struct peca jogarPeca(struct jogador jogadorJogar[], int qualJogador){

  int pecaJogada, i;

  printf("Mão do jogador: %s\n", jogadorJogar[qualJogador].nome);

  for(i = 0; i < jogadorJogar[qualJogador].contadorDePecas; i++){

    printf("|%d|%d|\nPeça |%d|\n", jogadorJogar[qualJogador].mao[i].ladoEsquerdo, jogadorJogar[qualJogador].mao[i].ladoDireito, i);

  }

  printf("Qual peça você deseja jogar?\n");
  scanf("%d", &pecaJogada);

  return jogadorJogar[qualJogador].mao[pecaJogada];

}

// --------- confirmação de jogada -------------
int podeJogar(struct peca pecaEscolhidaJogador, struct peca pecaMesa1, struct peca pecaMesa2){

  if(pecaMesa1.ladoDireito != -1 && pecaMesa2.ladoDireito != -1){
    if(pecaEscolhidaJogador.ladoDireito == pecaMesa1.ladoEsquerdo){
        if(pecaEscolhidaJogador.ladoEsquerdo == pecaMesa2.ladoDireito){
        printf("Pode ser jogada no lado direito\n");
        return 2;
        }
        printf("Pode ser jogada no lado esquerdo\n");
        return 1;
    }
  }

  else if(pecaMesa1.ladoDireito == -1){
        if(pecaEscolhidaJogador.ladoEsquerdo == pecaMesa2.ladoDireito){
        printf("Pode ser jogada no lado direito\n");
        return 2;
        }
    }else if(pecaMesa2.ladoDireito == -1){
            if(pecaMesa1.ladoDireito != -1 && pecaMesa2.ladoDireito != -1){
                printf("Pode ser jogada no lado esquerdo\n");
                return 1;
            }
    }
}

int primeiraJogada(struct jogador jogadoresMain[], int numJogadores, struct peca pecaEscolhida){

  struct peca maiorCarrossel1, maiorCarrossel2;
  int soma1, soma2;

  maiorCarrossel1 = carrossel(jogadoresMain[0]);
  maiorCarrossel2 = carrossel(jogadoresMain[1]);

  if(maiorCarrossel1.ladoDireito == -1 && maiorCarrossel2.ladoDireito == -1){

    soma1 = calcularSomaPecas(jogadoresMain[0]);
    soma2 = calcularSomaPecas(jogadoresMain[1]);

    if(soma1 > soma2){
      printf("%s\nComeça...\n", jogadoresMain[0].nome);
      return 0;
    }else{
      printf("%s\nComeça...\n", jogadoresMain[1].nome);
      return 1;
    }

  }
  else{
    if(maiorCarrossel1.ladoDireito > maiorCarrossel2.ladoDireito){
      printf("%s\nPossui o maior carrossel\n", jogadoresMain[0].nome);
      return 0;
    }
    else{
      printf("%s\nPossui o maior carrossel\n", jogadoresMain[1].nome);
    return 1;
    }
  }
}

// ----------- somar a quantidade diponível das peças -------------
int calcularSomaPecas(struct jogador jogador){
    int soma = 0;
    for (int i = 0; i < 7; ++i) {
        soma = soma + (jogador.mao[i].ladoEsquerdo) + (jogador.mao[i].ladoDireito);
    }
    return soma;
}
