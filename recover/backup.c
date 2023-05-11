#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }
    // open input file passed by command-line argument
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = NULL;
    BYTE buffer[512];
    int jpeg = 0;

    if (inputFile == NULL)
    {
        printf("Could not open the file\n");
        return 2;
    }

    char filename[8];

    while (fread(buffer, sizeof(BYTE) * 512, 1, inputFile) == 1)
    {

        // check if is found
        // if(buffer[0]==0xFF&&buffer[1]==0xD8&&buffer[2]==0xFF&&(buffer[3]&0xF0)==0xE0)
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            if (outputFile != NULL)
            {
                fclose(outputFile);
            }
            sprintf(filename, "%03d.jpg", jpeg++);

            outputFile = fopen(filename, "w");
        }
        if (outputFile != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, outputFile);
        }
    }
    if (outputFile != NULL)
    {
        fclose(outputFile);
    }

    fclose(inputFile);
    return 0;
}
