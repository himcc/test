#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
int id=1;
void * thread(void *arg)
{
	int pid=fork();
	if(pid==0)
		id=2;
	printf("%d t's %d\n",id,getpid());
	sleep(100);
	pthread_exit((void*)"return");
}
int main()
{
	signal(SIGCLD, SIG_IGN);
	void * ret;
	pthread_t t;
	pthread_create(&t,NULL,thread,NULL);
	sleep(1);
	printf("%d main's %d\n",id,getpid());
	pthread_join(t,&ret);

	return 0;
}
