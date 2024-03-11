#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include<semaphore.h>

#define SHM_NAME "/my_shared_memory"
#define BUFFER_SIZE sizeof(int)

int main() {
    int shm_fd;
    int *shm_ptr;
    sem_t key;

    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, BUFFER_SIZE) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object into the address space of the process
    shm_ptr = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Initialize the shared variable
    *shm_ptr = 0;

    // Fork a child process for increment
    
    sem_init(&key, 0,1);
    pid_t increment_pid = fork();
    if (increment_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (increment_pid == 0) {
        // Child process (increment)
        for (int i = 1; i <= 100; i++) {
        	sem_wait(&key);
            (*shm_ptr)++;
            printf("%d. Increment %d\n", i,*shm_ptr);
            sem_post(&key);
            //sleep(1); // Simulate some work
        }
        exit(EXIT_SUCCESS);
    }
	else{
        // Child process (decrement)
        for (int i = 1; i <= 100; i++) {
        	sem_wait(&key);
            (*shm_ptr)--;
            printf("%d. Decrement %d\n",i, *shm_ptr);
            sem_post(&key);
            //sleep(1); // Simulate some work
        }
        exit(EXIT_SUCCESS);
    }

    // Wait for both child processes to finish
    wait(NULL);
    wait(NULL);

	sem_destroy(&key);
    // Unmap the shared memory
    if (munmap(shm_ptr, BUFFER_SIZE) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    if (close(shm_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }


    if (shm_unlink(SHM_NAME) == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}

