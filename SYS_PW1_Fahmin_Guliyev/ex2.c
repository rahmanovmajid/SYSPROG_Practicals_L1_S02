#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct SMonth{
    char name[9 + 1] ;     /* name */
    int days;              /* number of days in the month */
};


int main(){


    struct SMonth Months[12] =  {  {"January",31},{"February",28},
    {"March",31},{"April",30},{"May",31},
    {"June",30},{"July",31},{"August",31},
    {"September",30},{"October",31},{"November",30},
    {"December",31}   };
    

    FILE *fp;
    char myString[10];
    int nStr = 10;
    int c = 0;

    fp = fopen("ex2.txt","r");


    if ( fp == NULL ){
        perror("Error opening the file ");
        return -1;
    }
        fgets(myString,nStr,fp);

        for ( int i = 0 ; i < 12 ; i++ ){
            if ( strcmp(myString,Months[i].name)==0 ){
                printf("%s is  %d-th month\n",Months[i].name,i+1);
                printf("and %s has %d days.\n",Months[i].name,Months[i].days);
                c++;
            }
        }

        if ( c == 0 )    printf("Invalid month\n");

        return 0;
    
}