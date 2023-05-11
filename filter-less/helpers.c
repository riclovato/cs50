#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // black
            float rgbtGray = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.00);
            image[i][j].rgbtRed = rgbtGray;
            image[i][j].rgbtBlue = rgbtGray;
            image[i][j].rgbtGreen = rgbtGray;
        }
    }
    return;
}
int checkSepia(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }

    return RGB;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // black
            // float SepiaRed = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            // float SepiaBlue = 0.272 * image[i][j].rbgtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            // float SepiaGreen = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            sepiaRed = checkSepia(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            sepiaBlue = checkSepia(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            sepiaGreen = checkSepia(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    float buffer[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer[0] = image[i][j].rgbtRed;
            buffer[1] = image[i][j].rgbtBlue;
            buffer[2] = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

            image[i][width - j - 1].rgbtRed = buffer[0];
            image[i][width - j - 1].rgbtBlue = buffer[1];
            image[i][width - j - 1].rgbtGreen = buffer[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum[] = {0, 0, 0};
            float counter = 0;
            for (int k = i - 1; k < (i + 2); k++)
            {
                for (int m = j - 1; m < (j + 2); m++)
                {
                    if (k < 0 || m < 0 || k >= height || m >= width)
                    {
                        continue;
                    }
                    sum[0] = sum[0] + copy[k][m].rgbtRed;
                    sum[1] = sum[1] + copy[k][m].rgbtBlue;
                    sum[2] = sum[2] + copy[k][m].rgbtGreen;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(sum[0] / counter);
            image[i][j].rgbtBlue = round(sum[1] / counter);
            image[i][j].rgbtGreen = round(sum[2] / counter);
        }
    }
    return;
}
