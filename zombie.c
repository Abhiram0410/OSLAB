#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void main()
{
	int status;
	pid_t pid,temp;
	pid=fork();
	if(pid==0)
	{
		temp=getpid();
		printf("Child Process ID: %d\n",temp);
		temp=getppid();
		printf("Child Parent Process ID: %d\n",temp);
		printf("Child Child Process ID: %d\n",pid);
	}
	else
	{
		system("ps");
		wait(&status);
		temp=getpid();
		printf("Parent Process ID: %d\n",temp);
		temp=getppid();
		printf("Parent Parent Process ID: %d\n",temp);
		printf("Parent Child Process ID: %d\n",pid);	
	}
}