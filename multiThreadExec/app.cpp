#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void* run(void* d)
{
	printf("in thread\n");
	sleep(20);
	char * const arg[]={0};
	char * const env[]={0};
	execve("/home/hadoop/test/tooltest/multiThreadExec/app2",arg,env);
	pthread_exit((void*)"a");
}
int main()
{
	void * ret;
	pthread_t t;
	pthread_create(&t,0,run,0);
	pthread_join(t,&ret);
	return 0;
}
