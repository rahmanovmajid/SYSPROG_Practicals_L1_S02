#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>


int main(int argc,char *argv[]){

    
    pid_t p;

    printf("before fork() : pid = %d\n",getpid());
    printf("trying fork...\n");
    p = fork();

    switch(p){
        case -1:        // Error
            perror("cannot fork");
            exit(1);
            break;
        case 0:         //Child Case
            close(1);
            if ( open("/dev/null",O_WRONLY) != 1 ){
                perror("cannot open");
                exit(1);
            }
            execlp("ps", "ps", "eaux", NULL);
            perror("cannot exec");
            exit(1);
        default:        // Parent case
            if ( wait((int *) 0) != p ){
                perror("cannot wait child");
                exit(1);
            }
            // times(&buffer);
            // hz = sysconf(_SC_CLK_TCK);
             printf(" ");
            break;
    }

    
    return 0;
}