#include <iostream>
#include <cstring>
#include <cctype>

#define TAM 100
char str[TAM];

// Namespace usado para remover o std antes de alguns códigos
using namespace std;

void inverterString(char str[TAM]) { // Função responsável por inverter a String
    char a;
    int i = strlen(str) - 1; // Define i
    int j = 0; // Define j

    while (j < i) { // Loop para inverter toda a String
        a = str[j];
        str[j] = str[i];
        str[i] = a;
        j++;
        i--;
    }
}

bool funcaoPalindromo(char str[TAM]) { // Função para verificar se a palavra é palíndroma
    unsigned int cont;
    char str2[TAM];

    int i = strlen(str) - 1; // Reseta i
    cont = 0; // Define cont

    strcpy(str2, str); // Copia a str para str2
    inverterString(str); // Chamar a função

    while (i >= 0) { // Loop que verifica se as letras batem
        if (str[i] == str2[i]) {
            cont++;
        }
        i--;
    }
    return cont == strlen(str); // Verifica se a função retorna verdadeiro ou falso
}

int main() {
    do {
        cout << "Digite uma palavra de até " << TAM << " letras:\n"; // Solicitar a palavra a ser invertida
        cin.getline(str, TAM);

        if (strlen(str) > (TAM - 1)) { // Verificação se o número de letras está correto
            cout << "A palavra deve ter no máximo " << TAM << " letras!\n";
        }
        if (funcaoPalindromo(str)) { // Chama função e exibe o resultado
            cout << "A palavra é palíndroma\n";
        } else {
            cout << "A palavra não é palíndroma\n";
        }
    } while (strlen(str) > (TAM - 1));
    return 0;
}
