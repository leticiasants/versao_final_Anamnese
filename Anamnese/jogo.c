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

// Criação da struct gamer
struct gamer {
    // Variávei pertencentes a struct gamer
    char nome[30];
    int pontuacao;
    int maior_sequencia;
};

// Função de alocação dinâmica da a struct gamer, nomeada GAMER
GAMER *criaJogador(){
    return (GAMER*)malloc(sizeof(GAMER));
}

// Função que libera a alocação dinâmica da struct gamer, neste caso GAMER *jogador
void liberaJogador(GAMER *jogador){
    free(jogador);
}

/*************************************
    Função para abrir o jogo
    Parâmetros: struct gamer jogador
    Retorno: não possui retorno (void)
**************************************/
void jogo(GAMER *jogador) {
    //Declaração de variáveis e vetores
    int tamanho;
    int *numeros_gerados;
    int numero_digitado;
    char sair;
    int i;
    int ponto = 0;
    int maior = 0;
    
    // Função para limpar o terminal
    system("cls");
    // Exibição do nome do jogo
    printf("-------------------------------------------------------\n");
    printf("                      ANAMNESE\n");
    printf("-------------------------------------------------------\n");
    // Leitura do nome do jogador
    printf("\n           Qual o seu nome de jogador? ");
    scanf("%s", jogador->nome);
    
    // Do while loop controlador da execução do jogo 
    do
    {
        // Função para limpar a tela do terminal
        system("cls");
        // Função para não gerar sempre a mesma sequência de números
        srand(time(NULL));
        // Exibição do nome do jogo
        printf("-------------------------------------------------------\n");
        printf("                      ANAMNESE\n");
        printf("-------------------------------------------------------\n");
        // Exibição da pontuação do jogador
        printf("\n                 Pontuacao atual: %d", ponto);
        printf("\n-------------------------------------------------------\n");
        // Leitura do tamanho da sequência que o jogador deseja memorizar
        printf("\n  Qual tamanho da sequencia que voce deseja memorizar? ");
        scanf("%d", &tamanho);

        // Alocação dinamica para os números da sequência que será exibida
        numeros_gerados = (int*) malloc(tamanho * sizeof(int)); 

        // Função que gera numeros aleatórios, de 0 a 10, para a sequência
        for (i = 0; i < tamanho; i++){
            numeros_gerados[i] = ((rand() + 1) % 10);
        }

        // Exibição dos números da sequencia
        printf("\n                   ");
        for (i = 0; i < tamanho; i++){
            printf("[%d] ", numeros_gerados[i]);
        }

        // Função de tempo, para aguardar 3 segundos e limpar a tela
        Sleep(3000);
        system("cls");

        // Função for para ler os números digitados pelo jogador
        for(i = 0; i < tamanho; i++) {

            system("cls");
            // Escrita do nome do jogo
            printf("-------------------------------------------------------\n");
            printf("                      ANAMNESE\n");
            printf("-------------------------------------------------------\n");
            // Leitura do número digitado pelo jogador
            printf("\nDigite o %d numero da sequencia: ", i+1);
            scanf("%d", &numero_digitado);
    
            if (numeros_gerados[i] == numero_digitado) {
                // Função que limpa o terminal
                system("cls");
                // Escrita do nome do jogo
                printf("-------------------------------------------------------\n");
                printf("                      ANAMNESE\n");
                printf("-------------------------------------------------------\n");
                // Escrita de mensagem afirmativa para o acerto
                printf("\n         Esta no caminho certo! Continue...");
            } else {
                // Função que limpa o terminal
                system("cls");
                // Escrita do nome do jogo
                printf("-------------------------------------------------------\n");
                printf("                      ANAMNESE\n");
                printf("-------------------------------------------------------\n");
                // Escrita de mensagem para o erro
                printf("\n         Eita :/! Melhor tentar novamente...");
                break;
            }
            
        }

         // If a ser executado se o jogador acertar toda a sequencia               
        if (i == tamanho) {
            system("cls");
            printf("-------------------------------------------------------\n");
            printf("                      ANAMNESE\n");
            printf("-------------------------------------------------------\n");
            printf("\n    Que boa sua memoria! Que tal aumentar a sequencia?");
            // Acrescentando pontos
            ponto++;
            // Armazenamento do tamanho da maior sequencia que o jogador memorizou
            if (maior < tamanho) {
                maior = tamanho;
            }
        }
       
        printf("\n-------------------------------------------------------\n");

        // Liberando alocação dinamica dos números gerados
        free(numeros_gerados);
        
        // Leitura da variável para continuar ou parar o jogo
        printf("\n\nDeseja continuar a jogar? [S] para sim e [N] para nao: ");
        scanf(" %c", &sair);
                    
    } while (letra_maiuscula(sair) != 'N');

    // Atribuição das variáveis para as variáveis da struct gamer jogador
    jogador->pontuacao = ponto;
    jogador->maior_sequencia = maior;

    // Ponteiro para o arquivo
    FILE *class_a;

    // Função para abrir o arquivo
    class_a = fopen("ranking.txt", "a");
    if (class_a == NULL) {
        printf("Erro ao abrir o arquivo!");
    }

    // Leitura de informações para o arquivo
    fprintf(class_a, "%s ", jogador->nome);
    fprintf(class_a, "%d ", jogador->pontuacao);
    fprintf(class_a, "%d\n", jogador->maior_sequencia);

    // Função para fechar o arquivo
    fclose(class_a);

    system("cls");
};
