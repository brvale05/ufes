#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t childpid = 0;
    int i, n;
    /* check for valid number of command - line arguments */
    n = 4;

    for (i = 1; i < n; i++)
    {
        childpid = fork();
    }

    return 0;
}