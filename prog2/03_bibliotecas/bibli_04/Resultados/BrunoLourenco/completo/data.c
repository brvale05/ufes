#include <stdio.h>
#include "data.h"

int verificaDataValida(int dia, int mes, int ano)
{
    if(dia > numeroDiasMes(mes, ano))
    {
        return 0;
    }
    return 1;
}

void imprimeMesExtenso(int mes)
{
    if(mes == 1)
    {
        printf("Janeiro");
    }
    if(mes == 2)
    {
        printf("Fevereiro");
    }
    if(mes == 3)
    {
        printf("Marco");
    }
    if(mes == 4)
    {
        printf("Abril");
    }
    if(mes == 5)
    {
        printf("Maio");
    }
    if(mes == 6)
    {
        printf("Junho");
    }
    if(mes == 7)
    {
        printf("Julho");
    }
    if(mes == 8)
    {
        printf("Agosto");
    }
    if(mes == 9)
    {
        printf("Setembro");
    }
    if(mes == 10)
    {
        printf("Outubro");
    }
    if(mes == 11)
    {
        printf("Novembro");
    }
    if(mes == 12)
    {
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano)
{
    if(ano % 400 < 1)
    {
        return 1;
    }
    else 
    if(ano % 4 < 1)
    {
        if(ano % 100 < 1)
        {
            if(ano % 400 < 1)
            {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano)
{
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        return 31;
    }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    if(mes == 2 && verificaBissexto(ano) > 0)
    {
        return 29;
    }
    return 28;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if(ano1 > ano2)
    {
        return 1;
    }
    else
    if(ano2 > ano1)
    {
        return -1;
    }
    else
    if(ano1 == ano2)
    {
        if(mes1 > mes2)
        {
            return 1;
        }
        else
        if(mes2 > mes1)
        {
            return -1;
        }
        else
        if(mes1 == mes2)
        {
            if(dia1 > dia2)
            {
                return 1;
            }
            else
            if(dia2 > dia1)
            {
                return -1;
            }
            return 0;
        }
    }
}

int calculaDiasAteMes(int mes, int ano)
{
    int i, soma = 0;
    for(i = 1; i < mes; i++)
    {
        soma = soma + numeroDiasMes(i, ano);
    }
    return soma;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int i, qtd_dias = 0;
    if(ano1 != ano2)
    {
        if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) > 0)
        {
            for(i = ano2; i < ano1; i++)
            {
                if(verificaBissexto(i) > 0)
                {
                    qtd_dias = qtd_dias + 366;
                }
                else
                {
                    qtd_dias = qtd_dias + 365; 
                }
        }
            qtd_dias = (qtd_dias - calculaDiasAteMes(mes2, ano2)) - dia2;
            qtd_dias = qtd_dias + calculaDiasAteMes(mes1, ano1) + dia1;
        }
        else
        if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) < 0)
        {
            for(i = ano1; i < ano2; i++)
            {
                if(verificaBissexto(i) > 0)
                {
                    qtd_dias = qtd_dias + 366;
                }
                else
                {   
                    qtd_dias = qtd_dias + 365; 
                }
        }
            qtd_dias = (qtd_dias - calculaDiasAteMes(mes1, ano1)) - dia1;
            qtd_dias = qtd_dias + calculaDiasAteMes(mes2, ano2) + dia2;      
        }
        return qtd_dias;
    }

    if(ano1 == ano2)
    {
        if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) > 0)
        {
            qtd_dias = calculaDiasAteMes(mes1, ano1) + dia1;
            qtd_dias = qtd_dias - calculaDiasAteMes(mes2, ano2) - dia2;
        } 
        else
        if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) < 0)
        {
            qtd_dias = calculaDiasAteMes(mes2, ano2) + dia2;
            qtd_dias = qtd_dias - calculaDiasAteMes(mes1, ano1) - dia1;
        }
        return qtd_dias;
    }

    return qtd_dias;

}

void imprimeProximaData(int dia, int mes, int ano)
{
    dia++;

    if(dia > numeroDiasMes(mes, ano))
    {
        dia = 1;
        mes++;
        if(mes > 12)
        {
            mes = 1;
            ano++;
        }
    }

    printf("%02d/%02d/%d", dia, mes, ano);

}