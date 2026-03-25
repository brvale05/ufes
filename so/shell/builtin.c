#include "utils.h"
#include "builtin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void executa_cd(char **args)
{
    if (args[1] == NULL)
    {
        // Busca o diretorio da pasta HOME quando o usuario digitar apenas "cd"
        char *dir_home = getenv("HOME");

        if (dir_home)
        {
            chdir(dir_home);
        }
        else
        {
            printf("Nao foi possivel encontrar o diretorio HOME");
        }

        return;
    }

    if (chdir(args[1]) == -1)
    {
        printf("bash: cd: %s: Arquivo ou diretório inexistente\n", args[1]);
    }
}

void executa_wait()
{
    pid_t pid;
    int wstatus;

    while ((pid = waitpid(-1, &wstatus, WNOHANG)) > 0)
    {
        if (WIFEXITED(wstatus))
        {
            printf("Filho terminou normalmente, PID DO PROCESSO: %d, codigo de saida do filho: %d\n", pid, WEXITSTATUS(wstatus));
        }
        else if (WIFSIGNALED(wstatus))
        {
            printf("Filho terminou por um sinal, PID DO PROCESSO: %d, codigo do sinal: %d\n", pid, WTERMSIG(wstatus));
        }
    }

    printf("Nao ha mais processos no estado 'ZOMBIE'\n");
}

void executa_exit(char **args, char **buffer)
{
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;

    libera_mem(args, buffer);

    exit(EXIT_SUCCESS);
}

void exec_builtin(char **args, char **buffer)
{
    if (!strcmp(args[0], "cd"))
    {
        executa_cd(args);
    }
    else if (!strcmp(args[0], "wait"))
    {
        executa_wait();
    }
    else
    {
        executa_exit(args, buffer);
    }
}

int eh_builtin(char **args)
{
    if (!strcmp(args[0], "cd") || !strcmp(args[0], "wait") || !strcmp(args[0], "exit"))
    {
        return 1;
    }

    return 0;
}