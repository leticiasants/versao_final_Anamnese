/**************************************************************************
    Jogo Anamnese
    Autores: Huandy Calini, Letícia Vitória, Luara Perilli e Luis Damasceno
    Data da última atualização: 20/06/2022
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

// Declaração de funções

/********************************************************* 
  Função para transformar letras minúsculas em maiúsculas
  Parâmetros: um parametro do tipo caracter
  Saída: a mesma letra mas em maiúsculo char
**********************************************************/
char letra_maiuscula(char opcao) {
  // Processo de transformação da letra para maiúsculo
  opcao = toupper(opcao);
  return opcao;
}

/***********************************************
    Função para executar as escolhar do usuário
    Parâmetros: caracter
    Saída: void
***********************************************/
void menu(char escolha, GAMER *jogador, FILE *classificacao) {
    // Declaração de variável
    int voltar_menu;
    char sair;

    // Estrutura condicional switch case responsável pela exibição da escolha do usuário
    switch (escolha)
    {
        // Opção para executar o jogo
        case 'J':
            // Do while loop controlador da exibição do jogo
            jogo(jogador, classificacao);
        break;


        // Opção para ver o ranking
        case 'R':
            // Do while loop controlador da exibição do ranking
            do
            {
                system("cls");
                voltar_menu = ranking();
                system("cls");

            } while (voltar_menu != 1);
        break;

        // Opção para mostrar as instruções do jogo
        case 'I':
            // Do while loop controlador da exibição das instruções
            do
            {
                voltar_menu = instrucoes();
                
            } while (voltar_menu != 1);
        break;

        // Opção para visualizar os créditos
        case 'C':
            // Do while loop controlador da exibição dos créditos
            do
            {
                voltar_menu = credito();
                
            } while (voltar_menu != 1);
        break;

        // Opção para sair do jogo
        case 'S':
            // Função para limpar a tela no terminal
            system("cls");
            // Exibição da mensagem que será exibida ao sair do jogo
            printf(" ----------------------------\n");
            printf("|          ANAMNESE          |\n");
            printf(" ----------------------------\n");
            printf("|       Fechando jogo...     |\n");
            printf(" ----------------------------\n");
        break;

        // Opção para quando o jogador teclar um caracter inválido
        default:
            // Do while loop controldor da exibição da opção inválida
            do
            {
                voltar_menu = opcao_invalida();
                
            } while (voltar_menu != 1);
        break;
    }
};

/*****************************
    Função para voltar ao menu
    Parâmetros: nenhum
    Saída: inteiro
******************************/
int voltar() {
    // Declaração de variável
    int retornar = 1;
    printf("\n\nDigite [1] para voltar ao menu: ");
    // Leitura da variável controladora da exibição do jogo
    scanf("%d", &retornar);

    return retornar;
};

/********************************
    Função para exibir o ranking
    Parâmetros: nenhum
    Saída: inteiro
*********************************/
int ranking(){
    int voltar_menu = 0;

    char nome[40];
    int ponto;
    int sequencia;

    FILE *class;

    class = fopen("ranking.txt", "r");

    while((fscanf(class, "%s %d %d\n", nome, &ponto, &sequencia))!=EOF) {
        printf("Nome:%s \nPonto:%d \nMaior sequencia decorada:%d\n\n", nome, ponto, sequencia);
    }

    voltar_menu = voltar();

    return voltar_menu;
}


/********************************
    Função para exibir instruções
    Parâmetros: nenhum
    Saída: inteiro
*********************************/
int instrucoes() {
    // Decaração da variável
    int voltar_menu;
    // Função para limpar a tela no terminal
    system("cls");
    // Exibição das instruções do jogo
    printf("------------------------------------------------------------------------\n");
    printf("|                             ANAMNESE                                 |\n");
    printf("------------------------------------------------------------------------\n");
    printf("                             INSTRUCOES\n");
    printf("------------------------------------------------------------------------\n");
    printf("\n  1. O jogador deve escolher o tamanho da sequencia que sera decorada;\n");
    printf("  2. O jogador deve reproduzir a sequencia de numeros na ordem correta;\n");
    printf("  3. O jogo termina caso o jogador cometa um erro ou opta por encerrar.\n\n");
    printf("------------------------------------------------------------------------\n");

    voltar_menu = voltar();

    return voltar_menu;
};

/*********************************
    Função para exibir os créditos
    Parâmetros: nenhum
    Saída: inteiro
**********************************/
int credito() {
    // Declaração de variável
    int voltar_menu;
    // Função para limpar a tela no terminal
    system("cls");
    // Exibição dos créditos aos criadores
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("|                                             ANAMNESE                                             |\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("                                              CREDITOS\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("\n Este jogo foi criado em 2022 por: ");
    printf("Huandy Calini de Camargo Silva, Leticia Vitoria dos Santos,\n");
    printf(" Luara do Val Perilli e Luis Eduardo Damasceno, ");
    printf("alunos da disciplina de Fundamentos de Programacao, \n");
    printf(" e deve ser utilizado como ferramenta educacional e de entretenimento.\n\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    voltar_menu = voltar();

    return voltar_menu;
};

/**************************************************
    Função para exibir mensagem para opção inválida
    Parâmetros: nenhum
    Saída: inteiro
***************************************************/
int opcao_invalida() {
    // Declaração de variável
    int voltar_menu;
    // Função para limpar a tela no terminal
    system("cls");
    // Exibição da mensagem que será exibida quando o usuário digitar uma opção inválida
    printf(" ----------------------------\n");
    printf("|          ANAMNESE          |\n");
    printf(" ----------------------------\n");
    printf("|       Opcao invalida       |\n");
    printf(" ----------------------------\n");
    
    voltar_menu = voltar();

    return voltar_menu;
};
