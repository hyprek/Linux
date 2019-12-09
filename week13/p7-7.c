#include "my.h"
void wait_for_signal(int sig,volatile sig_atomic_t *sflag){
    static sigset_t mask,oldmask;
    
}