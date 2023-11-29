// Rascunho do chatGPT - inserir dados em um arquivo


int calcularSomaPecas(Jogador jogador) {
    int soma = 0;
    for (int i = 0; i < 7; ++i) {
        soma += jogador.mao[i].lado1 + jogador.mao[i].lado2;
    }
    return soma;
}

int calcularMaiorDupla(Jogador jogador) {
    int maiorDupla = -1;
    for (int i = 0; i < jogador.quantidadePecas; ++i) {
        if (jogador.mao[i].lado1 == jogador.mao[i].lado2 && jogador.mao[i].lado1 > maiorDupla) {
            maiorDupla = jogador.mao[i].lado1;
        }
    }
    return maiorDupla;
}

int calcularMaiorNumero(Jogador jogador) {
    int maiorNumero = -1, maiorNumeroEsquerdo;
    for (int i = 0; i < 7; ++i) {
        if (jogador.mao[i].ladoDireito > maiorNumero) {
            maiorNumero = jogador.mao[i].lado1;
        }
        if (jogador.mao[i].ladoEsquerdo > maiorNumero) {
            maiorNumero = jogador.mao[i].lado2;
        }
    }
    return maiorNumero;
}

int determinarJogadorInicial(Jogador jogador1, Jogador jogador2) {
    int somaJogador1 = calcularSomaPecas(jogador1);
    int somaJogador2 = calcularSomaPecas(jogador2);

    int maiorDuplaJogador1 = calcularMaiorDupla(jogador1);
    int maiorDuplaJogador2 = calcularMaiorDupla(jogador2);

    int maiorNumeroJogador1 = calcularMaiorNumero(jogador1);
    int maiorNumeroJogador2 = calcularMaiorNumero(jogador2);

    if (maiorDuplaJogador1 > maiorDuplaJogador2) {
        return 1; // Jogador 1 tem a maior dupla
    } else if (maiorDuplaJogador2 > maiorDuplaJogador1) {
        return 2; // Jogador 2 tem a maior dupla
    } else {
        if (somaJogador1 > somaJogador2) {
            return 1; // Jogador 1 tem a maior soma
        } else if (somaJogador2 > somaJogador1) {
            return 2; // Jogador 2 tem a maior soma
        } else {
            if (maiorNumeroJogador1 > maiorNumeroJogador2) {
                return 1; // Jogador 1 tem a maior peça individual
            } else if (maiorNumeroJogador2 > maiorNumeroJogador1) {
                return 2; // Jogador 2 tem a maior peça individual
            } else {
                return 0; // Empate em todos os critérios, pode ser tratado de acordo com a necessidade
            }
        }
    }
}
