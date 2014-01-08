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
	char s[1000];
	while(1)
	{
		printf("%d\n",::read(cc,s,50));
	}
	
	return 0;
}
