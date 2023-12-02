#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "jogo.h"
#include "estruturaJogo.h"
#include "estruturaJogo.h"
#include "mostraTela.h"
#include "basicoJogo.h"

//funções pecas




void imprimirUmaPecas(struct peca pecaEscolhidaJogador, int quemVaiJogar, struct peca peca1, struct peca peca2);

void imprimirDuasPecas(struct peca pecaEscolhidaJogador, int quemVaiJogar, struct peca peca1, struct peca peca2);



// main

int main(void){

    setlocale(LC_ALL, "Portuguese");

    int op, quemJogou, fimJogo, primeiraJogada;

    struct peca todasPecas[28];
    struct jogador jogadoresMain[2];
    struct peca mesaL1, mesaL2;

    printf("Domino MASTER GAME\n\n");
    printf("Jogo novo - 1\nCarregar Jogo - 2\n"); //\n3 - Sair do Menu
    scanf("%d", &op);

    do{

        if(op == 1){
            printf("Um novo jogo será inicializado\n");
            // Iniciar o jogo
            fflush(stdin);
        } else if(op == 2){
            printf("Seu jogo está sendo carregado...encerrando\n");
            exit(1);
            //carregarJogo();
            fflush(stdin);
        } else{
            printf("opção inválida");
            fflush(stdin);
        }

    }while(op != 1 && op != 2);

    //---- básico do jogo para iniciar o jogo ------

    identificarJogador(jogadoresMain, 2);
    iniciandoPecas(todasPecas, 28);
    distribuirPecas(todasPecas, 28, jogadoresMain, 2);

    //---- mostrar a mesa com a mão dos jogadores -----


    primeiraJogada = jogada1(jogadoresMain, 2, todasPecas, 28, &mesaL1, &mesaL2);

    quemJogou = jogo(jogadoresMain, primeiraJogada, todasPecas, 28, &mesaL1, &mesaL2);

    while(fimJogo != 1){

      if(quemJogou == 0){//se for zero ent o jogador 1 joga.
        quemJogou = jogo(jogadoresMain, 1, todasPecas, 28, &mesaL1, &mesaL2);
      }else{
        quemJogou = jogo(jogadoresMain, 0, todasPecas, 28, &mesaL1, &mesaL2);
      }

      fimJogo = jogoAcabou(jogadoresMain, 2);


    }



    printf("passou das funções\n");
}

//funçoes pecas


// Escolha de qual peça mostrando a mão do player


// ---------- impressão do resultado da partida na mesa (continuar)

/*void imprimirUmaPecas(struct peca pecaEscolhidaJogador, int quemVaiJogar, struct peca peca1, struct peca peca2){

  system("cls");
  printf("|%d|%d|\n", pecaEscolhidaJogador.ladoEsquerdo, pecaEscolhidaJogador.ladoDireito);
  printf("|%d|%d|\n", peca2.ladoEsquerdo, peca2.ladoDireito);

}*/



/*void imprimirDuasPecas(struct peca pecaEscolhidaJogador, int quemVaiJogar, struct peca peca1, struct peca peca2){

  int lado1, lado2, qualLado;

  printf("qual lado deseja jogar?\n");
  printf("|%d|%d|\nlado 1\n", peca1.ladoEsquerdo, peca1.ladoDireito);
  printf("ou\n");
  printf("|%d|%d|\nlado 2\n", peca2.ladoEsquerdo, peca2.ladoDireito);
  scanf("%d", &qualLado);

  if(qualLado == 1){
    system("cls");
    printf("|%d|%d|\nlado 1\n", pecaEscolhidaJogador.ladoEsquerdo, pecaEscolhidaJogador.ladoDireito);
    printf("ou\n");
    printf("|%d|%d|\nlado 2\n", peca2.ladoEsquerdo, peca2.ladoDireito);
    scanf("%d", &qualLado);
  }else{
    printf("qual lado deseja jogar?\n");
    printf("|%d|%d|\nlado 1\n", peca1.ladoEsquerdo, peca1.ladoDireito);
    printf("ou\n");
    printf("|%d|%d|\nlado 2\n", pecaEscolhidaJogador.ladoEsquerdo, pecaEscolhidaJogador.ladoDireito);
  }

}*/















//int calcularMaiorPeca(struct jogador )

// funções jogo




//mesaL1 e mesaL2 - são as peças que foram jogadas

  //  JOGADA 1 ABAIXO

//L1 - lado esquerdo e o L2 - lado direito



  /* ---- Deverá ser a função jogada!
  while(jogadaPermitida != 1){

    pecaEscolhidaJogador = jogarPeca(jogadoresMesa, quemVaiJogar);
    qualLado = podeJogar(pecaEscolhidaJogador, primeiraPeca, pecaMesa1);

    if(qualLado == 1){
      printf("você só pode jogar nessa peça\n|%d|%d|\t", primeiraPeca.ladoEsquerdo, primeiraPeca.ladoDireito);

      imprimirUmaPecas(pecaEscolhidaJogador, quemVaiJogar, primeiraPeca, pecaMesa1);
      jogadoresMesa[quemVaiJogar].contadorDePecas--;
      //mesaL2 é peça do jogador
      *mesaL2 = pecaEscolhidaJogador;
      return quemVaiJogar;

    }else if(qualLado == 2){
      printf("você só poderá jogar nessas peças\n|%d|%d|\t|%d|%d|", primeiraPeca.ladoEsquerdo, primeiraPeca.ladoDireito, pecaMesa1.ladoEsquerdo, pecaMesa1.ladoDireito);

      imprimirDuasPecas(pecaEscolhidaJogador, quemVaiJogar, primeiraPeca, pecaMesa1);
      jogadoresMesa[quemVaiJogar].contadorDePecas--;
      //mesaL2 é peça do jogador
      *mesaL2 = pecaEscolhidaJogador;
      return quemVaiJogar;

    }
    else{
      printf("Deseja comprar uma peça?\nSim - 1\nNão - 0");
      scanf("%d", &comprar);
      if(comprar == 1){
        comprou = compraPeca(jogadoresMesa, numJogadores, todasPecasMesa, numPecas);
        return quemVaiJogar;
      }else{
        jogadaPermitida = 0;
      }
    }
  }*/
//}



