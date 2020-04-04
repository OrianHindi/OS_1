#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
char process_stack[10000+1];

void run (char * name){
    for (int i = 0; i <30 ; ++i) {
        printf("Im the %s process \n", name);
        usleep(300000);
    }
}

int keepALive(){
    run("Second");
}

int main(){
   int result = clone(keepALive,process_stack+10000, CLONE_PARENT,0);
   printf("clone process result=%d",result);
   run("First");
    return 0;
}

