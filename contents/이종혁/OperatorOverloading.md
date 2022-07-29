# 연산자 오버로딩
> 기존의 제공하고 있는 `연산자를 재정의`하여 사용자 정의 클래스로 사용하는 것
> * 전역 함수 또는 멤버 함수로 정의한다 
> * 키워드 `operator` 사용

<br>

``` cpp
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

    // 대부분의 연산자 오버로딩은
    // 자기 자신의 참조 값을 return 한다
    // 복사 대입 연산자
    Position & operator=(const Position & arg)
    {
        _x = arg._x;
        _y = arg._y;
        // Position * this = 자기 자신의 주소의 형태로
        // this 포인터가 존재한다
        return * this;
    }
public:
    int _x;
    int _y;
}

// 전역 함수
Position::operator+(int a, const Position & arg)
{
    Position pos;
    pos._x = a + arg._x;
    pos._y = a + arg._y;
    return pos;
}

Position pos, pos2, pos3;

pos3 = pos + pos2;           
pos3 = pos.operator+(pos2);
// 위 두 가지는 동일하다

pos3 = 1 + pos;
// 멤버 함수로 구현하면 1.operator(pos)와 동일하기 때문에 실행불가
```

<br>

### 멤버 함수 연산자
a operator b 형태에서 왼쪽 기준으로 실행되며 a가 클래스여야 한다.
 * a를 `기준 피연산자`라고 함
 * a가 클래스가 아니면 사용을 못한다 

<br>

### 전역 함수 연산자
a operator b 형태에서 a, b 모두 피연산자
 * 대입 연산자(a = b)는 전역 함수 형태가 불가능하다

<br>

### ***왜 참조 값을 매개변수로 받아올 때 const로 해야할까?***
> 다른 operator의 return 값이 Position & 이 아닌 Position 형태로 수정할 수 없는 복사 값을 건네주더라도 const Position & 형태로 참조하면 가능하다
> * 매개변수의 참조 값을 변경할 일이 없는 경우 type mismatch 오류를 줄일 수 있다.

<br>


### 오버로딩이 불가능한 연산자
|연산자|이름|
|---|---|
|.|멤버선택|
|.*|멤버 포인터 선택|
|::|범위|
|?:|조건|
|#|문자열 전처리기 변환|
|##|전처리기 연결|

<br>

### 단항 연산자의 오버로딩

<br>

1. 전위형(++a)
``` cpp
Position & operator++()
{
    _x++;
    _y++;
    return * this;
}
```

<br>

2. 후위형(a++)
``` cpp
Position & operator++(int)
{
    _x++;
    _y++;
    return * this;
}
```

<br>

> 전위형과 후위형을 구분해주기 위한 용도로만 후위형 단항연산자에 매개변수 int를 전달한다