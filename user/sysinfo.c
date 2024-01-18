#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/sysinfo.h"

int main(int argc,char* argv[]){
    struct sysinfo sinfo;
    if(sysinfo((&sinfo))){
        printf("sysinfo failed\n");
        exit(0);
    }
    printf("free memory: %x\n running process: %x\n",sinfo.freemem,sinfo.nproc);
    exit(0);

}