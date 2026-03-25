#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define TAM_MAX_TICKETS 10

/**
 * Uma estrutura que armazenará os tickets que serão atribuidos aos técnicos.
 *
 * A estrutura seguirá a ideia de uma Fila, isto é, primeiro ticket deve ser o primeiro a ser tratado.
 */
struct Fila
{
    Ticket **tickets;
    int qtdMAX;
    int qtdAtual;
};

/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila()
{
    Fila *f = malloc(sizeof(Fila));
    if (!f)
    {
        printf("erro ao alocar memoria fila!\n");
        exit(0);
    }

    f->tickets = malloc(sizeof(Ticket *) * TAM_MAX_TICKETS);
    if (!f->tickets)
    {
        printf("erro ao alocar vetor de tickets na fila!\n");
        exit(0);
    }

    f->qtdAtual = 0;
    f->qtdMAX = TAM_MAX_TICKETS;

    return f;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
void desalocaFila(Fila *f)
{
    if (f)
    {
        if (f->tickets)
        {
            int i;
            for (i = 0; i < getQtdTicketsNaFila(f); i++)
            {
                desalocaTicket(getTicketNaFila(f, i));
            }
            free(f->tickets);
        }
        free(f);
    }
}

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca)
{
    if (f->qtdAtual == f->qtdMAX)
    {
        f->qtdMAX = f->qtdMAX * 2;
        f = realloc(f->tickets, sizeof(Ticket *) * f->qtdMAX);
    }

    f->tickets[f->qtdAtual] = criaTicket(cpfSol, dado, getTempo, getTipo, notifica, desaloca);
    f->qtdAtual++;
}

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f)
{
    return f->qtdAtual;
}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status)
{
    int i, soma = 0;
    for (i = 0; i < f->qtdAtual; i++)
    {
        if (getStatusTicket(getTicketNaFila(f, i)) == status)
        {
            soma++;
        }
    }
    return soma;
}

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i)
{
    return f->tickets[i];
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f)
{
    int i;
    char id[30];

    for (i = 0; i < getQtdTicketsNaFila(f); i++)
    {
        sprintf(id, "Tick-%d", i + 1);
        setIDTicket(getTicketNaFila(f, i), id);
        notificaTicket(getTicketNaFila(f, i));
    }
}

