#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>


//Forking and telling each son to print it's pid and it's father's one
void daddySelfie(){
	pid_t pid;					// create pid
	pid = fork();				// creates a new process and gives the processs ID for 
								//pid in the father one and  0 to the just created one

	if(pid==0) {				// if pid==0, it is the process is the leaf of the tree
		printf("Hi, my ID is: %d, my father is the process with the ID: %d\n",getpid(), getppid()); //	getpid() return your pid, 
		pid = fork();																				//getppid() returns your parent process pid
		if(pid==0)
			printf("Hi, my ID is: %d, my father is the process with the ID: %d\n",getpid(), getppid());
	}
	printf("I'm the thread %d, my father is the process with the ID: %d\n",getpid(), getppid());

	wait(NULL); // parent process waits it's sons to die before it does. prevents getting wrong answers from getppid()
}

int main() {
	daddySelfie();

	return 0;
}