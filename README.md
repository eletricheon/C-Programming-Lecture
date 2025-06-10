# C-Programming-Lecture
# 변수
## 1. Scope 
- 지역변수
Scope: 선언된 블록
Lifetime: 블록이 종료되면 소멸

    ```c
    int func(int param);    // param같은 매개변수도 지역변수의 일종

    int main(void){
        int temp;   // 초기화되지 않았으므로 쓰레기값을 가짐
    }
    ```

- 전역변수
    - Scope: 소스파일 전체(함수 밖에 선언)
    - Lifetime: 프로그램 전체 기간동안 존속

        ```c
        #include <stdio.h>

        int temp;   // 따로 초기화하지 않아도 초기값은 0

        int main(void){

        }
        ```

- 하나의 블록 내에 같은 이름의 지역변수와 전역변수가 있을 때: 블록 내의 지역변수를 우선으로 참조

    ```c
    #include <stdio.h>

    int num = 1;    // 전역변수

    int main(void){
        int num = 0;    // 지역변수

        printf("num = %d\n", num);  // "sum = 0" 출력
    }
    ```

## 2. Lifetime
- 정적할당: 프로그램 실행시간 동안 메모리 유지
- 동적할당: 블록에 들어갈 때 생성, 블록에서 나갈때 소멸
- Lifetime 결정 요인: 변수가 선언된 위치, 저장 유형 자정자

    저장 유형 지정자: 
    - auto: 선언한 위치에서 자동으로 선언, 블록을 벗어날 때 자동으로 소멸(지역변수에서는 auto를 생략해도 자동변수가 됨)
    - register: CPU의 레지스터에 변수를 저장함. 
    - static: 정적변수를 선언할 때 사용한다.
    - extern: 
        - Linkage를 위해 사용
        - 지역변수와 전역변수의 이름이 같을 때, 블록 내에서 전역변수에 접근하기 위해 사용
            ```c
            #include <stdio.h> 

            int x = 50;

            int main(void){
                int x = 100;

                {
                    extern int x;
                    printf("global x = %d", x);
                }

                printf("local x = %d", x);
            }
            ```

            Output:
            ```
            global x = 50
            local x = 100
            ```


    - volatile: 컴파일러가 최적화를 중지하게 된다. 
        ```c
        *(unsigned int*)0x8C0F = 0x8001
        *(unsigned int*)0x8C0F = 0x8002
        *(unsigned int*)0x8C0F = 0x8003
        *(unsigned int*)0x8C0F = 0x8004
        ```

        위 4줄의 코드는 모두 같은 주소에서 연산을 수행하므로 컴파일러는 최적화를 통해 마지막줄 연산만 수행한다.  
        하드웨어를 제어하는 코드라면 최적화로 인해 오작동할 수 있으므로 volatile을 사용한다.

## 3. Linkage
- 연결(Linkage): 다른 범위에 속하는 변수들을 연결(전역변수만 가능)
    - 외부 연결: 전역변수 extern을 이용하여 연결
        ```c
        // file1.c
        extern int global;  // file2.c에 선언된 global과 연결

        // file2.c
        int global = 1;

        // file3.c
        extern int global;  // file2.c에 선언된 global과 연결
        ```
        - 함수 앞에 static이 붙을 경우 extern을 이용한 외부 연결 불가
    - 내부 연결
    - 무 연결

# 함수
## 1. 가변 매개 변수
매개 변수의 개수가 정해지지 않음.
```c
#include <stdio.h>
#include <stdarg.h>

void sum(int num, ...){
    int answer = 0;

    va_list argptr;     // 가변 인자 목록 포인터
    va_start(argptr, num);  // 가변 인자 목록 포인터 설정

    for(; num > 0; num--){
        answer += va_arg(argptr, int);  // int 크기만큼 인자 목록 포인터에서 값을 가져온다.
    }

    va_end(argptr);
    return answer;
}

```
## 2. 재귀 함수
>   어느날 학생이 교수님께 물었다.  
    "**재귀함수**가 무엇인가요?"  
    이에 교수님은 이렇게 답했다.  
    "잘 들어보게. 옛날에 산 꼭대기에 현자가 있었어. 질문에 모두 지혜롭게 답해주었지. 그런데 어느날, 선비가 찾아와서 물었어.  
    &emsp;"**재귀함수**가 무엇인가요?"  
    &emsp;"잘 들어보게. 옛날에 산 꼭대기에 현자가 있었어. 질문에 모두 지혜롭게 답해주었지. 그런데 어느날, 선비가 찾아와서 물었어.  
    &emsp;&emsp;"**재귀함수**가 무엇인가요?"  
    &emsp;&emsp;"잘 들어보게. 옛날에 산 꼭대기에...

## WEEK 11
- Array

## WEEK 13
- Pointer

## WEEK 14
- Stream and file i/o
