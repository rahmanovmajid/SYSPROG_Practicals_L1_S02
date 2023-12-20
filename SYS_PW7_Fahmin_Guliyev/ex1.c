#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>



int main(){


    pid_t p;
    int status;

    p = fork();

    if ( p == 0 ){  //enters as child p
        printf("I am the child process of pid: %d\tand my parent pid is: %d\n",getpid(),getppid());
        exit(getpid()%10);
    }
    else{ //enters as parent
        printf("I am the parent process and pid of my child is: %d\n",p);
        wait(&status);
    
        printf("The return code of terminating code of the child process is: %d\n",WEXITSTATUS(status));
    }




    return 0;
}