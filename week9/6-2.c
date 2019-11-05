#include<stdio.h>
#include<unitsd.>
#include<stdlib.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	int i=10;
	static k=20;
	
	pid=fork();
	if(pid<0){
		perror("fail to create child\n");
		exit;
	}
	else if(pid==0){
		printf("child:pid=%d,ppid=%d\n");
		printf("address:i=%p,k=%p,glo1=%p,glo2=%p\n",&i,&k,&glo1,&glo2);
		glo1=999;
		glo2=1000;
		i=12;
		k=19;
		
		sleep(2);
		printf("address:i=%p,k=%p,glo1=%p,glo2=%p\n",&i,&k,&glo1,&glo2);
		
		exit(0);
	}
	else{
		printf("parent:pid=%d,ppid=%d\n");
		printf("address:i=%p,glo1=%p,glo2=%p\n",&i,&glo1,&glo2);
		sleep(10);
		printf("address(sleep):i=%p,k=%p,glo1=%p,glo2=%p\n",&i,&k,&glo1,&glo2);
	}
}
