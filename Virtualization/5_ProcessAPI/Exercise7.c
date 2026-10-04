#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){


    pid_t parent_pid = getpid();
    pid_t child_pid = fork();

    if(child_pid == -1) return 1;
    

    if(child_pid  == 0){
        close(STDOUT_FILENO);
        printf("This is the child process PID : %d\n",getpid());
        if (fflush(stdout) == EOF)
            perror("Child: stdout write failed");            
    }

    if(child_pid  > 0){
        printf("This is the parent process!!The pid is %d\n",getpid());
    }

    return 0;
}
