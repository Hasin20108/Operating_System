#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

// Thread creation


int main(){
	pid_t newP;
	newP = fork();
	
	if(newP == 0){
		for(int i = 0; i < 100; i++){
			printf("%d. child\n",i);
		}
	}else {
		printf("waiting vai =======================\n");
		wait();
		for(int i = 200; i < 300; i++){
			printf("%d. Parent\n",i);
		}
			
	}
	
	return 0;
}
