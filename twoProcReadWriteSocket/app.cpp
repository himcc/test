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
	
	ServerSocket server(8899);
	
	server.bind();
	server.listen();
	int cc = server.accept();
	Socket client(cc);
	char c;
	char s[20];
	int pid = fork();
	if(pid)
	{
		int i;
		for(i=0;i<5;++i)
		{
			client.readchar(c);
			printf("inf %d\n",(int)c);
			sprintf(s,"inf %d abcdefg\r\n",i);
			client.write(s,strlen(s));
			sleep(1);
		}
	}else
	{
		int i;
		for(i=0;i<5;++i)
		{
			client.readchar(c);
			printf("inc %d\n",(int)c);
			sprintf(s,"inc %d uvwxyz\r\n",i);
			client.write(s,strlen(s));
			sleep(1);
		}
	}
	
	return 0;
}
