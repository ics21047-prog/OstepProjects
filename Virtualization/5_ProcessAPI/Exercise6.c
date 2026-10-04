#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){


    pid_t parent_pid = getpid();
    pid_t child_pid = fork();

    if(child_pid == -1) return 1;
    

    if(child_pid  == 0){
        int returnint = waitpid(parent_pid,NULL,0);
        printf("This is the child!!! Return from wait: %d\n",returnint);
        printf("Childs pid: %d\n",getpid());
    }

    if(child_pid  > 0){
        printf("This is the parent process!!The pid is %d\n",getpid());
    }

    return 0;
}
