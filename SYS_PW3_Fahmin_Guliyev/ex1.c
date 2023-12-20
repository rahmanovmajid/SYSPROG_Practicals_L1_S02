#include<stdio.h>
#include<string.h>


int main(){


    FILE *pCopy = fopen("foo.txt","r");
    if ( pCopy == NULL ){
        printf("File couldn't be opened.\n");
        return -1;
    }
    FILE *pPaste = fopen("bar.txt","w");






    return 0;
}