#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

    char myString[] = "Salam qardashim \tbugun 43 yashin olur lap yaxshi brat\n";

    for ( int i = 0 ; i < strlen(myString) ; i++ ){
        if ( myString[i] > 32 && myString[i] < 126 ){
            
        }
    }

    return 0;
}