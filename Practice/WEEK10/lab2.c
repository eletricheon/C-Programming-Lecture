/*
    Week 10: 함수와 변수
    Lab 2: 한번만 초기화하기
*/

#include <stdio.h>
#include <stdlib.h>

void hw_init(void);

int main(void){
    hw_init(); // 초기화 작업 수행
    hw_init(); // 초기화 작업은 이미 수행되었으므로 메시지 출력
    hw_init(); // 초기화 작업은 이미 수행되었으므로 메시지 출력

    return 0;
}

void hw_init(void){
    static int init = 0; // static 변수 => 초기화는 한번만 수행되고, 프로그램 실행시간 동안 유지
    if(init == 0){
        printf("초기화 작업을 수행합니다.\n");
        init = 1; // 초기화가 완료되었음을 표시
    } else {
        printf("초기화 작업은 이미 수행되었습니다.\n");
    }
}