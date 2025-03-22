#include <iostream> // Biblioteca padrão
#include <iomanip> // Biblioteca para usar setw(23)
#include <cmath> // Biblioteca para o funcionamento de sqrt(resultado)

// Namespace usado para remover o std antes de alguns códigos
using namespace std;

// Iniciar variaveis antes das funções para tornar elas globais
bool primeiravez = true, igual = false;
float resultado = 0, numeroum = 0, numerodois = 0;
char sinal[2];

// Iniciar todas as funções para manter coerencia no código
void calculo(float *resultado);
void fimprograma();
void sinaligual();
void soma();
void subtracao();
void multiplicacao();
void divisao();
void elevar();
void raiz();

// Função para verificar se o programa deve ser finalizado
void verificacaopfim(bool *igual){
    if (*igual){
        fimprograma();
    }
}

// Função apenas para meio ilustrativo da calculadora
void imprimircalculadora(){
    cout <<"   _______________________ "<< endl;
    cout <<"  |                       | "<< endl;
    // Linha resposável para exibir o numero atual e deixar um espaço para a exibição da calculadora não ficar torta
    cout << fixed << setprecision(2) << "  |" << setw(23) << resultado << "|" << endl; 
    cout <<"   _______________________ "<< endl;
    cout <<"  |_______________________| "<< endl;
    cout <<"  |       |       |       | "<< endl;
    cout <<"  |   1   |   2   |   +   | "<< endl;
    cout <<"  |_______|_______|_______| "<< endl;
    cout <<"  |       |       |       | "<< endl;
    cout <<"  |   3   |   4   |   -   | "<< endl;
    cout <<"  |_______|_______|_______| "<< endl;
    cout <<"  |       |       |       | "<< endl;
    cout <<"  |   5   |   6   |   /   | "<< endl;
    cout <<"  |_______|_______|_______| "<< endl;
    cout <<"  |       |       |       | "<< endl;
    cout <<"  |   8   |   7   |   x   | "<< endl;
    cout <<"  |_______|_______|_______| "<< endl;
    cout <<"  |       |       |       | "<< endl;
    cout <<"  |   9   |   0   |       | "<< endl;
    cout <<"  |_______|_______|   _   | "<< endl;
    cout <<"  |       |       |   _   | "<< endl;
    cout <<"  |   E   |   R   |       | "<< endl;
    cout <<"  |_______|_______|_______| "<< endl;
}

// Função responsavel por receber a entrada(numeros e operador) do usuário
void leituradosdigitos(){
    numeroum = 0;
    numerodois = 0;
    resultado = 0;
    
    // If para verificar se é a primeira vez que o programa roda, unica e exclusivamente para exibir a menssagem digite o primeiro numero
    if (primeiravez){ 
        cout <<"Digite o Primeiro Numero:"<< endl;
        cin >> numeroum;
        if(primeiravez){
            resultado = numeroum;
        }
        imprimircalculadora();
        cout <<"Oque Voce Deseja Fazer Com Esse Numero?"<< endl;
        cin >> sinal;
        sinal[0] = toupper(sinal[0]); // Transformar letra minúscula em maiúscula
        if (sinal[0] == '='){
            sinaligual();
        } else if(sinal[0] == 'R'){
            raiz();
        } else {
        cout <<"Digite o Segundo Numero:"<< endl;
        cin >> numerodois;
        }
        calculo(&resultado);
        imprimircalculadora();
        primeiravez = false;
    }

    // Loop para execução do resto do programa 
    while (sinal[0] != '=') {
        numerodois = 0;
        numeroum = 0;
        cout <<"Oque Voce Deseja Fazer Com Esse Numero?"<< endl;
        cin >> sinal;
        sinal[0] = toupper(sinal[0]); // Transformar letra minúscula em maiúscula
        if (sinal[0] == '='){
            sinaligual();
        } else if(sinal[0] == 'R'){
            raiz();
        } else {
        cout <<"Digite o Segundo Numero:"<< endl;
        cin >> numerodois;
        }
        calculo(&resultado);
        imprimircalculadora();
    }
}

// Função responsável por direcionar o programa para a conta definida pelo usuario com o operador
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
}

// Função para realizar soma
void soma(){
    resultado = resultado + numerodois;
}

// Função para realizar subtrção
void subtracao(){
    resultado = resultado - numerodois;
}

// Função para realizar multiplicação
void multiplicacao(){
    resultado = resultado * numerodois;
}

// Função para realizar divisão
void divisao(){
    resultado = resultado / numerodois;
}

// Função para realizar elevar o numero a um certo espoente definido pelo usuário
void elevar(){
    if(numerodois < 0) {
        cout <<"Numero Invalido Tente Denovo"<< endl;
        leituradosdigitos();
    } else if(numerodois == 0) {
        resultado = 1;
    } else{
        numeroum = resultado;
        while (numerodois > 1){
            resultado = resultado * numeroum;
            numerodois--;
        }
    }
}

// Função para realizar a raiz quadrada do numero atual
void raiz(){
    resultado = sqrt(resultado);
}

// Função responsável verificar se o usuário quer saber o resultado final da conta
void sinaligual(){
    igual = true;
    verificacaopfim(&igual);
}

// Função para exibir ultima parte do programa(resultado e menssagem final)
void fimprograma(){
    calculo(&resultado);
    cout << fixed << setprecision(2) <<"O Resultado Final Do Seu Caluculo e: "<< resultado << endl;
    cout <<"Fim Calculadora!"<< endl;
    exit(0);
}

// Main está sendo usado apenas para exibir uma menssagem inicial e puxar e funções do programa
int main() {
    cout <<"______Calculadora Em C______"<< endl;
    verificacaopfim(&igual);
    imprimircalculadora();
    leituradosdigitos();
    return 0;
}