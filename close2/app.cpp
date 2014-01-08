#include<stdio.h>
#include<unistd.h>
int main()
{
	int ret=close(0);
	printf("%d\n",ret);
	ret=close(0);	
	printf("%d\n",ret);
	return 0;
}
