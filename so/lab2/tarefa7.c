#include <stdio.h>
#include <unistd.h>   // For the syscall functions.
#include <sys/wait.h> // For wait and related macros.
#include <stdlib.h>

int main(void)
{
    pid_t pid_filho;
    pid_t pid;

    for(int i = 0; i < 3; i++)
    {
        pid = fork();

        if(!pid)
        {
            sleep(2);
            exit(0);
        }
    }

    int wstatus;

    for(;;)
    {
        sleep(2);

        pid_filho = waitpid(-1, &wstatus, WNOHANG);

        if(pid_filho > 0)
        {
            printf("Meu filho pid = %d terminou\n", pid_filho);
        }
        else
        {
            if(pid_filho < 0)
            {
                break;
            }
            else
            {
                printf("Nenhum filho terminou\n");
            }
        }

    }
    
}