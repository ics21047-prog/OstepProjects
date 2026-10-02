#include <stdio.h>
#include <unistd.h>


int main(){

    static int x = 100;
    
    pid_t rc = fork();
    if(rc < 0){
        printf("Something went wrong\n");
    }else if(rc == 0){
        x = 200;
        printf("Child Process Value X = %d\n",x);
    }else{
        x = 150;
        printf("Parent Process Value X = %d\n",x);
    }

    printf("Final Value of X: %d\n", x);


    return 0;
}
