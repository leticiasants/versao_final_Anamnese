/**************************************************************************
    Jogo Anamnese
    Autores: Huandy Calini, Letícia Vitória, Luara Perilli e Luis Damasceno
    Data da última atualização: 18/07/2022
***************************************************************************/

// Definição de bibiblioteca
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#include "menu.h"
#include "jogo.h"

/**************************
    Função principal
    Parametros: nenhum
    Retorno: inteiro
**************************/
int main()
{
    // Declaração das variáveis e struct
    char escolha;
    GAMER *jogador;

    // Chamada de função para alocação dinamica da struct gamer jogador
    jogador = criaJogador();
    
    // Do while loop controlador do menu principal
    do
    {
        // Função para limpar a tela no terminal
        system("cls");

        // Saída do nome do jogo
        printf(" ----------------------------\n");
        printf("|          ANAMNESE          |\n");
        printf(" ----------------------------\n");

        // Escrita das opções das quais o jogador deve escolher
        printf("|     Escolha uma opcao:     |");
        printf("\n|       [J] Jogar            |");
        printf("\n|       [R] Ranking          |");
        printf("\n|       [I] Instrucoes       |");
        printf("\n|       [C] Creditos         |");
        printf("\n|       [S] Sair             |\n");
        printf(" ----------------------------\n");
        // Leitura da variável escolha do usuário
        scanf(" %c", &escolha);

        // Chamada da função para transformar letra minuscula em maiuscula
        escolha = letra_maiuscula(escolha);

        // Chamada da função para realizar a escolha do usuário
        menu(escolha, jogador);
        
        printf("escolha = %c", escolha);

    } while (escolha != 'S');

    // Chamada da funçao que libera a alocação dinâmica da struct gamer jogador
    liberaJogador(jogador);
        
    return 0;
}
