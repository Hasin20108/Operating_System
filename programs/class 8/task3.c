#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo1";

    // Create a named pipe (FIFO)
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("Error creating named pipe");
        exit(EXIT_FAILURE);
    }

    printf("Named pipe created successfully: %s\n", fifo_name);

    return 0;
}

