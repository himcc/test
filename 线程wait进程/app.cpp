#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>
void* run(void* d)
{
	printf("in thread\n");
	int pid= fork();
	if(pid)
	{
		waitpid(pid,0,0);
	}else
	{
		sleep(10);
	}
	pthread_exit((void*)"a");
}
int main()
{
	void * ret;
	pthread_t t;
	pthread_create(&t,0,run,0);
	for(int i=0;i<10;++i)
	{
		printf("inf %d\n",i);
		sleep(1);
	}
	pthread_join(t,&ret);
	return 0;
}
