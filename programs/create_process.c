#include<unistd.h>
#include<stdio.h>

void main(){

	pid_t cPID,myPID,parentPID;
	int x = 5;
	int y = 10;
	cPID = fork();
	
	myPID = getpid();
	parentPID = getppid();
	
	if(cPID == 0){
		for(int i = 0;; i++){
			printf("Child = %d",i);
		}
	
	
	}else {

		for(int i = 0; i < 2000000; i++){
			printf("Parent = %d\n",i);
		}

		printf("Terminate Paaaareeenttttt\n\n\n");
		
		
	}
	

	printf("\n");
	
}
