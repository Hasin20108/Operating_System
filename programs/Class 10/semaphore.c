#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>



int x = 0;

sem_t key;

int sum(){
	for(int i = 1; i <= 100; i++){
		sem_wait(&key);
		x = x + 1; // critical section
		printf("%d. After Sumition = %d\n",i,x);
		sem_post(&key);
	}
	// return NULL;
}
int sub(){
	for(int i = 1; i <= 100; i++){
		sem_wait(&key);	
		x = x - 1; // critical section
		printf("%d. After Subtraction = %d\n",i,x);
		sem_post(&key);
	}
	// return NULL;
}

int main(){
	// Following funitons are conventionla functions 
	// sum();
	// sub();
	// Initialize mutex before using 
	sem_init(&key, 0,1);
	
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL, (void *) sum, NULL);
	pthread_create(&tid2,NULL, (void *) sub, NULL);
	
	// wait termination of all threads before terminating main thread.
	
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	sem_destroy(&key);
	
	printf("Main Thread will terminate now\n");
	// Exit Successful
	exit(EXIT_SUCCESS);	
}
