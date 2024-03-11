#include<unistd.h>
#include<stdio.h>

int main(){
	pid_t cPID,myPID,parentPID;
	int x = 5;
	cPID = fork();
	
	myPID = getpid();
	parentPID = getppid();
	// printf("x = %d\n", x);
	// for(int j = 0; j < 5; j++){
	if(cPID == 0){
		myPID = getpid();
		for(int i = 0; i < 200; i++){
			x = x+i;
			printf("child %d: i = %d  x = %d\n",myPID,i, x);
		}
		
	}else {

		for(int i = 0; i < 200; i++){
			x = x+20+i;
			printf("parent %d: i = %d  x = %d\n",myPID,i, x);
		}
		
		printf("================================   end of parent id   ==============================\n");
	}
	// }
	
	return 0;
	
}
