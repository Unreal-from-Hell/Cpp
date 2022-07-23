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

<br>


## 열거형(enum)
















