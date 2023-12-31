#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc ,char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int iRet = 0;

    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc!=3)
    {
        printf("INSUFFICIENT ARGUMENTS ....\n");
        return -1;
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("UNABLE TO OPEN FILE....\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest==-1)
    {
        printf("UNABLE TO CREATE FILE...\n");
        return -1;
    }

    while((iRet = read(fdSource,Buffer,sizeof(Buffer)))!=0)
    {
        write(fdDest,Buffer,iRet);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);

    return 0;
}