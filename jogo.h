#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED



#include "basicoJogo.h"


//int jogo(struct jogador jogadorRodada[], int qualJogador, struct peca todasPecas[], int numPecas, struct peca *mesaL1, struct peca *mesaL2, struct mesa *mesaJogo);

int menuDeJogadas(struct jogador jogadorRodada[], int qualJogador, struct peca todasPecas, int numPecas, struct mesa *mesaJogo);

int rodada(struct jogador *jogadorDaVez, struct mesa *mesaJogo);

void jogarNaMesa(int qualLado, struct peca *pecaEscolhida, struct mesa *mesaJogo);

void ladoDireito(int qualLado, struct peca *pecaEscolhida, struct mesa *mesaJogo);

void ladoEsquerdo(int qualLado, struct peca *pecaEscolhida, struct mesa *mesaJogo);
#endif // JOGO_H_INCLUDED
