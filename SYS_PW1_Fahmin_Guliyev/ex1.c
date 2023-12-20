#include<stdio.h>
#include<string.h>


int main(){

    FILE *fp;
    char  str[200];
    int sz = 200;


    fp = fopen("ex1.txt","r");
    if ( fp == NULL ){
        perror("Error opening the file");
        return -1;
    }

    if ( fgets (str,sz,fp) != NULL ){
        puts(str);
    }

    fclose(fp);

    printf("%s\n",str);
    printf("%ld - Length of the printed string\n",strlen(str));
    

    return 0;
}

