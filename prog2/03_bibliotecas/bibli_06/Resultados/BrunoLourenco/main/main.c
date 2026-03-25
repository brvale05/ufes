#include <stdio.h>
#include "temperature_conversor.h"

int main()
{
    int temp;
    char car1, car2;
    scanf("%d %c %c", &temp, &car1, &car2);

    if(car1 == 'c' && car2 == 'k')
    {
        printf("Temperature: %.2fK", convert_temperature(temp, convert_celsius_to_kelvin));
    }
    else
    if(car1 == 'c' && car2 == 'f')
    {
        printf("Temperature: %.2fFº", convert_temperature(temp, convert_celsius_to_fahrenheit));
    }
    else
    if(car1 == 'k' && car2 == 'c')
    {
        printf("Temperature: %.2fCº", convert_temperature(temp, convert_kelvin_to_celsius));
    }
    else
    if(car1 == 'k' && car2 == 'f')
    {
        printf("Temperature: %.2fFº", convert_temperature(temp, convert_kelvin_to_fahrenheit));
    }
    else
    if(car1 == 'f' && car2 == 'c')
    {
        printf("Temperature: %.2fCº", convert_temperature(temp, convert_fahrenheit_to_celsius));
    }
    else
    if(car1 == 'f' && car2 == 'k')
    {
        printf("Temperature: %.2fK", convert_temperature(temp, convert_fahrenheit_to_kelvin));
    }
    
    return 0;

}