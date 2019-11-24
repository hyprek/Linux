#include "my.h"

int main(){
	int pid,s;
	if((pid=fork())<0){
		perror("failes to fork\n");
		return -1;
	}
	else if(pid==0){
		printf("%d:child is running\n",getpid());
		printf("%d:child exit now\n",getpid());
		exit(120);
	}
	else{
		printf("%d:parent is waiting zombie\n",getpid());
		while((pid=wait(&s))!=1){
			if(WIFEXITED(s)){
				printf("child %d exit normally. exit code = %d\n",pid,WEXITSTATUS(s));	
			}
			else if(WIFSIGNALED(s)){
				printf("chaild %d exit by signal. signal = %d\n",pid,WTERMSIG(s));
			}
			else{
				printf("unknow\n");
			}
		}
	}
	exit(0);
}

