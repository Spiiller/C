#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print scores
    printf("Player 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to compute and return score for a string
int compute_score(string word)
{
    int score = 0;

    // Iterate through each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert the character to uppercase
        char c = toupper(word[i]);

        // Check if it is an uppercase letter
        if (isalpha(c))
        {
            // Use ASCII value of 'A' to calculate the index for the POINTS array
            score += POINTS[c - 'A'];
        }
    }

    return score;
}
