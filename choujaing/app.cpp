#include<stdio.h>
#include<pthread.h>
int pao=1;
void * run(void * arg)
{
	printf("in run\n");
	int jiang=0;
	while(pao)
	{
	//	if(jiang%10000==0) printf("run test %d\n",jiang/10000);
		jiang=(jiang+1);
	}
	printf("%d\n",jiang);
	printf("run over\n");
	pthread_exit((char *)"OVER");
}
int main()
{
	printf("in main\n");
	char s;
	
	pthread_t mythead;
	
	pthread_create(&mythead,NULL,run,NULL);
	printf("created\n");
	scanf("%c",&s);
	pao=0;
	printf("stop pao\n");
	void * ret;
	pthread_join(mythead,&ret);
	printf("run return %s\n",(char *)ret);
	printf("main over\n");
}
