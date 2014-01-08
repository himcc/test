#include<stdio.h>
#include<thread>
#include<exception>
#include<system_error>
using namespace std;
void run(int id)
{
	printf("%c\n",'a'+id);
}
int main()
{
	int i;
	for(i=0;i<10;++i)
	{
		printf("+%d\n",i);
		try
		{
			std::thread aworker(run,i);
			aworker.detach();
		}catch(const system_error & e)
		{
			printf("%s\n",e.what());
		}
		printf("+%d\n",i);
	}
}
