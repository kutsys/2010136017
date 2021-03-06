#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREAD 10

typedef struct Info{
	int id;
	int seed;
	int repeat;
}Info;

struct Critical_info{
	int cur_num;
	int complete_thread;
};

struct Critical_info cinfo;
pthread_mutex_t cinfo_mutex;

void* test_funct(void *arg);

int main(char argc,char *argv[]){

	int i;
	int res;
	pthread_t thread_list[MAX_THREAD];
	Info info[MAX_THREAD];
	printf("2010136017 김덕균\n");
	srand(time(NULL));
	for(i=0; i<MAX_THREAD;i++){
		info[i].id=i+1;
		info[i].seed=rand();
		info[i].repeat=20;
		
		res = pthread_create(&thread_list[i],NULL,test_funct,(void *)&info[i]);
		if(res != 0){
			perror("Thread creation failed.\n");
			exit(EXIT_FAILURE);
		}

	}

	for(i=0;i<MAX_THREAD;i++){
		res = pthread_join(thread_list[i],NULL);
	}

	printf("Finished Successfully\n");

	return 0;
}


void* test_funct(void *arg){
	Info info =*(Info*)arg;
	struct tm *tm_ptr;
	time_t the_time;
	int cnt_repeat=0;

	srand(info.seed);
	
	while(cnt_repeat < info.repeat){
		if(cinfo.cur_num < cnt_repeat){
			usleep(rand()%400+100);
			continue;
		}

		(void)time(&the_time);	
		tm_ptr = localtime(&the_time);  
	
		printf("thread num : %2d , ",info.id);
		printf("cur time : %d/%d/%d %d:%d:%d , ",
				tm_ptr->tm_year+1900,tm_ptr->tm_mon+1,tm_ptr->tm_mday,
				tm_ptr->tm_hour,tm_ptr->tm_min,tm_ptr->tm_sec);
		printf("count : %d\n",++cnt_repeat);
		
		pthread_mutex_lock(&cinfo_mutex);
			cinfo.complete_thread++;
			if(cinfo.complete_thread == MAX_THREAD){
				cinfo.cur_num++;
				cinfo.complete_thread = 0;
			}
		pthread_mutex_unlock(&cinfo_mutex);
	
		if(cnt_repeat < info.repeat){
			sleep(rand()%10+1);
		}

	}
										
}

