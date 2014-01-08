#include<unistd.h>
#include"Socket.h"

Socket::Socket(int client_socket)
{
	this->client_socket=client_socket;
}
void Socket::close()
{
	::close(client_socket);
}
int Socket::readchar(char &ch)
{
	return ::read(client_socket,&ch,1);
}
int Socket::writechar(char ch)
{
	return ::write(client_socket,&ch,1);
}
int Socket::getfd()
{
	return client_socket;
}
int Socket::write(char * p,int len)
{
	return ::write(client_socket,p,len);
}
int Socket::readLine(char *data)
{
	int data_len=0;
	int R=0;
	while(::read(client_socket,data+data_len,1)>0)
	{
		++data_len;
		if(data[data_len-1]=='\r')
		{
			R=1;
		}else if(data[data_len-1]=='\n'&&R==1)
		{
			return data_len;
		}else
		{
			R=0;
		}
	}
	return data_len;
}
int Socket::read(char * data,int len)
{
	return ::read(client_socket,data,len);
}
Socket::~Socket()
{
	close();
}
