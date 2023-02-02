#include<sys/types.h>
#include<sys/stat.h>
#include<iostream>
using namespace std;
int main()
{
	int res=mkfifo("/tmp/mStreamChannel",00700);
	if(res==-1)
	{
		cout<<"Named pipe not created or is already created"<<endl;
		return -1;
	}
	else
	cout<<"Named Pipe created"<<endl;
	return 0;
}
