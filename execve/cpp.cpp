#include<stdio.h>
#include<unistd.h>
int main()
{
	char * const arg[]={0};
	char * const env[]={"LL=$(hostname)",0};
	execve("/home/hadoop/test/tooltest/execve/app",arg,env);
}
