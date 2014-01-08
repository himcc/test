#include"worker.h"
#include<stdio.h>
#include"Request.h"
#include<string.h>

void worker(int socket)
{

	Socket client(socket);

	Request request(client);
	request.getHead();
	printf("%s+%s\n",request.path,request.method);
	client.write(request.path,strlen(request.path));
	client.writechar(' ');
	client.write(request.method,strlen(request.method));
	client.write((char *)"\r\n",2);

	
	char data[1024];
	int len;
	while( (len=client.readLine(data)) > 2 )
	{

		data[len]=0;
		client.write(data,len);
		printf("%s",data);
	}

	client.close();

}
