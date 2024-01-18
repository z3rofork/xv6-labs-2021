#include "kernel/types.h"
#include "user/user.h"



int isPrime(int k){
    if(k == 0)  return 0;  
    if(k == 1)  return 0;
    for(int i=2;i<k;i++){
        if(k%i==0){
            return 0;
        }
    }
    return 1;
}

int pipeline(int count){
    //int p_pid = getpid();
    int p1[2],p2[2];
    pipe(p1);
    pipe(p2);
    write(p1[1],(char *)&count,sizeof(count));

    if(fork() == 0){
        close(p1[1]);
        close(p2[0]);
        read(p1[0],(char *)&count,sizeof(count));
        write(p2[1],(char *)&count,sizeof(count));
        printf("prime %d\n",count);
        exit(0);
    }
    else{
        close(p1[0]);
        close(p2[1]);   
        wait(0);
    }
    return 0;
}

int main(int argc, char const *argv[])
{   
    int count =0;
    for(;count<500;count++){
        if(isPrime(count)){
            //printf("%d is prime\n",count);
            pipeline(count);
        }
    }
    
    exit(0);
}


