#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF_MAX 1024

void copy_file(char *src_file,unsigned short dot_cycle){
	FILE *in, *out;
    char block[BUF_MAX], output_file[BUF_MAX];
	int len, cnt_out=0;

	//복사할 파일명 만들기 원본파일명+_copy
	strcpy(output_file,src_file);
	strcat(output_file,"_copy");

	//읽기전용으로 파일읽기
	if ((in  = fopen(src_file, "rb")) == NULL){
		printf("%s 파일을 읽을 수 없습니다.\n",src_file);
		exit(0);
	}
	//쓰기전용으로 파일 읽기
	if ((out = fopen(output_file, "wb")) == NULL) {
		fclose(in); 
		printf("%s 파일을 생성할 수 없습니다.\n",output_file);
		exit(0);
	} 

	while ( (len = fread(block, sizeof(char), sizeof(block), in)) > 0 ){
	    if (fwrite(block, sizeof(char), len, out) == 0) {
			fclose(in); 
			fclose(out);
			unlink(output_file); //지금까지 만든 파일 삭제
			printf("용량이 부족합니다.\n");
			exit(0);
		}

		if(cnt_out++==dot_cycle){
			cnt_out=0;
			printf("*");
		}
	}

	fclose(in);
	fclose(out);
	puts("");
	puts("file copy complete");
}
int main(int argc, char** argv) {

	switch(argc){
		case 1:
			copy_file(argv[0],10);
			break;
		case 2:
			copy_file(argv[1],10);
			break;
		default :
			printf("인자가 너무 많습니다.\n");
			exit(0);
	}
	
}
