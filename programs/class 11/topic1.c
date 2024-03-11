#define _GNU_SOURCE
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>
#include<sys/wait.h>
#include<pthread.h>


void get_cpu_info(char *processType ,char *threadType) {
	int coreID;
	for(int i = 0; i < 10; i++){
		coreID = sched_getcpu();
		printf("%s, %s -> Core ID: %d\n",threadType, processType, coreID);
	}
}
void sub_thread(char *processType){
	get_cpu_info(processType, "Subthread");	
}

int main(){
	pid_t childPID;
	childPID = fork();
	
	
	if(childPID < 0){ // Error
		printf("Process didn't created");	
	}
	else if(childPID == 0){ // child process
		pthread_t tid;
		pthread_create(&tid, NULL,(void *)sub_thread, "child");
		pthread_join(tid, NULL);

	}
	else{ // parent process
		pthread_t tid;
		pthread_create(&tid, NULL,(void *)sub_thread, "parent");
		pthread_join(tid, NULL);
		wait(NULL);
	}


	exit(EXIT_SUCCESS);
}
