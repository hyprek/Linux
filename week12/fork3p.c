#include "my.h"
int main(int argc, char const *argv[])
{
	pid_t p1,p2,p3;
	p1 = fork();
	if (p1<0)
	{
		/* code */
		perror("failed\n");
		return -1;
	}else if (p1==0)
	{
		/* code */
		printf("p1 parent %d child %d\n", getppid(),getpid());
		return 0;
	}
	p2 = fork();
		if (p2<0)
	{
		/* code */
		perror("failed\n");
		return -1;
	}else if (p2==0)
	{
		/* code */
		printf("p2 parent %d child %d\n", getppid(),getpid());
		return 0;
	}
	p3 = fork();
	if (p3<0)
	{
		/* code */
		perror("failed\n");
		return -1;
	}else if (p3==0)
	{
		/* code */
		printf("p3 parent %d child %d\n", getppid(),getpid());
		return 0;
	}
	return 0;
}