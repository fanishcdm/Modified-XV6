#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char const *argv[])
{
	
	//saprintf(1, "my priority %d\n", getpriority(getpid()));
	long x=0;
	float z;
	int pid = fork();
	if(pid < 0)
	{
		
	}
	else if(pid == 0)
	{

		setpriority(getpid(), 6);
		printf(4, "!!!%d", getpriority(getpid()));
		for(z=0;z<900000;z=z+0.01){
			printf(2, "Priority for 1 is %d", getpriority(getpid()));
			printf(1, "2\n");
			// sleep();
			x = x + 3.15*z;
			if(x==0){
				x=x;
			}
		}	
	}
	else
	{
		setpriority(getpid(), 7);
		for(z=0;z<90;z=z+1){
			printf(3, "Priority for 2 is %d", getpriority(getpid()));
			printf(1, "1\n");
			x = x + 3.15*z;
			if(x==0){
				x=x;
			}
		}
		int pid1 = fork();
		if(pid1 < 0)
		{
			
		}
		else if(pid1 == 0)
		{

			setpriority(getpid(), 3);
			// wait();
			for(z=0;z<900000;z=z+0.01){
				//ps();
				printf(1, "pid: %d pr: %d\n", getpid(), getpriority(getpid()));
				printf(1,"3????? and pid = %d\n", getpid());
				x = x + 3.15*z;
				if(x==0){
					x=x;
				}
			}	
		}
		else
		{
			// printf(1, "bahar process: %d has been scheduled priority: %d\n", getpid(), getpriority(getpid()));
			for(z=0;z<900000;z=z+0.01){
				 // printf(1, "process: %d has been scheduled priority: %d\n", getpid(), getpriority(getpid()));
				if(getpriority(getpid()) >= 10)
					printf(1, "pid-: %d pr: %d\n", getpid(), getpriority(getpid()));
				x = x + 3.15*z;
				printf(1,"1\n");
				if(x==0){
					x=x;
				}
			}			
			wait();
			wait();
		}
	}
	exit();
}
/*int main(int argc , char *argv[]){
	long x=0;
	float z;
	int pid = fork();
	if(pid < 0)
	{
		
	}
	else if(pid == 0)
	{

		setpriority(getpid(), 18);
		for(z=0;z<900000;z=z+0.01){
			printf(1, "b\n");
			x = x + 3.15*z;
			if(x==0){
				x=x;
			}
		}	
	}
	else
	{
		for(z=0;z<90;z=z+1){
			printf(1, "a\n");
			x = x + 3.15*z;
			if(x==0){
				x=x;
			}
		}
		int pid1 = fork();
		if(pid1 < 0)
		{
			
		}
		else if(pid1 == 0)
		{
			setpriority(getpid(), 19);
			for(z=0;z<900000;z=z+0.01){
				printf(1,"c\n");
				x = x + 3.15*z;
				if(x==0){
					x=x;
				}
			}	
		}
		else
		{
			for(z=0;z<900000;z=z+0.01){
				x = x + 3.15*z;
				printf(1,"a\n");
				if(x==0){
					x=x;
				}
			}			
			wait();
			wait();
		}
	}
exit();
}
*/
