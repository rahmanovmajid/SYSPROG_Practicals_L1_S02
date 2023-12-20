#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include"color.h"



int main(int argc,char *argv[]){

    int conditionchecker = 1;
    char buffer;
    int status;
    int fd = open(argv[1],O_RDONLY);

    pid_t p;
    p = fork();

    while ( conditionchecker > 0 ){
        if ( p == -1 ){
            printf("Error duplicating the process.\n");
        }
        else if ( p == 0 ){
            //child
            conditionchecker = read(fd,&buffer,1);
            write(1,&buffer,1);
        }
        else{
            //parent
            conditionchecker = read(fd,&buffer,1);
            write(1,&buffer,1);
            wait(&status);
        }
    }
    return 0;
}