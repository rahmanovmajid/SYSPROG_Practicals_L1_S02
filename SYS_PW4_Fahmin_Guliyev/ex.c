#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

#define F_R 1
#define F_W 2

struct MYFILE{

    int flags;      //  (rwx...)
    int fd;         // file descriptor
    int r;          //  space available in the buffer
    unsigned char buf[4];  //  the buffer
    unsigned char *p;       //  a pointer to the current location in the buffer

};


// int open(char *path,int flag);
// int close(int fd);
// int read(int fd,void *buf,int size);
// int write(int fd,void *buf,int size);



//! FUNCTIONS START
struct MYFILE *myopen(char *file,char *mode){
    struct MYFILE *fi;
    int m;
    int f;
    int fd;
    switch(mode[0]){
        case 'r':
            m = O_RDONLY;
            f = F_R;
            break;
        case 'w':
            m = O_WRONLY;
            f = F_W;
            break;
        default:
            return 0;
            break;
    }

    fd = open(file,m);
    if ( fd == -1 ) return 0;
    fi = (struct MYFILE*) malloc(sizeof(*fi)); // ? bu nedi?
    if ( fi == NULL )   return 0;

    fi->flags = f;
    fi->fd = fd;
    fi->r = 0;

    fi->p = fi->buf;

    return fi;
}



int my_getc(struct MYFILE *f){
    if ( f->flags != F_R )  return 0;
    if ( f->r <= 0 ){
        f->r = read(f->fd,f->buf,256);
        f->p = f->buf;
    }
    if ( f->r <= 0 ){
        return 0;
    }
    else{
        int v = *(f->p);
        f->p++;
        f->r--;
        return v;
    }
}

int my_putc(struct MYFILE *f){

    if ( f->flags != F_W )  return 0;


}