#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ticket.h"
#include "fila.h"

#include "software.h"
#include "outros.h"
#include "manutencao.h"

#include "tecnico.h"
#include "usuario.h"

#include "vector.h"

#define MAX_TAMANHO_ACAO 20
#define MAX_TAM_TIPO 20

void Distribui_Tickets(Vector *v, Fila *f);

int CalculaIdadeMediaTec(Vector *v, Data *dtRef);

int CalculaIdadeMediaUser(Vector *v, Data *dtRef);

int CalculaMediaTempoTrabalhado(Vector *v);

int main(int argc, char **argv)
{
    char car;

    Vector *vecTec = VectorConstruct();
    Vector *vecUser = VectorConstruct();
    Vector *vecRankTec = VectorConstruct();
    Vector *vecRankUser = VectorConstruct();

    Fila *f = criaFila();

    Tecnico *t = NULL;
    Tecnico *tRank = NULL;

    Usuario *uRank = NULL;
    Usuario *u = NULL;
    
    Outros *o = NULL;
    Manutencao *m = NULL;
    Software *s = NULL;

    char cpf[MAX_TAM_CPF];
    char tipoTicket[MAX_TAM_TIPO];
    char acao[MAX_TAMANHO_ACAO];

    int existeCadastro = 0;
    int i;

    Data *dtRef = CriaData(18, 2, 2025);

    while (1)
    {
        existeCadastro = 0;

        scanf("%c", &car);
        scanf("%*[^\n]");
        scanf("%*c");

        if (car == 'F')
            break;

        switch (car)
        {
        case 'T':

            t = leTecnico();

            // Verificando se ja existe cadastro com esse cpf
            for (i = 0; i < VectorSize(vecTec); i++)
            {
                if (EhMesmoTecnico(t, VectorGet(vecTec, i)))
                {
                    desalocaTecnico(t);
                    existeCadastro = 1;
                    break;
                }
            }

            if (!existeCadastro)
            {
                tRank = CopiaTecnicos(tRank, t);
                VectorPushBack(vecTec, t);
                VectorPushBack(vecRankTec, tRank);
            }

            break;

        case 'U':

            u = leUsuario();

            // Verificando se ja existe cadastro com esse cpf
            for (i = 0; i < VectorSize(vecUser); i++)
            {
                if (EhMesmoUsuario(u, VectorGet(vecUser, i)))
                {
                    desalocaUsuario(u);
                    existeCadastro = 1;
                    break;
                }
            }

            if (!existeCadastro)
            {
                uRank = CopiaUsers(uRank, u);
                VectorPushBack(vecUser, u);
                VectorPushBack(vecRankUser, uRank);
            }

            break;

        case 'A':

            scanf("%[^\n]", cpf);
            scanf("%*c");

            scanf("%[^\n]", tipoTicket);
            scanf("%*c");

            // Verificando se existe cadastro
            for (i = 0; i < VectorSize(vecUser); i++)
            {
                if (comparaCPFUser(VectorGet(vecUser, i), cpf))
                {
                    IncrementaTicketsUser(VectorGet(vecUser, i));
                    existeCadastro = 1;
                    break;
                }
            }

            if (!strcmp(tipoTicket, "SOFTWARE"))
            {
                s = lerSoftware();

                if (existeCadastro)
                {
                    setTempoEstimadoSoftware(s);
                    insereTicketFila(f, cpf, s, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
                }
                else
                {
                    desalocaSoftware(s);
                }
            }
            else if (!strcmp(tipoTicket, "MANUTENCAO"))
            {
                m = lerManutencao();

                if (existeCadastro)
                {
                    for (int i = 0; i < VectorSize(vecUser); i++)
                    {
                        if (comparaCPFUser(VectorGet(vecUser, i), cpf))
                        {
                            setTempoEstimadoManutencao(m, getSetorUser(VectorGet(vecUser, i)));
                        }
                    }

                    insereTicketFila(f, cpf, m, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
                }
                else
                {
                    desalocaManutencao(m);
                }
            }
            else if (!strcmp(tipoTicket, "OUTROS"))
            {
                o = lerOutros();

                if (existeCadastro)
                {
                    insereTicketFila(f, cpf, o, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                }
                else
                {
                    desalocaOutros(o);
                }
            }

            break;

        case 'E':

            scanf("%[^\n]", acao);
            scanf("%*c");

            if (!strcmp(acao, "USUARIOS"))
            {
                printf("----- BANCO DE USUARIOS -----\n");
                VectorPrint(vecUser, imprimeUsuario);
                printf("----------------------------\n\n");
            }

            else if (!strcmp(acao, "TECNICOS"))
            {
                printf("----- BANCO DE TECNICOS -----\n");
                VectorPrint(vecTec, imprimeTecnico);
                printf("----------------------------\n\n");
            }

            else if (!strcmp(acao, "DISTRIBUI"))
            {
                Distribui_Tickets(vecTec, f);
            }

            else if (!strcmp(acao, "NOTIFICA"))
            {
                printf("----- FILA DE TICKETS -----\n");
                notificaFila(f);
                printf("---------------------------\n\n");
            }

            else if (!strcmp(acao, "RELATORIO"))
            {
                printf("----- RELATORIO GERAL -----\n");

                printf("- Qtd tickets: %d\n", getQtdTicketsNaFila(f));
                printf("- Qtd tickets (A): %d\n", getQtdTicketsPorStatusNaFila(f, 'A'));
                printf("- Qtd tickets (F): %d\n", getQtdTicketsPorStatusNaFila(f, 'F'));
                printf("- Qtd usuarios: %d\n", VectorSize(vecUser));
                printf("- Md idade usuarios: %d\n", CalculaIdadeMediaUser(vecUser, dtRef));
                printf("- Qtd tecnicos: %d\n", VectorSize(vecTec));
                printf("- Md idade tecnicos: %d\n", CalculaIdadeMediaTec(vecTec, dtRef));
                printf("- Md trabalho tecnicos: %d\n", CalculaMediaTempoTrabalhado(vecTec));

                printf("---------------------------\n\n");
            }

            else if (!strcmp(acao, "RANKING TECNICOS"))
            {
                printf("----- RANKING DE TECNICOS -----\n");

                for (i = 0; i < VectorSize(vecRankTec); i++)
                {
                    CopiaHorasTrabalhadas(VectorGet(vecRankTec, i), VectorGet(vecTec, i));
                }

                VectorOrdena(vecRankTec, comparaTecnicos);
                VectorPrint(vecRankTec, imprimeTecnico);

                printf("-------------------------------\n\n");
            }

            else if (!strcmp(acao, "RANKING USUARIOS"))
            {
                printf("----- RANKING DE USUARIOS -----\n");

                for (i = 0; i < VectorSize(vecRankUser); i++)
                {
                    CopiaQtdTickets(VectorGet(vecRankUser, i), VectorGet(vecUser, i));
                }

                VectorOrdena(vecRankUser, comparaUsuarios);
                VectorPrint(vecRankUser, imprimeUsuario);

                printf("-------------------------------\n\n");
            }

            break;

        default:

            break;
        }
    }

    VectorDestroy(vecRankTec, desalocaTecnico);
    VectorDestroy(vecTec, desalocaTecnico);
    VectorDestroy(vecUser, desalocaUsuario);
    VectorDestroy(vecRankUser, desalocaUsuario);
    desalocaFila(f);
    LiberaData(dtRef);

    return 0;
}

int CalculaMediaTempoTrabalhado(Vector *v)
{
    int i, soma = 0;
    for (i = 0; i < VectorSize(v); i++)
    {
        soma = soma + getTempoTrabalhado(VectorGet(v, i));
    }
    return soma / VectorSize(v);
}

int CalculaIdadeMediaUser(Vector *v, Data *dtRef)
{
    int i, soma = 0;
    for (i = 0; i < VectorSize(v); i++)
    {
        soma = soma + CalculaIdadeUser(VectorGet(v, i), dtRef);
    }
    return soma / VectorSize(v);
}

int CalculaIdadeMediaTec(Vector *v, Data *dtRef)
{
    int i, soma = 0;
    for (i = 0; i < VectorSize(v); i++)
    {
        soma = soma + CalculaIdadeTec(VectorGet(v, i), dtRef);
    }
    return soma / VectorSize(v);
}

void Distribui_Tickets(Vector *v, Fila *f)
{
    int i, j, flag_id_tec = 0;

    int idPassouPorAq = -1;

    for (i = 0; i < getQtdTicketsNaFila(f); i++)
    {
        for (j = flag_id_tec; j < VectorSize(v); j++)
        {
            if (getStatusTicket(getTicketNaFila(f, i)) == 'A')
            {

                if (getTipoTicket(getTicketNaFila(f, i)) == getTipoSoftware())
                {

                    if (!strcmp(getAreaAtuacao(VectorGet(v, j)), "TI"))
                    {

                        if (getDisponibilidade(VectorGet(v, j)) >= getTempoEstimadoTicket(getTicketNaFila(f, i)))
                        {
                            AlteraHorasTecnico(VectorGet(v, j), getTempoEstimadoTicket(getTicketNaFila(f, i)));
                            finalizaTicket(getTicketNaFila(f, i));
                            flag_id_tec = j + 1;

                            if (flag_id_tec >= VectorSize(v))
                            {
                                flag_id_tec = 0;
                            }
                            break;
                        }
                    }
                }
                else
                {
                    if (!strcmp(getAreaAtuacao(VectorGet(v, j)), "GERAL"))
                    {
                        if (getDisponibilidade(VectorGet(v, j)) >= getTempoEstimadoTicket(getTicketNaFila(f, i)))
                        {
                            AlteraHorasTecnico(VectorGet(v, j), getTempoEstimadoTicket(getTicketNaFila(f, i)));
                            finalizaTicket(getTicketNaFila(f, i));
                            flag_id_tec = j + 1;

                            if (flag_id_tec >= VectorSize(v))
                            {
                                flag_id_tec = 0;
                            }
                            break;
                        }
                    }
                }
            }

            if (j == VectorSize(v) - 1)
            {
                if (idPassouPorAq == i)
                {
                    flag_id_tec = 0;
                }
                else
                {
                    idPassouPorAq = i;
                    i--;
                    flag_id_tec = 0;
                }
            }
        }
    }
}
