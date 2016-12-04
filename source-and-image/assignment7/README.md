Lab-7 : Multi-processing
1. 아래와 같은 subproc 프로그램을 작성한다. 
- “test_funct()” 함수를 반복적으로 호출한다. 
- test_funct()함수에서는 현재 프로세스의 PID, 현재시간, 함수가 호출된 횟수를 카운트하여
출력한다. 
- test_funct함수의 호출간격은 1~10초 사이의 랜덤시간으로 한다. #include <time.h>
#include <stdlib.h>
srand(time(NULL));
int r = rand()%10;
sleep(r);
2. 아래와 같은 mproc1 프로그램을 작성한다. 
- 학번과 이름을 화면에 출력한다.
- fork(), exec() 함수를 사용하여 10개의 subproc 프로세스를 실행한다. 
- 각 함수 호출 카운트 값이 20이 되면 해당 프로세스를 종료시킨다. 
- 모든 프로세스가 종료되면 “Finished (process)”를 출력한다.
