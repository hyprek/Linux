#include <stdio.h>

int a;
static int b=10;
int main(int argc,char* argv[], char* envp[]){
	int a=10;
	char* p=(char*)malloc(sizeof(char));	// heap
	printf("a=%d,p=ox%x\n",a,p);	// *.so
	getchar();	// set block -getchar()/sleep()
	getchar();
	return 0;
}
