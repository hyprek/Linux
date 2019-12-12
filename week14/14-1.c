#include"my.h"

void * threadfun(void *arg){
	printf("thread pid =%d\n",geipid());
} 

int main(){
	pthread_t tidp;
	int error;
	error = pthread_create(&tidp,NULL,threadfun,NULL);
}
