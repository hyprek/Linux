#include "my.h"

int main(int argc, char const *argv[])
{
	pid_t p1,p2,p3;
	p1 = fork();
	int s1,s2,s3,r1,r2,r3;
	if (p1<0)
	{
		/* code */
		perror("fork1 failed.\n");
		return -1;
	}else if (p1==0)
	{
		/* code */
		count+=1;
		printf("child pid=%d,ppid%d,count=%d\n", getpid(),getppid(),count);
		exit(99);
	}else{
		printf("parent fork second time.\n");
		p2 = fork();
		if(p2<0){
			perror("fork2 failed.\n");
			return -1;
		}else if (p2==0)
		{
			/* code */
			count+1;
			printf("child pid =%d,ppid=%d,count=%d\n", getpid(),getppid(),count);
			exit(34);
		}else{
			printf("parent fork third time.\n");
			p3 = fork();
			if (p3<0)
			{
				/* code */
			}
		}
	}
	return 0;
}