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

struct peca;
struct jogador;



int jogo(struct jogador jogadorRodada[], int qualJogador, struct peca todasPecas[], int numPecas, struct peca *mesaL1, struct peca *mesaL2){

  int jogadaPermitida, quemVaiJogar, comprou, comprar, qualLado;
  struct peca primeiraPeca, pecaEscolhidaJogador, pecaMesa1, pecaMesa2;
  struct peca pecaEsquerda, pecaDireita;

  imprimeSimples(&mesaL1, &mesaL2);//imprime apenas as peças sozinhas, sem ter a do player

  while(jogadaPermitida != 1){

    pecaEscolhidaJogador = jogarPeca(jogadorRodada, qualJogador);

    qualLado = podeJogar(pecaEscolhidaJogador, primeiraPeca, pecaMesa1);//lado 1 - esquerdo e 2 - direito

    if(qualLado == 1){
      imprimeMesa(pecaEscolhidaJogador, &mesaL1, &mesaL2, qualLado);
      jogadorRodada[qualJogador].contadorDePecas--;
      //mesaL2 é peça do jogador
      *mesaL2 = pecaEscolhidaJogador;
      return quemVaiJogar;

    }else if(qualLado == 2){

      imprimeMesa(pecaEscolhidaJogador, &mesaL1, &mesaL2, qualLado);
      jogadorRodada[qualJogador].contadorDePecas--;

      //mesaL2 é peça do jogador
      *mesaL2 = pecaEscolhidaJogador;
      return quemVaiJogar;

    }
    else{
      printf("Deseja comprar uma peça?\nSim - 1\nNão - 0");
      scanf("%d", &comprar);
      if(comprar == 1){
        comprou = compraPeca(jogadorRodada, qualJogador, todasPecas, numPecas);
        return quemVaiJogar;
      }else{
        jogadaPermitida = 0;
      }
    }
  }
    return qualJogador;
}


