
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "tecnico.h"

struct Tecnico
{
    Ator *ator;
    char area[MAX_TAM_AREA];
    int disponibilidade;
    float salario;
    int tempoTrabalhado;
};

Tecnico *criaTecnico(Ator *ator, char *area, int disponibilidade, float salario)
{
    Tecnico *t = (Tecnico *)malloc(sizeof(Tecnico));

    t->ator = ator;
    strcpy(t->area, area);
    t->disponibilidade = disponibilidade;
    t->salario = salario;
    t->tempoTrabalhado = 0;

    return t;
}

Tecnico *leTecnico()
{
    Ator *a = leAtor();
    char area[MAX_TAM_AREA];
    int disponibilidade;
    float salario;

    scanf("%[^\n]", area);
    scanf("%*c");

    scanf("%d\n", &disponibilidade);
    scanf("%f\n", &salario);

    Tecnico *t = criaTecnico(a, area, disponibilidade, salario);

    return t;
}

void imprimeTecnico(void *t)
{
    Tecnico *tec = (Tecnico *)t;

    imprimeAtor(tec->ator);

    printf("- Area de Atuacao: %s\n" , tec->area);
    printf("- Salario: %.2f\n", tec->salario);
    printf("- Disponibilidade: %dh\n", tec->disponibilidade);
    printf("- Tempo Trabalhado: %dh\n", tec->tempoTrabalhado);
    
}

void desalocaTecnico(void *t)
{
    if (t)
    {
        Tecnico *tec = (Tecnico *)t;
        if (tec->ator)
        {
            desalocaAtor(tec->ator);
        }
        free(t);
    }
    t = NULL;
}

int EhMesmoTecnico(Tecnico *t1, Tecnico *t2)
{
    return EhMesmoAtor(t1->ator, t2->ator);
}

int getTempoTrabalhado(Tecnico *t)
{
    return t->tempoTrabalhado;
}

int getDisponibilidade(Tecnico *t)
{
    return t->disponibilidade;
}

int CalculaIdadeTec(Tecnico *t, Data *dtRef)
{
    return CalculaIdadeAtor(t->ator, dtRef);
}

char *getAreaAtuacao(Tecnico *t)
{
    return t->area;
}

char *getNomeTecnico(Tecnico *t)
{
    return getNomeAtor(t->ator);
}

void AlteraHorasTecnico(Tecnico *t, int horas)
{
    t->disponibilidade -= horas;
    t->tempoTrabalhado += horas;
}

// Função que vai ser usada no qsort
int comparaTecnicos(const void *t1, const void *t2)
{
    if ((*(Tecnico **)t1)->tempoTrabalhado > (*(Tecnico **)t2)->tempoTrabalhado)
    {
        return -1;
    }
    else if ((*(Tecnico **)t1)->tempoTrabalhado < (*(Tecnico **)t2)->tempoTrabalhado)
    {
        return 1;
    }
    else
    {
        return strcmp(getNomeTecnico((*(Tecnico **)t1)), getNomeTecnico((*(Tecnico **)t2)));
    }
}

Tecnico *CopiaTecnicos(Tecnico *t1, Tecnico *t2)
{
    t1 = malloc(sizeof(Tecnico));

    t1->ator = CopiaAtor(t1->ator, t2->ator);

    strcpy(t1->area, t2->area);
    t1->disponibilidade = t2->disponibilidade;
    t1->salario = t2->salario;
    t1->tempoTrabalhado = 0;

    return t1;
}

void CopiaHorasTrabalhadas(Tecnico *t1, Tecnico *t2)
{
    t1->tempoTrabalhado = t2->tempoTrabalhado;
    t1->disponibilidade = t2->disponibilidade;
}