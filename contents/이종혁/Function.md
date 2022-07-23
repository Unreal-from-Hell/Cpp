# 함수

<br>

## 함수(프로시저, 메소드, 루틴)

<br>

<img src="./Images/Function/Function.png" width = 500>

 * 입력에 대한 어떤 상호작용으로 인해 출력이 나오게 된다.

<br>

``` cpp
// input으로 무엇을 받고 output으로 무엇을 반환할지 정해주어야 한다

// [반환 타입] [함수 이름]([ 인자 타입 매개 변수])
// {
//     함수 내용 

//     return 반환 값
// }

#include<iostream>

using namespace std;

// Hello World를 콘솔에 출력하는 함수를 만들어보자 !
// input: 없음 / output : 없음 
// 인자타입: int, float, double, char, void 등등

void PrintHelloWorld()
{
    cout << "Hello World" << endl;
}

// 정수를 입력 받아서 출력하는 함수를 만들어보자 !
// input: int // output :없음 

void PrintNumber(int number)
{
    cout << "넘겨주신 숫자는" << number << "입니다" << endl;
}

// 2를 곱하고 결과물을 뱉는 함수를 만들어보자 !
// input: int // output: int

int MultiplyBy2(int a)
{
    int b = a * 2;
    return b;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어 보자 !
// input: int, int / output: int

int MultiplyBy(int a, int b)
{
    int c = a * b ;
    return c
}

int main(int argc, char * argv[])
{
    int a = 3 ;
    int b = 5;
    int result = MultiplyBy(a, b);
    // PrintHelloWorld();
    // int reuslt = MultiplyBy2(3);
    // PrintNumber(result);

    return 0;
}
```

<br><br>


## 스택 프레임

<br>

<img src="./Images/Function/StackFrame.png" width = 600>

<br>

## 지역 변수와 값 전달

<br>

### 전역 변수
> 프로그램이 시작될 때 생성되어 data 영역에 저장되며 프로그램 전체에서 사용 가능하며 프로그램이 종료되면 소멸된다

 * 초기화 여부, const 등에 따라서 .rodata .data .bss 로 나뉜다

<br>

### 지역 변수
> 함수 내부에서 생성되어 스택에 저장되며 선언된 함수 내부에서 사용되고 함수가 종료되면 소멸된다



