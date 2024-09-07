#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 44

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Open output file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        printf("Could not create file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Read and write header
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input_file);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output_file);

    // Read factor
    float factor = atof(argv[3]);

    // Read samples from input file, scale, and write to output file
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input_file) == 1)
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
