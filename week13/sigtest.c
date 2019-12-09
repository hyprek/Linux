#include "my.h"

void sigroutine(int signo){
    switch (signo)
    {
    case 1:
        /* code */
        printf("recive SIGHUP\n");
        break;
    case 2:
        /* code */
        printf("recive SIGUINT\n");
        break;
    case 3:
        /* code */
        printf("recive SIGQUIT\n");
        break;
    default:
        break;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    signal(1,sigroutine);
    signal(2,sigroutine);
    signal(3,sigroutine);
    printf("test process.\n pid = %d\n",getpid());
    while (1);
    return 0;
}
