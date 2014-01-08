#include<stdio.h>
#include<unistd.h>
int main()
{
	char c[100];
	int pid=fork();
	if(pid)
	{
		while(gets(c))
		{
			printf("1 %s 1\n",c);
		}
		wait(c);
		printf("sub-process state %s\n",c);
	}else
	{
		while(gets(c))
		{
			printf("2 %s 2\n",c);
		}
	}
}
