#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Função para verificar se a chave de substituição é válida
bool is_valid_key(string key);

// Função para criptografar o texto simples usando a chave de substituição
void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Verifica se o número de argumentos é correto
    if (argc != 2)
    {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    // Verifica se a chave é válida
    if (!is_valid_key(argv[1]))
    {
        printf("A chave deve conter 26 caracteres alfabéticos únicos.\n");
        return 1;
    }

    // Solicita ao usuário um texto simples
    string plaintext = get_string("Texto simples: ");

    // Criptografa o texto simples usando a chave de substituição
    encrypt(plaintext, argv[1]);

    return 0;
}

bool is_valid_key(string key)
{
    // Verifica se a chave tem o comprimento correto
    if (strlen(key) != 26)
    {
        return false;
    }

    // Inicializa um array para marcar caracteres já encontrados
    bool found[26] = {false};

    // Verifica cada caractere na chave
    for (int i = 0; i < 26; i++)
    {
        // Verifica se o caractere é uma letra alfabética
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Converte o caractere para maiúsculas
        key[i] = toupper(key[i]);

        // Verifica se o caractere já foi encontrado anteriormente
        if (found[key[i] - 'A'])
        {
            return false;
        }

        // Marca o caractere como encontrado
        found[key[i] - 'A'] = true;
    }

    return true;
}

void encrypt(string plaintext, string key)
{
    printf("Texto cifrado: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Verifica se o caractere é alfabético
        if (isalpha(c))
        {
            // Converte o caractere para maiúsculas
            c = toupper(c);

            // Encontra a posição da letra na chave original
            int index = c - 'A';

            // Imprime a letra correspondente na chave de substituição
            printf("%c", islower(plaintext[i]) ? tolower(key[index]) : key[index]);
        }
        else
        {
            // Imprime caracteres não alfabéticos inalterados
            printf("%c", c);
        }
    }

    printf("\n");
}
