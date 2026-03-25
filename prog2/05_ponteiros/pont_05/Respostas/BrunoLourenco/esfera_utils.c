#include "esfera_utils.h"
#include <stdio.h>

void CalculaVolume (float R, float *volume)
{
    *volume = (4*PI*R*R*R)/3;
}

void CalculaArea (float R, float *area)
{
    *area = 4*PI*R*R;
}
