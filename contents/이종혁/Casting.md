# C++ Casting

<br>

```cpp
int hp = 100;
int maxHp = 200;
float ratio = (float)hp / maxHp;   // c스타일 형변환
ratio = static_cast<float>(hp) / maxHp  // static_cast

class Player
{

};

class Knight : public Plyaer
{

};

class Archer : public Player
{

};
```

---
<br>

## 1. static_cast
> 타입 원칙에 비춰볼 때 논리적인 캐스팅만 허용해준다

 * 형변환 능력을 가진 가장 기본적인 캐스팅 연산
 * 형변환 시점이 c스타일과는 다르게 컴파일 타임이기 때문에 오류를 미리 발견할 수 있다
 * 포인터 형변환이 불가능하지만 업캐스팅, 다운캐스틷은 가능하다
    * 단, 다운캐스팅의 경우 안정성은 보장하지 못한다

<br>

### ***따라서 이미 캐스팅 할 자료가 어떤 타입인지 어느정도 알 수 있는 경우 사용하는게 좋다***

<br>

``` cpp
Plyaer* player = new Knight();          // new Archer()인 경우 잘못된 캐스팅으로 위험하다
Knight* knight = static_cast<Knight*>(player);    
```
> 해당 위험을 방지하기 위해 dynamic_cast가 나왔다

---
<br>

## 2. dynamic_cast
> 런타임에 동적으로 상속 관계를 가로지르거나 다운캐스팅을 할 때 사용된다

 * 다형성을 이용해 모호한 타입 캐스팅을 시도할 경우에 사용
 * 다형성을 띄지 않은 객체간 형변환은 불가능하며 시도시 컴파일 에러가 발생 
 * 캐스팅을 실패할 경우 nullptr을 반환한다
 
<br>

RTTI(RunTime Type Information)에 의존적이기 때문에 캐스팅 연산 비용도 꽤 비싼 편에 속하고 연산 비용은 상속 체계의 복잡도와 깊이에 따라 증가한다
 * 다형성을 가지려면 virtual 멤버 함수가 존재해야한다

<br>

``` cpp
knight* knight2 = dynamic_cast<Knight*>(player);
```

<br>

### ***올바른 타입으로 캐스팅을 했는지 확인할 때 유용하다***

---
<br>

## 3. const_cast
> 포인터나 참조의 상수성(const)을 제거하거나 추가할 떄 사용한다
> * 대부분 제거의 목적을 위해 사용된다

 * volatile 키워드를 잠깐 제거하는데도 사용
 * 형변환은 불가능하나 상수성을 제거하는 것에 사용
 
<br>

``` cpp
void Print(char* str)
{
    cout << str << endl;
}

Print("print");   // const char* 타입이기 때문에 오류 발생
Print(const_cast<char*>("print"));
```

### ***실제로 사용하는 일은 거의 없다고 한다***

---
<br>

## 4. reinterpret_cast
> 가장 위험하고 강력한 형태의 캐스팅으로 모든 포인터간의 형 변환을 허용한다

 * 캐스팅 대상을 해당 타겟 타입으로 비트단위 재해석을 거치는 캐스팅이다
 * 연관성이 없는 포인터 타입을 변환하기 위해서 사용한다
 * 캐스팅 결과가 컴파일러마다 다를 수 있다
 * 정수 자료형의 경우 메모리 주소값으로 변경할 수 있다 ***`매우 위험`***

<br>

``` cpp
knight* k2;

__int64 address = k2;     // 아무런 연관성이 없는 캐스팅
__int64 address = (__int64)k2;    // c스타일의 캐스팅이지만 위험하다 
__int64 address = reinterpret_cast<__int64>(k2);
```

