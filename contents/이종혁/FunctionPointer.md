# 함수 포인터(Function Pointer)

### 함수 포인터란 `함수의 주소 값`을 지닐 수 있는 포인터 변수이다

<br>

``` cpp
int (*fp)()
int (*fp2)(int)
int (*fp3)(int, int)
```

> [반환 타입] [*(함수 이름)] [매개변수]의 형태로 선언한다

<br>

단계별 함수 포인터 선언
``` cpp
int Add(int a, int b)
{
    return a + b;
}

// FUNC_TYPE 함수 타입 선언 
typedef int(FUNC_TYPE)(int, int );

// 변수 fn이름의 포인터
// 데이터 타입: 함수, 반환형:int, 매개변수(int, int)인 FUNC_TYPE
FUNC_TYPE* fn;

// 함수 포인터
fn = &Add;

// 함수의 이름은 함수의 시작 주소를 가지고 있다 -> 배열과 유사함
int result = Add(1, 2);
result = fn(1, 2);       // 함수 포인터를 통해 함수를 사용할 수 있다
result = (*fn)(1, 2);    // 접근 연산자(*)가 붙어도 함수 주소를 가르킨다

// 함수 포인터 한 번에 선언하기
int (*fn)(int, int);
```

<br>


다른 함수의 인자로 함수 전달하기

``` cpp
class Item
{
public:
    Item(): _itemId(0), _rarity(0), _ownerId(0)
    {

    }
public:
    int _itmeId;    // 아이템을 구분하기 위한 ID
    int _rarity;    // 희귀도
    int _ownerId;   // 소지자 ID
};

Item* FindItem(Item items[], int itemCount, bool(*selector)(Item* item))
{
    fot(int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        if(selector(item))
            return item;
    }
    return nullptr;
}

bool IsRareItem(Item* item)
{
    return item->_rarity >= 2;
}

Item items[10] = {};
items[3]._rarity = 2; 
Item* rareItem = FindItem(items, 10, IsRareItem);
```

<br>


### ***그러나 위 문법으로는 호출 규약이 동일한 전역함수, 정적 함수만 담을 수 있다***

<br>


멤버 함수의 포인터

```cpp
class Knight
{
public:
    int GetHp(int, int)
    {
        return _hp;
    }
public:
    int _hp = 100;
};

typedef int(Knight::*PMEMFUNC)(int, int);   // 멤버 함수 포인터

Knight k1;    

// 멤버 함수 포인터 선언 
PMEMFUNC mfn;
mfn = &Knight::GetHp;      

(k1.*mfn)(1, 1);      // 멤버 함수라는 의미를 전달하기 위해 "*" 연산자를 사용한다

Knight* k2 = new Knight();   // 클래스의 포인터형의 포인터 함수 사용
(k2->*mfn)(1, 1);

delete k2;
```

<br>

### 함수 포인터의 단점
1. 시그니처가 안 맞으면 사용할 수 없다
2. 상태를 가질 수 없다

---
<br>

## 함수 객체(Functor)
> 함수처럼 동작하는 객체로 함수 포인터의 단점을 어느정도 보완할 수 있다
> * 함수 포인터는 시그니처가 동일해야만 사용할 수 있지만, 함수 객체는 `operator()`를 오버로딩하여 쉽게 다른 시그니처를 만들어서 사용할 수 있다

 * 일반 함수와는 다르개 `상태`를 저장할 수 있다
 * 객체를 만들어주는 시점과 실행하는 시점을 분리할 수 있다
    > 예를 들어 100만 명의 플레이어가 게임에 접속하려 할 때 한 번에 접속을 시키는 것은 어렵다
    > 하지만 함수 객체를 활용하면 각 플레이어에게 `접속 요청`을 받아놓고 여유가 되는대로 접속을 시켜주도록
    > 만들 수 있다

<br>

``` cpp
class Functor
{
public:
    void operator()()      // operator() 오버로딩 
    {
        cout << "Functor Test" << endl;
        cout << _value << endl;
    }
    bool operator(int num)()
    {
        cout << "Functor Test(int num)" << endl;
        _value += num;
        cout << _value << endl;
    }
private:
    int _value = 0;
};

Functor functor;    
functor();      // functor.operator() 호출
bool ret = functor(3);     
```

<br>

### MMORPG에서 함수 객체를 사용하는 예시

<br>

클라이언트와 서버와의 통신
``` cpp

// 요청들을 저장, 실행할 객체
class MoveTask
{
public:
    void operator()()
    {
        // TODO
        cout << "해당 위치로 플레이어 이동" << endl;
    }
public:
    int _playerId;
    int _posX;
    int _posY;
}

// 서버: 클라이언트가 보내준 네트워크 패킷을 받아서 처리한다
// 클라이언트: (5, 0) 좌표로 이동 요청
MoveTask task;
task._playerId = 100;
task._posX = 5;
task._posY = 0;

// 여유 될 때 요청을 처리한다
taks();
```
