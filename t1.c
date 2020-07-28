#include "types.h"
#include "stat.h"
#include "user.h"
int main()
{
    // #ifdef PBS
    //     printf(1,"PBS\n\a");
    // #elif FCFS 
    //     printf(1,"FCFS\n");
    // #elif MLFQ
    //     printf(1,"MLFQ\n");
    // #endif
    int w,r,ret,p[10];
    //if(fork()==0)
     //{
        for(int i=0;i<5;i++)
        {
            p[i]=fork();
            if(p[i]==0)
            {
                for(int i=0;i<=100000000;i++)
                    printf(1,"");
                // sleep(1000);
                // exec(argv[1],argv);
                exit();
            }
        }
        for(int i=0;i<5;i++)
        {
            printf(1,"proc %d.... pid %d \n",i,p[i]);
            /*printf(1," %d\n",getpriority(p[i]));*/
            setpriority(p[i],64-i);
            /*printf(1," %d\n",getpriority(p[i]));*/
        }
        for(int i=0; i<5;i++)
        {
            ret=waitx(&w,&r);
            printf(1,"pid-%d rtime-%d wtime-%d\n",ret,r,w);
        }
        exit();
    // }
    // ret=waitx(&w,&r);
    // printf(1,"parent proc:- pid-%d rtime-%d wtime-%d\n",ret,w,r);
    // exit();
}
