#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(){
    pid_t pid = fork();

    if(pid == -1){
        fprintf(stderr,"Fork Failed\n");
        return -1;
    }

    if(pid == 0){
        printf("Hello\n");
    }

    if(pid > 0){
        for(int i = 0; i < 100000; i++){
            int count = 0; count++;
        }
        printf("Goodbuy!!\n");
    }



    return 0;
}
