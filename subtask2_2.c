#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
char process_stack[10000+1];

void run (char* name){
    for (int i = 0; i <30 ; ++i) {
        printf("Im the %s process \n",name);
        usleep(1000000);
    }
}
int keepAlive1(){
    run("Second");
}
int keepAlive(){
    run("Third");
}

int main(){
    int result = clone(keepAlive1,process_stack+10000,CLONE_PARENT,0);
//    printf("first clone result: %d",result);
   int result2 = clone(keepAlive,process_stack+10000,CLONE_PARENT,0);
  //  printf("first clone result: %d",result2);
    run("First");


    return 0;
}

