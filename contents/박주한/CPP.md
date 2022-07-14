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