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
        pid_t pid =fork();
        if(pid == 0){
            imHERE("grandChild"); //grandchild
        }
        else {
            imHERE("child");
        }
    }
    else{
        imHERE("father");
    }
    return 0;
}