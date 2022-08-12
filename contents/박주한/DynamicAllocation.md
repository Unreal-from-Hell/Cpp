## 동적할당 
프로그램이 실행되는 런타임동안 사용자가 직접 공간의 크기와 할당받는 시점을 결정하여 힙영역의 메모리를 할당 받음  
- 할당받은 메모리는 사용이 끝나면 명시적으로 메모리 할당 해제 해야함
> C언어 malloc/free  
> C++ new/delete  
  
- 스텍 영역
> 함수가 끝나면 같이 정리되는 불안정한 메모리  
> 잠시 함수에 매개변수 넘긴다거나, 하는 용도로는 ok  

- 메모리 영역  

    프로그램이 실행되는 도중에는 '무조건' 사용되는  
- 힙  
필요할때만 사용하고, 필요없으면 반납  
생성/소멸 시점을 관리 할수 있음  

유저 영역> 메모장,lol 등등  
커널 영역 (windows등의 핵심 코드)  
```
유저 영역) 운영체제에서 제공하는 API 호출  
커널 영역) 메모리 할당해서 건내줌  
```
C++에서는 기본적으로 CRT(C런타임 라이브러리)의 힙 관리자를 통해 힙 영역 사용  
단 정말 원하면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음(MMORPG 서버 메모리 풀링)  
  
  - void* 포인터  
>*가 있으니까 포인터는 포인터  
>타고 가면 void가 뭐가 있는지 모르므로 변환해서 사용  

- Malloc  
>할당할 메모리 크기를 건내준다  
>메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다(메모리 부족 NULL)  

- free
>malloc을 통해 할당된 영역을 해제  
>힙 관리자가 할당/미할당 여부를 구분해서 관리  

ex)  
```c++
void* pointer = malloc(sizeof(Monster));

Monster* m1 = (Monster*)pointer;
m1->hp = 100;
m1->_x = 1;
m1->_y = 2;
```

- new/ delete  
C++에 추가됨  
malloc/free 함수! new/delete는 연산자(operatior) 

``` c++
Monster * m2 = new Monster;
m1->hp = 100;
m1->_x = 1;
m1->_y = 2;
delete m2
```

- new[]/ delete[]  
    new가 malloc에 비해 좋긴 한데~ 배열과 같이 n개의 데이터를 같이 할당  

```c++
new[] / delete[]
Monster * m2 = new Monster[5];
m1->hp = 100;
m1->_x = 1;
m1->_y = 2;
delete m2[];
```
  
- malloc/free vs new/delete   
사용 편의성은 new/delete   
타입에 상관없이 특정한 크기의 메모리 영역을 할당> malloc/free  

근본적인 차이는 new/delete는(생성타입이 클래스일 경우) 생성자/소멸자를 호출해준다!  

## 타입 변환 
 [1] 값 타입 변환  
 특징) 의미를 유지하기 위해서 원본 객체와 다른 비트열 재구성
``` c++
int a = 123456789; 2의보수  
float b = (float)a; 부동소수점(지수 + 유효 숫자)
```
[2] 참조 타입 변환  
특징) 비트열을 재구성하지 않고, '관점'만 바꾸는 것  
거의 쓸일은 없지만, 포인터 타입 변환도 '참조 타입 변환' 동일한 룰을 따름
```c++
int  a = 123456789;
float b = (float&)a;
cout << b << endl;
```
-------안전분류 ---------  
[1]안전도 변환  

특징) 의미가 항상 100% 완전히 일치하는 경우  
같은 타입이면서 크기만 더 큰 바구니로 이동  
작은 바구니-> 큰바구니 이동 ok (업캐스팅)  
```
ex) char -> short, short -> int, int -> _int64  
```

[2] 불안전한 변환
특징) 의미가 항상 100% 일치한다고 보장하지 못하는 경우  
타입이 다르거나  
같은 타입이지만 큰 바구니-> 작은 바구니 이동(다운 캐스팅)  
``` c++
int a = 12346789;
float b = a;
short c = a;
```

------프로그래머 의도에 따라 분류 --------

[1] 암시적 변환  
특징) 이미 알려진 타입 변환 규칙에 따라 컴파일러 '자동'으로 타입 변환  
``` c++
int a = 12345789;
float b = a // 암시적으로 시키지 않아도 타입 변환
cout << b << endl;
```
[2]명시적 변환
특징)
```c++
int a = 123456789;
int*b = (int*a); //명시적 
cout <<b << endl;
```

------아무 연관 없는 클래스 사이의 변환 --------  

[1] 연관없는 클래스 사이의 '값 타입' 변환

특징) 일반적으로 안됨 
```c++
class Knight
{
    public:
    int_hp = 10;
}

class Dog
{
    public:
    int _age = 1;
    int _cuteness = 2;
}
Knight knight;
Dog dog = (Dog)knight; //불가능
```
하지만 예외로 타입 변환자 생성자, 타입 변환 연산자 사용시 가능  
```c++
class Knight
{
    public:
    int_hp = 10;
}

class Dog
{
public:
    Dog(const Knight& knight) // 타입 변환 생성자
    {
        _age= knight._hp;
    }
    operator Knight() // 타입 변환 연산자
    {
        return(Knight)(*this);
    }
    public:
    int _age = 1;
    int _cuteness = 2;
}
Knight knight;
Dog dog = (Dog)knight; // 가능 
Knight knight2 = dog;
```
[2] 연관없는 클래스 사이의 참조 타입 변환  
특징)명시적으로 ok
```c++
Knight knight;
//어셈블리 : 포인터 = 참조
//[주소] -> [Dog]
Dog& dog = (Dog&)knight;
```

------상속 관계에 있는 클래스 사이의 변환 --------  
[1] 상속 관계 클래스의 값 타입 변환  
``` c++
Dog dog;
BullDog bulldog = (BullDog)dog; //안댐

Bulldog  bulldog;
Dog dog = bulldog; //가능
```
[2] 상속 관계 클래스의 참조 타입 변환
특징)자식 -> 부모 ok / 부모-> (암시적No) (명시적 ok)
```c++
Dog dog;
BullDog& bulldog = (BullDog&)dog;
```  

## 타입 변환 (포인터)
``` c++

class item
{
public:
    Item()
    {
        cout <<"Item()" << endl; 
    }
    Item(const Item& item)
    {
        cout << "Item(const Item&)" << endl;
    }

public:
    int _itemType = 0;
    int _itemDbld = 0;

    char _dummy[4096] = {};
  
}
```

부모->  자식 변환 테스트  
[ [item]]  
[ damge] ]  
넘쳐서 다른 메모리 건드릴 확률 높다  

자식 -> 부모 변환 테스트  
암시적으로 된다!  
하지만 명시적으로 타입 변환할때 항상 조심해야 한다.  

암시적이여도 부노 -> 자식, 자식 -> 부모로 넘어가는 경우가 생기므로  
무조건 안전하지는 않다 

소멸자를 할경우 상속 받을 경우 원본의 소멸자를 사용후 삭제해야 깔끔하게 삭제됨  
부모 - 자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙여야함!    

## 얕은복사 vs 깊은 복사
 
 ``` c++
 Knight knight; 
 Knight._hp = 20; // 기본생성자

 Knight knight2 = knight; // 복사 생성자 

 Knight knight3; //기본생성자
 knight3 = knight; // 복사 대입 연산자
 ```

복사 생성자 + 복사 대입 연산자  
둘다 안 만들어주면 컴파일러 '암시적으로'만들어준다.  

```
복사 생성자 

```

얕은 복사  
멤버 데이터를 비트열 단위로 '똑같이' 복사(메모리 영역 값을 그대로 복사)  
포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리키는 상태가 됨  
Stack : Knight1 [ hp 0x1000] -> heap 0X1000 Pet[ ]  
Stack : Knight1 [ hp 0x1000] ->   
Stack : Knight1 [ hp 0x1000] ->  

깊은 복사  
멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다 (원본 객체가 참조하는 대상까지 새로 만들어서 복사함 )  
포인터는 주소값 바구니-> 새로운 객체를 생성 -> 상이한 객체 가리키는 상태가 됨  
Stack : Knight1 [ hp 0x1000] -> heap 0X1000 Pet[ ]
Stack : Knight1 [ hp 0x2000] -> heap 0X2000 Pet[ ]
Stack : Knight1 [ hp 0x3000] -> heap 0X3000 Pet[ ]

- 암시적 복사 생성자  
[ 1 ] 부모 클래스의 복사 생성자 호출  
[ 2 ] 멤버 클래스의 복사 생성자 호출  
[ 3 ] 멤버가 기본 타입일 경우 메모리 복사(얕은 복사)

- 명시적 복사 생성자   
[ 1 ] 부모 클래스의 기본 생성자 호출    
[ 2 ] 멤버 클래스의 기본 생성자 호출  

- 암시적 복사 대입 연산자  
[ 1 ] 부모 클래스의 복사 생성자 호출  
[ 2 ] 멤버 클래스의 복사 생성자 호출  
[ 3 ] 멤버가 기본 타입일 경우 메모리 복사(얕은 복사) 

- 명시적 복사 대입 연산자  
[ 1 ] 알아서 해주는거 없음 

깊은 복사를 할려면 필연적으로 명시적 복사를 사용해야하는데  
프로그래머가 다 직접 생성자 해야하므로 굉장히 조심해야함  

## 캐스팅 (타입 변환)
- static_cast :타입 원칙에 비춰볼 때 상식전인 캐스팅 만 허용  
1) int <-> float 
2) Player* -> Knight* (다운 캐스팅)  
``` c++
int hp = 100;
int maxHp = 200;
float ratio = static_cast<float>(hp) / maxHp;
``` 
- dynamic_cast: 상속 관계에서의 안전 형변환  
RTTI(RunTime Type Information)  
다형성을 활용하는 방식 virtual으로 객체의 메모리에 가상 함수 테이블 주소가 기입되며  
만약 잘못된 타입으로 캐스팅 했으면 nullptr 반환 
맞는 타입으로 캐스팅을 했는지 확인  
```C++
Knight* k2 = dynamic_cast<Knight*>(p);
```

- const_cast : const을 붙이거나 뗴거나 할떄 사용
```C++
PrintName(const_cast<char*>("Rokkiss));
```

- reinterpret_cast  
가장 위험하고 강력한 캐스터  
다시 간주하고 / 생각하다로 포인터랑 전혀 관계없는 다른 타입 변환 등  
```C++
Knight* k2;
__int64 address = reinterpret_cast(__int64>(k2);)
```