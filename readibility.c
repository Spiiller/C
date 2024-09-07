#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Prompt the user for input
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate Coleman-Liau index
    int index = calculate_index(letters, words, sentences);

    // Output the result
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 1; // Start with 1 to account for the first word

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

int calculate_index(int letters, int words, int sentences)
{
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}
