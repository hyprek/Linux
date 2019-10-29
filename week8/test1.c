#include <stdio.h>
#include <malloc.h>

void print(char *,int);
int main(){
	char *s1 = "abcde";		// s1\s2\s5 have the same address
	char *s2 = "abcde";
	char s3[] = "abcde";
	long int *s4[100];
	char *s5 = "abcde";
	int a = 5;
	int b = 6;	//a,b in stack,&a>&b
	
	printf("variables address in main function: s1=%p,s2=%p,s3=%p,s4=%p,s5=%p,a=%p,b=%p \n",s1,s2,s3,s4,s5,a,b); 
	printf("variables address in processcall:n");
	print("ddddddddd",5);	// <-(stack)  &p>&str
	printf("main=%p,print=%p \n",main,print);	// &main(first)<&print(later)	 
} 

void print(char *str,int p){
	char *s1 = "abcde";
	char *s2 = "abcde";		// s2-s1 maybe = 0,&s1>&s2
	char s3[] = "abcdeee";
	long int *s4[100];
	char *s5 = "abcde";
	int a = 5;
	int b = 6;
	int c;
	int d;	// abcd in stack,&a>b>c>d
	char *q=str;
	int m=p;
	char *r=(char *)malloc(1);
	char *w=(char *)malloc(1);	// r<w
	
	printf("s1=%p,s2=%p,s3=%p,s4=%p,s5=%p,a=%p,b=%p,c=%p,d=%p,str=%p,q=%p,p=%p,m=%p,r=%p \n",s1,s2,s3,s4,s5,&a,&b,&c,&d,&str,q,&p,&m,r,w);
		// stcak heap (running)
		// local variable in stack
		// malloc -> heap,growing
		// r>w -> stack,&r<&w 
}
