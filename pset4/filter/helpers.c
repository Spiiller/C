#include "helpers.h"
#include "bmp.h"
#include <stdio.h>

// Protótipos de funções auxiliares
RGBTRIPLE get_average_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width]);

// Converte uma imagem para tons de cinza
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calcula a média dos valores de vermelho, verde e azul para obter um tom de cinza
            int avg = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;

            // Define os valores de vermelho, verde e azul para a média calculada
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Aplica o filtro sépia à imagem
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calcula os novos valores de vermelho, verde e azul para o efeito sépia
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            // Garante que os valores estejam no intervalo [0, 255]
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
}

// Reflete horizontalmente a imagem
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Troca os pixels da esquerda com os da direita para criar o efeito de reflexão horizontal
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Aplica o filtro blur à imagem
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Cria uma matriz temporária para armazenar os pixels com valores borrados
    RGBTRIPLE temp[height][width];

    // Copia a imagem original para a matriz temporária
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Aplica o filtro blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calcula a média dos pixels circundantes
            RGBTRIPLE average_pixel = get_average_pixel(i, j, height, width, temp);

            // Define os valores de vermelho, verde e azul para a média calculada
            image[i][j] = average_pixel;
        }
    }
}

// Retorna o pixel médio em torno do pixel (i, j)
RGBTRIPLE get_average_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed = 0, sumGreen = 0, sumBlue = 0;
    int count = 0;

    // Percorre os pixels em torno do pixel (i, j)
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ni = i + di;
            int nj = j + dj;

            // Verifica se o pixel (ni, nj) está dentro dos limites da imagem
            if (ni >= 0 && ni < height && nj >= 0 && nj < width)
            {
                sumRed += image[ni][nj].rgbtRed;
                sumGreen += image[ni][nj].rgbtGreen;
                sumBlue += image[ni][nj].rgbtBlue;
                count++;
            }
        }
    }

    // Calcula a média dos valores de vermelho, verde e azul
    RGBTRIPLE average_pixel;
    average_pixel.rgbtRed = round((float) sumRed / count);
    average_pixel.rgbtGreen = round((float) sumGreen / count);
    average_pixel.rgbtBlue = round((float) sumBlue / count);

    return average_pixel;
}
