#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

bool primeiravez = true, igual = false;
float resultado = 0, numeroum = 0, numerodois = 0;
char sinal[2];


void calculo(float *resultado);
void fimprograma();
void sinaligual();
void soma();
void subtracao();
void multiplicacao();
void divisao();
void elevar();
void raiz();

void verificacaopfim(bool *igual){
    if (*igual){
        fimprograma();
    }
}

void imprimircalculadora(){
    printf("   _______________________ \n");
    printf("  |                       | \n");
    printf("  |%22.2f |\n", resultado);
    printf("   _______________________ \n");
    printf("  |_______________________| \n");
    printf("  |       |       |       | \n");
    printf("  |   1   |   2   |   +   | \n");
    printf("  |_______|_______|_______| \n");
    printf("  |       |       |       | \n");
    printf("  |   3   |   4   |   -   | \n");
    printf("  |_______|_______|_______| \n");
    printf("  |       |       |       | \n");
    printf("  |   5   |   6   |   /   | \n");
    printf("  |_______|_______|_______| \n");
    printf("  |       |       |       | \n");
    printf("  |   8   |   7   |   x   | \n");
    printf("  |_______|_______|_______| \n");
    printf("  |       |       |       | \n");
    printf("  |   9   |   0   |       | \n");
    printf("  |_______|_______|   _   | \n");
    printf("  |       |       |   _   | \n");
    printf("  |   E   |   R   |       | \n");
    printf("  |_______|_______|_______| \n");
}

void leituradosdigitos(){
    numeroum = 0;
    numerodois = 0;
    resultado = 0;
    
    if (primeiravez){
        printf("Digite o Primeiro Numero:");
        scanf("%f", &numeroum);
        if(primeiravez){
            resultado = numeroum;
        }
        imprimircalculadora();
        printf("Oque Voce Deseja Fazer Com Esse Numero?");
        scanf(" %c", sinal);
        sinal[0] = toupper(sinal[0]);
        if (sinal[0] == '='){
            sinaligual();
        } else if(sinal[0] == 'R'){
            raiz();
        } else {
        printf("Digite o Segundo Numero:");
        scanf("%f", &numerodois);
        }
        calculo(&resultado);
        imprimircalculadora();
        primeiravez = false;
    }
    while (sinal[0] != '=') {
        numerodois = 0;
        numeroum = 0;
        printf("Oque Voce Deseja Fazer Com Esse Numero?");
        scanf(" %c", sinal);
        sinal[0] = toupper(sinal[0]);
        if (sinal[0] == '='){
            sinaligual();
        } else if(sinal[0] == 'R'){
            raiz();
        } else {
        printf("Digite o Segundo Numero:\n");
        scanf("%f", &numerodois);
        }
        calculo(&resultado);
        imprimircalculadora();
    }
}

void calculo(float *resultado){
    switch (sinal[0])
    {
    case '+':
        soma();
        break;
    case '-':
        subtracao();
        break;    
    case 'X':
        multiplicacao();
        break;
    case '/':
        divisao();
        break; 
    case 'E':
        elevar();
        break;   
    default:
        break;
    }  
    resultado = resultado;
}

void soma(){
    resultado = resultado + numerodois;
}

void subtracao(){
    resultado = resultado - numerodois;
}

void multiplicacao(){
    resultado = resultado * numerodois;
}

void divisao(){
    resultado = resultado / numerodois;
}

void elevar(){
    if(numerodois < 0) {
        printf("Numero Invalido Tente Denovo\n");
        leituradosdigitos();
    } else if(numerodois == 0) {
        resultado = 1;
    } else{
        numeroum = resultado;
        while (numerodois > 0){
            resultado = resultado * numeroum;
            numerodois--;
        }
        resultado = resultado / numeroum;
    }
}

void raiz(){
    resultado = sqrt(resultado);
}

void sinaligual(){
    igual = true;
    verificacaopfim(&igual);
}

void fimprograma(){
    calculo(&resultado);
    printf("O Resultado Final Do Seu Caluculo e: %.2f\n", resultado);
    printf("Fim Calculadora!\n");
    exit(0);
}

int main() {
    printf("______Calculadora Em C______\n");
    verificacaopfim(&igual);
    imprimircalculadora();
    leituradosdigitos();
    return 0;
}