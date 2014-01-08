#ifndef _REQUEST_H

#define _REQUEST_H

#include"Socket.h"
class Request
{
private:
	Socket & client;
public:
	char method[10];
	char path[512];
	char query[512];
	int body_len;
	Request(Socket & c):client(c){};
	void getQLine();
	void getHeadField();
	void getHead();
	void getBody();
};

#endif
