#include <stdio.h>
#include <stdlib.h>

int main(char argc, char* argv[])
{	
	char* envList[] = {"HOME", "PS1", "PATH", "LD_LIBRARY_PATH","TEST_ENV"};
	int envCnt = sizeof(envList) / sizeof(char*);
	int i;

	for(i=0; i<envCnt; ++i){
		printf("$%s : %s\n", envList[i], getenv(envList[i]));
	}

	printf("TEST_ENV 환경 변수 셋팅 \n");
	if(setenv("TEST_ENV","1234",1)==-1){
		printf("환경 변수 셋팅에 실패하였습니다.\n");
	}else{
		printf("TEST_ENV 환경변수 셋팅 성공\n 현 프로세스에서만 유효\n");
	}
	printf("$TEST_ENV : %s\n",getenv("TEST_ENV"));


	return 0;
}
