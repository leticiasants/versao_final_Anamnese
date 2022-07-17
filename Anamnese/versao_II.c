/**************************************************************************
    Jogo Anamnese
    Autores: Huandy Calini, Letícia Vitória, Luara Perilli e Luis Damasceno
    Data da última atualização: 16/07/2022
***************************************************************************/

// Definição de bibiblioteca
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "menu.h"
#include "jogo.h"

/**************************
    Função principal
    Parametros: nenhum
    Saída: inteiro
**************************/

int main()
{
    // Abrindo arquivo
    FILE *classificacao;

    // Declaração das variáveis
    char escolha;
    GAMER *jogador;

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

        escolha = letra_maiuscula(escolha);

        menu(escolha, jogador, classificacao);

    } while (escolha != 'S');

    liberaJogador(jogador);
        
    return 0;
}
