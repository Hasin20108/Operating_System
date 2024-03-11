#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main() {
    const char *pipeName = "myfifo";
    int fd;
    ssize_t reader;
    char msg[1024];


    fd = open(pipeName, O_RDONLY);

    //reader = read(fd, msg, sizeof(msg));

	while ((reader = read(STDIN_FILENO, msg, sizeof(msg))) > 0) {
		if(msg == "bye"){
			break;
		}
    	msg[reader] = '\0';
		printf("%s\n", msg);
		
	}
    close(fd);




    //printf("Data read from named pipe: %s\n", msg);

    return 0;
}

