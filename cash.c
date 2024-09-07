#include <stdio.h>
#include <math.h>

int main(void) {
    // Variável para armazenar o valor em reais
    float reais;

    // Solicita ao usuário a entrada do valor em reais
    printf("Troca devida: ");
    scanf("%f", &reais);

    // Converte o valor para centavos e arredonda para o inteiro mais próximo
    int centavos = round(reais * 100);

    // Definindo os valores das moedas
    int moeda1 = 1;
    int moeda5 = 5;
    int moeda10 = 10;
    int moeda25 = 25;

    // Calcula a quantidade de cada moeda
    int qtd_moeda25 = centavos / moeda25;
    centavos %= moeda25;

    int qtd_moeda10 = centavos / moeda10;
    centavos %= moeda10;

    int qtd_moeda5 = centavos / moeda5;
    centavos %= moeda5;

    int qtd_moeda1 = centavos / moeda1;

    // Exibe o resultado
    printf("Moedas de 25 centavos: %d\n", qtd_moeda25);
    printf("Moedas de 10 centavos: %d\n", qtd_moeda10);
    printf("Moedas de 5 centavos: %d\n", qtd_moeda5);
    printf("Moedas de 1 centavo: %d\n", qtd_moeda1);

    return 0;
}
