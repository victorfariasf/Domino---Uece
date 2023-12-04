#ifndef BASICOJOGO_H_INCLUDED
#define BASICOJOGO_H_INCLUDED

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

struct mesa{
    struct peca pecas[60];
    int qntd;
};

void identificarJogador (struct jogador jogadoresMain[], int numJogadores);

void iniciandoPecas(struct peca pecas[], int numPecas);

void distribuirPecas(struct peca pecas[], int numPecas, struct jogador jogadores[], int numJogadores);


#endif // BASICOJOGO_H_INCLUDED
