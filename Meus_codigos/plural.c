#include <stdio.h>
#include <string.h>
#include <cs50.h>

#define MAX_CANDIDATES 9

typedef struct
{
    const char* name;
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];

int candidate_count;

bool vote(const char* name);
void print_winner(void);

int main(int argc, const char* argv[])
{
    // Check if there are enough command-line arguments
    if (argc < 2)
    {
        printf("Usage: %s candidate1 candidate2 ...\n", argv[0]);
        return 1;
    }

    // Initialize candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get number of voters
    printf("Number of voters: ");
    int voter_count;
    scanf("%d", &voter_count);

    // Get votes from each voter
    for (int i = 0; i < voter_count; i++)
    {
        printf("Vote: ");
        char vote_name[100];  // Adjust the size accordingly
        scanf("%s", vote_name);

        if (!vote(vote_name))
        {
            printf("Invalid vote.\n");
            i--; // Decrement i to re-vote in case of an invalid vote
        }
    }

    // Print the winner(s)
    print_winner();

    return 0;
}

bool vote(const char* name)
{
    // Check if the given name is a valid candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    // Find and print the candidate(s) with the maximum votes
    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
