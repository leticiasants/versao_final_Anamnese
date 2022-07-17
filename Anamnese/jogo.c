#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "menu.h"
#include "jogo.h"


struct gamer {
    char *nome;
    int pontuacao;
    int maior_sequencia;
};

GAMER *criaJogador(){
    return (GAMER*)malloc(sizeof(GAMER));
}

void liberaJogador(GAMER *jogador){
    free(jogador);
}

/*******************************
    Função para abrir o jogo
    Parâmetros: nenhum
    Saída: inteiro
********************************/

void jogo(GAMER *jogador, FILE *classificacao) {
    //Declaração de variáveis e vetores
    int tamanho;
    int *numeros_gerados;
    int numero_digitado;
    char sair;
    int i;
    int erro = 0;
    int ponto = 0;
    int maior = 0;
    
    system("cls");
    printf("-------------------------------------------------------\n");
    printf("                      ANAMNESE\n");
    printf("-------------------------------------------------------\n");
    printf("\n\n          Qual o seu nome de jogador? ");
    scanf("%s", jogador->nome);

    do
    {
        // Função para limpar a tela do terminal
        system("cls");
        srand(time(NULL));
        // Execução do jogo
        printf("-------------------------------------------------------\n");
        printf("                      ANAMNESE\n");
        printf("-------------------------------------------------------\n");
        printf("\n\n             Pontuacao atual: %d", ponto);
        printf("\n-------------------------------------------------------\n");
        printf("\n  Qual tamanho da sequencia que voce deseja memorizar? ");
        scanf("%d", &tamanho);

        if (maior < tamanho) {
            maior = tamanho;
        }

        numeros_gerados = (int*) malloc(tamanho * sizeof(int)); 

        for (i = 0; i < tamanho; i++){
            numeros_gerados[i] = ((rand() + 1) % 10);
        }

        printf("\n              ");
        for (i = 0; i < tamanho; i++){
            printf("%d ; ", numeros_gerados[i]);
        }

        Sleep(3000);
        system("cls");

        for(i = 0; i < tamanho; i++) {

            printf("-------------------------------------------------------\n");
            printf("                      ANAMNESE\n");
            printf("-------------------------------------------------------\n");
            printf("\nDigite o %d numero da sequencia: ", i+1);
            scanf("%d", &numero_digitado);
    
            if (numeros_gerados[i] == numero_digitado) {
                system("cls");
                printf("\n         Esta no caminho certo! Continue...");
            } else {
                printf("\n         Eita :/! Melhor tentar novamente...");
                break;
            }
            
        }
                        
        if (i == tamanho) {
            printf("\n    Que boa sua memoria! Que tal aumentar a sequencia?");
            ponto++;
        }
       
        printf("\n-------------------------------------------------------\n");

        printf("\n\nDeseja continuar a jogar? [S] para sim e [N] para nao: ");
        scanf(" %c", &sair);
        sair = letra_maiuscula(sair);
        
        free(numeros_gerados);
    } while (sair != 'N');

    jogador->pontuacao = ponto;
    jogador->maior_sequencia = maior;

    classificacao = fopen("ranking.txt", "a");
    if (classificacao == NULL) {
        printf("Erro ao abrir o arquivo!");
    }

    fprintf(classificacao, "%s ", jogador->nome);
    fprintf(classificacao, "%d ", jogador->pontuacao);
    fprintf(classificacao, "%d\n", jogador->maior_sequencia);

    fclose(classificacao);

    system("cls");
};
