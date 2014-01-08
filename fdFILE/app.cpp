#include<stdio.h>
#include<unistd.h>
int main()
{
	char c;
	scanf("%c",&c);
	printf("%c\n",c);
	read(0,&c,1);
	printf("%c\n",c);
	return 0;
}
