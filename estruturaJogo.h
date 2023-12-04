#ifndef ESTRUTURAJOGO_H_INCLUDED
#define ESTRUTURAJOGO_H_INCLUDED


#include "basicoJogo.h"

int jogada1(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas, struct peca *mesaL1, struct peca *mesaL2);

int jogoAcabou(struct jogador players[], int numPlayers);

struct peca decidirPeca(struct jogador *jogadorJogar[], int *qualJogador);

//struct peca jogarPeca (struct jogador jogadorJogar[], int qualJogador);

int podeJogarLado(struct peca pecaEscolhidaJogador, struct mesa *pecaMesa)

//int podeJogar(struct peca pecaEscolhidaJogador, struct peca *mesaL1, struct peca *mesaL2);

int primeiraJogada(struct jogador jogadoresMain[], int numJogadores, struct peca pecaEscolhida);

int calcularSomaPecas(struct jogador jogador);

void giraPeca(struct peca *pecaEscolhidaJogador);


#endif // ESTRUTURAJOGO_H_INCLUDED
