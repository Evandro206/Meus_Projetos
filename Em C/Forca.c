#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gameLogic();

char *words[] = {"mamão", "uva", "carro", "azul", "teste"}; // Array de palavras
char word[45];                                              // Palavra a ser descoberta
char hiddenWord[45];                                        // Palavra escondida
char usedLetters[45];                                       // Letras usadas
int nLetters, hit, temphit, error;                          // Número de letras, acertos, acertos temporários e erros
char letter;                                                // Letra digitada

void start()
{ // Função de inicio do jogo
    printf("--- Bem vindo ao jogo da forca! ---\n\n");
    printf("Para começar vamos explicar as regras!\n");
    printf("1 - A palavra é aleatória e escolhida dentre um grupo de palavras já definido.\n");
    printf("2 - Cada letra digitada conta como um chute.\n");
    printf("3 - Se for um acerto será exibida a palavra sem as outras letras.\n");
    printf("4 - Se for um erro será exibida a forca.\n");
    printf("5 - Você tem até 6 erros, cuidado.\n\n");
    printf("Boa sorte!\n");
}

char *randomize(char *words[], int nWords)
{                                         // Função para randomizar a palavra a ser descoberta
    srand(time(0));                       // Gera numero aleatório com base no tempo decorrido a partir de 1 de janeiro de 1970
    strcpy(word, words[rand() % nWords]); // Randomiza um numero entre 0 e nWords e atribui a palavra referente a esse numero à variável word
    nLetters = strlen(word);              // Define o número de letras da palavra
    for (int i = 0; i < nLetters; i++)
    {
        hiddenWord[i] = '_'; // Inicializa a palavra escondida com underscores
    }
    hiddenWord[nLetters] = '\0'; // Adiciona o caractere nulo ao final da string para tornar ela valida em C
    return word;
}

void showStrength() 
{                  // Função para exibir a forca e a palavra escondida
    switch (error) // Exibe a forca de acordo com o número de erros
    {
    case 0:
        printf("  __________\n  |        |\n  |        |\n  |\n  |\n  |\n  |\n  |\n _|_    ");
        break;
    case 1:
        printf("  __________\n  |        |\n  |        |\n  |        O\n  |\n  |\n  |\n  |\n _|_    ");
        break;
    case 2:
        printf("  __________\n  |        |\n  |        |\n  |        O\n  |        |\n  |\n  |\n  |\n _|_    ");
        break;
    case 3:
        printf("  __________\n  |        |\n  |        |\n  |        O\n  |       /|\n  |\n  |\n  |\n _|_    ");
        break;
    case 4:
        printf("  __________\n  |        |\n  |        |\n  |        O\n  |       /|\\\n  |\n  |\n  |\n _|_    ");
        break;
    case 5:
        printf("  __________\n  |        |\n  |        |\n  |        O\n  |       /|\\\n  |       /\n  |\n  |\n _|_    ");
        break;
    default:
        break;
    }
    for (int i = 0; i < nLetters; i++)
    {
        printf("%c ", hiddenWord[i]); // Exibe a palavra escondida
    }
    printf("\n\n");
    gameLogic();
}

void gameLogic() // Função para a lógica do jogo
{
    temphit = 0;
    printf("Digite uma letra: ");
    scanf(" %c", &letter);

    if (strchr(usedLetters, letter)) // Verifica se a letra já foi usada
    {
        printf("Você já usou essa letra!\n");
    }
    else
    {
        strcat(usedLetters, (char[]){letter, '\0'}); // Adiciona a letra usada ao array de letras usadas
        for (int i = 0; i < nLetters; i++)
        {
            if (word[i] == letter) // Verifica se a letra digitada está na palavra
            {
                hiddenWord[i] = letter;
                hit++;
                temphit++;
                if (hit == nLetters) // Verifica se todas as letras foram acertadas
                {
                    printf("Parabéns! Você acertou a palavra: %s\n", word);
                    abort();
                }
            }
        }
        if (temphit == 0) // Verifica se a letra digitada não está na palavra
        {
            error++;
            printf("Número de erros: %d\n", error);
            if (error == 6) // Verifica se o número de erros é igual a 6
            {
                printf("  __________\n  |        |\n  |        |\n  |        O\n  |       /|\\\n  |       / \\\n  |\n  |\n _|_    ");
                printf("Você perdeu! A palavra era: %s\n", word);
                abort();
            }
        }
    }
    showStrength();
}

int main()
{
    hit = 0;
    error = 0;
    start();
    int nWords = sizeof(words) / sizeof(words[0]); // Calcula o número total de palavras dentro do array
    randomize(words, nWords);                      // Randomiza a palavra a ser descoberta
    showStrength();                                // Exibe a forca e a palavra escondida
    return 0;
}