#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct peca
{
    int ladoDireito;
    int ladoEsquerdo;
};

struct jogador
{
    char nome[50];
    struct peca mao[21];
    int contadorDePecas;
};

struct pecasDaMesa
{
    struct peca pecasDaPilha[28];
    int contadorDePecas;
};

struct mesa
{
    struct peca pecas[61];
    int qntd;
};

struct estate
{
    struct jogador j[2];
    struct pecasDaMesa pilha;
    struct mesa mesaJogo;
};

//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------

// ----------------- criação das peças --------------------

void iniciandoPecas(struct pecasDaMesa *pilha)
{

    // Iniciar as peças com suas combinações possíveis
    // igual ao meio;

    int pieceI = 0, j, i;

    for (i = 0; i < 7; i++)
    {
        for (j = i; j < 7; j++)
        {
            pilha->pecasDaPilha[pieceI].ladoDireito = i;
            pilha->pecasDaPilha[pieceI].ladoEsquerdo = j;
            // printf("- |%d|%d| -", pilha->pecasDaPilha[i].ladoDireito, pilha->pecasDaPilha[i].ladoEsquerdo);
            pieceI++;
        }
    }

    pilha->contadorDePecas = pieceI;

    for (i = 0; i < pilha->contadorDePecas; i++)
    {
        printf("- |%d|%d| -", pilha->pecasDaPilha[i].ladoDireito, pilha->pecasDaPilha[i].ladoEsquerdo);
    } // debug*/
}

void identificar(struct jogador jogadoresMain[], int numJogadores)
{

    int i;

    for (i = 0; i < numJogadores; i++)
    {
        printf("insira um nome para o jogador %d: ", i + 1);
        scanf("%s", &jogadoresMain[i].nome);
        // jogadoresMain[i].contadorDePecas = 7;
    }
}

void distribuirPecas(struct pecasDaMesa *pilha, struct jogador *jogadores)
{

    // Embaralhar as peças e dar as peças ao jogador

    int cont = pilha->contadorDePecas, controle = 0;
    int i, j, embaralharIndice;

    // srand(time(NULL));

    while (controle < 7)
    {
        embaralharIndice = rand() % 28;
        if (pilha->pecasDaPilha[embaralharIndice].ladoDireito == -1 && pilha->pecasDaPilha[embaralharIndice].ladoEsquerdo == -1)
        {
            continue;
        }
        else
        {

            jogadores->mao[controle] = pilha->pecasDaPilha[embaralharIndice];
            printf("|%d|%d|\n", jogadores->mao[controle].ladoEsquerdo, jogadores->mao[controle].ladoDireito);
            printf("em cima peça do jogador, embaixo a peça usada\n");
            printf("|%d|%d|\n", pilha->pecasDaPilha[embaralharIndice].ladoEsquerdo, pilha->pecasDaPilha[embaralharIndice].ladoDireito);
            printf("---\n");
            pilha->pecasDaPilha[embaralharIndice].ladoDireito = -1;
            pilha->pecasDaPilha[embaralharIndice].ladoEsquerdo = -1;
            pilha->contadorDePecas--;

            // printf("%d - %d\n", pilha->pecasDaPilha[embaralharIndice].ladoEsquerdo, pilha->pecasDaPilha[embaralharIndice].ladoDireito);
            controle++;
        }
    }
    for (i = 0; i < 21; i++)
    {
        if (jogadores->mao[i].ladoDireito != -1)
        {
            jogadores->contadorDePecas++;
        }
    }

    printf("-------------\n");
    printf("%s - quantas peças: %d", jogadores->nome, jogadores->contadorDePecas);
    system("pause");
}

//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------

struct peca carrossel(struct jogador jogadorC, int *indice)
{

    struct peca duplaMaiorPeca;
    struct peca naoDeu;

    naoDeu.ladoDireito = -1;
    naoDeu.ladoEsquerdo = -1;

    duplaMaiorPeca.ladoDireito = 0;
    duplaMaiorPeca.ladoEsquerdo = 0;

    int valorMaiorDupla = -1, i;

    for (int i = 0; i < 7; ++i)
    {
        if (jogadorC.mao[i].ladoEsquerdo == jogadorC.mao[i].ladoDireito && jogadorC.mao[i].ladoEsquerdo > valorMaiorDupla)
        {
            valorMaiorDupla = jogadorC.mao[i].ladoEsquerdo;
        }
    }

    for (i = 0; i < 7; i++)
    {
        if (jogadorC.mao[i].ladoEsquerdo == valorMaiorDupla && jogadorC.mao[i].ladoDireito == valorMaiorDupla)
        {
            duplaMaiorPeca = jogadorC.mao[i];
            *indice = i;
            return duplaMaiorPeca;
        }
    }
    // naoDeu é uma peça que não tem duplas e significa que não foi achado nenhum carrossel na mão do player
    printf("sem carrossel!\n");
    return naoDeu;
}

int primeiro(struct jogador jogadoresMain[], int jogadores, struct mesa *mesaJogo, int *indiceCarrossel1, int *indiceCarrossel2)
{

    struct peca maiorCarrossel1, maiorCarrossel2;
    int soma1, soma2, i;
    int maiorDupla1 = -1, maiorDupla2 = -1, pecaJogada;

    maiorCarrossel1 = carrossel(jogadoresMain[0], indiceCarrossel1);
    maiorCarrossel2 = carrossel(jogadoresMain[1], indiceCarrossel2);

    if (maiorCarrossel1.ladoDireito == -1 && maiorCarrossel2.ladoDireito == -1)
    {

        soma1 = calcularSomaPecas(jogadoresMain[0]);
        soma2 = calcularSomaPecas(jogadoresMain[1]);

        if (soma1 > soma2)
        {
            printf("%s\nComeça com a maior soma...\n", jogadoresMain[0].nome);

            for (i = 0; i < 20 + 1; i++)
            {
                if (jogadoresMain[0].mao[i].ladoDireito != -1)
                {
                    printf("|%d|%d| - Peça %d\n", jogadoresMain[0].mao[i].ladoEsquerdo, jogadoresMain[0].mao[i].ladoDireito, i);
                }
            }
            printf("Qual peça vc vai jogar?\n");
            scanf("%d", &pecaJogada);
            mesaJogo->pecas[30] = jogadoresMain[0].mao[pecaJogada];
            jogadoresMain[0].contadorDePecas--;

            return 0;
        }
        else
        {
            printf("%s\nComeça com a maior soma...\n", jogadoresMain[1].nome);

            for (i = 0; i < 20 + 1; i++)
            {
                if (jogadoresMain[1].mao[i].ladoDireito != -1)
                {
                    printf("|%d|%d| - Peça %d\n", jogadoresMain[1].mao[i].ladoEsquerdo, jogadoresMain[1].mao[i].ladoDireito, i);
                }
            }
            printf("Qual peça vc vai jogar?\n");
            scanf("%d", &pecaJogada);
            mesaJogo->pecas[30] = jogadoresMain[1].mao[pecaJogada];
            jogadoresMain[1].contadorDePecas--;

            return 1;
        }
    }
    else
    {
        if (maiorCarrossel1.ladoDireito > maiorCarrossel2.ladoDireito)
        {
            printf("%s\nPossui o maior carrossel - |%d|%d| \n", jogadoresMain[0].nome, maiorCarrossel1.ladoEsquerdo, maiorCarrossel1.ladoDireito);
            mesaJogo->pecas[30] = maiorCarrossel1;

            return 2;
        }
        else
        {
            printf("%s\nPossui o maior carrossel - |%d|%d| \n", jogadoresMain[1].nome, maiorCarrossel2.ladoEsquerdo, maiorCarrossel2.ladoDireito);
            mesaJogo->pecas[30] = maiorCarrossel2;

            return 3;
        }
    }
}

int calcularSomaPecas(struct jogador jogador)
{
    int soma = 0;
    for (int i = 0; i < 7; ++i)
    {
        soma = soma + (jogador.mao[i].ladoEsquerdo) + (jogador.mao[i].ladoDireito);
    }
    return soma;
}

//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------
//----------------------------------------------

int decidirPeca(struct jogador *jogador, struct pecasDaMesa *pilha)
{
    int pecaJogada, i, girar, opcao, ui;
    struct peca pecaInvertida;

    printf("\n--peças da pilha da mesa ->%d<-\n", pilha->contadorDePecas);

    printf("\nMão do jogador: >%s<\n", jogador->nome);

    printf("peças do: %s ->%d<-\n", jogador->nome, jogador->contadorDePecas + 1);

    for (i = 0; i < 20 + 1; i++)
    {
        if (jogador->mao[i].ladoDireito != -1)
        {
            printf("|%d|%d| - Peça %d\n", jogador->mao[i].ladoEsquerdo, jogador->mao[i].ladoDireito, i);
        }
    }

    printf("\nJogar - 1\nComprar peca - 2\nPassar a vez - 3\nEncerrar Jogo - 4\n");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        printf("Qual peça vc vai jogar?\n");
        scanf("%d", &pecaJogada);
        return pecaJogada;
    }
    else if (opcao == 2)
    {
        compraPeca(jogador, pilha);
        return -1;
    }
    else if (opcao == 3)
    {
        return -1;
    }
    else if (opcao == 4)
    {
        printf("Encerrando o jogo\n");
        exit(1);
    }

    return pecaJogada;
}

void compraPeca(struct jogador *jogador, struct pecasDaMesa *pilha)
{

    struct peca pecaTemp;
    int indice, i, n1, n2;

    if (pilha->contadorDePecas == 0)
    {
        printf("Sem peças\n");
        return;
    }

    for (i = 0; i < 28; i++)
    {
        indice = rand() % 28;
        if (pilha->pecasDaPilha[indice].ladoDireito != -1 && pilha->pecasDaPilha[indice].ladoEsquerdo != -1)
        {
            if (pilha->pecasDaPilha[indice].ladoDireito >= 0 && pilha->pecasDaPilha[indice].ladoDireito <= 6, pilha->pecasDaPilha[indice].ladoEsquerdo >= 0 && pilha->pecasDaPilha[indice].ladoEsquerdo <= 6)
            {
                pecaTemp = pilha->pecasDaPilha[indice];
                break;
            }
        }
    }

    for (i = 8; i < 21; i++)
    {
        if (jogador->mao[i].ladoDireito == -1)
        {
            jogador->mao[i] = pecaTemp;
            printf("peça comprada: |%d|%d| - peça %d", jogador->mao[i].ladoEsquerdo, jogador->mao[i].ladoDireito, i);
            jogador->contadorDePecas++;
            pilha->contadorDePecas--;
            system("pause");
            pilha->pecasDaPilha[indice].ladoDireito = -1;
            return;
        }
    }
}

int menu2(int girou)
{

    int opcao;
    if (girou != 2)
    {

        printf("1 - JogarPeca\n2 - GirarPeca\n");
        scanf("%d", &opcao);
        return opcao;
    }
    else
    {
        printf("Peça girada será jogada\n");
        return 1;
    }
}

int verifica(struct jogador *jogador, int qualPeca, struct mesa *mesaJogo, int *qualLado)
{

    int i, ladoE = 0, ladoD = 0;

    for (i = 0; i < 31; i++)
    {
        if (mesaJogo->pecas[i].ladoDireito == -1)
        {
            if (mesaJogo->pecas[i + 1].ladoEsquerdo == jogador->mao[qualPeca].ladoDireito)
            {
                ladoE = 1;
                break;
            }
            continue;
        }
    }

    for (i = 30; i < 60; i++)
    {
        if (mesaJogo->pecas[i].ladoDireito == -1)
        {
            if (mesaJogo->pecas[i - 1].ladoDireito == jogador->mao[qualPeca].ladoEsquerdo)
            {
                ladoD = 2;
                break;
            }
            continue;
        }
    }

    if (ladoE == 1 && ladoD != 2)
    {
        printf("Pode jogar no lado esquerdo\n");
        *qualLado = 1;
        return 1;
    }
    else if (ladoD == 2 && ladoE != 1)
    {
        printf("Pode jogar no lado direito\n");
        *qualLado = 2;
        return 1;
    }
    else if (ladoE == 1 && ladoD == 2)
    {
        printf("Pode jogar dos dois lados\n");
        *qualLado = 3;
        return 1;
    }
    printf("Não pode jogar em nenhum lado\n");
    return 0;
}

void girarPeca(struct jogador *jogador, int qualPeca)
{
    int aux;

    aux = jogador->mao[qualPeca].ladoDireito;
    jogador->mao[qualPeca].ladoDireito = jogador->mao[qualPeca].ladoEsquerdo;
    jogador->mao[qualPeca].ladoEsquerdo = aux;

    return 2;
}

void jogarPeca(struct jogador *jogador, int qualPeca, struct pecasDaMesa *pilha, struct mesa *mesaJogo, int qualLado)
{

    int ED, deu, i;

    if (qualLado == 1)
    {
        for (i = 0; i < 31; i++)
        {
            if (mesaJogo->pecas[i].ladoDireito != -1)
            {
                mesaJogo->pecas[i - 1] = jogador->mao[qualPeca];
                for (i = 0; i < 60; i++)
                {
                    if (mesaJogo->pecas[i].ladoDireito == -1)
                    {
                        continue;
                    }
                    else
                    {
                        printf("- |%d|%d| -", mesaJogo->pecas[i].ladoEsquerdo, mesaJogo->pecas[i].ladoDireito);
                    }
                }
                jogador->contadorDePecas--;
                jogador->mao[qualPeca].ladoDireito = -1;
                system("pause");
                break;
            }
        }
        printf("Lado Esquerdo\n");
    }

    else if (qualLado == 2)
    {

        for (i = 30; i < 60; i++)
        {
            if (mesaJogo->pecas[i].ladoDireito == -1)
            {
                mesaJogo->pecas[i] = jogador->mao[qualPeca];
                for (i = 0; i < 60; i++)
                {
                    if (mesaJogo->pecas[i].ladoDireito == -1)
                    {
                        continue;
                    }
                    else
                    {
                        printf("- |%d|%d| -", mesaJogo->pecas[i].ladoEsquerdo, mesaJogo->pecas[i].ladoDireito);
                    }
                }
                jogador->contadorDePecas--;
                jogador->mao[qualPeca].ladoDireito = -1;
                system("pause");
                break;
            }
        }
        printf("Lado Direito\n");
    }

    else if (qualLado == 3)
    {
        printf("Deseja colocar em qual lado?\n");
        printf("ESQUERDO - 1\nDIREITO - 2\n");
        scanf("%d", &ED);
        do
        {

            if (ED == 1)
            {
                for (i = 0; i < 31; i++)
                {
                    if (mesaJogo->pecas[i].ladoDireito != -1)
                    {
                        mesaJogo->pecas[i - 1] = jogador->mao[qualPeca];
                        for (i = 0; i < 60; i++)
                        {
                            if (mesaJogo->pecas[i].ladoDireito == -1)
                            {
                                continue;
                            }
                            else
                            {
                                printf("- |%d|%d| -", mesaJogo->pecas[i].ladoEsquerdo, mesaJogo->pecas[i].ladoDireito);
                            }
                        }
                        jogador->contadorDePecas--;
                        jogador->mao[qualPeca].ladoDireito = -1;
                        system("pause");
                        return;
                        break;
                    }
                }
                printf("Lado Esquerdo\n");
            }

            else if (ED == 2)
            {

                for (i = 30; i < 60; i++)
                {
                    if (mesaJogo->pecas[i].ladoDireito == -1)
                    {
                        mesaJogo->pecas[i] = jogador->mao[qualPeca];
                        for (i = 0; i < 60; i++)
                        {
                            if (mesaJogo->pecas[i].ladoDireito == -1)
                            {
                                continue;
                            }
                            else
                            {
                                printf("- |%d|%d| -", mesaJogo->pecas[i].ladoEsquerdo, mesaJogo->pecas[i].ladoDireito);
                            }
                        }
                        jogador->contadorDePecas--;
                        jogador->mao[qualPeca].ladoDireito = -1;
                        system("pause");
                        return;
                        break;
                    }
                }
                printf("Lado Direito\n");
            }

            else
            {
                printf("Insira 1 ou 2\n");
            }
        } while (ED != 1 || ED != 2);
    }
}

void imprimeMesa(struct mesa *mesaJogo)
{
    int i;
    system("cls");

    for (i = 0; i < 60; i++)
    {
        if (mesaJogo->pecas[i].ladoDireito == -1)
        {
            continue;
        }
        else
        {
            printf("- |%d|%d| -", mesaJogo->pecas[i].ladoEsquerdo, mesaJogo->pecas[i].ladoDireito);
        }
    }
}

int passarVez(int quemComeca)
{

    if (quemComeca == 1)
    {
        return 0;
    }
    if (quemComeca == 0)
    {
        return 1;
    }
    if (quemComeca == 2)
    {
        return 1;
    }
    if (quemComeca == 3)
    {
        return 0;
    }
}

void salvar(struct estate *estado)
{

    FILE *arq = fopen("save.bin", "wb");
    if (arq == NULL)
    {
        printf("erro ao abrir o save.bin para salvar o game\n");
        exit(1);
    }
    else
    {
        if (fwrite(estado, sizeof(struct estate), 1, arq) != 1)
        {
            printf("erro pra salvar\n");
            system("pause");
            return;
        }
        else
        {
            printf("salvo com sucesso\n");
            system("pause");
            system("cls");
        }
    }
    fclose(arq);
}

void carregar(struct estate *estado)
{

    FILE *arq = fopen("save.bin", "rb");
    if (arq == NULL)
    {
        printf("erro ao abrir o save.bin para carregar o game\n");
        exit(1);
    }
    else
    {
        if (fread(&estado, sizeof(struct estate), 1, arq) != 1)
        {
            printf("erro pra carregar\n");
            system("pause");
            exit(1);
        }
        else
        {
            printf("salvo com sucesso\n");
            system("pause");
            system("cls");
        }
    }
    fclose(arq);
}

int menuEspecial()
{

    int opcao;

    printf("1 - girar mais uma vez\n2 - Passar a vez\n");
    scanf("%d", &opcao);
    return opcao;
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int op, quemJogou, fimJogo, primeiraJogada, i, j, opcaoEscolhida;

    int quemComeca, opcao, qualPeca, jogaOuGira, pode, qualLado = 0, feito, girou, jogador, opcaoEspecial;
    int partida, ladoEscolhido, iC1, iC2, controle = 0, save;

    struct estate estado;
    struct mesa mesaJogo;
    struct pecasDaMesa pilha;
    struct jogador jogadoresMain[2];
    mesaJogo.qntd = 0;
    for (i = 0; i < 60; i++)
    {
        mesaJogo.pecas[i].ladoDireito = -1;
        mesaJogo.pecas[i].ladoEsquerdo = -1;
    }

    /*for(i = 0; i < 60; i ++){
        printf("-|%d|%d|-", mesaJogo.pecas[i].ladoEsquerdo, mesaJogo.pecas[i].ladoDireito);
    }
    system("pause");*/
    // para debug

    mesaJogo.pecas[30].ladoEsquerdo = -2;

    struct peca pecaNula;
    pecaNula.ladoDireito = -1;
    pecaNula.ladoEsquerdo = -1;

    // todas as peças vazias são inicializadas com -1 para melhor identiicação

    for (j = 0; j <= 21; j++)
    {
        jogadoresMain[0].mao[j] = pecaNula;
    }
    for (j = 0; j <= 21; j++)
    {
        jogadoresMain[1].mao[j] = pecaNula;
    }

    // contador de peças da pilha e dos jogadores são inicializadas também!

    do
    {
        system("cls");

        printf("Domino MASTER GAME\n\n");
        printf("Jogo novo - 1\nCarregar Jogo - 2\nSair - 3\n"); //\n3 - Sair do Menu
        scanf("%d", &op);

        if (op == 1)
        {
            printf("Um novo jogo será inicializado\n");
            // Iniciar o jogo
            fflush(stdin);
        }
        else if (op == 2)
        {
            printf("Seu jogo está sendo carregado...\n");

            carregar(&estado);

            jogadoresMain[0] = estado.j[0];
            jogadoresMain[1] = estado.j[1];
            pilha = estado.pilha;
            mesaJogo = estado.mesaJogo;
            // loadEstate(&jogadoresMain[0], &jogadoresMain[1], &mesaJogo, &pilha);

            /*
            for(i = 0; i < 60; i++){
                printf("|%d|%d| - ", mesaJogo.pecas[i].ladoDireito, mesaJogo.pecas[i].ladoEsquerdo);
            }
            for(i = 0; i < 2; i++){
                printf("%s - %d peças", jogadoresMain[i].nome, jogadoresMain[i].contadorDePecas);
                for(i = 0; i < 20; i++){
                    printf("- |%d|%d| - peca %d\n", jogadoresMain[i].mao->ladoEsquerdo, jogadoresMain[i].mao->ladoDireito, jogadoresMain[i].contadorDePecas);
                }
            }
            for(i = 0; i < 28; i++){
                printf("- |%d|%d| - peca da pilha %d", pilha.pecasDaPilha->ladoEsquerdo, pilha.pecasDaPilha->ladoDireito, i );
            }
            printf("A pilha tem %d peças", pilha.contadorDePecas);
            system("pause");
            */
            // debug

            // função começa aqui

            // Função carregar estava sendo implementada

            do{
                imprimeMesa(&mesaJogo);
                printf("\n%s tem %d peças\n", jogadoresMain[0].nome, 1 + jogadoresMain[0].contadorDePecas);
                printf("%s tem %d peças\n", jogadoresMain[1].nome, 1 + jogadoresMain[1].contadorDePecas);

                qualPeca = decidirPeca(&jogadoresMain[jogador], &pilha);
                controle = 0;

                if (qualPeca != -1){

                    do
                    {
                        jogaOuGira = menu2(girou);

                        if (jogaOuGira == 1)
                        { // jogou e não girou
                            pode = verifica(&jogadoresMain[jogador], qualPeca, &mesaJogo, &qualLado);

                            if (pode == 1)
                            {
                                jogarPeca(&jogadoresMain[jogador], qualPeca, &pilha, &mesaJogo, qualLado);
                                // tem que atualizar a pilha

                                system("pause");
                                system("cls");
                                imprimeMesa(&mesaJogo);
                                // após toda jogada verifica se alguém venceu
                                if (1 + jogadoresMain[jogador].contadorDePecas == 0)
                                {
                                    printf("jogador %s, venceu\n", jogadoresMain[jogador].nome);
                                    system("pause");
                                    exit(1);
                                }
                            }
                            else
                            { // não pôde jogar
                                printf("não pôde jogar\n");
                                controle = 1;
                                break;
                            }
                        }

                        else if (jogaOuGira == 2)
                        { // girou a peça
                            girarPeca(&jogadoresMain[jogador], qualPeca);
                            printf("peça girada com sucesso\n");
                            printf("|%d|%d|\n", jogadoresMain[jogador].mao[qualPeca].ladoEsquerdo, jogadoresMain[jogador].mao[qualPeca].ladoDireito);
                            system("pause");
                            // jogaOuGira = 1;
                            controle = 1;
                            break;
                        }

                    } while (jogaOuGira != 1);

                    if (controle == 1)
                    { // controle se passa a vez ou se o jogador continua
                        system("cls");
                        imprimeMesa(&mesaJogo);
                        continue;
                    }
                }
                else if (qualPeca == -1){ // decidir peça tem um menu que tem uma opção que traz pra cá, pula a vez
                    printf("passando a vez\n");
                    system("pause");
                    system("cls");
                    imprimeMesa(&mesaJogo);
                }

                    jogador = passarVez(jogador);
                    system("cls");
                    imprimeMesa(&mesaJogo);
                }while (1);
                
                    
            }
            else if (op == 3)
            {
                printf("saindo...\n");
                exit(1);
            }
            else
            {
                printf("opção inválida");
                fflush(stdin);
            }
        }
        while (op != 1 && op != 2)
            ;

        //---- básico do jogo para iniciar o jogo ------
        if (op == 1)
        {

            iniciandoPecas(&pilha);

            identificar(jogadoresMain, 2);

            distribuirPecas(&pilha, &jogadoresMain[0]);

            distribuirPecas(&pilha, &jogadoresMain[1]);
        }

        system("cls");

        // primeiro rodada
        int terminou = 0;

        quemComeca = primeiro(jogadoresMain, 2, &mesaJogo, &iC1, &iC2);

        if (quemComeca == 2 || quemComeca == 3)
        {
            system("cls");

            imprimeMesa(&mesaJogo);
            if (quemComeca == 2)
            {
                printf("\n%s, começa com o carrossel\n", jogadoresMain[0].nome);
                jogadoresMain[0].mao[iC1].ladoDireito = -1;
                jogadoresMain[0].contadorDePecas--;
            }
            else
            {
                printf("\n%s, começa com o carrossel\n", jogadoresMain[1].nome);
                jogadoresMain[1].mao[iC2].ladoDireito = -1;
                jogadoresMain[1].contadorDePecas--;
            }
            jogador = passarVez(quemComeca);
        }
        else
        {
            jogador = quemComeca;
        }

        printf("\nquem é o jogador atual: %s\n", jogadoresMain[jogador].nome);

        do
        {
            imprimeMesa(&mesaJogo);
            printf("\n%s tem %d peças\n", jogadoresMain[0].nome, 1 + jogadoresMain[0].contadorDePecas);
            printf("%s tem %d peças\n", jogadoresMain[1].nome, 1 + jogadoresMain[1].contadorDePecas);

            qualPeca = decidirPeca(&jogadoresMain[jogador], &pilha); // qualPeca == opção
            controle = 0;

            if (qualPeca != -1)
            {

                do
                {
                    jogaOuGira = menu2(girou);

                    if (jogaOuGira == 1)
                    { // jogou e não girou
                        pode = verifica(&jogadoresMain[jogador], qualPeca, &mesaJogo, &qualLado);

                        if (pode == 1)
                        {
                            jogarPeca(&jogadoresMain[jogador], qualPeca, &pilha, &mesaJogo, qualLado);
                            // tem que atualizar a pilha

                            system("pause");
                            system("cls");
                            imprimeMesa(&mesaJogo);
                            // após toda jogada verifica se alguém venceu
                            printf("salvar - 1\nNão - 2\n");
                            scanf("%d", &save);
                            if (save == 1)
                            {

                                struct estate estado;
                                estado.j[0] = jogadoresMain[0];
                                estado.j[1] = jogadoresMain[1];
                                estado.mesaJogo = mesaJogo;
                                estado.pilha = pilha;
                                salvar(&estado);
                            }

                            if (1 + jogadoresMain[jogador].contadorDePecas == 0)
                            {
                                printf("jogador %s, venceu\n", jogadoresMain[jogador].nome);
                                system("pause");
                                exit(1);
                            }
                        }
                        else
                        { // não pôde jogar
                            printf("não pôde jogar\n");
                            controle = 1;
                            break;
                        }
                    }
                    else if (jogaOuGira == 2)
                    { // girou a peça
                        girarPeca(&jogadoresMain[jogador], qualPeca);
                        printf("peça girada com sucesso\n");
                        printf("|%d|%d|\n", jogadoresMain[jogador].mao[qualPeca].ladoEsquerdo, jogadoresMain[jogador].mao[qualPeca].ladoDireito);
                        system("pause");
                        // jogaOuGira = 1;
                        controle = 1;
                        break;
                    }

                } while (jogaOuGira != 1);

                if (controle == 1)
                { // controle se passa a vez ou se o jogador continua
                    system("cls");
                    imprimeMesa(&mesaJogo);
                    continue;
                }
            }
            else if (qualPeca == -1)
            { // decidir peça tem um menu que tem uma opção que traz pra cá, pula a vez
                printf("passando a vez\n");
                system("pause");
                system("cls");
                imprimeMesa(&mesaJogo);
            }

            jogador = passarVez(jogador);
            system("cls");
            imprimeMesa(&mesaJogo);

        } while (1);

        /*
        do{
            imprimeMesa(&mesaJogo);
            printf("\n%s tem %d peças\n", jogadoresMain[0].nome, 1 + jogadoresMain[0].contadorDePecas);
            printf("%s tem %d peças\n", jogadoresMain[1].nome, 1 + jogadoresMain[1].contadorDePecas);

            qualPeca = decidirPeca(&jogadoresMain[jogador], &pilha);
            controle = 0;

            if(qualPeca != -1){

                do{
                    jogaOuGira = menu2(girou);

                    if(jogaOuGira == 1){//jogou e não girou
                        pode = verifica(&jogadoresMain[jogador], qualPeca, &mesaJogo, &qualLado);

                        if(pode == 1){
                            jogarPeca(&jogadoresMain[jogador], qualPeca, &pilha, &mesaJogo, qualLado);
                            //tem que atualizar a pilha

                            system("pause");
                            system("cls");
                            imprimeMesa(&mesaJogo);

                            if(1 + jogadoresMain[jogador].contadorDePecas == 0){
                                printf("jogador %s, venceu\n", jogadoresMain[jogador].nome);
                                system("pause");
                                exit(1);
                            }

                            break;
                        }
                        else if(pode == 0){
                            printf("Não pode jogar essa peça");
                        }
                        else if(girou == 2){
                            printf("Não pode jogar a peça girada\n");

                        }
                    }
                    else if(jogaOuGira == 2){//girou a peça
                        girarPeca(&jogadoresMain[jogador], qualPeca);
                        printf("peça girada com sucesso\n");
                        printf("|%d|%d|\n", jogadoresMain[jogador].mao[qualPeca].ladoEsquerdo, jogadoresMain[jogador].mao[qualPeca].ladoDireito);
                        system("pause");
                        //jogaOuGira = 1;
                        controle = 1;
                        break;
                    }

                }while(jogaOuGira != 1);

                if(controle == 1){
                    system("cls");
                    imprimeMesa(&mesaJogo);
                    continue;
                }
            }
            else if(qualPeca == -1){
                printf("passando a vez\n");
                system("pause");
                system("cls");
                imprimeMesa(&mesaJogo);
            }

            jogador = passarVez(jogador);
            system("cls");
            imprimeMesa(&mesaJogo);

        }while(1);*/
    }
