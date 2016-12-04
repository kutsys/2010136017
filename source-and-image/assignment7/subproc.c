#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


void test_funct(){
	static int cnt_repeat = 0;
	
	struct tm *tm_ptr;
	time_t the_time;

	(void)time(&the_time);
	tm_ptr = localtime(&the_time);

	printf("PID : %d , ",getpid());

	printf("cur time : %d/%d/%d %d:%d:%d , ",
			tm_ptr->tm_year+1900,tm_ptr->tm_mon+1,tm_ptr->tm_mday,
				tm_ptr->tm_hour,tm_ptr->tm_min,tm_ptr->tm_sec);
	printf("count : %d\n",++cnt_repeat);
}


int main(char argc,char *argv[]){
	int cnt_repeat;
	int i;

	if(argc <=1 ){
		printf("The repeat count parameter is required.\n");
		exit(1);
	}else if(argc >2){
		printf("Too many parameters.\n");
		exit(1);
	}else{
		cnt_repeat = atoi(argv[1]);
		if(cnt_repeat <1){
			printf("Invalid parameter.\n");
			exit(1);
		}
	}
	
	srand(getpid());
	for(i=0;i<cnt_repeat-1;i++){
		test_funct();
		sleep(rand()%10+1);
	}
	test_funct();

	return 0;
}
