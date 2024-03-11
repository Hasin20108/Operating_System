#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    int pipefd[2]; // File descriptors for the pipe
    ssize_t bytes_written;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Write data to the pipe
    const char* data = "Hello, Pipe!";
    bytes_written = write(pipefd[1], data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to pipe");
        close(pipefd[0]);
        close(pipefd[1]);
        exit(EXIT_FAILURE);
    }

    printf("Data written to pipe successfully.\n");

    // Close the pipe
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

