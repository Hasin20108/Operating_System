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
    int id;
    int *x;
    sem_t key;

    id = shm_open(SHM_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(shm_fd, BUFFER_SIZE) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    x = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, id, 0);
    
    if (x == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
}
