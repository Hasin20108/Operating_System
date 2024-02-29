#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

   	mkfifo("myfifo1", 0666);
   	mkfifo("myfifo",0666);
   	
    printf("Named pipe created successfully\n");

    return 0;
}

