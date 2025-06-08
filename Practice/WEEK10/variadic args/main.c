#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...){
    int answer = 0;

    va_list argptr;     // 가변 인자 목록 포인터
    va_start(argptr, num);  // 가변 인자 목록 포인터 설정

    for(; num > 0; num--){
        answer += va_arg(argptr, int);  // int 크기만큼 인자 목록 포인터에서 값을 가져온다.
    }

    va_end(argptr);
    return answer;
}

int main(void){
    printf("sum(1, 10) = %d\n", sum(1, 10));
    printf("sum(3, 10, 20, 30) = %d\n", sum(3, 10, 20, 30));
    printf("sum(5, 10, 20, 30, 40, 50) = %d\n", sum(5, 10, 20, 30, 40, 50));

    return 0;
}