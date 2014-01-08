#include"Request.h"
#include<string.h>
#include<stdio.h>

void Request::getQLine()
{
	char data[1024];
	int data_len = client.readLine(data);
	sscanf(data,"%s%s",method,path);
	int i=0;
	while(path[i]!='?'&&path[i]!='#'&&path[i]!=0) ++i;
	if(path[i]!=0)
	{
		sscanf(path+i,"%s",query);
		path[i]=0;
	}
}
void Request::getHeadField()
{
	char data[1024];
	int data_len;
	while((data_len=client.readLine(data))>2)
	{
		
	}
}
void Request::getHead()
{
	body_len=0;
	getQLine();
	getHeadField();
}
void Request::getBody()
{
	
}
