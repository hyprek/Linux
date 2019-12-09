#include "my.h"
void fun(){

}
int main(int argc, char const *argv[])
{
    int i;
    sigset_t set,pendset;
    struct sigaction act;
    (void)signal(2,fun);
    if (sigemptyset(&set)<0)
        perror("init set failed!\n");
    if (sigeaddset(&set,2)<0)
        perror("init set failed!\n");
    if (sigemptyset(&set)<0)
        perror("init set failed!\n");    
    return 0;
}
