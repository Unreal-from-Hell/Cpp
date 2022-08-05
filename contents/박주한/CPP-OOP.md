## 객체지향

- 객체지향 (실무에서 선호)
기존의 프로그래밍은 절차(procedural) 지향 프로그래밍  
procedure = 함수  
  
프로그래밍 = 데이터 + 가공(로직 , 동작)  
객체지향 = 객체
객채란? 게임에서는 모든 오브젝트 ex(플레이어 , 몬스터, Game room )  

Knight를 설계해보자
속성(데이터): hp,attack , x,y  
기능(동작): Move , Attack, Die  
  
class는 일종의 설계도  
```c++
class Knight{
public:
    //멤버 함수
    void Move(int y, int x);
    void Attack();
    void Die();
public:
    //멤버 변수 
    int hp;
    int attack;
    int posY;
    int posX;
}
void Knight::Move(int y, int x)
{
    posY =y;
    posX = x;
    cout << Move << endl;
}
void Knight::Attack(int y, int x)
{
    cout << "Attack:"<< attack << endl;
}
// instantiate 객체를 만듬
int main()
{
    Knight k1;
    k1.hp = 100;
    k1.attack = 10;
    k1.posY = 0;
    k1.posX = 0;
    Knight k2;
    k2.hp = 100;
    k2.attack = 10;
    k2.posY = 0;
    k2.posX = 0;

    k1.Move(2,2);
    k1.Attack();
    k1.Die();
}

```
  
- 생성자 소멸자  
클래스에 소속된 함수들을 멤버 함수라함  
시작을 알리는 함수-> 생성자(여러개 존재 가능)  
끝을 알리는 함수->소멸자(1개만)  
  
암시적 생성자  
생성자를 명시적으로 만들지 않으면,  
아무 인자도 받지 않는 기본생성자가 컴파일러에 의해 자동으로 만들어짐.  
그러나 우리가 명시적으로 아무 생성자 만들면 자동으로 만들어지던 기본 생성자는  
만들어지지 않음!  
```c++
class Knight{
    Knight() // 기본 생성자(인자 없음) 탄생과 즉시 생성
    
    ~Knight(){}//소멸자

    // 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음 )
    //일반적으로 똑같은 데이터를 지닌 객체가 생성되길 기대  
    Knight(const Knight& knight)
    {
        _hp =knight.hp;
        _hp =knight._attack;
        _hp =knight._posX;
        _hp =knight._posy;
    }
    // 기타 생성자

    //이중에서 인자 1개만 받는 기타 생성자를  
    //타입 변환 생성자라고 부르기도 함  

    //명시적인 용도로만 사용할것!
    explicit Knight(int hp)

    Knight(int hp, int attack, int posX, int posY)
    {
        _hp =knight.hp;
        _hp =knight._attack;
        _hp =knight._posX;
        _hp =knight._posy;
    }
public:
}
```
Knight k2(k1) // 복사 생성자  
Knight k3 - k1  // 복사 생성자  
생성하자마자 복사   
  
Knight k4; // 생성자  
Knight k4 = k1; // 복사    
생성한후 복사  
  
- 암시적 형변환 - 컴파일러가 알아서 바꿔침
```c++
int num = 1;
  
float f = (float)num; // 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문함
double d = num;// 암시적 < 별말 안했는데 컴파일러가 알아서 처리함 
```

- 상속성  
상속 ? 부모 -> 자식에게 유산을 물려주는 것  

메모리  
[ [플레이어]]  
[ Knight ]  
재정의 :부모님의 유산을 거부하고 새로운 이름으로 만든?  
-> 사실상 실전에서 잘 안 씀  
  
생성자는 탄생을 기념해서 호출되는 함수  
-knight을 만들면 -> player의 생성자도 생성됨  
knight 생성시 순서  
>Player 생성자 생성  
>Knight 생성자 생성  
>Knight 소멸자 생성  
>Player 생성자 생성  
``` c++
Class Player
{
public:
	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }
public:
	int _hp;
	int _attack;
	int _defence;
}
class Knight : public Player
{
public:

public:
	int _stamina;
};
class Knight : public Player(100)
//여기서 Player(int hp)생성자를 골라서 호출
class mage : public Player
{
public:

public:
	int mp;
};
```

- 은닉성 
은식성 == 캡슐화  
몰라도 되는 것은 깔끔하게 숨기겠다!  
숨기는 이유?
1) 정말 위험하고 건드리면 안되는 경우  
2) 다른 경로로 접근하길 원하는 경우  

자동차
>핸들  
>페달  
>엔진  
>문  
>각종 전기선  
  
일반 구매자 입장에서 사용하는것은?  
>핸들,페달,문  
몰라도 됨(오히려 건드리면 큰일남)  
엔진 각종 전기선  

public: 누구나 사용가능(pulic -> public, protected -> protected)  
protected: 나의 상속 받은 자손만 사용 가능  (public -> protected, protected -> protected)  
private : 나만 사용할꺼 << class Car 내부에서만!(public -> private, protected -> private)   

- 다형성  
겉은 똑같은데 기능이 다르게 동작한다  
>오버로딩 함수 중복 정의 = 함수 이름의 재사용  
>오버라이딩 = 재정의 부모클래스의 함수를 자식 클래스에서 재정의  

-정적 바이딩   
컴파일 시점에서 결정  
일반 함수들은 정적 바이딩 사용  


-동적 바인딩  
실행 시점에 결정  
  
가상 함수(virtual function)  
함수 앞에 virtual 붙임  
가상 함수는 재정의를 하더라도 가상 함수  
```
virtual vod Move() {cout << "Move Player"}
```
  
>가상 함수 테이블(vftable)
>클래스에 가상함수가 있으면 컴파일러는 가상 함수 테이블을 생성, 해당 클래스에 vfptr이라는 가상 함수 테이블을 가르키는 함수 포인터 변수를 생성
>>해당 클래스는 직접적으로 객체를 만들 수 없다  
>>상속 받은 자식 클래스는 순수 가상 함수를 재정의 해야만 사용 가능  
  
- 순수 가상 함수: 구현은 없고 '인터페이스'만 전달하고 싶은 경우  
순수 가상 함수가 1개 이상 포함되면 해당 클래스는 추상 클래스로 간주

```
virtual vod VAttack() = 0;
```

# 초기화 리스트  
초기화해야하는 이유  
>버그 예방  
> 포인터 등 주소값이 연루되어 있을 경우
    
멤버 변수 초기화 다양한 문법이 존재  
>생성자 본문에서 초기화
>초기화 리스트
>C++11 문법

>일단 상속 관계에서 원하는 부모 생성자 호출할 떄 필요
> 생성자 내에서 초기화 vs 초기화 리스트 
>일반 변수는 별 차이 없음  
>멤버 타입이 클래스인 경우 차이가 난다  
``` c++
class Player()
{

};
class Knight() : public Player
{
public:
    Kinght() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
    //  선처리 영역
    // inventory() 생성자 호출
    {
        // _hp = 100;
        // _inventory = Inventory(20);
        // 선처리 영역에서 기본생성자 호출 후
        // Inventory(int size) 생성자 호출 후 대입
    }
public:
    int _hp;
    Inventory _inventory;
    int & _hpRef;
    const int _hpConst;
}
class Inventory()
{
public:
    Inventory(){ cout << "Inventory()" << endl;}
    Inventory(int size){ cout << "Inventory(int size)" << endl;}
    ~Inventory(){ cout << "~ Inventory()" << endl;}
public:
    int _size = 10 ;
};
```
> 선처리 영역에서 const 또는 reference 변수와 같이 초기값이 필요한 멤버를 초기화할 수 있음  

# 연산자 오버로딩 
- 연산자 오버로딩 vs 함수  
연산자는 피연산자의 개수/타입이 고정 되어 있음  
  
연산자 오버로딩?  
일단 [연산자 함수]를 정의해야함  
함수도 멤버함수 vs 전역함수가 존재하는것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음  
  
- 멤버 연산자 함수 version
> a op b 형태에서 왼쪽으로 기준으로 실행됨(a가 클래스여야 가능. a를 기준 피연산자 라고 함)
> a가 클래스가 아니면 사용 불가 
``` c++ 
class Position
{
public:
    // 멤버 함수
    Position operator+(const Position & arg)
    {
        Position pos;
        pos._x = _x + arg._x;
        pos._y = _y + arg._y;
        return pos;
    }
public:
    int _x;
    int _y;
```

- 전역 연산자 함수 version
> a op b 형태라면 , a, b 모두를 연산자 함수의 피연산자로 만듦
>대입 연산자로 만들지 못함  

``` c++
Position operator+(int a, const Position & b)
{
    Position ret;
    ret._x = b._x + a;
    ret._y = b._y + a;

    return ret;
}
```

> 그럼 무엇이 더 좋은가? 그런거 없음, 심지어 둘 중 하나만 지원하는 경우도 있끼 때문.
>대표적으로 대입 연산자(a=b)는 전역 연산자로 만들지 못한다.