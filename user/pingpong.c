#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char const *argv[])
{
    int p1[2],p2[2];
    int pid;
    char* buf[20] = {0};
    pipe(p1);
    pipe(p2);
    pid = fork();
    if(pid == -1){
        printf("fork failed");
        exit(0);
    }
    if(pid == 0){
        close(p2[1]);
        close(p1[0]);
        write(p1[1],"aaaa",4);
        read(p2[0],buf,sizeof(buf));
        printf("%d: received ping\n",getpid());
        sleep(1);
        exit(0);
    }
    else{
        close(p2[0]);
        close(p1[1]);
        write(p2[1],"bbbb",4);
        wait(0);
        read(p1[0],buf,sizeof(buf));
        printf("%d: received pong\n",getpid());
        sleep(1);
        exit(0);
    }
    
}
