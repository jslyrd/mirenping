#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
void my_daemond(void)
{
    pid_t pid=fork();
    if(pid>0)//如果是父进程则退出
    {
        exit(1);
    }
    //在子进程中创建新的会话,使子进程完全独立出来，脱离控制
    setsid();
    if(chdir("/")<0)
    {
        perror("chdir");
         exit(1);     
    }

    umask(0022);

   close(STDIN_FILENO);
    open("/dev/null",O_RDWR);
    dup2(0,STDOUT_FILENO);
    dup2(0,STDERR_FILENO);
    
}


int main(int argc,char * argv[])
{
   my_daemond();
  
   /*
    time_t now;
    struct tm *timenow;
    time(&now);
    timenow=localtime(&now);
    printf("Local time is %s\n",asctime(timenow));
    */
    
    //在此循环中可以实现守护进程的核心工作
        while(1)
        {
            sleep(2000);

        }
        
        return 0;


}
