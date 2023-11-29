#ifndef DOMINO_H

#define DOMINO_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <domino.h>

void iniciandoPecas(struct peca pecas[], int numPecas);
void distribuirPecas(struct peca pecas[], int numPecas, struct jogador jogadores[], int numJogadores);

void jogarPeca(struct jogador jogadorJogar[], int numJogadores);

void imprimirMesa(struct jogador jogadoresMesa[], int numJogadores, struct peca todasPecasMesa[], int numPecas);

#endif