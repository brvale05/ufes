#include <stdio.h>
#include "tDepartamento.h"

int main()
{
    int numDepart;
    scanf("%d", &numDepart);
    scanf("%*[^\n]");
    scanf("%*c");

    tDepartamento departamentos[numDepart];

    int d = 0;
    while(d < numDepart)
    {
        char nome[STRING_MAX];
        scanf("%[^\n]", nome);
        scanf("%*c");

        char diretor[STRING_MAX];
        scanf("%[^\n]", diretor);
        scanf("%*c");

        char curso1[STRING_MAX];
        scanf("%[^\n]", curso1);
        scanf("%*c");

        char curso2[STRING_MAX];
        scanf("%[^\n]", curso2);
        scanf("%*c");

        char curso3[STRING_MAX];
        scanf("%[^\n]", curso3);
        scanf("%*c");

        int n1, n2, n3;
        scanf("%d %d %d", &n1, &n2, &n3);
        scanf("%*[^\n]");
        scanf("%*c");


        if(n1 < 0 || n2 < 0 || n3 < 0)
        {
            printf("\nDigite um departamento com médias válidas");
        }
        else
        {
            departamentos[d] = CriaDepartamento(curso1, curso2, curso3, nome, n1, n2, n3, diretor);
            d++;
        }
    }

    OrdenaDepartamentosPorMedia(departamentos, numDepart);

    for(d = 0; d < numDepart; d++)
    {
        ImprimeAtributosDepartamento(departamentos[d]);
        if(d == numDepart-1) printf("\n");
    }

    return 0;

}