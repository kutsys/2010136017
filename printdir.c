#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir, int depth) {
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "cannot open directory : %s\n", dir);
		return;
	}
	//현재 프로세스의 작업 경로를 dir로 변경
	chdir(dir);
	//입력받은 디렉토리의 내용이 끝날때까지 반복
	while ((entry = readdir(dp)) != NULL) {
		//읽은 엔트리의 상태를 확인하는 함수
		lstat(entry->d_name, &statbuf);
		//해당 엔트리가 디렉토리도 아니고 히든파일도 아닐경우 출력
		if (!S_ISDIR(statbuf.st_mode) && entry->d_name[0] !='.') {
			printf("%s\n",entry->d_name);
		}
	}
	closedir(dp);
}
int main() {
	printf("Directory scan of ./:\n");
	printdir("./", 0);
	printf("done.\n");
	exit(0);
}
