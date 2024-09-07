#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int inicial_population, final_population;

    // Solicitar o tamanho inicial da população ao usuário
    do
    {
        printf("Tamanho inicial: ");
        scanf("%d", &inicial_population);

        if (inicial_population < 9)
        {
            printf("Por favor, insira um tamanho igual ou maior que 9.\n");
        }

    } while (inicial_population < 9);

    // Solicitar o tamanho final da população ao usuário
    do
    {
        printf("População Final: ");
        scanf("%d", &final_population);

        if (final_population < inicial_population)
        {
            printf("O tamanho final deve ser maior ou igual ao tamanho inicial.\n");
        }

    } while (final_population < inicial_population);

    // Calcular o número de anos necessários para atingir o tamanho final
    int anos = 0;
    while (inicial_population < final_population)
    {
        inicial_population = inicial_population + inicial_population / 3 - inicial_population / 4;
        anos++;
    }

    // Imprimir o número de anos necessários
    printf("Anos: %d\n", anos);

    return 0;
}
