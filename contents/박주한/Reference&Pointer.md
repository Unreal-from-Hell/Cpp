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
> * = 포인터의 의미 = 주소를 저장하는 바구니 = 4/8바이트 고정 크기  
  
주소에 가면 뭐가 있는데?  
>ex) 결혼식 청첩장에 있는 주소 = 예식장 주소  
>ex) 명함에 있는 주소 = 회사 주소  
>* = 포인터 (주소 담는 바구니)  
  
타입의 불일치
```
	int number = 1;
	__int64* ptr2 = (__int64*)&number;

	*ptr2 = 0xAABBCCDDEEFF;
    return 0
```

# 포인터 연산
- 주소 연산자(&)  
>해당 변수의 주소를 알려주세요  
>더 정확히 말하면 해당 변수 타입(TYPE)에 따라서 TYPE* 변환  

- 산술 연산자 (+ -)  

>int*  
>* : 포인터 타입이네! (8바이트) 주소를 담는 바구니!  
>int : 주소를 따라가면 int(4바이트 정수형 바구니)가 있다고 가정해라!  

>[!] 포인터에서 +나 -등 산술 연산으로 1을 더하거나 빼면,  
>정말 '그 숫자'를 더하고 빼라는 의미가 아니라  
>한번에 TYPE의 크기만큼 이동하라!  
>정리해서 다음/이전 바구니로 이동하고 싶다 << [바구니 단위]의 이동으로  
>즉, 1을 더하면 = 바구니 1개 이동시켜라  
>3을 더하면 = 바구니 3개 이동시켜라  

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
>경우에 따라 값을 수정이 아니라 읽는 용도면  
>양쪽 다 일단 문제 없음 
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

``` C++
void PrintinfoByPtr(Statinfo* info)
{
    cout << "--------------" << endl;
    cout << "HP: " << info<-hp << endl; 
    cout << "HP: " << info<-attack << endl; 
    cout << "HP: " << info<-defence << endl; 
    cout << "--------------" << endl;
}
``` 

``` C++
int main()
{
    statinfo info;
    CreateMonster(&info);

    PrintInfoByCopy(info);
    PrintinfoByPtr(&info);
}

```

StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
>-(값 전달) Statinfo로 넘기면 1000바이트가 복사되는  
>-(주소 전달)Statinfo*는 8바이트  
>-(참조 전달)Statinfo&는 8바이트  

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
>값 전달처럼 편리하게 사용하고 
>주소 전달처럼 주소값을 이용해 진퉁을 건드리는
>일석이조의 방식 

## 포인터 vs 참조  
포인터 vs 참조 세기의 대결  
성능 : 똑같음!  
편의성 : 참조가 더 좋음  

1) 편의성 관련
편의성이 좋다는게 꼭 장점만은 아니다  
포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있으나  
참조는 자연스럽게 모르고 지나칠 수도 있다  
>ex) 마음대로 고친다면?  
const를 사용해서 마음대로 고치는 부분 개선 가능  
  
참고) 포인터도 const를 사용 가능  
*을 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 다름  
  
별 뒤에 붙인다면?  
StatInfo* const info  
info라는 바구니의 내용물(주소)을 바꿀 수 없음  
info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!  
  
별 앞에 붙인다면?  
const StatInfo* info  
info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음  
'원격' 바구니의 내용물을 바꿀 수 없음  

``` C++
StatInfo globalInfo;
void PrintInfo(StatInfo* info)
{
	if (info == nullptr)
		return;
	
	cout << "HP: " << info->hp << endl;  
	cout << "ATT: " << info->attack << endl;  
	cout << "DEF: " << info->defence << endl;  
    // info[ 주소값 ]	주소값[ 데이터 ]  
	// info = &globalInfo;  
	// info->hp = 10000;  
}
```
  
2) 초기화 여부  
참조 타입은 바구니의 2번째 이름 (별칭?)  
-> 참조하는 대상이 없으면 안됨  
반면 포인터는 그냥 어떤~ 주소라는 의미  
-> 대상이 실존하지 않을 수도 있음  
포인터에서 '없다'는 의미로? -> nullptr 사용  

``` C++
{
    StatInfo* pointer;  
    pointer = &info;  
    PrintInfo(&pointer);  
  
    StatInfo& reference = info;  
    PrintInfo(reference);  
}

```
널 체크로 크래쉬 방지  
if (info == nullptr)  
return;  
  
결론  
>사실 Team By Team... 정해진 답은 없다  
>ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용  
>ex) 언리얼 엔진에선 reference도 애용  
  
Rookiss 선호 스타일)  
없는 경우도 고려해야 한다면 pointer (null 체크 필수)
바뀌지 않고 읽는 용도만 사용하면 const ref&  
그 외 일반적으로 ref (명시적으로 호출할 때 OUT을 붙인다)  
단, 다른 사람이 pointer을 사용했을경우 바꾸지않고 계속 사용  
``` c++  
#define OUT  
void ChangeInfo(OUT StatInfo& info)  
{  
	info.hp = 1000;  
}  
```  
  
Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?  
PrintInfo(*pointer);  
  
Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?  
PrintInfo(&reference);  

## 배열 기초 
- 배열  
  
배열의 크기는 상수여야 함 (VC 컴파일러 기준)  
  
 const int monsterCount = 10;  
 StatInfo monsters[monsterCount];  
   
여태껏 변수들의 [이름]은 바구니의 이름이었음  
	int a = 10;  
그런데 배열은 [이름] 조금 다르게 동작한다  
	StatInfo players[10];  

배열의 이름은 곧 배열의 시작 주소  
정확히는 시작 위치를 가리키는 TYPE* 포인터  

포인터의 덧셈  진짜 1을 더하라는게 아니라, 
StatInfo 타입 바구니 한개씩 이동하라는 의미  
    StatInfo* monster_1 = monsters + 1;
포인터와 참조는 자유자재로 변환 가능하다  
    StatInfo& monster_2 = *(monsters + 2);  
  
두개의 의미가 다르다  
```
StatInfo& monster_2 = *(monsters + 2);
monster_2.hp = 300;
monster_2.attack = 30;
monster_2.defence = 3;
```
   
```
StatInfo temp = *(monsters + 2);
temp.hp = 400;
temp.attack = 40;
temp.defence = 4;
```
temp에 내용을 복사해서 넣는 것 
  
배열로 자동화 가능 ex> for  
  
```
for (int i = 0; i < 10; i++)
{
	StatInfo& monster = *(monsters + i);
	monster.hp = (i + 1) * 100;
	monster.attack = (i + 1) * 10;
	monster.defence = i + 1;
}
```
근데 *(monsters + i) 너무 불편하고 가독성이 떨어짐  

- 인덱스  
배열은 0번부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]  
    *(monsters + i) = monsters[i]  
  
- 배열 초기화 문법
  
```
int numbers[5] = {}; // 다 0
int numbers1[10] = { 1, 2, 3, 4, 5 }; // 설정한 애들은 설정한 값들로, 나머지 값들은 0으로 초기화
int numbers2[] = { 1,2,3,4,11,24,124,14,1 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다
```

- 배열 요약  

선언  
	int arr[10] = { };  
인덱스로 접근  
	arr[1] = 1;  
	cout << arr[1] << endl;  

## 포인터 vs 배열 

배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다 (char [] -> char*)  
즉 배열의 내용 전체를 넘긴게 아니라, 시작 주소(포인터)만 넘긴 것  

포인터는 [주소를 담는 바구니]  
배열은 [닭장] 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'  
다만 [배열 이름]은 '바구니 모음'의 [시작 주소]  

배열을 함수의 인자로 넘기게 되면?  
test2가 바뀔까? 안바뀔까? -> 바뀐다!  

## 다중 포인터
다중 포인터 : 혼동스럽다  
그냥 양파까기라고 생각하면 된다  
*을 하나씩 까면서 타고 간다고 생각하면 편하다  
2차 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵  

``` C++
#include <iostream>  
using namespace std;  
void SetNumber(int* a)  
{  
	*a = 1;  
}  
  
void SetMessage(const char* a)  
{  
	a = "Bye";  
}  
  
void SetMessage(const char** a)  
{  
	*a = "Bye";  
}  
  
void SetMessage2(const char*& a)  
{  
	a = "Wow";  
}  
  
int main()
{
int a = 0;  
SetNumber(&a);  
cout << a << endl;  
.rdata Hello주소 [H][e][l][l][o][\0]  
	// msg [ Hello주소 ] << 8바이트  
	const char* msg = "Hello";  
  
	// [매개변수][RET][지역변수(msg(Hello주소))]  
	SetMessage(msg);  
	// cout << msg << endl;  

	// .rdata Hello주소 [H][e][l][l][o][\0]  
	// msg[ Hello 주소] << 8바이트  
	// pp[ &msg ] << 8바이트  
	const char** pp = &msg;  

	// [매개변수][RET][지역변수(msg(Hello주소))][매개변수(a(&msg msg의 주소))][RET][지역변수]  
	SetMessage(&msg);  
	// cout << msg << endl;  
  
	// 다중 포인터 : 혼동스럽다?  
	// 그냥 양파까기라고 생각하면 된다  
	// *을 하나씩 까면서 타고 간다고 생각하면 편하다  
  
	// [매개변수][RET][지역변수(msg(Hello주소))][매개변수(a(&msg msg의 주소))][RET][지역변수]  
	SetMessage2(msg);  
	cout << msg << endl;  
}  
```

## 다차원 배열 
  2차 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵
```
	int map[5][5] =
	{
		{ 1, 1, 1, 1, 1},
		{ 1, 0, 0, 1, 1},
		{ 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0},
		{ 1, 1, 1, 1, 1},
	};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int info = map[y][x];
			cout << info;
		}
		cout << endl;
	}
}
```

## 포인터 마무리  
  
int* p  
주소를 담는 바구니  
진퉁은 어딘가에 있음  
p는 단지 그 곳으로 워프하는 포탈  
  
int arr[10]  
진짜배기! 원조 데이터  
닭장처럼 데이터의 묶음 (엄청 많고 거대함)  

[배열 = 포인터]라 착각하는 경향이 있음!  
[배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능!  
[TYPE형 1차원 배열]과 [TYPE*형 포인터]는 완전히 호환이 된다  