#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>



int main(){
    close(STDOUT_FILENO);
    int file = open("./somefile.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Failed to Fork\n");
    }else if(rc == 0) {
        printf("This is from the child\n");
    }else{
        printf("This is from the Parent\n");
    }
    close(file);

    return 0;
}
