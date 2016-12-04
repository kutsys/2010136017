#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_PROCESS 10

int main(char argc,char *argv[]){
	
	int arr_pid[MAX_PROCESS]={0};
	pid_t new_pid;

	int i;
	int stat;

	printf("2010136017 김덕균\n");
	for(i=0;i<MAX_PROCESS;i++){
		new_pid = fork();

		switch(new_pid){
			case -1:
				printf("fork failure.\n");
				exit(1);
			case 0:
				execl("./subproc","subproc","20",NULL);
				break;
			default:
				arr_pid[i]=new_pid;
		}
	}

	for(i=0;i<MAX_PROCESS;i++){
		//printf("%d ", wait(&stat));
		wait(&stat);
	}
	printf("Finished (process)\n");


	return 0;
}
