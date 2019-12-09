#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<strings.h>
#include<signal.h>
void usage(){
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "...........");
	fprintf(stderr, "signal sender pid signo timesn");
}

int main(int argc, char*argv[]){
	pid_t pid = -1;
	int signo = -1;
	int times = -1;
	int i;
	if(argc<4){
		usage();
		return -1;
	}
	
	pid = atol(argv[1]);
	signo = atoi(argv[2]);
	times = atoi(argv[3]);
	if( pid<=0 || times<0 || signo<1 || signo>=64 || signo==32 ||signo ==33){
		usage();
		return-2;
	}
	printf("pid = %d,signo = %d,times = %d\n" ,pid, signo, times);
	for (i=0;i<times;i++){
		if(kill(pid,signo) == -1){
			fprintf(stderr,"send signo(%d) to pid(%sd) failed, reason(%s)ln",signo,pid,strerror(errno));
			return-3;
		}
	}
	fprintf(stdout,"done\n");
	return 0; 	
}

