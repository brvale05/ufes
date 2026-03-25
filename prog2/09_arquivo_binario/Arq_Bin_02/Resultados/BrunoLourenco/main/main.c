#include "base_alunos.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caminho[100];

    scanf("%[^\n]", caminho);

    tBaseAlunos *base = CriarBaseAlunos();
    LerBaseAlunos(base, caminho);
    
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;
}