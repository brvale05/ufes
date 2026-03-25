#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pfd[2];
    pid_t pid_1, pid_2;

    if (pipe(pfd) == -1)
        exit(EXIT_FAILURE);

    pid_1 = fork();

    if (pid_1 < 0)
    {
        exit(EXIT_FAILURE);
    }

    if (pid_1 == 0)
    {
        // filho1

        close(pfd[0]);

        dup2(pfd[1], 0);

        close(pfd[1]);

        execlp("ping", "ping", "-c", "5", "google.com", NULL);

        printf("erro ao executar execlp");
        exit(EXIT_FAILURE);
    }

    pid_2 = fork();

    if (pid_2 < 0)
    {
        exit(EXIT_FAILURE);
    }

    if (pid_2 == 0)
    {

        // filho 2

        close(pfd[1]);

        dup2(pfd[0], 0);

        close(pfd[0]);

        execlp("grep", "grep", "rtt", NULL);

        printf("erro ao executar execlp");
        exit(EXIT_FAILURE);
    }

    close(pfd[0]);
    close(pfd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}