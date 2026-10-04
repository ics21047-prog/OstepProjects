#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>



int main(){

    pid_t pid = fork(); 

    if(pid == -1){
        perror("Fork Failed");
        return -1;
    }

    if(pid == 0){
        char *myargs[2];
        myargs[0] = "ls";
        myargs[1] = NULL;
        execvp(myargs[0], myargs);
    }


    return 0;
}
