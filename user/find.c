#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"


int find(char* path,char* filename){
    int fd;
    struct dirent de;
    struct stat st;
    fd = open(path,0);

    if(fstat(fd. &st) < 0){
        fprintf(2,"find cannot stat current dir.\n");
        close(fd);
        return 0;
    }

    switch (st.type)
    {
    case T_FILE:
        
        break;
    
    default:
        break;
    }

    
}

int main(int argc, char const *argv[])
{


    exit(0);
}
