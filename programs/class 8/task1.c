#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;


    bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    return 0;
}

