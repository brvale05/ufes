#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd_1[2]; // pipe 1
    int fd_2[2]; // pipe 2
    int fd_3[2]; // pipe 3

    int wstatus;

    pid_t pid;
    pid_t pid_2;

    if (pipe(fd_1) < 0)
        write(STDERR_FILENO, "pipe 1 error\n", 13);

    if (pipe(fd_2) < 0)
        write(STDERR_FILENO, "pipe 2 error\n", 13);

    if (pipe(fd_3) < 0)
        write(STDERR_FILENO, "pipe 3 error\n", 13);

    pid = fork();

    if (pid < 0)
    {
        write(STDERR_FILENO, "fork 1 error\n", 13);
    }
    else if (pid > 0)
    {
        // processo pai

        pid_2 = fork();

        if (pid_2 < 0)
        {
            write(STDERR_FILENO, "fork 1 error\n", 13);
        }
        else if (pid_2 == 0)
        {
            waitpid(pid, NULL, 0);

            int num_f2 = 0;

            close(fd_1[1]);
            close(fd_2[1]);

            int n = read(fd_2[0], &num_f2, sizeof(int));

            num_f2 = num_f2 + 10;

            close(fd_1[0]);
            close(fd_2[0]);

            n = write(fd_3[1], &num_f2, sizeof(int));

            exit(EXIT_SUCCESS);
        }

        int num = atoi(argv[1]);

        close(fd_2[0]);
        close(fd_1[0]);

        int n = write(fd_1[1], &num, sizeof(int));

        // espera o primeiro filho morrer
        waitpid(pid, &wstatus, 0);
    }
    else
    {
        // filho 1
        int num_f1 = 0;

        close(fd_3[1]);
        close(fd_1[1]);

        int n = read(fd_1[0], &num_f1, sizeof(int));

        num_f1 = num_f1 + 5;

        close(fd_1[0]);

        n = write(fd_2[1], &num_f1, sizeof(int));

        exit(EXIT_SUCCESS);
    }

    int result = 0;

    close(fd_3[1]);

    int n = read(fd_3[0], &result, sizeof(int));

    printf("RESULTADO FINAL: %d\n", result);

    return 0;
}