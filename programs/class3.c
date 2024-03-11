#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, ppid;
    
    pid = getpid();
    printf("My PID is: %d\n", pid);

    ppid = getppid();
    printf("My parent's PID is: %d\n", ppid);

    return 0;
}

