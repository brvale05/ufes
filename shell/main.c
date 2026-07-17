// #define _POSIX_C_SOURCE  200809L

//PARA RODAR:
//make --> compila
//make run --> roda

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "utils.h"
#include "comandos.h"
#include "sig.h"

volatile sig_atomic_t ctrlc_recebido = 0;
volatile sig_atomic_t qtdfilhos_vivos = 0;

int main(int argc, char **argv)
{
    int i;
    config_sigaction();

    char **buffer = malloc(sizeof(char *) * TAM_MAX_BUFFER);

    for (i = 0; i < TAM_MAX_BUFFER; i++)
        buffer[i] = NULL;

    char **args = malloc(sizeof(char *) * ARG_MAX);

    for (i = 0; i < ARG_MAX; i++)
        args[i] = NULL;

    char *line;

    int tam_buffer = 0;

    while (1)
    {
        printf("lsh> ");
        fflush(stdout);

        line = read_line();

        // Verificacao se houve erro de leitura
        if (line == NULL)
        {
            // Filho quando morre envia um SIGCHLD, que eh tratado pela handle_sigchld
            // A flag SA_RESTART nao esta ativada, o que significa que o sistema aborta a leitura
            // EINTR indica que um sinal foi recebido durante uma chamada de sistema, nesse caso, a leitura de linha por fgets
            // Variavel errno recebe o valor de EINTR
            // Eh verdadeiro quando um filho morre ou o usuario digita um ctrl+c no terminal
            if (errno == EINTR)
            {
                if (ctrlc_recebido)
                {
                    ctrlc_recebido = 0;

                    // Nao ha comandos enfileirados
                    if (tam_buffer == 0)
                    {
                        // Verifica se pode terminar a shell
                        if (confirma_saida())
                        {
                            break;
                        }
                    }
                    else
                    {
                        exec_buffer(buffer, &tam_buffer, args);
                    }
                }

                // Importante para limpar indicadores de erro do stdin.
                clearerr(stdin);
                errno = 0; // Reseta errno para a proxima leitura de linha

                // Sobrescreve a linha atual em vez de imprimir uma nova
                // Utilizado para quando um filho morrer e entrar nesse if, imprimir corretamente o prompt
                // O cursor volta para o começo da linha "\r"
                // O terminal apaga tudo o que existe do cursor até o final da linha
                printf("\r\033[K");

                continue;
            }
            else
            {
                // Deu algum erro que nao era pra acontecer
                break;
            }
        }

        if (tam_buffer < TAM_MAX_BUFFER)
        {
            buffer[tam_buffer] = line;
            tam_buffer++;
        }
        else
        {
            free(line);
        }
    }

    if (buffer)
        free(buffer);

    if (args)
        free(args);

    return 0;
}