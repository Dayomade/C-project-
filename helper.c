#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round(.393 * originalRed + .769 *originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 *originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 *originalGreen + .131 * originalBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 :sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 :sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 :sepiaBlue;

        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
         for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            float count = 0.0;

            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int neighborRow = i + r;
                    int neighborCol = j + c;

                   if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width )
                   {
                    sumRed += temp[neighborRow][neighborCol].rgbtRed;
                    sumGreen += temp[neighborRow][neighborCol].rgbtGreen;
                    sumBlue += temp[neighborRow][neighborCol].rgbtBlue;
                    count++;
                   }

                }
            }
            image[i][j].rgbtRed = round(sumRed / count);
            image[i][j].rgbtGreen = round(sumGreen / count);
            image[i][j].rgbtBlue = round(sumBlue / count);
        }
    }
}
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {
        { -1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
       
    };

    int Gy[3][3] = {
        { -1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for (int i = 0; i < height; i++)
    {
         for (int j = 0; j < width; j++)
         {
            int Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            int Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            for (int r = -1; r<= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int neighborRow = i + r;
                    int neighborCol = j + c;

                    if ( neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width)
                    {
                        int weightX = Gx[r + 1][c + 1];
                        int weightY = Gy[r + 1][c + 1];

                        Gx_red  += temp[neighborRow][neighborCol].rgbtRed * weightX;
                        Gx_green  += temp[neighborRow][neighborCol].rgbtGreen * weightX;
                        Gx_blue  += temp[neighborRow][neighborCol].rgbtBlue * weightX;

                        Gy_red  += temp[neighborRow][neighborCol].rgbtRed * w