#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    // Solicitaraltura
    do
    {
        n = get_int("Altura: ");
    }
    while (n < 1);

    // Loop para cada linha
    for (int i = 0; i < n; i++)
    {
        //  espaços à esquerda
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // caracteres '#' para a parte esquerda
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        //  espaços entre as partes
        printf("  ");

        // caracteres '#' para a parte direita
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        //  uma nova linha após cada linha
        printf("\n");
    }

    return 0;
}
