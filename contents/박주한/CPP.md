## 데이터 갖고놀기 - 정수
- 주석 종류 
```
// 
Ctrl+K+C(Comment) Ctrl+K+U(UnComment)
/* 내용 */
```

- 변수 선언 방법
```
[타입] [이름];
[타입] [이름] = [초기값];
```

- 데이터, signed, unsigned 
```
0이 아닌 초기화 값이 있으면 .data 영역
    char    //1바이트 (-128 ~ 127)
    short   //2바이트 (-32768 ~ 32767)
    int     //4바이트 (-21.4억 ~ 21.4억)
    _int64  //8바이트 (long long) (어마어마하게 크다)
초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역
    unsigned char ;     // 1byte (0 ~ 255)
    unsigned short ;    // 2byte (0 ~ 65536)
    unsigned int ;      // 4byte (0 ~ 42.9억)
    unsigned __int64 ;  // 8byte (long long) (0~어마어마하게 크다)

//귀찮은데 그냥 대충 4바이트 가면 안될까?
    -> 콘솔/모바일 -> 메모리 늘 부족, 온라인 게임 -> 4바이트 * 1만명 
//참고
    이론적으로 양수만 존재할 수 있는 데이터 unsigned
    무조건 unsigned를 사용할지 의견이 갈림
    레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾는게 낫다
    unsigned / signed 사이의 변환
```
- 정수 오버플로우
```
    선언한 데이터형의 숫자를 넘길 경우 발생
    b = 32767;
    b = b + 1;
    cout << b << endl;  // -32768
```
- 정수 언더 플로우
```
    ub = 0;
    ub = ub - 1;
    cout << ub << endl; // 65535
```
## 불리언 부동소수점
- 불리언 참/거짓
``` 
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;
```

    bool은 그냥 1바이트 정수에 불과 -> 일리 있음. 어셈블리에서 bool이라는 것은 없음
    bool만 봐도 참/거짓 둘 중 하나라는 가독성

- 부동 소수점
    .을 유동적으로 움직여서 표현
```
ex)float, double
float 부호(1) 지수(8) 유효숫자(23) = 32비트 = 4바이트
double 부호(1) 지수(11) 유효숫자(52) = 64비트 = 8바이트

ex) -3.375라는 값을 저장

    1) 2진수 변환 = (3) + (0.375) = 0b11 + 0b0.011 = 0b11.011
        0.375 = 0.5 * 0 + 0.25 * 1 + 0.125 * 1 = 0b0.011

    2) 정규화 0b1.1011 * 2^1
        1(부호) 1(지수) 1011(유효숫자)

    단 지수는 unsigned byte라고 가정하고 숫자 + 127 만들어줌
    예상 결과 : 0b 1 10000000 1011000'0000'0000'0000'0000

    부동소수점은 항상 근사값
    수가 커질수록 오차 범위도 매우커짐
    실수 2개를 ==로 비교하는것은 지양
```

## 문자와 문자열 
- 문자
    char: 그냥 정수이지만, '문자'를 나타내기 위해 사용 

    char: 알파벳/숫자 문자를 나타냄
    wchar_t: 유니코드 문자를 나타냄

``` 
    char ch = 'a';
    char ch2 = '1';
    char ch3 = 'a' + 1;

    wchar_t wch = 0xc548; // L'안';
```

    '문자'의 의미로 작은 따음표 '' 사용

- 유니코드
    국제화 시대에는 영어만으로 서비스 할 수 없음
    전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드(unicode)

    유니코드는 표기 방식이 여러가지가 있음 (UTF-8 UTF-16)
```
UTF-8
    알파벳, 숫자 1바이트 (ASCII 동일한 번호)
    유럽 지역의 문자는 2바이트
    한글, 한자 등은 3바이트
UTF-16
    알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
    매우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)
```
- Escape Sequence
    표기 하기 애매한 애들을 표현
```
    \0 = 아스키코드0 = NULL
    \t = 아스키코드9 = Tab
    \n = 아스키코드10 = LineFeed (한줄 아래로)
    \r = 아스키코드 13 = CarriageReturn (커서 맨 앞으로)
```

- 문자열
    문자들이 열을 지어서 모여 있는 것 (문자 배열?)
    정수 (1 ~ 8바이트) 고정 길이로
    끝은 NULL(0)
```
char str[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
char str2[] = "Hello World";
wchar_t str3[] = L"Hello World";
```

## 산술연산

- 대입 연산
    a에 b를 대입하고 b를 반환 -> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사

- 사칙 연산 
```
    a = b + 3; // 덧셈 add
    a = b - 3; // 뺄셈 sub
    a = b * 3; // 곱셈 mul
    a = b / 3; // 나눗셈 div
    a = b % 3; // 나머지 div

    a += 3;	// a = a + 3;
    a -= 3;
    a *= 3;
    a /= 3;
    a %= 3;

증감 연산자
    a = a + 1;	// add eax, 1 -> inc eax
    a++;
    ++a;
    a--;
    --a;

    b = a++;	// b = a -> a를 1 증가
    b = ++a;	// a를 1증가 -> b = a

    b = (a + 1) * 3;
```

## 비교연산
- 비교연산
```
a == b : a와 b의 값이 같은가?
같으면 1, 다르면 0
isSame = (a == b);

a != b : a와 b의 값이 다른가?
다르면 1, 같으면 0
isDifferent = (a != b);

a > b : a가 b보다 큰가?
a >= b : a가 b보다 크거나 같은가?
크면 1, 아니면 0
isGreater = (a > b);

a < b : a가 b보다 작은가?
a <= b : a가 b보다 작거나 같은가?
작으면 1, 아니면 0
isSmaller = (a < b);
```
- 논리 연산
    조건에 대한 논리적 사고가 필요할 때 사용
```
! : not
0이면 1, 그 외 0
test = !isSame;	// 사실상 isDifferent의 의미

&& : and
a && b -> 둘다 1이면 1, 그 외 0
test = (hp <= 0 && isInvincible == false);	// 죽음

|| : or
a || b -> 둘 중 하나라도 1이면 1, 둘다 0이면 0
test = (hp > 0 || isInvincible == true);	// 생존
```

## 비트 연산
    비트 단위의 조작이 필요할때 사용
    BitFlag
```
~ : bitwise not
단일 숫자의 모든 비트를 대상으로 0은 1, 1은 0으로 뒤바꿈

& : bitwise and
두 숫자의 모든 비트 쌍을 대상으로, and를 한다

| : bitwise or
두 숫자의 모든 비트 쌍을 대상으로 , or를 한다

^ : bitwise xor
두 숫자의 모든 비트 쌍을 대상으로, xor를 한다

<< : 비트 좌측 이동
비트열을 N만큼 왼쪽으로 이동
왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 N개의 비트는 0
*2를 할 때 자주 보이는 패턴

>> : 비트 우측 이동
비트열을 N만큼 오른쪽으로 이동
오른쪽의 넘치는 N개의 비트는 버림
왼쪽 생성되는 N개의 비트는
- 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
- 아니면 0

ex) 

0b0000 [무적][변이][스턴][공중부양]

무적 상태로 만든다
flag = (1 << 3);

변이 상태를 추가한다 (무적 + 변이)
flag |= (1 << 2);

무적인지 확인하고 싶다? (다른 상태는 관심 없음)
// bitmask
bool invincible = ((flag & (1 << 3)) != 0);

무적이거나 스턴 상태인지 확인하고 싶다면?
bool stunOrInvincible = ((flag & 0b1010) != 0);
```

## conts와 메모리 구조 

- const 상수화
    한번 정해지면 절대 바뀌지 않는 값들
    상수화
    const를 붙였으면 초기값을 '반드시' 지정

- 전역 변수 
```
[데이터 영역]
.data (초기값 있는 경우)
    int a = 2;

.bss (초기값 없는 경우)
    int b;

.rodata (읽기 전용 데이터)
const char* msg = "Hello World";
```
- 지역 변수
```
메인 안에서
    [스택 영역]
    int c = 3;

```
## 유의사항 (데이터 갖고놀기 파트 )

- 변수의 유효범위
전역 변수
    int hp = 10;

스택
    같은 이름 두번 사용할 때 문제
    {}중괄호의 범위가 생존 범위

- 연산 우선순위
    연산의 우선순위를 생각하여 괄호를 주어 우선순위 지정

- 타입 변환
```
int hp = 10

short hp2 = hp; // 윗쪽 비트 데이터가 짤린 상태로 저장
float hp3 = hp; // 실수로 변환할 때 정밀도 차이가 있기 때문에 데이터 손실
unsigned int hp4 = hp;  // 비트 단위로 보면 똑같은데, 분석하는 방법에 따라 다름
```

- 사칙 연산 관련

    곱셈 - 오버 플로우
    나눗셈 - 0나누기 조심, 실수 관련

------------------------------------------------------------------------
## 코드의 흐름 제어 - 분기문    

   - if-else
```
const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;

int input = ROCK;

if(input == ROCK)
    cout << "바위를 냈습니다" << endl;
else if(input == PAPER)
    cout << "보를 냈습니다" << endl;
else if(input == SCISSORS)
    cout << "가위를 냈습니다" << endl;
else
    cout << "뭘 낸겁니까?" << endl;

```
- switch-case
    '정수' 계열만 넣을 수 있다 
```
switch(input)
case ROCK:
    cout << "바위를 냈습니다" << endl; 
    break;
case PAPER:
    cout << "보를 냈습니다" << endl;
    break;
case SCISSORS:
    cout << "가위를 냈습니다" << endl;
    break;
default:
    cout << "뭘 낸겁니까? << endl;
    break;
```
## 반복문 
- while문
    한번만 실행하는게 아니라, 특정 조건까지 계속 반복해야 하는 상황
```
    while(조건식){
        명령문
        }

    do{
    명령문
    }while(조건식)
        무조건 한번 실행

```
- for문
```
    for(초기식; 조건식; 제어식){
        명령문
    }
```

- break 
    루프문을 빠져 나갈때 사용

- continue 
    다음 루프문으로 넘어가기 위해 사용 

## 연습 문제 (별 찍기와 구구단) (가위바위보)

## 열거형
- const형
```
    상수 인건 알겠는데 너무 따로 노는데?

    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;

```

- enum형
    숫자를 지정 안하면 첫 값은 0부터 시작
    그 다음 값들은 이전 값 + 1
```
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};
```

- 전처리형
    #이 붙은거 -> 전처리 지시문
    #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙! 
    컴파일 순서 -> 1) 전처리 2) 컴파일 3) 링크
```
    #define DEFINE_SISSORS 1
```
# 함수 기초

- 함수 (프로시저, 메소드 ,루틴)
    input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

```
반환타입 함수이름([인자 타입 매개변수])
{
	함수 내용
	return ---;
}
```

- 예제
Hello World를 콘솔에 출력하는 함수를 만들어보자!
input : 없음 / output : 없음
타입 : int float double char ~~ void
```
void PrintHelloWorld()
{
	cout << "Hello World" << endl;
}
```
정수를 입력(함수) 받아서, 콘솔에 출력하는 함수를 만들어보자
input : int / output : 없음
```
void PrintNumber(int number)
{
	cout << "넘겨주신 숫자는 " << number << " 입니다" << endl;
}
```

2를 곱하는 결과물을 뱉는 함수를 만들어보자
input : int / output : int
```
int MultiplyBy2(int a)
{
	int b = a * 2;
	return b;
}
```
두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
input : int, int / output : int
```
int MultiplyBy(int a, int b)
{
	int c = a * b;
	return c;
}

int main()
{
	int result = MultiplyBy(3, 5);
	PrintNumber(result);
	PrintHelloWorld();
}
```
# 스택 프레임
- 디버깅 
    F5 -> 걸어주는 곳만 실행
    F10 -> 프로시저(함수) 단위 실행
    F11 -> 한 단계씩 코드 실행(한줄씩 코드 실행)

# 지역 변수와 값 전달
- 전역 변수
    함수 외부에 선언하는 변수
    어떤 함수에서 사용 가능
    데이터 영역에 들어가는 변수

    참고)초기화 여부, const 등, rodata, data .bss

- 지역 변수
    함수 내부에 선언하는 변수
    스택 영역에 들가는 변수

# 호출 스택 
    스택 프레임에서 반환 주소값과 밀접한 관련

# 함수 선언
    함수 선언부와 함수 구현부를 나눠 코딩하는데 
    C++은 위에서 아래로 실행되서 미리 선언 해야함

F5로 디버깅하면 하단에 있는 호출 스택으로 해당 함수가 어디에서 왔는지 찾을 수 있다

# 함수 마무리 
- 오버로딩(중복 정의 : 함수 이름의 재사용)
    매개변수 갯수가 다르거나
    매개변수 타입이 다르거나 (순서가 다른걸 포함)
```
int Add(int a, int b)
{
	int result = a + b;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
}
```
# 기본 인자값
    인자의 값 미리 설정
    맨 끝(오른쪽)에서 설정 해야함
- 스택 오버플로우
    너무 많은 함수 호출시 스텍 메모리가 고갈되어 버티지 못하는 상황

# TextRPG #1 #2

# 포인터 

    지금까지의 방식 number라는 이름의 4바이트 정수 타입의 바구니를 만든다
    number라는 변수는 스택 메모리에 할당
    number = 1; -> number 바구니에 1이라는 숫자르 넣으라는 의미
    따라서 스택 메모리에 있는 특정 주소(number 바구니)에 우리가 원하는 값을 넣은 셈
    number는 비유하자면 메모리에 이름을 붙인 것(찰떡같이 알아들어서)
    나쁘지 않고 편리한데, 단점은 TextRPG 원본 수정
```
int i = 1;
```

    포인터
    바구니는 바구니인데...
    [주소를 저장하는 바구니다!]
    변수 선언할 때 * 등장했다 -> 포인터 = 주소
    참고) 포인터라는 바구니는 8바이트(64비트) 고정 크기
```
int* ptr = *number;
```

    근데 남의 주소를 갖고 뭘 어떻게 하라는거지?
    추가 문법 : [주소를 저장하는 바구니]가 가리키는 주소로 가서 무엇인가를 해라!
    *변수이름 = 값;

    *이 여러번 등장하니 헷갈리는데, 사용 시점에 따라서 구분해서 기억하자
    변수 선언(주소를 저장하는 바구니다!)
    사용할 때(포탈 타고 순간이동)
```
int value1 = *ptr;
*ptr = 2;
```

    TYPE은 왜 붙여줄까?
        * = 포인터의 의미 = 주소를 저장하는 바구니 = 4/8바이트 고정 크기

    주소에 가면 뭐가 있는데?
        ex) 결혼식 청첩장에 있는 주소 = 예식장 주소
        ex) 명함에 있는 주소 = 회사 주소
    * = 포인터 (주소 담는 바구니)

    타입의 불일치
```
	int number = 1;
	__int64* ptr2 = (__int64*)&number;

	*ptr2 = 0xAABBCCDDEEFF;
    return 0
```

# 포인터 연산
- 주소 연산자(&)
    해당 변수의 주소를 알려주세요
    더 정확히 말하면 해당 변수 타입(TYPE)에 따라서 TYPE* 변환

- 산술 연산자 (+ -)
    int*
    * : 포인터 타입이네! (8바이트) 주소를 담는 바구니!
    int : 주소를 따라가면 int(4바이트 정수형 바구니)가 있다고 가정해라!

    [!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면,
    정말 '그 숫자'를 더하고 빼라는 의미가 아니라
    한번에 TYPE의 크기만큼 이동하라!
    정리해서 다음/이전 바구니로 이동하고 싶다 << [바구니 단위]의 이동으로 
    즉, 1을 더하면 = 바구니 1개 이동시켜라
    3을 더하면 = 바구니 3개 이동시켜라

- 간접연산자(*)
    포탈을 타고 해당 주소로 이동

- 간접 멤버 연산자(->)
    * : 간접 연산자(포탈 타고 해당 주소로 이동)
    . : 구조체의 특정 멤버를 다룰 때 사용 (어셈블리 언어로 까보면 사실상 그냥 덧셈)
    -> 위 두개를 한방에 !

# 포인터 실습

# 참조기초

- 참조 
    값 전달 방식
        경우에 따라 값을 수정이 아니라 읽는 용도면
        양쪽 다 일단 문제 없음 
```
void PrintinfoByCopy(Statinfo info)
{
    cout << "--------------" << endl;
    cout << "HP: " << info.hp << endl; 
    cout << "HP: " << info.attack << endl; 
    cout << "HP: " << info.defence << endl; 
    cout << "--------------" << endl;
}

```
    주소 전달 방식

```
void PrintinfoByPtr(Statinfo* info)
{
    cout << "--------------" << endl;
    cout << "HP: " << info<-hp << endl; 
    cout << "HP: " << info<-attack << endl; 
    cout << "HP: " << info<-defence << endl; 
    cout << "--------------" << endl;
}
``` 

```
int main()
{
    statinfo info;
    CreateMonster(&info);

    PrintInfoByCopy(info);
    PrintinfoByPtr(&info);
}

```

StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
    -(값 전달) Statinfo로 넘기면 1000바이트가 복사되는
    -(주소 전달)Statinfo*는 8바이트
    -(참조 전달)Statinfo&는 8바이트

값 전달 방식을 사용한 경우 매개변수의 어마한 데이터를 받아야할 수 있지만
주소 전달 방식을 사용하면 주소값 크기는 (4바이트,8바이트 ) 고정이므로 부담이 없다 


    4바이트 정수형 바구니를 사용할거야
    앞으로 그 바구니 이름을 number라고 할꼐
    그러니까 number에서 뭘 꺼내거나, number에 뭘 넣는다고 하면
    찰떡같이 알아듣고 해당 주소(data, stack, heap)에 1을 넣어주면 됨!
```
    int number = 1;
```
    *주소를 담는 바구니
    int 그 바구니를 따라가면 int 데이터(바구니)가 있음
```
    int * pointer = &number;
```
    pointer 바구니에 있는 주소를 타고 이동해서
    그 멀리 있는 바구니에 2 를 넣는다
```
    *pointer = 2;
```

    로우 레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
```
    int& reference = number;
```

    C++관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
    number라는 바구니에 reference라는 다른 이름을 지어줄게
    앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면
    실제 number 바구니(진퉁) 그 값을 꺼내거나 넣으면 됨
```
    reference = 3;
```

    다른 이름을 짓는 이유는?
    그냥 number = 3 이라고 해도 똑같은데...
    참조 전달 때문

    참조 조달
        값 전달처럼 편리하게 사용하고 
        주소 전달처럼 주소값을 이용해 진퉁을 건드리는
        일석이조의 방식 