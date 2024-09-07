#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verifica se o número de argumentos é correto
    if (argc != 2)
    {
        printf("Use: ./caesar key\n");
        return 1;
    }

    // Verifica se todos os caracteres do argumento são dígitos
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Use: ./caesar key\n");
            return 1;
        }
    }

    // Converte a string do argumento para um inteiro
    int k = atoi(argv[1]);

    // Solicita ao usuário um texto simples
    string plaintext = get_string("plaintext: ");

    // Criptografa o texto simples
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            printf("%c", (c - base + k) % 26 + base);
        }
        else
        {
            printf("%c", c);
        }
    }

    // Imprime uma nova linha e retorna 0
    printf("\n");
    return 0;
}
