#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"

struct Data
{
    int dia;
    int mes;
    int ano;
};


Data *CriaData(int dia, int mes, int ano)
{
    Data *d = malloc(sizeof(Data));

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void LiberaData(Data *data)
{
    if (data != NULL)
    {
        free(data);
        data = NULL;
    }
}

void ImprimeData(Data *data)
{
    printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
}

int CalculaDiffAnos(Data *inicio, Data *fim)
{
    if (fim->mes > inicio->mes)
    {
        return (fim->ano - inicio->ano);
    }

    if (fim->mes == inicio->mes)
    {
        if (fim->dia > inicio->dia)
        {
            return (fim->ano - inicio->ano);
        }
    }

    return (fim->ano - inicio->ano) - 1;
}

Data *CopiaData(Data *d1, Data *d2)
{
    d1 = malloc(sizeof(Data));

    d1->ano = d2->ano;
    d1->mes = d2->mes;
    d1->dia = d2->dia;

    return d1;
}