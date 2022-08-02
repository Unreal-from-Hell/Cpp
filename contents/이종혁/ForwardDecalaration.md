# 전방 선언(Forward Declaration)
> 실제로 식별자를 정의하기 전에 식별자의 존재를 컴파일러에 미리 알리는 것

<br>

함수의 전방 선언을 하기 위해선 함수 원형(prototype)이라고 하는 선언문을 사용해야 한다.
> 함수 원형은 [반환형] [함수 이름] [매개 변수]; 로 구성된다

 * 함수의 정의는 포함하지 않는다

<br>

``` cpp
// 전방 선언
int sum(int x, int y);   // 함수 원형, 선언문

int main()
{
    cout << sum(3, 5) << endl;
    return 0;
}

int sum(int x, int y)    // 함수 정의
{
    return x + y;
}
```
<br>

### ***전방 선언은 클래스에도 적용된다***

<br>

``` cpp
// #include "Monster.h"

// 전방 선언
class Monster;

class Player
{
public:

public:
    int _hp;
    int _attack;

    // Monster _target;   클래스를 정의한 헤더파일이 필요하다 
    Monster* _target;     // 전방 선언으로도 충분하다
    // class Monster* _target;   이또한 전방 선언이다
}
```

> 클래스를 멤버로 직접 포함하게 되면 해당 클래스의 크기를 정확히 알아야하기 때문에 클래스를 선언한 헤더파일이 필요하다

 * 반면 해당 클래스 타입의 포인터로 포함하게 되면 주소 값의 크기는 고정이기 때문에 전방 선언으로 충분하다

<br>


### ***단, 클래스 내부의 멤버 함수 혹은 변수에 접근하기 위해서는 클래스를 선언한 헤더파일을 포함해야한다***
