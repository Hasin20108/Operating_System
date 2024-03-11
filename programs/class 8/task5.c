#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



int main() {
    const char *pipeName = "myfifo";
    int fd; 
    ssize_t writter,reader;
    char msg[1024];


    fd = open(pipeName, O_WRONLY);


	while ((reader = read(STDIN_FILENO, msg, sizeof(msg))) > 0) {
		if(msg == "bye"){
			break;
		}
    	writter = write(fd, msg, strlen(msg));
	}


    close(fd);

    printf("Data written to named pipe successfully.\n");

    return 0;
}

