/**************************************************************************
  Jogo Anamnese
  Autores: Huandy Calini, Letícia Vitória, Luara Perilli e Luis Damasceno
  Data da ultima atualização: 18/07/2022
***************************************************************************/
// Função para renomear o tipo struct
typedef struct gamer GAMER;

// Protótipos das funções relacionadas a execução do jogo
void jogo(GAMER *jogador);
GAMER *criaJogador();
void liberaJogador(GAMER *jogador);
