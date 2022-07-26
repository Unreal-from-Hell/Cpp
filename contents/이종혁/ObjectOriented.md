# 객체지향 프로그래밍(OOP)

<br>

## OOP(Object Oriented Programming)
객체지향 프로그래밍은 컴퓨터 프로그래밍 패러다임 중 하나로
> 프로그래밍에서 필요한 데이터를 `추상화`시켜 `상태`와 `책임(행동)`을 가진 `객체`를 만들고 그 객체들 간의 `협력`을 통해 객체간의 조화를 이루며 적극적으로 상호작용하는 협력적인 객체를 창조하는 것이다

<br>

<details>
  <summary> <b>참고</summary>
  <div markdown="0">
  <a href = "https://github.com/jonghyeok98/ReadingRecord/tree/main/contents/%EA%B0%9D%EC%B2%B4%EC%A7%80%ED%96%A5%EC%9D%98%20%EC%82%AC%EC%8B%A4%EA%B3%BC%20%EC%98%A4%ED%95%B4">OOP</a>
  </div>
</details>

---
<br>

## 생성자
> C++ 에서 생성자(Constructer)를 통해 객체를 생성함과 동시에 멤버 변수를 초기화 할 수 있다

 * 클래스 이름과 동일한 이름으로 구현된다

<br>

### 생성자의 특징
1. 생성자는 반환값이 없다
2. 생성잔는 오버로딩 될 수 있다

<br>

### 기본 생성자
``` cpp
class Knight
{
public:           
    int _hp;        
    int _attack;
    int _posX;
    int _posY; 
public:
    Knight()                   // 기본 생성자
    {
        cout << "Knight() 기본 생성자 호출" << endl;
        _hp = 100;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }
    Knight(int hp)                   // 기타 매개변수를 받는 생성자
    {
        cout << "Knight() 기본 생성자 호출" << endl;
        _hp = hp;         // 받아온 매개변수로 초기화
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }
}
```
<br>

* 팀에 따라 mHp, m_hp 등으로 매개변수를 구분하도록 작성한다
* `기본 생성자`는 매개 변수를 가지지 않으며 별도로 지정하지 않으면
* `디폴트 생성자`가 멤버 변수를 0, NULL 등으로 초기화 한다

<br>

### ***명시적으로 생성자를 `하나`라도 만들면 디폴트 생성자는 호출되지 않는다***

<br>

### 복사 생성자
> 일반적으로 `같은 데이터를 지닌` 객체를 생성할 때 사용된다

 * 자기 자신의 클래스와 동일한 참조 타입을 인자로 받는다
 * 동적 할당의 경우 깊은 복사가 이루어지도록 해주어야한다

``` cpp
Knight(const Knight& knight)
{
    _hp = knight.hp;
    _attack = knight.attack;
    _posX = knight._posX;
    _posY = knight._posY;
}
```
---
<br>

## 소멸자
> 객체의 수명이 끝났을 때 객체를 제거하기 위한 목적으로 사용된다
> * 객체의 수명이 끝났을 때 자동으로 컴파일러가 소멸자 함수를 호출한다

 * 클래스명과 동일하며 `~` 기호를 사용한다
 * 동적 할당이 이루어졌을 경우 이 때 함께 해제한다

 ``` cpp
 ~Kinght()
 {
    cout << "Knight() 소멸자 호출" << endl;
 }
 ```
---
<br>




