# CppStudy

## 환경설정
> 22.07.02
- Visual Studio 설치
- 새 프로젝트 생성

## 정수
> 22.07.02
- 주석  
```
// 이렇게 주석을 달 수 있어요!  
// Ctrl+K+C(Comment) Ctrl+K+U(UnComment)<-단축키  
/*
주석이 여러 줄이라면 이렇게 달 수 있어요!
*/
```

- 정수 선언 방법  
[타입] [이름];  
[타입] [이름] = [초기값];  
```
// 0이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;

// 초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역
char a;     // 1byte (-128 ~ 127)
short b;    // 2byte (-32768 ~ 32767)
int c;      // 4byte (-21.4억 ~ 21.4억)
__int64 d;  // 8byte (long long) (어마어마하게 크다)

unsigned char ua;     // 1byte (0 ~ 255)
unsigned short ub;    // 2byte (0 ~ 65536)
unsigned int uc;      // 4byte (0 ~ 42.9억)
unsigned __int64 ud;  // 8byte (long long) (0 ~ 어마어마하게 크다)
```

- 참고  
이론적으로 양수만 존재할 수 있는 데이터 unsigned  
무조건 unsigned를 사용할지 의견이 갈림  
레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾는게 낫다  
unsigned / signed 사이의 변환  

- 오버플로우 / 언더플로우
```
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    cout << b << endl;  // -32768

    // 정수 언더플로우
    ub = 0;
    ub = ub - 1;
    cout << ub << endl; // 65535
```

## 불리언과 부동소수점
> 22.07.02
- 불리언(boolean) 참/거짓  
```
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;
```
- [Note]  
사실 bool은 그냥 1바이트 정수에 불과  
왜 정수 시간에 왜 안 다뤘을까?  
-> 일리 있음. 어셈블리에서 bool이라는 것은 없음  
bool만 봐도 참/거짓 둘 중 하나라는 힌트를 줍니다. (가독성)  

- 실수(부동소수점)  
float double  
.을 유동적으로 움직여서 표현하는 방법  
float 부호(1) 지수(8) 유효숫자(23) = 32비트 = 4바이트  
double 부호(1) 지수(11) 유효숫자(52) = 64비트 = 8바이트  
```
float attackSpeed = -3.375f;	// 4바이트
double attackSpeed2 = 123.4123;	// 8바이트
```
ex) -3.375라는 값을 저장  
1) 2진수 변환 = (3) + (0.375) = 0b11 + 0b0.011 = 0b11.011  
0.375 = 0.5 * 0 + 0.25 * 1 + 0.125 * 1 = 0b0.011  
2) 정규화 0b1.1011 * 2^1  
1(부호) 1(지수) 1011(유효숫자)  
단 지수는 unsigned byte라고 가정하고 숫자 + 127 만들어줌  
예상 결과 : 0b 1 10000000 1011000'0000'0000'0000'0000  
  
프로그래밍할 때 부동소수점은 항상 '근사값'이라는 것을 기억  
특히 수가 커질 수록 오차 범위도 매우 커짐  
실수 2개를 == 으로 비교하는 것은 지양  

## 문자와 문자열
> 22.07.02
- 문자  
char : 그냥 1바이트 정수지만 '문자' 의미를 나타내기 위해 사용  
char : 알파벳 / 숫자 문자를 나타낸다  
wchar_t : 유니코드 문자를 나타낸다  
```
char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;
wchar_t wch = L'안';

// 출력
// cout은 char 전용
cout << ch << endl;

// wchar 출력을 위해선 wcout 사용
wcout.imbue(locale('kor'));
wcout << wch << endl;
```

- 유니코드  
국제화 시대에는 영어만으로 서비스 할 수 없음  
전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드 (unicode)  
참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어  
  
유니코드는 표기 방식이 여러가지가 있는데 대표적으로 UTF-8 UTF-16  
UTF-8  
알파벳, 숫자 1바이트 (ASCII 동일한 번호)  
유럽 지역의 문자는 2바이트  
한글, 한자 등은 3바이트  
UTF-16  
알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트  
매우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)  

- Escape Sequence  
표기하기 애매한 애들을 표현  
\0 = 아스키코드0 = NULL  
\t = 아스키코드9 = Tab  
\n = 아스키코드10 = LineFeed (한줄 아래로)  
\r = 아스키코드 13 = CarriageReturn (커서 맨 앞으로)  

- 문자열  
문자들이 열을 지어서 모여 있는 것 (문자 배열?)  
정수 (1 ~ 8바이트) 고정 길이로  
끝은 NULL(0)  
```
char str[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
char str2[] = "Hello World";
wchar_t str3[] = L"Hello World";
```

## 산술 연산
> 22.07.02
- 대입연산  
a에 b를 대입하고 b를 반환하라  
-> b라는 바구니 안에 있는 값을, a라는 바구니 안에다 복사한다  
```
// 대입연산
a = b;
```
- 사칙연산  
언제 필요한가?  
ex) 데미지 계산  
ex) 체력을 깎는다거나  
ex) 루프문에서 카운터를 1 증가시킨다거나  
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

// 증감 연산자
a = a + 1;	// add eax, 1 -> inc eax
a++;
++a;
a--;
--a;

b = a++;	// b = a -> a를 1 증가
b = ++a;	// a를 1증가 -> b = a

b = (a + 1) * 3;
```

## 비교 연산과 논리 연산
> 22.07.02
- 비교 연산  
언제 필요한가?  
ex) 체력이 0이 되면 사망  
ex) 체력이 30% 이하이면 궁극기를 발동 (100 * hp / maxHp)  
ex) 경험치가 100이상이면 레벨업  
```
// a == b : a와 b의 값이 같은가?
// 같으면 1, 다르면 0
isSame = (a == b);

// a != b : a와 b의 값이 다른가?
// 다르면 1, 같으면 0
isDifferent = (a != b);

// a > b : a가 b보다 큰가?
// a >= b : a가 b보다 크거나 같은가?
// 크면 1, 아니면 0
isGreater = (a > b);

// a < b : a가 b보다 작은가?
// a <= b : a가 b보다 작거나 같은가?
// 작으면 1, 아니면 0
isSmaller = (a < b);
```
- 논리 연산  
언제 필요한가? 조건에 대한 논리적 사고가 필요할 때  
ex) 로그인할 때 아이디도 같고 AND 비밀번호도 같아야 한다  
ex) 길드 마스터이거나 OR 운영자 계정이면 길드 해산 가능  
```
// ! : not
// 0이면 1, 그 외 0
test = !isSame;	// 사실상 isDifferent의 의미

// && : and
// a && b -> 둘다 1이면 1, 그 외 0
test = (hp <= 0 && isInvincible == false);	// 죽음

// || : or
// a || b -> 둘 중 하나라도 1이면 1, 둘다 0이면 0
test = (hp > 0 || isInvincible == true);	// 생존
```

## 비트 연산과 비트 플래그
> 22.07.02
- 비트 연산  
언제 필요한가? (사실 많이는 없음)  
비트 단위의 조작이 필요할 때  
대표적으로 BitFlag  
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
```
- 실습
```
// 0b0000 [무적][변이][스턴][공중부양]

// 무적 상태로 만든다
flag = (1 << 3);

// 변이 상태를 추가한다 (무적 + 변이)
flag |= (1 << 2);

// 무적인지 확인하고 싶다? (다른 상태는 관심 없음)
// bitmask
bool invincible = ((flag & (1 << 3)) != 0);

// 무적이거나 스턴 상태인지 확인하고 싶다면?
bool stunOrInvincible = ((flag & 0b1010) != 0);
```

## const와 메모리 구조
> 22.07.05
- const  
한번 정해지면 절대 바뀌지 않을 값들  
constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)  
const를 붙였으면 초기값을 반드시 지정해야 함  
  
그러면 const도 바뀌지 않는 읽기 전용  
.rodata?  
사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음  
그냥 컴파일러 (VS) 마음  
```
int AIR = 0;
int STUN = 1;
int POLYMORPH = 2;
int INVINCIBLE = 3;
```

- 전역 변수  
```
// [데이터 영역]
// .data (초기값 있는 경우)
int a = 2;

// .bss (초기값 없는 경우)
int b;

// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";
```

- 지역 변수
```
int main()
{
    // [스택 영역]
    int c = 3;
}
```

## 유의사항
> 22.07.05
- 1) 변수의 유효범위
```
// 전역 변수
// int hp = 10;

// 스택 (지역 변수)
// { } 중괄호의 범위가 생존 범위
``` 
- 2) 연산 우선순위  
연산의 우선순위를 생각하여 괄호를 주어 우선순위 지정  

- 3) 타입 변환
```
int hp = 10;

// 바구니 교체
short hp2 = hp; // 윗쪽 비트 데이터가 짤린 상태로 저장
float hp3 = hp; // 실수로 변환할 때 정밀도 차이가 있기 때문에 데이터 손실
unsigned int hp4 = hp;  // 비트 단위로 보면 똑같은데, 분석하는 방법에 따라 다름
```

- 4) 사칙 연산 관련  
곱셈 - 오버플로우  
나눗셈 - 0 나누기 조심, 실수 관련  

## 분기문
> 22.07.05
- if-else문
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

- switch-case문
```
// 정수 계열만 넣을 수 있다.
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
> 22.07.05
- while문  
한 번만 실행하는게 아니라, 특정 조건까지 계속 반복해야 하는 상황  
ex) 게임을 끌때까지 계속 게임을 실행해라  
ex) 목적지에 도달할때까지 계속 이동하라  
```
while(조건식)
{
}
```

- for문
```
for(초기식; 조건식; 제어식)
{

}
```

- break, continue  
루프문을 빠져 나가기 위해서는 break 
다음 루프문으로 넘어가기 위해서는 continue  

## 연습 문제(별찍기와 구구단)
> 22.07.07
- 별찍기1  
유저들이 어떤 정수를 입력하면  
N * N개의 별을 찍었으면 좋겠어요!  
```
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			cout << "*";
		cout << endl;
	}
```
- 별찍기2  
1개부터 시작해서 순차적으로 줄마다 증가하게 수정해주세요!
```
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << "*";
		cout << endl;
	}
```
- 별찍기3  
N개부터 시작해서 줄마다 1개씩 줄어드는 형태로!
```
	int a;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a - i; j++)
			cout << "*";
		cout << endl;
	}
```
- 구구단  
2단부터 9단까지 구구단을 출력해주세요!
```
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
			cout << i << " * " << j << " = " << i * j << endl;
		cout << endl;
	}
```

## 가위-바위-보
> 22.07.07
- 실습
```
int main()
{
	srand(time(0));	// 시드 설정

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	int wins = 0;
	int total = 0;

	while (true)
	{
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		cout << "> ";

		if (total == 0)
		{
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			int winPercentage = (wins * 100) / total;	// 승률?
			cout << "현재 승률 : " << winPercentage << endl;
		}
		// 컴퓨터
		int computerValue = rand() % 3 + 1;

		// 사용자
		int input;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case PAPER:
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
				break;
			case ROCK:
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case ROCK:
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
				break;
			case PAPER:
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;
			}
		}
		else
		{
			break;
		}
	}
}
```

## 열거형
> 22.07.07
- const형
```
const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;
```
- enum
```
// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};
```
- 전처리형
```
// #이 붙은거 -> 전처리 지시문
// #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙!
// 컴파일 순서 -> 1) 전처리 2) 컴파일 3) 링크
#define DEFINE_SISSORS 1
```