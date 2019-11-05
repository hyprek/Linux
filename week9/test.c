#include<stdio.h>
#include<unitsd.>
#include<stdlib.h>

int main(int argc,char argv[]){
char *args[]={"/home/rlk/Desktop/1/week9/test",NULL};

//printf("test:pid=%d,ppid=%d\n",getpid(),getppid());
printf("test execve:pid=%d,ppid=%d\n",getpid(),getppid());

if(execve("/home/rlk/Desktop/1/week9/test",args,NULL)<0)
	perror("fail to create process by execve\n");

printf("arter\n");;;
return 0;
}
