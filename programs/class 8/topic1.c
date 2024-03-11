#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
	// declare local variable
	char *msg;
	char buffer[100];
	int n,c;
	
	// write to standard output device (i.e., monitor)
	msg = "Insert a number: ";
	write(STDOUT_FILENO, msg, strlen(msg) +1);
	
	// read standard input (i.e., keyboard)
	n = read(STDIN_FILENO,	 &buffer, sizeof(buffer));
	buffer[n] = '\0';
	write (STDOUT_FILENO,buffer,strlen(buffer));
	
	return 0;
}
