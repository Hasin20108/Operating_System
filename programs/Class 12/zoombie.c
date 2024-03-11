#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        printf("Child process turned off\n");
        exit(EXIT_SUCCESS);
    } else {
        sleep(100);    
        printf("Parent process exiting\n");
    }

    return 0;
}

