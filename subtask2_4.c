#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>
#include <sched.h>
char process_stack[10000+1];

void run (char * name){

    for (int i = 0; i < 30; ++i) {
        printf("Im the %s process \n",name);
        usleep(300000);
    }

}
int daemonRun(void* none){

    char*  args[]={"./subtask2.3",NULL};
    execvp(args[0],args);

}

int keepALive(void* none){
    char* args[]= {"./subtask2.2",NULL};
    execvp(args[0],args);
}


int main(){
    pid_t pid = fork();
    printf("pid is: %d",pid);
    if(pid==0) {  //child process
        char* args[] = {"./subtask2.1",NULL};
        int result = clone(keepALive,process_stack+10000, CLONE_PARENT,0);
        execvp(args[0],args);
    }

    else{
        int result2= clone(daemonRun,process_stack+10000,CLONE_PARENT,0);
        run("father");
    }
//printf("%d , %d , %d",stdin,stdout,stderr);
    return 0;
}