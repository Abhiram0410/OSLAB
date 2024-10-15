#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
	pid_t pid,temp;
	pid=fork();
	if(pid==0)
	{
		sleep(3);
		temp=getpid();
		printf("\nChild Process ID: %d\n",temp);
		temp=getppid();
		printf("Child Parent Process ID: %d\n",temp);
		printf("Child Child Process ID: %d\n",pid);
		system("ps");
	}
	else
	{
		temp=getpid();
		printf("Parent Process ID: %d\n",temp);
		temp=getppid();
		printf("Parent Parent Process ID: %d\n",temp);
		printf("Parent Child Process ID: %d\n",pid);	
	}
}