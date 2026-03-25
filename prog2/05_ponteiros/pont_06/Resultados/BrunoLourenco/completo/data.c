#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data)
{
    data->dia = dia;
    data->mes = mes;
    data->ano = ano; 

    if(dia > InformaQtdDiasNoMes(data))
    {
        data->dia = InformaQtdDiasNoMes(data);
    }

    if(mes > 12)
    {
        data->mes = 12;
    }
}

void LeData( tData *data )
{
    int dia, mes, ano;

    scanf("%d %d %d", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData( tData *data )
{
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data )
{
    if(data->ano%100 < 1)
    {
        if(data->ano%400 < 1)
        {
            return 1;
        }
        
        return 0;

    }

    if(data->ano%4 < 1)
    {
        return 1;
    }

    return 0;

}

int InformaQtdDiasNoMes( tData *data )
{
    if(data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
    {
        return 31;
    }

    if(data->mes == 2)
    {
        if(EhBissexto(data))
        {
            return 29;
        }

        return 28;
    }

    return 30;

}

void AvancaParaDiaSeguinte( tData *data )
{
    if(data->dia == InformaQtdDiasNoMes(data))
    {
        data->dia = 1;
        
        if(data->mes == 12)
        {
            data->mes = 1;
            data->ano++;
        }
        else
        {
            data->mes++;
        }
    }
    else
    {
        data->dia++;
    }
}

int EhIgual( tData *data1, tData *data2 )
{
    if(data1->dia != data2->dia)
    return 0;

    if(data1->mes != data2->mes)
    return 0;

    if(data1->ano != data2->ano)
    return 0;

    return 1;
}