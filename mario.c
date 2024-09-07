#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    // largura
    do
    {
        n = get_int("width: ");
    }
    while (n < 1);

    // Loop para cada linha
    for (int i = 0; i < n; i++)
    {
        // espaços à esquerda
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        //  '#' para cada coluna
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // nova linha após cada linha
        printf("\n");
    }

    return 0;
}
