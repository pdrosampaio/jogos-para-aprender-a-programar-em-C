#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int seed = time(0);
    srand(seed);

    int numero_secreto = rand() % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int numero_tentativas;
    int dificuldade;
    int acertou;

    printf("************************************\n");
    printf("* Bem-Vindo ao jogo de adivinhação *\n");
    printf("************************************\n");

    printf("Você deseja jogar em qual dificuldade?\n");
    printf("(1) Muito fácil (2)Fácil (3)Médio (4)Difícl\n\n");
    printf("Esoclha: ");
    scanf("%d", &dificuldade);

    if (dificuldade == 1){
        numero_tentativas = 100;
        printf("Você escolheu a dificuldade Muito fácil.\n");
    } 
    else if (dificuldade == 2){
        numero_tentativas = 50;
        printf("Você escolheu a dificuldade Fácil.\n");
    } 
    else if (dificuldade == 3){
        numero_tentativas = 20;
        printf("Você escolheu a dificuldade Médio.\n");
    } 
    else {
        numero_tentativas = 10;
        printf("Você escolheu a dificuldade Difícil.\n");
    }
    
    for (int i=1; i<=numero_tentativas; i++){
        
        printf("Tentativa número %d.", tentativas);
        printf("Qual é o seu chute? \n");
        scanf("%d", &chute);
        printf("Seu chute foi %d.\n", chute);
        
        int maior = chute > numero_secreto;
        acertou = chute == numero_secreto;

        if (chute < 0){
            printf("Você não pode chutar números negativos!\n");

            continue;
        }
        else if (acertou){
            printf("Você acertou!");
            
            break;
        }
        else if (maior){
            printf("Você errou!");
            printf("Seu chute foi maior que o número secreto.\n");
        }
        else {
            printf("Você errou!");
            printf("Seu chute foi menor que o número secreto.\n");
        }
        tentativas++;

        double pontos_perdidos = (double)(chute - numero_secreto) / 2;
        pontos = pontos - abs(pontos_perdidos);
    }
    printf("Fim de jogo!\n");
    
    if (acertou){
        printf("Você acertou em %d.\n", tentativas);
        printf("Você fez %.2f pontos.\n", pontos);
    }
    else {
        printf("Você perdeu! Tente novamente.");
    }
}