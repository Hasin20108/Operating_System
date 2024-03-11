#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int fd; // File descriptor
    ssize_t written,reading;
	char data[BUFFER_SIZE];
	
	
    // Open or create a file for writing
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write data to the file
  
    reading = read(STDIN_FILENO, data, BUFFER_SIZE);
    written = write(fd, data, strlen(data));
    if (written == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file
    close(fd);

    printf("Data written to file successfully.\n");

    return 0;
}

