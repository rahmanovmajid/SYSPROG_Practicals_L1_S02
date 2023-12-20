#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include"color.h"


void lire_fichier(int desc,int desc2){
    char c;

    while ( read(desc,&c,sizeof(char)) > 0 ){
        write(desc2,&c,sizeof(char));
        printf("je suis le proc %d et j'ai lu le car: %c\n",getpid(),c);
        //experience interessant, ajouter ici
        sleep(1);
    }
}

int main(int argc,char *argv[]){
    pid_t pid;
    int desc,desc2;


    if ( argc < 2 ){
        printf("usage: %s filename\n",argv[0]);
        exit(1);
    }

    if ( (desc = open(argv[1], O_RDONLY)) < 0 ){
        perror("open error");
        exit(2);
    }


    pid = fork();
    switch (pid){
        case -1:
            perror("erreur");
            break;
        case 0:
            printf(FG_BLUE "processus fils: %d (mon pere est : %d)\n" NOCOLOR,getpid(),getppid());
            lire_fichier(desc,desc2);
            break;
        default:
            printf(FG_GREEN "processus pere: %d\n" NOCOLOR, getpid());
            lire_fichier(desc,desc2);
            break;
    }

    printf("fin: %d\n",getpid());
    return 0;
}