#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Solicita ao usuário um número de cartão de crédito
    long card_number;
    do
    {
        card_number = get_long("Número: ");
    }
    while (card_number <= 0);

    // Verifica a validade do número do cartão e identifica a bandeira
    int sum = 0;
    int digit_count = 0;
    long temp_number = card_number;

    while (temp_number > 0)
    {
        int digit = temp_number % 10;

        if (digit_count % 2 == 1)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;
        temp_number /= 10;
        digit_count++;
    }

    if (sum % 10 == 0)
    {
        // Identifica a bandeira do cartão
        if ((card_number >= 34e13 && card_number < 35e13) || (card_number >= 37e13 && card_number < 38e13))
        {
            printf("AMEX\n");
        }
        else if (card_number >= 51e14 && card_number < 56e14)
        {
            printf("MASTERCARD\n");
        }
        else if ((card_number >= 4e12 && card_number < 5e12) || (card_number >= 4e15 && card_number < 5e15))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
