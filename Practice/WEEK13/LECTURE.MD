# 포인터
## 1. 변수와 메모리
- 변수는 메모리에 저장된다.
- 메모리는 바이트 단위로 접근할 수 있다.
- 자료형에 따라 차지하는 메모리 공간의 크기가 다르다. 예를 들어 `char`형은 1바이트, `int`형은 4바이트를 차지한다. 

    ```c
    #include <stdio.h>

    int main(void){
        int intData = 10;
        char charData = 'a';
    }
    ```

    |변수명|intData|charData|
    |:---:|:-----:|:-----:|
    |**변수값**|10|97|
    |**주소**|4 5 6 7|8

## 2. 변수의 주소
- 주소 연산자 `&`을 사용하여 변수의 주소에 접근할 수 있다.

    |변수명|intData|charData|
    |:---:|:-----:|:-----:|
    |**변수값**|10|97|
    |**주소**|4 5 6 7|8
    
    &rarr; `&intData = 4`, `&charData = 8`이다.

- 변수의 주소는 프로그램을 실행할 때마다 달라진다. 

## 3. 포인터 변수의 선언
- 포인터 변수는 변수의 주소를 가지고 있는 변수이다.
- `*`를 붙여 포인터 변수를 선언한다.
    
    ```c
    int *pData;
    ```

- 다음과 같이 절대 주소로 초기화할 수 있으나, 윈도우와 같은 OS환경에서는 불가능하고, 임베디드 환경에서만 가능하다.

    ```c
    char *p = (char*)0x30000000
    ```

## 4. 포인터와 변수의 연결
- 변수의 주소를 포인터 변수에 대입

    ```c
    int i = 10;
    int *pData;

    pData = &i;     // 포인터 변수 pData는 int 변수 i의 주소를 가리킴
    ```

- 간접 참조 연산자`*`를 이용하여 포인터가 가리키는 주소의 변수값을 연산

    ```c
    int i = 10;
    int *pData;

    pData = &i;

    printf("%d", *pData);   // pData 앞에 붙은 연산자`*`는 포인터가 가리키는 변수의 값을 반환환 
    ```

    Output:
    ```
    10
    ```

## 5. 포인터 사용시 주의점
- 초기화가 안된 포인터를 사용하면 안된다.

    ```c
    int main(void){
        int *pData;

        *pData = 100;   // pData가 초기화 되지 않았으므로 위험한 코드이다.

        return 0;
    }
    ```

- 포인터가 아무것도 가리키지 않을 경우에는 항상 `NULL`로 초기화 해야한다.

    ```c
    int *pData = NULL;
    ```

- 포인터와 포인터가 가리키는 변수의 타입이 일치해야 한다.

    ```c
    int main(void){
        int i;
        double *pd;

        pd = &i;    // 오류
        *pd = 36.5;

        return 0;
    }
    ```

## 6. 포인터 연산
- 증가, 감소, 덧셈, 뺄셈 연산이 가능하다.
- 증감 연산
    - 포인터 변수의 타입에 따라 증감 연산에 의해 증가/감소되는 값이 다르다.
    
        |타입|`++`연산으로 증가되는 값|
        |:---:|:---:|
        |**`char`**|1|
        |**`short`**|2|
        |**`int`**|4|
        |**`float`**|4|
        |**`double`**|8|

        - `int`형 포인터 변수의 연산

            ```c
            int a;
            int *pi;

            pi = &a;
            *pi = 4;
            ```

            &emsp;&downarrow;
            
            |변수명| | | |`a`|`a`|`a`|`a`| |
            |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
            |**변수값**| | | | | |4| | |
            |**주소**|0|1|2|3|4|5|6|7|
            |**포인터**| | | |`pi`| | | |`pi+1`|

        - `char`형 포인터 변수의 연산
            
            ```c
            char b;
            char *pc;

            pc = &b;
            *pc = 'a';
            ```

            &emsp;&downarrow;
            
            |변수명| | | |`b`| | | | |
            |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
            |**변수값**| | | |'a'| || | |
            |**주소**|0|1|2|3|4|5|6|7|
            |**포인터**| | | |`pc`|`pc+1`|`pc+2`|`pc+3`|`pc+4`|
    
- 주의점
    - `(*pi)++`는 `pi`가 가리키는 값을 증가시킨다.
    - `*pi++`는 `pi`가 가리키는 값을 가져온 후에 `pi`를 증가시킨다.  

        ```c
        #include <stdio.h>

        int main(void){
            int i = 10;
            int *pi;

            pi = &i; 

            printf("i = %d, pi = %d\n", i, pi);

            (*pi)++;
            printf("i = %d, pi = %d\n", i, pi);

            *pi++;
            printf("i = %d, pi = %d\n", i, pi);
        }
        ```

        Output:
        ```
        i=10, pi=000000FFEBCFF974
        i=11, pi=000000FFEBCFF974
        i=11, pi=000000FFEBCFF978
        ```

## 7. 포인터 형 변환
- 명시적으로 포인터 변수의 타입을 변환할 수 있다.

    ```c
    double f;
    double *pd = &f;
    int *pi;

    pi = (int*)pd;

    ```

- Lab 8. 코드 설명

    ```c
    int main(void){
        int data = 0x0A0B0C0D;
        char *pc;
        
        pc = (char*)&data;
        
        for(int i = 0; i < 4; i++) 
            printf("*(pc + %d) = %02X \n", i, *(pc + i));
        
        return 0;
    }
    ```

    - `int`형 변수 `data`는 16진수 정수 `0x0A0B0C0D`로 초기화됨.
    - `pc`는 `char`형의 포인터변수
    - `&data`는 `int`형 변수의 주소이므로 `char*`으로 형변환 하여 `pc`에 대입해야 한다. 
    - 포인터 변수`pc`를 증가시키며 해당 주소값이 가리키는 변수의 값을 출력하는데, 출력값은 시스템 유형에 따라 다르게 나온다.

        - Little-Endian: 가장 낮은 바이트(**LSB**, Least Significant Byte)가 가장 먼저 저장된다.
            
            ```
            *(pc + 0) = 0D 
            *(pc + 1) = 0C 
            *(pc + 2) = 0B 
            *(pc + 3) = 0A 
            ```

        - Big-Endian: 가장 큰 바이트(**MSB**, Most Significant Byte)가 가장 먼저 저장된다.
            
            ```
            *(pc + 0) = 0A 
            *(pc + 1) = 0B 
            *(pc + 2) = 0C 
            *(pc + 3) = 0D 
            ```
        
        - 대부분의 Windows, Linux(x64, x86)환경에서는 **Little-Endian**을 사용한다.

## 8. 인수 전달
- 값에 의한 호출(Call By Value): 변수의 복사본을 통해 **값**을 전달한다.
- 참조에 의한 호출(Call By Reference): 변수의 **원본**이 전달되는 방법으로, C에서는 포인터를 이용한다.

- Swap 함수
    - Call By Value

        ```c
        #include <stdio.h>

        void swap(int x, int y){
            int temp = x;

            x = y;
            y = temp;
        }

        int main(void){
            int a = 100, b = 200;

            swap(a, b);     // swap함수의 인자로 전달 된 것은 복사본으로, 실제로 a, b의 값이 바뀌지는 않았음.

            printf("a = %d\nb = %d", a, b);     // a = 100, b = 200으로 출력됨.   
            return 0;
        }

    - Call By Reference

        ```c
        #include <Stdio.h>

        void swap(int *x, int *y){
            int temp = *x;

            *x = *y;
            *y = temp;
        }

        int main(void){
            int a = 100, b = 200;

            swap(&a, &b);       // swap함수의 인자로 a, b의 주소가 전달 되었으므로, 실제로 값을 변경할 수 있음.

            printf("a = %d\nb = %d", a, b);     // a = 200, b = 100으로 출력됨.
            return 0;
        }
        ```

- `scanf()`에서의 인수 전달
    
    ```c
    #include <stdio.h>

    int main(void){
        int input;

        printf("정수를 입력하세요:");
        scanf("%d", &input);

        printf("input = %d", input);

        return 0;
    }
    ```

    &rarr; `input`변수에 직접 접근하여 값을 변형해야 하므로 인자로 `&input`과 같이 주소를 받는 것이다.

- 함수가 두개 이상의 값을 반환해야 하는 경우 포인터 변수를 인자로 전달 받아 결과를 변수에 저장해도 된다. *(Lab.11 코드 참고)*

## 9. 포인터와 배열
- 포인터는 배열처럼 사용할 수 있고, 인덱스 표기법도 사용할 수 있다.

    ```c
    #include <stdio.h>

    int main(void){
        int arr[] = {10, 20, 30, 40};
        int *p;

        p = arr;

        printf("arr[0] = %d, arr[1] = %d, arr[2] = %d\n", arr[0], arr[1], arr[2]);
        printf("p[0] = %d, p[1] = %d, p[2] = %d", p[0], p[1], p[2]);

        return 0;
    }
    ```

    Output:
    
    ```
    arr[0] = 10, arr[1] = 20, arr[2] = 30
    p[0] = 10, p[1] = 20, p[2] = 30
    ```
    
    &rarr; 포인터를 배열처럼 사용할 수 있다.

    |변수명|`arr[0]`|`arr[1]`|`arr[2]`|`arr[3]`|
    |:---:|:---:|:---:|:---:|:---:|
    |**주소**|4 5 6 7|8 9 10 11|12 13 14 15|16 17 18 19 20|
    |**포인터**|`p`|`p+1`   |`p+2`   |`p+3`   |

- 함수의 매개변수로 배열을 사용하는 경우 배열 전체의 복사본을 만드는 것은 비효율적이므로 주소를 전달하고, 기억 장소가 할당되지 않는다. 따라서 배열 매개 변수는 포인터로 생각할 수 있다.

## 10. 포인터 사용의 장점
- 연결 리스트, 이진 트리 등의 자료구조를 만들 수 있다.
- 참조에 의한 호출(Call By Reference)를 구현할 수 있다.
- 메모리 매핑 하드웨어
- 동적 메모리 할당