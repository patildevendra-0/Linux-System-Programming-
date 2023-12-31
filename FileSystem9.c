#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc ,char *argv[])
{
    int fd = 0;
    int Mode = 0;

    printf("USAGE: Name_Executable Name_File  Mode_Of_Open \n");

    if(argc!=3)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    if(strcmp(argv[2],"Read")==0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        Mode = O_RDONLY;
    }

    fd = open(argv[1],Mode);
    
    if(fd == -1)
    {
        printf("UNABLE TO OPEN FILE....\n");
        return -1;
    }
    else
    {
        printf("FILE IS SUCCESSFULLY OPEN WITH FD- %d AND MODE-%d \n",fd,Mode);
    }


    return 0 ;
}