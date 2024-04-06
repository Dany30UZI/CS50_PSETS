#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];
    int count = 0;
    FILE *output_file = NULL;

    while (fread(buffer, 1, 512, input_file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                fclose(input_file);
                fprintf(stderr, "Could not create output file %s.\n", filename);
                return 1;
            }

            count++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, 1, 512, output_file);
        }
    }

    fclose(input_file);
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    return 0;
}
