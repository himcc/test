#include<stdio.h>
#include<string.h>
#include<unistd.h>
char req[1000];
int getreq()
{
	char c;
	int wei=0;
	int flag=0;
	int shisan=0;
	//int fuyi=0;
	while(flag!=2)// || fuyi==0)
	{
		c=getchar();
		while(c==-1)
		{
			//fuyi++;
			if(wei)
			{
				perror("-");
				req[wei]=0;
				return 0;
			}
			sleep(1);
			c=getchar();
		}
		if(c==13)
		{
			shisan=1;
		}else if(c==10&&shisan==1)
		{
			shisan=0;
			flag++;
		}else
		{
			flag=0;
			shisan=0;
		}
		req[wei++]=c;
	}
	//perror("*");
	req[wei]=0;
	return 0;
}
int main()
{
	int i=0;
	char s[100],c;
	while(1)
	{
		getreq();
		//i=scanf("%s",s);
		//c=getchar();
		//sprintf(s,"get %d",i++);
		//perror(s);
		//putchar(c);
		//gets(s);//return 0;
		//puts(s);
		//if(s[0]==0)
		{
			sprintf(s,"\n\n\n%d",i++);
			perror(s);
			//sprintf(s,"%c %d",c,(int)c);
			perror(req);
			printf("HTTP/1.1 200 OK\r\nContent-Length: 5\r\nContent-Type: text/html;charset=utf-8\r\nConnection: close\r\n\r\n12345");
			printf("\r\n");
			fflush(stdout);
		}
	}
	return 0;
}
