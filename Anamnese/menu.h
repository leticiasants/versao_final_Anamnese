/**************************************************************************
  Jogo Anamnese
  Autores: Huandy Calini, Letícia Vitória, Luara Perilli e Luis Damasceno
  Data da ultima atualização: 18/07/2022
***************************************************************************/

// Inclusão de biblioteca para acessar a struct gamer jogador
#include "jogo.h" 

// Protótipos das funções relacionadas ao menu
char letra_maiuscula(char opcao);
void menu(char escolha, GAMER *jogador);
int voltar();
int ranking();
int instrucoes();
int credito();
int opcao_invalida();
