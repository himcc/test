#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid = fork();
	int ff[2];
	pipe(ff);
	if(pid)
	{
		printf("f: [0]=%d [1]=%d\n",ff[0],ff[1]);
		sleep(200);
		printf("father is over\n");
	}else
	{
		printf("f: [0]=%d [1]=%d\n",ff[0],ff[1]);
		close(0);
		dup(ff[0]);

		execv("./ss",0);

		sleep(200);
		printf("child is over\n");
	}
}
