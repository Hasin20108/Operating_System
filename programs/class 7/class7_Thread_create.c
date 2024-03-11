#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
// Thread creation
int p = 100;

//int x = 10, y = 5;
int sum (){
	int x = 10, y = 5;
	//printf("x + y = %d\n",x+y);
	for(int i = 0; i < 100; i++){
		printf("x + y = %d   ",x+y); 
		printf("%d. sumission\n",i);
	}
}

int sub (){
	int x = 10, y = 5;
	//printf("x - y = %d\n",x-y);
	for(int i = 0; i < 100; i++){
		printf("x - y = %d ",x-y);
		printf("%d. subtraction\n",i);
	}
}

int main(){
	//sum();
	//sub();
	
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL, (void *)sum, NULL);
	pthread_create(&t2,NULL, (void *)sub, NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	exit(EXIT_SUCCESS);
}
