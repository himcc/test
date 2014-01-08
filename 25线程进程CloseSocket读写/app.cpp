#include<stdio.h>
#include"ServerSocket.h"
#include"Socket.h"
#include"worker.h"
#include<thread>
#include"Server.h"
#include<unistd.h>
#include<string.h>
int main()
{
	printf("A\n");
	ServerSocket server(8899);
	printf("B\n");
	server.bind();
	server.listen();
	printf("C\n");
	int cc = server.accept();
	printf("D\n");
	Socket client(cc);
	char c;
	char s[20];
	int pid = fork();
	printf("after fork\n");
	if(pid)
	{
		printf("inf pid\n");
		//close(cc);
	}else
	{
		sleep(5);
		printf("inc\n");
		close(0);
		dup(cc);
		close(1);
		char ch;
		for(int i=0;i<10;i++)
		{
			scanf("%c",&ch);
			perror("Z");
			printf("I get a %c\r\n",c);
		}
		dup(cc);
		perror("inc exit");
	}
	perror("ret");
	return 0;
}
