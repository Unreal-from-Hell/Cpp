# 코드의 흐름 제어

<br>

## 분기문(조건문)
> 가공한 데이터를 이용해서 특정 조건에 따라서 무엇인가를 하고 싶을 때 사용한다

* 대표적으로 `if문`, `switch문`이 있다.

<br>

### if문
``` cpp
#include<iostream>

using namespace std;

int main(int argc, char * argc[])
{
    int hp=100;   // 몬스터 hp
    int damage=100; // 플레이어 데미지

    hp-=dagmae; // 피격 판정
    bool isDead=(hp<=0>); // 처치 판정
    
    if(isDead)      // 몬스터가 죽었다면
        cout << "몬스터를 처치했습니다" << endl;
    else if(hp <= 20)   // 새로운 조건
        cout << "몬스터가 도망칩니다" << endl;
    else            // 몬스터가 죽지 않았다면
        cout << "몬스터가 반격했습니다" << endl;
    return 0;
}
```

<br>

> 위 코드는 데이터를 이용해서 어떤 사실에 따라 취하는 행동을 나눌 수 있다

1. 몬스터의 hp가 0보다 작거나 같다면 -> 몬스터 사망
2. 몬스터의 hp가 0보다 크다면 -> 몬스터 생존 후 반격 

<br>

### Switch - Case 문

``` cpp
#include<iostream>

using namespace std;

int main(int argc, char * argc[])
{
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    int input = ROCK;

    switch(input)
    {
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
            cout << "제대로 내주세요" << endl;
    }

    return 0;
}

```

<br>

> 위 코드와 같이 switch - case 문을 이용해서도 조건문을 작성할 수 있다.

* c++의 switch 문에서는 정수형, 열거형만 넣을 수 있다
---

<br>


## 반복문
> 특정 조건까지 어떤 행동을 반복해서 수행하고 싶을 때 사용한다

* 대표적으로 `for문`, `while문`이 있다.

<br>

### while문 

``` cpp
#include<iostream>

using namespace std;

int main(int argc, char * argv[])
{
    int count=0;
    while(count < 5)
    {
        cout << "hello world\n";
        count ++;     // 반복 횟수 count
    }

    return 0;
}

```

<br>

* while(조건식) 으로 조건식을 만족할 때 까지 반복 수행한다.

<br>

### for문 

``` cpp
#include<iostream>

using namespace std;

int main(int argc, char * argv[])
{
    for(int count = 0; count < 5; cout++)
        cout << "hello world\n";

    return 0;
}

```

<br>

* for(초기식; 조건식; 제어식) 으로 조건식을 만족할 때 까지 반복 수행한다

<br>

### ***위의 두 코드 모두 hello world를 5번 출력하는 반복문이지만 다른 방식으로 표현할 수 있다.***
> while문의 경우 for문과 다르게 제어식을 괄호안에 넣어야하기 때문에 실수가 더 발생하는 일도 있다고 한다

* break: 반복문, 조건문 중간에서 가장 가까운 반복문, 조건문을 탈출한다
* continue: 반복문에서 다음번 반복으로 스킵한다


<br>


### break 예제

``` cpp
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int round = 1;
    int hp = 100;
    int damage = 10;

    // 무한 루프: 전투 시작
    while(true)   
    {
        hp -= damage;
        if(hp < 0)
            hp = 0;   // 음수 체력을 0으로 보정

        //시스템 메시지
        cout << "Round" << round << "몬스터 체력" << hp << endl;

        if(hp == 0)
        {
            cout << "몬스터 처치" << endl;
            break;
        }

        if(rount == 5)
        {
            cout << "제한 라운드 종료" << endl;
            break;
        }
        rount ++;
        
    }

    return 0;
}
```

<br>


### continue 예제

```cpp
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
    for(int count = 1; count <= 10; count++)
    {
        bool isEven = (count % 2) == 0;  // 짝수인지 확인
        if(isEven)
            continue;                    // 짝수 스킵 

        cout << count << endl;
    }

    return 0;
}

```

---

<br>

## 열거형 데이터
> 상수 데이터들을 하나의 집합으로 관리하는 방법

<br>

### enum 사용하기

```cpp
enum ENUM_SRP
{
    ENUM_SCISSORS,      // 0
    ENUM_ROCK,          // 1
    ENUM_PAPER          // 2
}

```

<br>

> 초기화를 하지 않으면 첫 값은 0부터 시작하여 다음 값들은 이전 값 +1로 초기화된다.

<br>

### 전처리 지시문
> #include 구문을 만나면 해당 헤더파일을 찾아서 내용을 순차적으로 삽입한다.

* #include, #define, #ifndef 등
---

<br>

## 빌드 과정

<img src="./Images/CodeFlow/Proprocess.png" width = 300>

<br>

### 1. 전처리(Proprocess)

헤더 파일을 포함하고 매크로 확장을 하는 단계로
> * #include 구문을 만나면 헤더파일을 찾아 내용을 순차적으로 삽입
> * 매크로 치환 및 적용(#define, #ifdef와 같은 전처리기 매크로 치환 및 처리)

<br>

ex)
``` cpp
#include<iostream>     // 헤더 파일

#define MAX_NUM = 100  // 매크로

#define DEFINE_TEST cout << "hello world\n" ;
```

> 전처리기는 해당 매크로를 정의된 부분으로 그대로 바꿔치기 한다

<br>

> 이 때 cpp라는 전처리기를 사용하여 생성된 결과물은 포함된 헤더파일에 정의된 변수와 함수를 포함하는 `파일명.i`이다 

<br>

### 2. 컴파일(Compile)

컴파일 단계에서 c언어 코드가 cll에 의해 어셈블리어로 변한된다

<br>

1. 전단부(Front-end): 언어 종속적인 부분 처리 
 * 어휘, 구문, 의미 분석

2. 중단부(Middle-end): SSA 기반으로 최적화 수행
 * 프로그램 수행 속도 향상으로 성능을 높이기 위함
> SSA(Static Single Assignment: 정적 단일 배정) 
> * 현재 데이터 흐름 분석이나 코드 최적화를 위해 컴파일러의 중간 표현으로 사용된다


3. 후단부(Back-end): RTS로 아키텍처 최적화 수행
 * 더 효율적인 명령어로 대체해서 성능을 높이기 위함

> 이 때 결과물은 어셈블리어의 형태의 데이터와 코드를 포함하는 `파일명.s`이다.

<br>

### 3. 어셈블(Assemble)

컴파일이 끝나면 어셈블리 코드가 되고 이 코드는 어셈블러에 의해 `기계어`가 된다.
> 어셈블 단계에서는 c코드를 컴파일하고 모은다.

<br>

어셈블러로 생성되는 파일은 `명령어`와 `데이터`가 들어있는 `ELF 바이너리 포맷` 구조를 가진다
 * 링커가 여러 바이너리 파일을 하나의 실행 파일로 효과적으로 묶기 위해 `명령어와 데이터의 범위`를 일정한 규칙을 갖고 형식화 해놓는 과정

<br>

> 이 때 결과물은 각 소스에 대한 바이너리 파일(Object 파일)인 `파일명.o`이다.
 * 바이너리 파일은 데이터와 기계어를 포함한다

<br>

### 4. 링크(Link)

오브젝트 파일들과 프로그램에서 사용된 표준 C 라이브러리, 사용자 라이브러리를 링크한다
> 해당 링킹 과정을 거치면 실행파일(exe)이 만들어진다.

<br>

링크 단계에서 바이너리 파일들과 정적 라이브러리들이 연결된다.

> 이 때 결과물은 코드와 데이터를 포함하는 `실행 가능한` 바이너리 파일인 `파일명.exe`이다.
---

<br>

### 요약

1. 전처리 - 전처리기 (cpp)
    * #include, #define등 #으로 시작하는 문법 사항이 적절히 전처리된 C언어 `소스파일(source file)` 생성

2. 컴파일 - 컴파일러 (ccl) 
    * C언어 소스파일은 컴파일 과정을 거쳐 `어셈블리 소스 파일(assembly source file)`이 된다

3. 어셈블 - 어셈블러 (as)
    * 어셈블리 소스 파일은 어셈블 과정을 거쳐 `목적 파일(object file)`이 된다

4. 링크 - 링커 (ld)
    * 목적 코드는 라이브러리와 링크되어 `실행 가능한 파일(exe)`이 된다


