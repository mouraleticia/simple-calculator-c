#include <stdio.h>
#include <stdlib.h>

void limparTela(){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls || clear");
    #elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #else
        for(int i = 0; i < 50; i++) printf("\n");
    #endif
}

void pausar(){
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

void mostrarMenu(){
    printf("\x1b[1;34m==========================================\x1b[0m\n");
    printf("\x1b[1;34m                CALCULADORA               \x1b[0m\n");
    printf("\x1b[1;34m==========================================\x1b[0m\n");
    printf("\x1b[1;33m[1]\x1b[0m" " Soma\n");
    printf("\x1b[1;33m[2]\x1b[0m" " Subtracao\n");
    printf("\x1b[1;33m[3]\x1b[0m" " Multiplicacao\n");
    printf("\x1b[1;33m[4]\x1b[0m" " Divisao\n");
    printf("\x1b[1;31m[5]\x1b[0m" " Sair\n");
    printf("\x1b[1;34m------------------------------------------\x1b[0m\n");
    printf("\x1b[1;34m            Escolha uma opcao:            \x1b[0m\n");
}

float soma(float a, float b){
    return a + b;
}

float subtracao(float a, float b){
    return a - b;
}

float multiplicacao(float a, float b){
    return a * b;
}

float divisao(float a, float b){
    if(b == 0){
        printf("\x1b[1;31mERRO:" "\x1b[31m Nao eh possivel fazer divisao por zero!\x1b[0m\n");
        return 0;
    }
    return a / b;
}

int main(){

    int opcao;
    float x, y, resultado;

    do{
        limparTela();
        mostrarMenu();
        scanf("%d", &opcao);

        if(opcao >=1 && opcao <=4){
            printf("Digite o primeiro numero: ");
            scanf("%f", &x);

            printf("Digite o segundo numero: ");
            scanf("%f", &y);

            switch(opcao){

                case 1:
                resultado = soma(x,y);
                break;

                case 2:
                resultado = subtracao(x,y);
                break;

                case 3:
                resultado = multiplicacao(x,y);
                break;

                case 4:
                resultado = divisao(x,y);
                break;

            }

            printf("Resultado: %.2f\n", resultado);
            pausar();

        }else if(opcao <=0 || opcao > 5){
            printf("Opcao invalida!\n");
            pausar();
        }

    }while(opcao != 5);

    printf("Programa encerrado\n");

    return 0;
}