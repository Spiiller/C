#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENERATIONS 3

// Define a struct for a person
typedef struct person {
    struct person *parents[2]; // Array of pointers to parents
    char alleles[2]; // Array of alleles
} person;

// Function to generate a random allele (A, B, or O)
char random_allele() {
    int r = rand() % 3;
    if (r == 0)
        return 'A';
    else if (r == 1)
        return 'B';
    else
        return 'O';
}

// Function to create a family with a specified number of generations
person *create_family(int generations) {
    person *new_person = malloc(sizeof(person)); // Allocate memory for a new person

    if (generations > 1) {
        // If there are more generations, recursively create parents
        new_person->parents[0] = create_family(generations - 1);
        new_person->parents[1] = create_family(generations - 1);

        // Assign alleles randomly from parents
        new_person->alleles[0] = new_person->parents[0]->alleles[rand() % 2];
        new_person->alleles[1] = new_person->parents[1]->alleles[rand() % 2];
    } else {
        // If it's the last generation, assign random alleles and set parents to NULL
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;
    }

    return new_person;
}

// Function to free memory recursively for the entire family
void free_family(person *p) {
    if (p == NULL)
        return;

    // Recursively free parents before freeing the child
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free the current person
    free(p);
}

// Function to print the family tree recursively
void print_family(person *p, int generation) {
    if (p == NULL)
        return;

    // Print current person's blood type
    printf("Generation %d, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);

    // Print parents' information recursively
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    person *family = create_family(MAX_GENERATIONS); // Create the family

    print_family(family, 0); // Print the family tree

    free_family(family); // Free allocated memory

    return 0;
}
