#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>


#define n 1024


void *writet(void *arg) {
    int fd;
    char message[n];


    fd = open("myfifo1", O_WRONLY);

    while (1) {
        // printf("Person 1: ");
        fgets(message, n, stdin);

        write(fd, message, strlen(message));

        if (strncmp(message, "bye", 3) == 0) {
            break;
        }
    }

    close(fd);

    return NULL;
}

void *readt(void *arg) {
    int fd;
    char message[n];

    fd = open("myfifo", O_RDONLY);

    while (1) {
        ssize_t reader = read(fd, message, n);
        
        message[reader] = '\0';

        printf("Hasin: %s", message);

        if (strncmp(message, "bye", 3) == 0) {
            break;
        }
    }

    close(fd);

    return NULL;
}

int main() {
    pthread_t writer, reader;

    pthread_create(&writer, NULL, writet, NULL);
    pthread_create(&reader, NULL, readt, NULL);

    pthread_join(writer, NULL);
    pthread_join(reader, NULL);

    return 0;
}

