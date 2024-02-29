#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>



void *writet(void *arg) {
    int fd;
    char message[1024];


    fd = open("myfifo", O_WRONLY);

    while (1) {
        // printf("Person 1: ");
        fgets(message, 1024, stdin);

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
    char message[1024];

    fd = open("myfifo1", O_RDONLY);

    while (1) {
        ssize_t reader = read(fd, message, 1024);
        
        message[reader] = '\0';
		
        printf("Siddik: %s", message);

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

