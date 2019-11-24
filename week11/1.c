#include"my.h"
void init_daemon(void){
	pid_t child1,child2;
	int i;
	child1 = fork();
	if (child1>0)
	{
		/* code */
		exit(0);
	}else if (child1<0)
	{
		/* code */
		perror("failed!");
		exit(1);
	}
	setsid();
	chdir("/tmp");
	umask(0);
	for (i = 0; i < NOFILE; ++i)
	{
		/* code */
		close(i);
		return;
	}
}
// int main(int argc, char const *argv[])
// {
	
// 	init_daemon();
// 	return 0;
// }
