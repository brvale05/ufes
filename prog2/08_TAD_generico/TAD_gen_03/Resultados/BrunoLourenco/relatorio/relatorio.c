#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

float GetQtdAprovados(Vector *alunos)
{
    int i;
    float soma = 0;
    for (i = 0; i < VectorSize(alunos); i++)
    {
        if (GetNotaAluno(VectorGet(alunos, i)) >= 6)
        {
            soma++;
        }
    }

    return soma;
}

float CalculaMedia(Vector *alunos)
{
    int i;
    float soma = 0;
    for (i = 0; i < VectorSize(alunos); i++)
    {
        soma = soma + GetNotaAluno(VectorGet(alunos, i));
    }

    return (soma / VectorSize(alunos));
}

float PorcentagemAprovados(Vector *alunos)
{
    return (GetQtdAprovados(alunos) / VectorSize(alunos)) * 100;
}

float GetQtdMasc(Vector *alunos)
{
    int i, total = 0;
    for (i = 0; i < VectorSize(alunos); i++)
    {
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'M')
        {

            total++;
        }
    }
    return total;
}

float GetQtdFem(Vector *alunos)
{
    int i, total = 0;
    for (i = 0; i < VectorSize(alunos); i++)
    {
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'F')
        {

            total++;
        }
    }
    return total;
}

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos)
{
    printf("Media das notas: %.2f\n", CalculaMedia(alunos));

    printf("Porcentagem de alunos aprovados: %.2f", PorcentagemAprovados(alunos));
    printf("%%");
    printf("\n");

    printf("Porcentagem de cada genero:\n");

    printf("Masculino: %.2f", (GetQtdMasc(alunos) / (float)VectorSize(alunos)) * 100);
    printf("%%");
    printf("\n");

    printf("Feminino: %.2f", (GetQtdFem(alunos) / (float)VectorSize(alunos)) * 100);
    printf("%%");
    printf("\n");

    printf("Outro: %.2f", ((VectorSize(alunos) - GetQtdMasc(alunos) - GetQtdFem(alunos))/(float)VectorSize(alunos))*100);
    printf("%%");
    printf("\n");
}