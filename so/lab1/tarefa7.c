#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    int N = 3;

    printf("pid = %d, ppid = %d\n\n", getpid(), getppid());

    for(int i = 0; i < N; i++)
    {
        pid = fork();

        if(pid < 0)
        exit(EXIT_FAILURE);

        if(!pid)
        {
            printf("pid = %d, ppid = %d\n", getpid(), getppid());
            break;
        }

    }

    return 0;
}