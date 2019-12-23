#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <limits.h>
//#include "err_exit.h"
#include <signal.h>
#include <assert.h>
#include <time.h>
#define check_error(return_val,msg){        \
    if (return_val != 0){                   \
        fprintf(stderr,"%s: %s\n",msg,strerror(return_val));\
        exit(1);\
    }\
}