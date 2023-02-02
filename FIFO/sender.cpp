#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<cstring>
#include<sys/wait.h>
#include<sys/stat.h>
using namespace std;
void encryption(char arr1[])
{
	char var1=0,var2=0,var3=0;
	for(int i = 0; arr1[i] != '\0'; i++)
	{
    		var1 = arr1[i];
    		if(var1 >= 'a' && var1 <= 'z')
    		{
			var1 = var1 + 3;
      			if(var1 > 'z')
      			{
				var1 = var1 - 'z' + 'a' - 1;
      			}
      			arr1[i] = var1;
    		}
    		else if(var1 >= 'A' && var1 <= 'Z')
    		{
      			var1 = var1 + 3;
      			if(var1 > 'Z')
      			{
        			var1 = var1 - 'Z' + 'A' - 1;
      			}
      			arr1[i] = var1;
    		}
  	}		
}
int main()
{
	char arr1[60]="Send email to Ahmed,My Password is 123,Hey to everyone";
	int n=0;
	int pid=fork();	
	if(pid!=0)
	{
		int pipeopen=open("/tmp/Reader",O_WRONLY);
		if(pipeopen==-1)
		{
			cout<<"Unable to open 1st pipe for writing\n";
			return -1;
		}
		else 
		{
			//cout<<"Opening 1st pipe for writing"<<endl;
			n=write(pipeopen,arr1,sizeof(arr1));
		}	
		close(pipeopen);
		cout<<"Original Messages---------"<<endl;
		cout<<arr1<<endl;
		wait(NULL);//Waiting for child process
		cout<<"Encrypted Messages.........\n";
		pipeopen=open("/tmp/Writer",O_RDWR);
		if(pipeopen==-1)
		{
			cout<<"Unable to open 1st pipe for reading\n";
			return -1;
		}
		else
		{
			
			read(pipeopen,arr1,sizeof(arr1));
			arr1[n]='\0';
			cout<<arr1<<endl;
		}
		close(pipeopen);
	}	
	else if(pid==0)
	{
		
		int pipeopen=open("/tmp/Reader",O_RDWR);
		if(pipeopen==-1)
		{
			cout<<"Unable to open 1st pipe for reading\n";
			return -1;
		}
		else
		{
			//cout<<"Opening 1st pipe for reading"<<endl;
			n=read(pipeopen,arr1,sizeof(arr1));
			arr1[n]='\0';
			encryption(arr1);
			//cout<<arr1<<endl;
		}
		close(pipeopen);
		pipeopen=open("/tmp/Writer",O_RDWR);
		if(pipeopen==-1)
		{
			cout<<"Unable to open 2nd pipe for writing\n";			
			return -1;
		}
		else
		{
			//cout<<"Opened 2nd pipe for writing\n";
			write(pipeopen,arr1,n);
		}
		close(pipeopen);
	}
	return 0;
}
