#include <stdio.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void mapCharacter(unsigned char pixel)
{
    static const char shades[] =
        "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?"
        "-_+~<>i!lI;:\",^`'.";
    const int n_shades = (int)(sizeof shades - 1);   /* 70 */
    int idx = (pixel * (n_shades - 1)) / 255; 
    putchar(shades[idx]);
}



int main() {
    int x,y,n;
    unsigned char *data = stbi_load("bruh.jpg", &x, &y, &n, 1);
    // printf("%d, %d, %d\n", x, y, n);

    unsigned char image[y][x];

    for (int i = 0 ; i < y ; i++) {
        for (int j = 0 ; j < x ; j++) {
            image[i][j] = data[i * x  + j];
        }
    }

    for (int i = 0 ; i < y ; i++) {
        for (int j = 0 ; j < x ; j++) {
            mapCharacter(image[i][j]);
        }
        printf("\n");
    }
    
}