#include "my.h"

int i=0;
int fun(void *d){
i++;
printf("tid=%p i=%d\n",pthread_self(),i);
}

int main(){
pthread_t tid;
int ret[4],i;

for(int i=0;i<4;i++){
ret[i]=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
	if(ret[i]!=0){
		perror("failed\n");
		return -1;
	}
}

/*pthread_join(tid,NULL);
ret=pthread_create(&tid,NULL,(void*(*)())fun,NULL);
pthread_join(tid,NULL);*/

for(int i=0;i<4;i++){
pthread_detach(tid);
}
sleep(10);
printf("done\n");

return 0;
}
