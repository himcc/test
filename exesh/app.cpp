#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char s[100];
	printf("in app\n");
	sprintf(s,"%s/my.sh",getenv("PWD"));
	char * const arg[]={0};
	char * const env[]={0};
	execve(s,arg,env);
	return 0;
}
