#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main()
{
	int pipeopen=open("/tmp/mStreamChannel",O_WRONLY);
	if(pipeopen==-1)
	{
		cout<<"Unable to open pipe for writing\n";
		return -1;
	}
	srand(time(NULL));
	int arr[4];
	for(int i=0;i<5000;i++)
	{
		for(int j=0;j<29;j++)
		{
			for(int k=0;k<4;k++)
			{
				arr[k]=	(rand()%100)+1;
				wait((int*)250);		
			}
			write(pipeopen,arr,4);
		}
	}
	close(pipeopen);
	return 0;
}
