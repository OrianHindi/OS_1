#include <stdio.h>
#include <stdlib.h>
void imHERE(char* name) {
    for (int i = 0; i < 30; ++i) {
        printf("Im the %s process \n", name);
        usleep(300000);
    }
}

int main(){
    pid_t pid = fork();
    if(pid == 0){ //child is build
            imHERE("child");
    }
    else{
        imHERE("father");
    }
    return 0;
}