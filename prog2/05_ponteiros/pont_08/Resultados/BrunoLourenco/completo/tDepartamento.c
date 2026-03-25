#include <stdio.h>
#include "tDepartamento.h"
#include <string.h>

tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento departamento;

    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    strcpy(departamento.curso1, curso1);
    strcpy(departamento.curso2, curso2);
    strcpy(departamento.curso3, curso3);

    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;

    return departamento;
}

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    printf("\nDepartamento: %s\n", depto.nome);
    printf("    Diretor: %s\n", depto.diretor);

    printf("    1o curso: %s\n", depto.curso1);
    printf("    Media do 1o curso: %d\n", depto.m1);

    printf("    2o curso: %s\n", depto.curso2);
    printf("    Media do 2o curso: %d\n", depto.m2);

    printf("    3o curso: %s\n", depto.curso3);
    printf("    Media do 3o curso: %d\n", depto.m3);

    float media = (depto.m1 + depto.m2 + depto.m3)/(float)3;

    printf("    Media dos cursos: %.2f\n", media);
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    int i, index;

    float maior;

    for(i = 0; i < num_deptos; i++)
    {
        if(i < 1)
        {
            maior = ((vetor_deptos+i)->m1 + (vetor_deptos+i)->m2 + (vetor_deptos+i)->m3)/3; 
            index = i;
        }
        
        if(((vetor_deptos+i)->m1 + (vetor_deptos+i)->m2 + (vetor_deptos+i)->m3)/3 > maior)
        {
            tDepartamento aux;

            aux = *(vetor_deptos+i);
            *(vetor_deptos+i) = *(vetor_deptos+index);
            *(vetor_deptos+index) = aux;

            maior = ((vetor_deptos+i)->m1 + (vetor_deptos+i)->m2 + (vetor_deptos+i)->m3)/3; 
            index = i;
        }
    }
}