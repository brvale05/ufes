#include <stdio.h>
#include "ponto.h"



int main()
{
    float xA, yA, xB, yB;

    scanf("%f %f %f %f", &xA, &yA, &xB, &yB);

    Ponto p1, p2;

    p1 = pto_atribui_x(p1, xA); p1 = pto_atribui_y(p1, yA);
    p2 = pto_atribui_x(p2, xB); p2 = pto_atribui_y(p2, yB);

    printf("%g\n", pto_distancia(p1, p2));

    return 0;

}