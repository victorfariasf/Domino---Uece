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
struct mesa;

int compraPeca(struct jogador jogadores[], int jogador, struct peca todasPecas[], int numPecas){
  int i, indiceAleatorio;
  for(i = 0; i < jogadores->contadorDePecas + 1; i++){
    if(jogadores->mao[i].ladoEsquerdo == -2){
      srand(time(NULL));
      indiceAleatorio = rand() % 28;
      jogadores->mao[i] = todasPecas[indiceAleatorio];
      jogadores->contadorDePecas++;
    }
  }
  return 1;
}

// ------- modo de identificar peças com duplas ---------
struct peca carrossel(struct jogador jogadorC){

  struct peca duplaMaiorPeca;
  struct peca naoDeu;

  naoDeu.ladoDireito = -1;
  naoDeu.ladoEsquerdo = -1;

  duplaMaiorPeca.ladoDireito = 0;
  duplaMaiorPeca.ladoEsquerdo = 0;

  int valorMaiorDupla = -1, i;

  for (int i = 0; i < 7; ++i) {
    if (jogadorC.mao[i].ladoEsquerdo == jogadorC.mao[i].ladoDireito && jogadorC.mao[i].ladoEsquerdo > valorMaiorDupla) {
       valorMaiorDupla = jogadorC.mao[i].ladoEsquerdo;
    }
  }

  for(i = 0; i < 7; i++){
    if(jogadorC.mao[i].ladoEsquerdo == valorMaiorDupla && jogadorC.mao[i].ladoDireito == valorMaiorDupla) {
      duplaMaiorPeca = jogadorC.mao[i];
      return duplaMaiorPeca;
    }
  }
//naoDeu é uma peça que não tem duplas e significa que não foi achado nenhum carrossel na mão do player
    printf("sem carrossel!\n");
    return naoDeu;

}
