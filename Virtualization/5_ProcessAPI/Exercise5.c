#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main() {
    pid_t pid = fork();
    if(pid == -1) return 1;

    if(pid == 0){
        pid_t rc_wait = wait(NULL);
        printf("RC:WAIT %d , Current Process PID : %d\n",rc_wait, getpid());
    }

    if(pid > 0){
        printf("Parent: %d Child:%d\n", getpid(), pid);
    }


    return 0;
}
