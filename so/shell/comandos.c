#include "comandos.h"
#include "builtin.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

void exec_comando_externo(char **args, char **buffer, pid_t *pgid_lider)
{
    // Incrementa qtd de filhos antes do fork para evitar race conditions
    qtdfilhos_vivos++;
    pid_t pid = fork();

    if (pid == -1)
    {
        // Decrementa caso o fork falhe
        qtdfilhos_vivos--;
        libera_mem(args, buffer);
        exit(EXIT_FAILURE);
    }

    if (pid > 0)
    {
        // Eh o primeiro comando do buffer
        if (*pgid_lider == 0)
        {
            // Processo lider
            *pgid_lider = pid;
        }
    }
    else
    {
        //------FILHO------//

        // Tive que utilizar para o firefox parar de escrever logs no terminal, estava travando a shell
        // dev_null: arquivo especial de alguns sistemas unix que descarta qualquer dado escrito nele
        // 0_WRONLY: flag para somente escrita
        int dev_null = open("/dev/null", O_WRONLY);
        if (dev_null > 0)
        {
            dup2(dev_null, STDERR_FILENO); // Redireciona o STDERR_FILENO para dev_null
            close(dev_null);
        }

        if (*pgid_lider == 0)
        {
            // Sou o lider
            setpgid(0, 0);
        }
        else
        {
            // Ja existe um lider
            setpgid(0, *pgid_lider);
        }

        execvp(args[0], args);

        // Executa essa sequencia do codigo caso o exec de erro
        printf("%s: comando não encontrado\n", args[0]);
        libera_mem(args, buffer);
        exit(EXIT_FAILURE);
    }
}

void exec_comando_pipe(char **args, int pipe_indice, char **buffer, pid_t *pgid_lider)
{
    int pfd[2];

    if (pipe(pfd) == -1)
        exit(EXIT_FAILURE);

    pid_t pid_f1, pid_f2;

    // Incrementa qtd de filhos antes do fork para evitar race conditions
    qtdfilhos_vivos++;
    pid_f1 = fork();

    if (pid_f1 == -1)
    {
        // Decrementa caso o fork falhe
        qtdfilhos_vivos--;
        libera_mem(args, buffer);
        exit(EXIT_FAILURE);
    }

    if (pid_f1 > 0)
    {
        // Eh o primeiro comando do buffer
        if (*pgid_lider == 0)
        {
            // Processo lider
            *pgid_lider = pid_f1;
        }

        setpgid(pid_f1, *pgid_lider);
    }
    else
    {
        //------FILHO------//

        if (*pgid_lider == 0)
        {
            // Sou o lider
            setpgid(0, 0);
        }
        else
        {
            // Lider ja existe
            setpgid(0, *pgid_lider);
        }

        // Redireciona a saida padrao do programa para o pipe
        close(pfd[STDIN_FILENO]);
        dup2(pfd[STDOUT_FILENO], STDOUT_FILENO);
        close(pfd[STDOUT_FILENO]);

        execvp(args[0], args);

        // Executa essa sequencia do codigo caso o exec de erro
        printf("%s: comando não encontrado\n", args[0]);
        libera_mem(args, buffer);
        exit(EXIT_FAILURE);
    }

    // Incrementa qtd de filhos antes do fork para evitar race conditions
    qtdfilhos_vivos++;
    pid_f2 = fork();

    if (pid_f2 == -1)
    {
        // Decrementa caso o fork falhe
        qtdfilhos_vivos--;
        libera_mem(args, buffer);
        exit(EXIT_FAILURE);
    }

    if (pid_f2 == 0)
    {
        //------FILHO------//

        setpgid(0, *pgid_lider);

        // Redireciona a entrada padrao do programa para o pipe
        close(pfd[STDOUT_FILENO]);
        dup2(pfd[STDIN_FILENO], STDIN_FILENO);
        close(pfd[STDIN_FILENO]);

        execvp(args[pipe_indice], args + pipe_indice);

        // Executa essa sequencia do codigo caso o exec de erro
        printf("%s: comando não encontrado\n", args[pipe_indice]);
        libera_mem(args, buffer);
        exit(EXIT_FAILURE);
    }

    // Fecha descritores do pai
    close(pfd[STDIN_FILENO]);
    close(pfd[STDOUT_FILENO]);
}

void exec_buffer(char **buffer, int *tam, char **args)
{
    printf("\n");
    int i = 0, pipe_indice = 0;

    // Responsavel por definir o PGID do respectivo lote de processos
    pid_t pgid_lider = 0;

    for (i = 0; i < *tam; i++)
    {
        pipe_indice = split_line(buffer[i], args);

        if (eh_builtin(args))
        {
            exec_builtin(args, buffer);
        }
        else if (pipe_indice > 0)
        {
            exec_comando_pipe(args, pipe_indice, buffer, &pgid_lider);
        }
        else
        {
            exec_comando_externo(args, buffer, &pgid_lider);
        }

        // Libera as linhas alocadas
        if (buffer[i])
            free(buffer[i]);

        // Garante um funcionamento previsivel e desejado do programa
        buffer[i] = NULL;
    }

    // Reseta tamanho do buffer
    *tam = 0;
}