#include "sig.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

void handle_sigint(int sig)
{
    ctrlc_recebido = 1;
}

void handle_sigchld(int sig)
{
    // Garante que essa variavel nao atinja valores negativos 
    if (qtdfilhos_vivos > 0)
        qtdfilhos_vivos--;
}

void config_sigaction()
{
    // Estrutura basica para captura de sinais por um handler
    struct sigaction sa_int;
    sa_int.sa_handler = &handle_sigint;
    sa_int.sa_flags = 0;
    sigemptyset(&sa_int.sa_mask);
    sigaction(SIGINT, &sa_int, NULL);

    struct sigaction sa_chld;
    sa_chld.sa_handler = &handle_sigchld;
    sa_chld.sa_flags = SA_NOCLDSTOP;
    sigemptyset(&sa_chld.sa_mask);
    sigaction(SIGCHLD, &sa_chld, NULL);
}

int confirma_saida()
{
    if (qtdfilhos_vivos > 0)
    {
        printf("\nlsh> Não posso morrer... sou lenta mas sou mãe de família!!!");
        printf("\nlsh> ");
        fflush(stdout);
    }
    else
    {
        // Nao existe filho vivo nem comando no buffer. Logo, a shell finaliza a execucao
        printf("\nlsh> Ok... você venceu! Adeus!\n");
        return 1;
    }

    // Estrutura para delimitar o tempo em que o usuario digita ctrl-c para terminar o programa
    struct timespec timeout;
    timeout.tv_sec = 3;
    timeout.tv_nsec = 0;

    sigset_t mask_bloqueia, mask_original;
    sigemptyset(&mask_bloqueia);       // Boa pratica
    sigaddset(&mask_bloqueia, SIGINT); // Adiciona o SIGINT(ctrl-c) na mascara de sinais

    sigprocmask(SIG_BLOCK, &mask_bloqueia, &mask_original); // Adiciona essa mascara ao programa com SIG_BLOCK e salva a antiga em mask_original

    int finalizar = 0;

    // Essa funcao para a execucao do programa ate que os 3 segundos acabem.
    if (sigtimedwait(&mask_bloqueia, NULL, &timeout) == SIGINT) // Verifica se o usuario digitou ctrl-c dentro do tempo estipulado
    {
        printf("\nlsh> Ok... você venceu! Adeus!\n");
        finalizar = 1;
    }
    else
    {
        printf("\n");
    }

    sigprocmask(SIG_SETMASK, &mask_original, NULL); // Retorna a mascara de sinais original

    return finalizar;
}