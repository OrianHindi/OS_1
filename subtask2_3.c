#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>

void run (){
    for (int i = 0; i <30 ; ++i) {
        syslog(LOG_NOTICE,"Daemon is working");
        usleep(30000);
    }
}

int main(){
    pid_t pid = fork();
    if(pid==0){
        chdir("/"); //change daemon dir.

        setsid();  //change daemon session

        close(stdin);   //close input.
        close(stdout);  //close output.
        close(stderr);  //close errors.

        openlog("myDaemon",LOG_PID,LOG_DAEMON);

        syslog(LOG_NOTICE,"daemon is starting"); //print daemon start
        usleep(3000);
        run();
    }
    else{
        printf("daemon PID:%d",pid);
    }

    return 0;
}
