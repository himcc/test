#include<stdio.h>
#include<unistd.h>
int main()
{
	//sleep(100);
	printf("%d\n",fileno(stdin));
	return 0;
}
