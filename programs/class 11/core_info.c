#define _GNU_SOURCE
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<sys/wait.h>
#include<pthread.h>


void get_cpu_info(char *threadType) {
	int coreID;
	coreID = sched_getcpu();
	
	printf("ProcessId = %d   Core ID: %d   thread = %s\n",getpid(),coreID,threadType);
}

void sub_thread1(){
	get_cpu_info("Subthread1");	
}

void sub_thread2(){
	get_cpu_info("Subthread2");	
}

int main(){
	int coreID;
	pid_t prodhan;
	
	prodhan = getpid();
	fork();
	fork();
	fork();
	fork();
	
	if(prodhan == getpid()){
		wait(NULL);
	}else{
		//cpu_set_t cpuset;
    	//CPU_ZERO(&cpuset);
    	//CPU_SET(0, &cpuset);
    	//sched_setaffinity(0, sizeof(cpuset), &cpuset);

		pthread_t tid1,tid2;
		
		pthread_create(&tid1, NULL,(void *)sub_thread1, NULL);
		pthread_create(&tid2, NULL,(void *)sub_thread2, NULL);
		
		pthread_join(tid1, NULL);
		pthread_join(tid2,NULL);
	}
	// printf("hello Hasin\n");
	exit(EXIT_SUCCESS);
}
