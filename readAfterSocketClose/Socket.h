#ifndef _SOCKET_H
#define _SOCKET_H

#include<unistd.h>
class Socket
{
private:
	int client_socket;
public:
	Socket(int client_socket);
	void close();
	int readchar(char &ch);
	int writechar(char ch);
	int getfd();
	int write(char * p,int len);
	int readLine(char *data);
	int read(char * data,int len);
	~Socket();
};

#endif
