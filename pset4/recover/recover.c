#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Couldn't open file %s\n", argv[1]);
    }
    
    int fileNumber = 0;
    char fileName[9];
    int chunkSize = 512;
    unsigned char buffer[chunkSize];
 
    int bytesRead = chunkSize;
    bool isFirstJpg = true;
    
    while ((bytesRead = fread(buffer, 1, chunkSize, file)) > 0)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (isFirstJpg)
            {
                isFirstJpg = false;
            }
    
            else
            {
                fileNumber++;
            }
            sprintf(fileName, "%03i.jpg", fileNumber);
            FILE *img = fopen(fileName, "w");
            fwrite(buffer, 1, chunkSize, img);
            fclose(img);
        }

        else
        {
            if (!isFirstJpg)
            {
                FILE *img = fopen(fileName, "a");
                fwrite(buffer, 1, chunkSize, img);
                fclose(img);
            }
        }
    }
}
