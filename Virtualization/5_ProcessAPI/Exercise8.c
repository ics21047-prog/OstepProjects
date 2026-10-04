#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define SIZE 26

int main(){
    int p[2];
    if(pipe(p) < 0) exit(1);

    pid_t rc1 = fork();

    if(rc1 < 0){
        perror("Failed the First fork!!\n");
        return EXIT_FAILURE;
    }

    if(rc1 == 0){
        char buffer[SIZE];
        printf("This is the First Child : %d\n",getpid());
        read(p[0],buffer,SIZE);
        printf("%s\n",buffer);
        return 0;
    }

    pid_t rc2 = fork();

    if(rc2 < 0){
        perror("Failed the Second fork!!\n");
        return EXIT_FAILURE;
    }

    if(rc2 == 0){
        write(p[1],"Hello from Child 2 to 1",SIZE);
        return 0;
    }

    return 0;
}
