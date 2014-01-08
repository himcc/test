#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
static int alarm_fired = 0;
void ding(int sig)
{
	alarm_fired = 1;
}
void ding2(int sig)
{
//	aalarm_fired = 1;
	printf("child\n");
}
int main()
{
	pid_t pid;

	printf("start\n");

	pid=fork();

	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			sleep(30);
			kill(getppid(),SIGALRM);
			exit(0);
	}
	printf("forked\n");
	signal(SIGALRM,ding);
	signal(SIGCHLD,ding2);
	pause();
	if(alarm_fired)
	{
		printf("Ding\n");
	}	
	printf("Done\n");
	exit(0);
}




