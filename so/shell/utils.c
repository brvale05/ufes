#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *read_line()
{
    char *line = malloc(sizeof(char) * TAM_MAX_LINE);

    if (fgets(line, TAM_MAX_LINE, stdin) == NULL)
    {
        free(line);
        return NULL;
    }

    line[strcspn(line, "\n")] = '\0';

    return line;
}

int split_line(char *line, char **args)
{
    char *token;
    int index = 0;
    int pipe_posicao = 0;

    token = strtok(line, " ");

    while (token != NULL)
    {
        if (!strcmp(token, "#"))
        {
            pipe_posicao = index + 1;
            args[index] = NULL;
        }
        else
        {
            args[index] = token;
        }

        token = strtok(NULL, " ");
        index++;
    }

    args[index] = NULL;

    return pipe_posicao;
}

void libera_mem(char **args, char **buffer)
{
    if (args)
        free(args);

    if (buffer)
    {
        for (int i = 0; i < TAM_MAX_BUFFER; i++)
        {
            if (buffer[i])
                free(buffer[i]);
        }

        free(buffer);
    }
}
