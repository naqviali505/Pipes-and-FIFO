#include<sys/types.h>
#include<iostream>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
bool isPrime(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int arr[4];
	int primecount=0,count=0;
	int pipeopen=open("/tmp/mStreamChannel",O_RDONLY);
	if(pipeopen==-1)
	{		
		cout<<"Pipe unable to open for reading\n";
		return -1;
	}
	for(int i=0;i<5000;i++)
	{
		for(int j=0;j<29;j++)
		{
			int check=read(pipeopen,arr,4);
			if(check)
			{
				for(int k=0;k<4;k++)
				{
					if(isPrime(arr[k])==true)
					primecount++;	
				}
			}	
			count=count+check;			
		}
	}
	close(pipeopen);
	cout<<"Total Numbers "<<count<<endl;
	cout<<"Total Prime Numbers "<<primecount<<endl;
	return 0;
}
