#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
using namespace std;
int main()
{
	int namedpipe=mkfifo("/tmp/Writer",00777);
	if(namedpipe==-1)
	{
		cout<<"Unable to create 1st pipe as it is already created\n";
	}
	else
	cout<<"Named Pipe1 Created"<<endl;
	 namedpipe=mkfifo("/tmp/Reader",00777);
	if(namedpipe==-1)
	{
		cout<<"Unable to create 2nd pipe as it is already created\n";
		return -1;
	}
	else
	{
		cout<<"Named Pipe2 Created"<<endl;
	}
return 0;
}
