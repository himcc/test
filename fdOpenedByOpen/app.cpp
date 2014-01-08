#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd=open("/home/hadoop/index.html",O_RDONLY);
	printf("fd is %d\n",fd);
	sleep(200);
}
