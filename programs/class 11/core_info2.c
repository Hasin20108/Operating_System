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
	int cores = sysconf(_SC_NPROCESSORS_ONLN);
	printf("Cores = %d\n",cores);
	exit(EXIT_SUCCESS);
}
