#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


int x = 0;

pthread_mutex_t key;

void sum(){
	for(int i = 1; i <= 100; i++){
		pthread_mutex_lock(&key);
		x = x + 1; // critical section
		printf("%d. After Sumition = %d\n",i,x);
		pthread_mutex_unlock(&key);
	}
	// return NULL;
}
void sub(){
	for(int i = 1; i <= 100; i++){
		pthread_mutex_lock(&key);	
		x = x - 1; // critical section
		printf("%d. After Subtraction = %d\n",i,x);
		pthread_mutex_unlock(&key);
	}
	// return NULL;
}

int main(){

	
	pthread_mutex_init(&key, NULL);
	
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL, (void *) sum, NULL);
	pthread_create(&tid2,NULL, (void *) sub, NULL);
	
	// wait termination of all threads before terminating main thread.
	
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	
	pthread_mutex_destroy(&key);
	
	printf("Main Thread will terminate now\n");
	exit(EXIT_SUCCESS);	
}
