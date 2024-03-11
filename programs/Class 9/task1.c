#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 1024

void *writer_thread(void *arg) {
    int fd;
    char message[BUFFER_SIZE];

    // Open the named pipe (FIFO) for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Error opening named pipe for writing");
        exit(EXIT_FAILURE);
    }

    // Write to the named pipe multiple times consecutively
    for (int i = 1; i <= 5; i++) {
        sprintf(message, "Message from Writer Thread %d", i);
        if (write(fd, message, strlen(message)) == -1) {
            perror("Error writing to named pipe");
            close(fd);
            exit(EXIT_FAILURE);
        }
        sleep(1); // Sleep for 1 second between writes
    }

    // Close the named pipe
    close(fd);

    return NULL;
}

void *reader_thread(void *arg) {
    int fd;
    char message[BUFFER_SIZE];

    // Open the named pipe (FIFO) for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening named pipe for reading");
        exit(EXIT_FAILURE);
    }

    // Read from the named pipe multiple times consecutively
    ssize_t bytes_read;
    while ((bytes_read = read(fd, message, BUFFER_SIZE)) > 0) {
        message[bytes_read] = '\0'; // Null-terminate the read data
        printf("Reader Thread: Read data: %s\n", message);
    }

    if (bytes_read == -1) {
        perror("Error reading from named pipe");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the named pipe
    close(fd);

    return NULL;
}

int main() {
    pthread_t writer_tid, reader_tid;

    // Create writer and reader threads
    if (pthread_create(&writer_tid, NULL, writer_thread, NULL) != 0) {
        perror("Error creating writer thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&reader_tid, NULL, reader_thread, NULL) != 0) {
        perror("Error creating reader thread");
        exit(EXIT_FAILURE);
    }

    // Wait for the threads to finish
    pthread_join(writer_tid, NULL);
    pthread_join(reader_tid, NULL);

    return 0;
}

