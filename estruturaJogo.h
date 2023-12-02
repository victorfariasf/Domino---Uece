#ifndef ESTRUTURAJOGO_H_INCLUDED
#define ESTRUTURAJOGO_H_INCLUDED


#include "basicoJogo.h"

int jogada1(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas, struct peca *mesaL1, struct peca *mesaL2);

int jogoAcabou(struct jogador players[], int numPlayers);

struct peca jogarPeca (struct jogador jogadorJogar[], int qualJogador);

int podeJogar(struct peca pecaEscolhidaJogador, struct peca pecaMesa1, struct peca pecaMesa2);

int primeiraJogada(struct jogador jogadoresMain[], int numJogadores, struct peca pecaEscolhida);

int calcularSomaPecas(struct jogador jogador);

#endif // ESTRUTURAJOGO_H_INCLUDED
