# Domino
 

Partida de Dominó
Como base, eu tomei o jogo de dominó cotidiano, que usualmente
jogamos.
28 peças no total e 7 para cada jogador. Cada jogador pode jogar, comprar
ou passar a vez. No final, o jogador que não tiver mais peças ganha. E a
decisão de quem joga primeiro se dá por meio, na esmagadora maioria de
vezes, por meio do maior carrossel.
Tendo como base esses fundamentos, eu desenvolvi um código que
simula uma partida de dominó entre dois jogadores, por meio de diversas
funções e estruturas do jogo.
Explicando:
O código apresenta quatro estruturas principais, struct peca, jogador,
pecasDaMesa, mesa e todas elas, exceto a struct peca, possuem a struct
peca como variável de seus tipos.
Depois de inicializar as estruturas, entramos na mais. Lá somos
apresentados a um menu simples de jogo novo ou carregar jogo. Jogo
novo: inicia um nova partida do zero de dominó e carregar jogo apenas
continua a partida que foi salva anteriormente.
Partindo do jogo novo: iniciamos três funções básicas do jogo. Inicialização
das peças, nome dos jogadores, distribuição.
Nessas três, respectivamente, todas as pecas da estrutura pecasDaMesa
é inicializada com as 28 peças do dominó, em seguida damos um nome ao
player 1 e 2 ou 0 e 1, pois são um array. E por fim o distribuir peças que
possui um algoritmo de randomizar indices de peças da estrutura
pecasDaMesa para serem colocados na mao do jogador, sendo essas
outras estruturas de pecas dentro do struct jogador.
Após essas três funções bases, o código nos leva para a decisão do
primeiro jogador. Essa função irá, prioritariamente, procurar o primeiro
carrossel para ser posto na mesa e assim o jogo iniciar. o carrossel será
procurado por meio de função dentro desta maior, no caso, a função
carrossel que apenas compara os valores de um lado da peça.
Caso não existam carrosséis outros meios de desempate são acionados.
Como a dupla maior ou a maior soma.
Após a primeira peça ser posta o loop básico do jogo é inicializado.
O loop é formado por 2 loops do-while. O primeiro loop é infinito, o
segundo acaba quando uma peça é girada ou não.
Esse loop básico representa o funcionamento principal de um jogo de
dominó. Vou descrever o que cada parte do loop faz em termos de lógica
do jogo:
Impressão do Estado Atual:
A função imprimeMesa é chamada para exibir o estado atual da mesa de
jogo.
As informações sobre o número de peças que cada jogador possui são
exibidas.
Escolha da Peça:
A função decidirPeca é chamada para que o jogador atual (representado
pela variável jogador) escolha uma peça para jogar.
Se o jogador optar por não jogar (talvez porque não tem peças válidas
para jogar), ele pode passar sua vez.
Menu para Jogar ou Girar:
Um menu é apresentado ao jogador, oferecendo a opção de jogar a peça
escolhida ou girá-la.
Se o jogador optar por girar a peça, a função girarPeca é chamada para
girar a peça escolhida.
Verificação da Possibilidade de Jogar:
Se o jogador escolher jogar a peça, a função verifica é chamada para
verificar se a peça escolhida pode ser jogada na mesa.
Se possível, a peça é jogada na mesa usando a função jogarPeca, e a
pilha de peças é atualizada.
Se o jogador optar por salvar o estado do jogo, a função saveEstate é
chamada.
Verificação de Condição de Vitória:
Após cada jogada, verifica-se se o jogador atual esgotou suas peças. Se
sim, ele é declarado vencedor e o jogo termina.
Passagem da Vez:
A função passarVez é chamada para alternar para o próximo jogador.
Loop Infinito:
O jogo continua em um loop infinito (while(1)) até que uma condição de
término seja atendida.
Esse loop fornece uma estrutura básica para a jogabilidade, permitindo
que os jogadores escolham peças, as joguem na mesa, girem peças, e
assim por diante. O jogo continua indefinidamente até que um jogador
vença ou até que seja encerrado manualmente.
E isso continua até o jogo finalizar!
Funções:
void iniciandoPecas(struct pecasDaMesa *pilha);
inicializar todas as peças
void identificar(struct jogador jogadoresMain[], int numJogadores);
dá nome aos jogadores
void distribuirPecas(struct pecasDaMesa *pilha, struct jogador *jogadores);
dá as peças aos jogadores
struct peca carrossel(struct jogador jogadorC, int *indice);
verifica os carrosséis
int primeiro(struct jogador jogadoresMain[], int jogadores, struct mesa
*mesaJogo,
int *indiceCarrossel1, int *indiceCarrossel2);
quem será o primeiro jogador
int calcularSomaPecas(struct jogador jogador);
calcula a soma das peça para desempate
int decidirPeca(struct jogador *jogador, struct pecasDaMesa *pilha);
pequeno menu para jogar, comprar peça ou passar a vez
void compraPeca(struct jogador *jogador, struct pecasDaMesa *pilha);
compra uma peça
int menu2(int girou);
se o jogador quer girar ou não um determinada peça
int verifica(struct jogador *jogador, int qualPeca, struct mesa *mesaJogo,
int *qualLado);
verifica se pode jogar no lado esquerdo ou direito ou em ambos da
mesa
void girarPeca(struct jogador *jogador, int qualPeca);
gira uma determinada peça
void jogarPeca(struct jogador *jogador, int qualPeca, struct pecasDaMesa
*pilha, struct mesa *mesaJogo, int qualLado);
coloca uma peça da mão do player na mesa
void imprimeMesa(struct mesa *mesaJogo);
mostra a mesa para os jogadores
int passarVez(int quemComeca);
passa a vez para o outro player
void saveEstate(struct jogador *jogadoresMain0, struct jogador
*jogadoresMain1, struct mesa *mesaJogo, struct pecasDaMesa *pilha);
salva o jogo em um arquivo
void loadEstate(struct jogador *jogadoresMain0, struct jogador
*jogadoresMain1, struct mesa *mesaJogo, struct pecasDaMesa *pilha);
carrega o jogo de um arquivo
Structs:
struct peca{
int ladoDireito;
int ladoEsquerdo;
};
Peça base
struct jogador {
char nome[50];
struct peca mao[21];
int contadorDePecas;
};
Jogador
struct pecasDaMesa{
struct peca pecasDaPilha[28];
int contadorDePecas;
};
Peças da mesa, as que podem ser compradas
struct mesa{
struct peca pecas[61];
int qntd;
};
Mesa do jogo com as peças que foram jogadas
Dificuldades:
A maior dificuldade foi a abstração que um jogo requer. Diferente de um
sistema mais usual, como um sistema de cadastro ou algo do gênero, é
que o um jogo exige que pensemos fora da caixa, exige que pensemos
sobre novas, diferentes e inovadoras formas de fazer a mesma coisa. Por
exemplo, durante conversas com colegas sobre como eles imprimiam a
mesa do jogo eu percebi que todos tinham uma forma diferente de fazer a
mesma coisa. Por quê? Porque um jogo é muito mais abstrato do que um
sistema comum.
Realizações
Ter feito esse código sozinho, pensando na maioria das funções e nas
formas de implementá-las, me fez me sentir muito autônomo e
responsável. Ir atrás de respostas de erros, segmentation fault, campos
indevidos de structs e por aí vai.


