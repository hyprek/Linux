#include "my.h"

int main(int argc, char const *argv[])
{
	pid_t p1,p2,p3;
	p1 = fork();
	p2 = fork();
	p3 = fork();
	if (p1==-1||p2==-1||p3==1)
	{
		/* code */
		printf("failed\n");
		return -1;
	}
	if (p1 == 0)
	{
		/* code */
		printf("p1 parent %d child %d\n", getppid(),getpid());
	}
	if (p2 == 0)
	{
		/* code */
		printf("p2 parent %d child %d\n", getppid(),getpid());
	}
	if (p3 == 0)
	{
		/* code */
		printf("p3 parent %d child %d\n", getppid(),getpid());
	}
	
	return 0;
}