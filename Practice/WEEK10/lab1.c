/*
    Week 10: 변수와 함수
    Lab 1: static 변수로 계좌 입출금 구현
*/

#include <stdio.h>

void save(int amount){
    static long balance = 0;    // static 변수 => 초기화는 한번만 수행되고, 프로그램 실행시간 동안 유지
    if(amount >= 0 ){
        printf("%d\t\t", amount);
    } else {
        printf("\t%d\t", -amount);
    }

    balance += amount;
    printf("%d\n", balance);
}

int main(void){
    printf("입금\t출금\t잔금\n");
    save(1000);
    save(2000);
    save(-500);
    save(-300);
    save(1500);

    return 0;
} 