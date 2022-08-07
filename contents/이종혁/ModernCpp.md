# Modern C++
> C++11 부터를 Modern C++이라고 부르며 코드를 짧고 간결하게 가독성을 높여주는 새로운 기능들이다

<br>

## auto
> auto 키워드를 사용하면 변수를 선언할 때 특정 자료형을 지정하지 않아도 된다

 * 컴파일 단계에서 자동으로 타입을 추론한다
 * 단, 초기화 하지 않고 사용할 수 없다
 
<br>

### auto의 사용
``` cpp
auto Int = 3;           // int
auto Float = 3.14f;     // flaot
auto Double = 1.23;     // double
auto Class = Knight();  // class
auto String = "Hello";  // string

const auto Const = 3;   // 상수
auto& ref = Int;        // 참조자
auto* ptr = &Int;       // 포인터
auto* Func = printf;    // 함수 포인터
auto Begin = v.begin(); // iterator

auto Temp;  // Error! 초기화 되지 않은 변수 
```

---
<br>

## 범위 기반 for문

<br>

### auto를 사용해 반복문을 간단하게 만들 수 있다
``` cpp
for(vector<int>::iterator it = v.begin(); it != v.end(); ++i);

for(auto it = v.begin; it != v.end(); ++it);
```

<br>

### Modern C++ 에서는 Python처럼 범위 기반 for문을 지원한다
``` cpp
for(auto& it : v);      // 배열 혹은 컨테이너
```
 * 참조자를 사용하여 복사 비용을 줄이고 값에 직접 접근이 가능하다

---
<br>

## 균일한 초기화(Uniform Initalization)
> 중괄호 초기화라고도 부르며 초기화 시 `()` 대신 `{}`를 사용한다

 * 모든 종류의 객체를 일관성있게 리스트형 초기화(Initializer list)를 통해 다양한 방식으로
 초기화할 수 있다

<br>

### 다양한 사용법
``` cpp
int v{5};                           // 변수 초기화
int v[]{1, 2, 3};                   // 배열 초기화

vector<int> v(3);                   // 길이가 3인 비어있는 벡터
vector<int> v{1, 2, 3};             // 원소 1, 2 ,3이 들어가있는 벡터

int* v = new int[3] {1, 2, 3};      // 동적할당 초기화

// 함수의 리턴 값으로 사용
vector<int> func(){return {1, 2, 3};}
vector<int> v = func();

// 함수의 인자로 사용
void func(vector<int> v){ for(auto i : v)cout << i << endl;}
func({1, 2, 3});
```
> vector등 container에 사용하면 유용하다

<br>

### 축소 변환을 방지한다
```cpp
int x = 0;
double y{x};   // Error ! 
```

<br>

### initializer_list
> 배열이나 컨테이너를 정의할 때 중괄호 초기화 `{}`를 사용하면 initializer list를 이용하여 초기화한다

<br>

### initializer_list 사용 시 주의할 점
``` cpp
class Knight
{
public:
    Knight()
    {

    }
    Knight(int a, int b)
    {

    }
    // 생성자 호출 시 initializer_list의 우선권이 높다
    Knight(initializer_list<int> li)
    {

    }
};

Knight k{1, 2};       // initializer_list 호출
Knight k(1, 2.5);     // Knight(int a, int b) 호출 double -> int 축소 변환
Knight k{1, 2.5};     // initializer_list 호출 Error ! 축소 변환
```
> 중괄호 초기화 `{}`를 사용하여 객체를 생성할 경우, 생성자 오버로딩 시에 해당 함수가 `최우선`으로 고려된다

 * 해당 문제를 방지하기 위해선 initializer_list의 원소 타입으로 타입 변환 자체가 불가능한 경우여야 한다

<br>

### 괄호 초기화 `()`
 * 전통적인 C++ 방법으로 거부감이 없다
 * vector 등 특이한 케이스에 대해서만 중괄호 초기화 `{}` 사용

<br>

### 중괄호 초기화 `{}`
 * 초기화 문법의 일치화를 위해 사용한다
 * 축소 변환을 방지한다

<br>

### initializer_list 와 auto
> `{}`를 사용하여 초기화 할때 `auto`를 사용하여 변수 타입을 정의하면 컴파일러는 어떤 방식으로 추론할까 ?

``` cpp
auto a = {1};           // initializer_list<int>
auto b{2};              // int
auto c = {1, 2};        // initializer_list<int>
auto d = {1, 2, 2.5};   // Error (인자들의 타입이 다름)
auto e{1, 2};           // Error (인자가 여러 개)
```

<br>

### 규칙은 다음과 같다
 * `auto x = {arg1, arg2, ...}` 형태: 인자들이 모두 같은 타입이라면 initializer_list<T>로 추론된다
 * `auto x{arg1, agr2, ...}` 형태: 인자가 1개라면 해당 타입으로 추론되고 여러 개일 경우 오류가 발생한다

---
<br>


## nullptr
> C++ 11부터 추가된 키워드로 Null Pointer를 뜻한다

 * 포인터만을 위한 NULL 상수이다

``` cpp
int* ptr = nullptr;
```

---
<br>

## using
> 내부적으로는 `typedef`와 동일하지만 직관성과 기능을 더해 생긴 새로운 키워드이다

 * `using 지시문`: `using namespace std`를 사용하여 std namespace의 모든 것을 사용하고 싶다고 컴파일러에게 알릴 수 있다

<br>

### typedef와 차이점
``` cpp
// 1. 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2. 템플릿 사용 여부
template<typename T>
using Vector = vector<T>;
```

---
<br>

## Enum Class(scoped enum)
> 기존의 eunm은 별도의 이름공간(namespace)를 가지지 않기 때문에 중복을 해결하는 문제가 발생했다

 * 기존의 enum의 단점을 보완하기 위해 등장했다
 * 열거자 이름에 의한 중복이 없다
 * 암시적인 형변환이 불가능하다
 * 전방선언이 가능하다

<br>

### eunm class의 사용법
 * 정의: enum class 열거형 이름
 * 접근: 열거형 이름::열거자

``` cpp
enum class PlayerType : int;    // 전방 선언

enum class PlayerType : int     // default는 int형이다
{
    Player,
    Knight,
    Monster
}

int id = PlayerType::Player;
double id2 = PlayerType::Knight:    // Error! 암시적인 형변환 불가
```

---
<br>

## Delete Function(삭제된 함수)
> 특정 함수의 호출을 금지하고 싶은 경우에 사용한다

### 기존의 방식
``` cpp
class knight
{
private:
    // 정의되지 않은 비공개 함수로 선언하여 외부에서 함수 사용을 막는 기능이다
    void operator=(const Knight& k);    // 외부에서 복사 금지
};
```
> private로 선언하면 외부에서 해당 함수 호출이 불가능하고 friend나 자기 자신이 호출 하면
> 링크 과정에서 에러를 발생시킨다

 * 구체적으로 컴파일러 입장에서는 현재 선언이 있는 것을 보고 정의가 어딘가 있겠지 생각한다. 해당 파일이 없으면
외부에서 연결해주겠지 하고 역할을 넘겨버리고 결국 Linker에서 linking을 하는 과정에서 에러가 발생한다

<br>

### ***에러는 빨리 알수록 좋다***

<br>

### 새로운 방식
``` cpp
class knight
{
public:
    // 함수를 사용하지 못하게 삭제 하는 기능
    void operator=(const Knight& k) = delete;
};
```

* 함수를 제공하지 않을 때: 함수 호출 시 인자가 변환 가능 타입을 가지는 동일 이름의 다른 함수를 호출한다
* 선언만 한 경우일 때: 링크 에러를 유발한다
* `delete`를 사용할 때: 컴파일 에러를 유발한다

<br>

### ***delete 선언은 public에 사용하는 것이 좋다***
 * delete된 함수를 호출하면 컴파일러가 "삭제된 함수를 참조하려고 합니다"라고 오류 메시지를 띄워준다
 * private에 선언한 경우 접근 권한 에러가 뜰 가능성이 높아 제대로 된 오류 메시지를 받을 수 없다

<br>

### delete는 주로 아래의 경우 사용한다
1. 일반 함수 삭제
2. 함수 템플릿 생성시 특정 타입에 대한 삭제
3. 멤버 함수 삭제 (e.g. 복사 생성자, 복사 대입 연산자)
4. 싱글톤, 복사 금지 스마트 포인터, mutex 등

---
<br>


## Virtual, Override, Final
> 상속 관련 오버라이딩을 할 때 사용하는 키워드로 용도가 조금씩 다르다

<br>

### ***키워드를 통해서 오버라이딩의 범위를 표현한다***

<br>

### Virtual
> 가상 함수를 뜻하며 해당 클래스를 상속받는 하위 클래스에서 함수를 재정의 할 때 사용한다

 * 순수 가상 함수: 함수의 몸체를 정의하지 않는 것으로 자식 클래스에서 재정의를 필수로 해야한다
 * 일반 가상 함수: 함수의 몸체를 정의하는 것으로 자식 클래스에서 재정의 여부를 선택할 수 있다

<br>

``` cpp
class Player
{
public:
    virtual void print() = 0;   // 순수 가상 함수

    virtual void print          // 일반 가상 함수
    {
        cout << "Player" << endl;
    }
};
```

### ***Virtual은 상속의 시작을 알린다 즉, 부모 클래스에서 사용한다***

<br>

### Override
> C++11 이후에 나온 키워드로 자식 클래스에서 override 했음을 표현한다

<br>

``` cpp
class Knight : public Player
{
public:
    virtual void print() override
    {
        cout << "Knight" << endl;
    }
};
```

### Final
> C++11 이후에 나온 키워드로 가상 함수의 마지막을 표현한다

 * 즉, 마지막 하위 클래스의 가상 함수에서 사용한다
 * 더 이상 해당 함수를 오버라이딩 하지 않겠다는 의미이다

<br>

``` cpp
class Archer: public Player
{
public:
    virtual void print() final
    {
        cout << "Archer" << endl;
    }
};
```





