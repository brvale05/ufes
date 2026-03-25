#include <stdio.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

int main()
{

    char c;
    char msg[101];
    float n1, n2;
    int prior, numElem;

    printf("Digite o numero de tarefas: ");
    scanf("%d", &numElem);

    tAgendaTarefas *tarefas = CriaAgendaDeTarefas(numElem);

    for (int i = 0; i < numElem; i++)
    {
        scanf("\n%d", &prior);
        scanf(" %c ", &c);
        
        void *tar;
        if (c == 'I')
        {
            scanf("%100[^\n]", msg);
            tar = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(tarefas, prior, tar, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if (c == 'S')
        {
            scanf("%f %f", &n1, &n2);
            tar = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(tarefas, prior, tar, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else if (c == 'M')
        {
            scanf("%f %f", &n1, &n2);
            tar = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(tarefas, prior, tar, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else
        {
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");

            scanf("%100[^\n]", msg);
            i--;
        }
    }

    ExecutarTarefasDaAgenda(tarefas);
    DestroiAgendaDeTarefas(tarefas);

    return 0;
}
