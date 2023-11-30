#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

// Criação de struct em formato peça
struct peca{
  int ladoDireito;
  int ladoEsquerdo;
};

// Criação de struct que representa um jogador
struct jogador {
  char nome[50];
  struct peca mao[14];
  int contadorDePecas;
};

struct peca carrossel(struct jogador jogadorC);
struct jogador jogarPeca (struct jogador jogadorJogar[], int qualJogador);
void iniciandoPecas(struct peca pecas[], int numPecas);
void distribuirPecas(struct peca pecas[], int numPecas, struct jogador jogadores[], int numJogadores);
void imprimirMesa(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas);
int primeiraJogada(struct jogador jogadoresMain[], int numJogadores, struct peca todasPecas[], int numPecas);

/*
void imprimirJogadorMao(jogador j1);
void jogarPeca(jogador jogadorJogar[], int numJogadores);
void imprimirPeca(peca p1);
void imprimirMesa(jogador jogadoresMesa[], int numJogadores, peca todasPecasMesa[], int numPecas);
void podeJogar(peca p1, peca mesa,int tamMesa);
//void jogarPeca(struct peca p1, struct peca Mesa, int *tamMesa);
void ganhou(jogador j1);
*/


int main(void){

    setlocale(LC_ALL, "Portuguese");

    int op, quemJoga;

    struct peca todasPecas[28];
    struct jogador jogadoresMain[2];

    printf("Domino MASTER GAME\n\n");
    printf("Jogo novo - 1\nCarregar Jogo - 2\n"); //\n3 - Sair do Menu
    scanf("%d", &op);

    do{

        if(op == 1){
            printf("Um novo jogo será inicializado\n");
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

    quemJoga = primeiraJogada(jogadoresMain, 2, todasPecas, 27);
    if(quemJoga == 0){
      
    }

    

    imprimirMesa(jogadoresMain, 2, todasPecas, 28 );



    printf("passou das funções\n");
}


int primeiraJogada(struct jogador jogadoresMain[], int numJogadores, struct peca todasPecas[], int numPecas){

  struct peca maiorCarrossel1, maiorCarrossel2;
  int soma1, soma2;
  
  maiorCarrossel1 = carrossel(jogadoresMain[0]);
  maiorCarrossel2 = carrossel(jogadoresMain[1]);

  if(maiorCarrossel1.ladoDireito == -1 && maiorCarrossel2.ladoDireito == -1){

    soma1 = calcularSomaPecas(jogadoresMain[0]);
    soma2 = calcularSomaPecas(jogadoresMain[1]);

    if(soma1 > soma2){
      printf("jogador 1 começa...\n");
      return 0;
    }else{
      printf("jogador 2 começa...\n");
      return 1;
    }

  }
  else{
    if(maiorCarrossel1.ladoDireito > maiorCarrossel2.ladoEsquerdo){
      printf("|%d|%d|\t", maiorCarrossel1.ladoEsquerdo, maiorCarrossel1.ladoDireito);
      return 0;
    }
    else{
      printf("|%d|%d|\t", maiorCarrossel2.ladoEsquerdo, maiorCarrossel2.ladoDireito);
    return 1;
    } 
  }
}

// IDENTIFICAR PESSAS COM DUPLAS
struct peca carrossel(struct jogador jogadorC){
  
  struct peca duplaMaiorPeca;
  struct peca naoDeu;
  naoDeu.ladoDireito = -1;
  duplaMaiorPeca.ladoDireito = 0;
  duplaMaiorPeca.ladoEsquerdo = 0;
  int maiorDupla = -1, i;

  for (int i = 0; i < 7; ++i) {
    if (jogadorC.mao[i].ladoEsquerdo == jogadorC.mao[i].ladoDireito &&   jogadorC.mao[i].ladoEsquerdo > maiorDupla) {
       maiorDupla = jogadorC.mao[i].ladoEsquerdo;
    }
  }
  
  for(i = 0; i < 7; i++){
    if(jogadorC.mao[i].ladoEsquerdo == maiorDupla && jogadorC.mao[i].ladoDireito == maiorDupla) {
      duplaMaiorPeca = jogadorC.mao[i];
      return duplaMaiorPeca;
    }
  }
  
 return naoDeu;
  
}

int calcularSomaPecas(struct jogador jogador) {
    int soma = 0;
    for (int i = 0; i < 7; ++i) {
        soma += jogador.mao[i].ladoEsquerdo+ jogador.mao[i].ladoDireito;
    }
    return soma;
}



//---------------

  

// INTIFICAR NOME DOS DOIS JOGADORES
void identificarJogador (struct jogador jogadoresMain[], int numJogadores){

    //jogadores[numJogadores];

    int i, j;

    for(i = 0; i < 2; i++){
        printf("insira o nome do jogador %d:\n", i + 1);
        fgets(jogadoresMain[i].nome, 50, stdin);
        fflush(stdin);
    }

}

// CRIAÇÃO DE PEÇAS
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

// DISTRIBUIÇÃO DE PEÇAS ENTRE JOGADORES 
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

struct jogador jogarPeca (struct jogador jogadorJogar[], int qualJogador){

  int pecaJogada, i;
  
  printf("Mão do jogador: %s", jogadorJogar[qualJogador].nome);
  
  for(i = 0; i < 7; i++){

    printf("|%d|%d|\nPeça |%d|\t", jogadorJogar[qualJogador].mao[i].ladoEsquerdo, jogadorJogar[qualJogador].mao[i].ladoDireito, i);
    
  }

  printf("Qual peça você deseja jogar?\n");
  scanf("%d", &pecaJogada);

  //podeJogar(jogadorJogar, pecaJogada);

  return jogadorJogar[qualJogador];
  
}

// IMPRIMIR O RESULTADO DA PARTIDA NA MESA -- Continuar
void imprimirMesa(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas){

  int jogadaPermitida;
  struct peca pecaEscolhida;
  
  while(jogadaPermitida != 1){
  
    pecaEscolhida = jogarPeca(jogadoresMesa[0], 0);
    jogadaPermitida = podeJogar(pecaEscolhida, pecaNaMesa);
    
  }
  

}

/*void carregarJogo(void){
    printf("EM ANDAMENTO");
}*/

// Falta ainda alterar os nomes!

  

        // ainda a ser usado
      /*
struct carrosel(jogador jogador1){
      peca duplaMaior;
      int maiorDupla = -1, i;

      for (int i = 0; i < 7; ++i) {
          if (jogador.mao[i].ladoEsquerdo == jogador.mao[i].ladoDireito &&   jogador.mao[i].ladoEsquerdo > maiorDupla) {
              maiorDupla = jogador.mao[i].ladoEsquerdo;
          }
      }
      for(i = 0; i < 7; i++){
        if(jogador.mao[i].ladoEsquerdo == maiorDupla && jogador.mao[i].ladoDireito == maiorDupla) {
          return duplaMaior
      }
}

      */
//int comprarPeca()

//int passarVez();