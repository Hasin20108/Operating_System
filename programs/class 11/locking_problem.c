#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Shared resource (a simple counter)
int sharedResource = 0;

// Mutex for protecting the shared resource
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function executed by the threads
void* fooAPI(void* param) {
    // Acquire the mutex lock
    pthread_mutex_lock(&mutex);

    // Critical section: Modify the shared resource
    printf("Changing the shared resource now.\n");
    sharedResource = 42;

    // Release the mutex lock
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t thread;

    // Lock the mutex (not necessary in this example, just for demonstration)
    pthread_mutex_lock(&mutex);

    // Create a new thread that executes fooAPI
    pthread_create(&thread, NULL, fooAPI, NULL);

    // Sleep for a while to allow the thread to run
    sleep(1);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Now we need to lock again to read the shared resource
    pthread_mutex_lock(&mutex);
    printf("Shared resource value: %d\n", sharedResource);
    pthread_mutex_unlock(&mutex);

    // Clean up and exit
    pthread_mutex_destroy(&mutex);

    return 0;
}

