#include <stdio.h>
#include <math.h>
#include "ponto.h"


Ponto pto_cria (float x, float y)
{
    Ponto ponto;

    ponto.x = x; ponto.y = y;

    return ponto;

}

float pto_acessa_x (Ponto p)
{
    return p.x;
}

float pto_acessa_y (Ponto p)
{
    return p.y;
}

Ponto pto_atribui_x (Ponto p, float x)
{
    p.x = x;
    return p;
}

Ponto pto_atribui_y (Ponto p, float y)
{
    p.y = y;
    return p;
}

float pto_distancia (Ponto p1, Ponto p2)
{
    float dist_x = (pto_acessa_x(p1) - pto_acessa_x(p2))*(pto_acessa_x(p1) - pto_acessa_x(p2));
    float dist_y = (pto_acessa_y(p1) - pto_acessa_y(p2))*(pto_acessa_y(p1) - pto_acessa_y(p2));

    return sqrt(dist_x + dist_y);
}