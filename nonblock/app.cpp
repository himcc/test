#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int flags = fcntl(0,F_GETFL,0);
	fcntl(0,F_SETFL,O_NONBLOCK|flags);
	char c;
	int d=123456;
	//c=getchar();
	int ret=scanf("%d",&d);
	//printf("%d %d\n",ret,d);return 0;
	while(d>0)
	{
		if(ret>0)
		{
			printf("%d",d);
		}else
		{
			printf("working...\n");
		}
		sleep(1);
		//c=getchar();
		ret=scanf("%d",&d);
	}
	return 0;
}
