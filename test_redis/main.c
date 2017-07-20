#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"redis_op.h"

int main()
{
    redisContext *conn=rop_connectdb("192.168.79.146","6379","mirenping");
    if(conn==NULL)
    {
        printf("connection error");
        return -1;
    }
    printf("connection success");
    rop_disconnect(conn);
    return 0;
}
