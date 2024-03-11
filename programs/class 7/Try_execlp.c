#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	
	
	execlp("./helloworld", "hasinaa", NULL);
	
	printf("hasin");

    //perror("execlp");
    return 1;
}

