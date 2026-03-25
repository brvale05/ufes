#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int glob = 6;

int main(void) 
{
	int var; 	
	pid_t pid;	
		
	var = 88;

	printf("before fork\n");

	pid = fork();

	if (pid < 0)
	{
		fprintf(stderr, "fork error\n");
	}
	else if (pid == 0) 
	{ 		
		glob++;
		var++;
	}
	else
	{
		sleep(15);		/* ***parent***; try to guarantee that child ends first*/
	}
	
	printf("pid = %d, ppid = %d, glob = %d, var = %d\n", getpid(), getppid(), glob, var);
	printf("%d\n", getpgrp());

	return 0;
}
