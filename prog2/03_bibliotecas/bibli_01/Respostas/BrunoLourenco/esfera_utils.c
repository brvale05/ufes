#include "esfera_utils.h"

float calcula_volume (float R)
{
    float area = calcula_area(R);
    return (area*R)/3;
}

float calcula_area (float R)
{
    return 4*PI*R*R;
}
