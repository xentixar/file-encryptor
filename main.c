#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptDecrypt(const char* input_file, const char* output_file, const char* key)
{
    FILE *input = fopen(input_file, "rb");
    if(!input)
    {
        perror("Error while reading the file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "wb");
    if(!output)
    {
        perror("Error while opening the output file");
        exit(EXIT_FAILURE);
    }

    size_t key_length = strlen(key);
    int ch;
    size_t i = 0;

    while ((ch = fgetc(input)) != EOF) {
        char encryptedCharacter = ch ^ key[i % key_length];
        fputc(encryptedCharacter, output);
        i++;
    }

    fclose(input);
    fclose(output);
}


int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Usage: encrytor input_file output_file key");
        return 1;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];
    const char* key = argv[3];

    encryptDecrypt(input_file, output_file, key);

    printf("Processed successfully");
    return 0;
}
