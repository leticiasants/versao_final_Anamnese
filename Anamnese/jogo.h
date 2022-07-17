/**************************************************************************
  Jogo Anamnese
  Autores: Huandy Calini, Letícia Vitória, Luara Perilli e Luis Damasceno
  Data da ultima atualização: 05/07/2022
***************************************************************************/
typedef struct gamer GAMER;

//Protótipos do projeto
void jogo(GAMER *jogador, FILE *classificacao);

GAMER *criaJogador();

void liberaJogador(GAMER *jogador);