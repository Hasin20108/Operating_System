#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    
    
    char *pipePath = "/home/hasin/Desktop/CSE3241_2024/programs/class 8";
    int pipeFlag;
    pipeFlag = mkfifo(pipePath,0666);
    
    printf("%d\n",pipeFlag);
    return 0;
    
}

