#include "esfera_utils.h"
#include <stdio.h>

int main()
{
    float raio;
    scanf("%f", &raio);

    printf("Area: %.2f\n", calcula_area(raio));
    printf("Volume: %.2f\n", calcula_volume(raio));

    return 0;

}