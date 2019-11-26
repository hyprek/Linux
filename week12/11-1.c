#include "my.h"

int main(int argc, char const *argv[])
{
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[1];
	memset(buf,0,sizeof(buf));
	if (pipe(pipefd)<0)
	{
		/* code */
		perror("pipe failed.\n");
		return -1;
	}
	r = fork();
	if (r<0)
	{
		/* code */
		perror("fork failed.\n");
		return -1;
	}else if (r==0)
	{
		/* code */
		char b='a';
		close(pipefd[0]);
		for (int i = 0; i < 65537; ++i)
		{
			/* code */
			printf("child write %d times\n", i);
			write(pipefd[1],&b,1);
		}
		printf("child write done.\n");
		close(pipefd[1]);
		exit(0);
	}
	return 0;
}