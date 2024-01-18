#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]){
    char* msg = "wrong arguements.\r\n";
    if (argc <= 1)  { write(1,msg,20); exit(1);}
    
    int seconds = atoi(argv[1]);
    sleep(seconds);
    exit(0);
}