#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <sched.h>
char process_stack[10000+1];



void run(char* name){    //function that keep alive the thread
    for(int i=0;i<2000000;i++){
        printf("%s Thread is working\n",name);
        usleep(30000);
    }
}

void daemonWork(){     //function that keep alive the daemon thread.
    for(int i =0;i<20000000;i++) {
        syslog(LOG_NOTICE, "Daemon is working");
        usleep(30000);
    }
}
int keepAlive(){
    run("second");
}

int main(){
   int result = clone(keepAlive,process_stack+1000,CLONE_PARENT,0);
   if(result){
       printf("clone result: %d",result);
   }
   else{
       run("first");
   }

    return 0;
}