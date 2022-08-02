# 템플릿(Template)
> 템플릿이란 함수나 클래스를 개별적으로 다시 작성하지 않아도 여러 자료형으로 사용할 수 있도록 만들어 놓은 틀

 * 매개변수의 타입에 따라 함수나 클래스를 생성하는 메커니즘
 * 타입이 매개변수에 의해 표현되므로 매개변수화 타입이라고도 불린다
 * 타입마다 별도의 함수나 클래스를 만들지 않고, 여러 타입에서 동작할 수 있는 단 하나의 함수나 클래스를
 작성하는 것이 가능하다

<br>

## 함수 템플릿(Function Template)
> 함수를 만들어 낼때, 함수의 기능은 명확하지만 자료형을 모호하게 두는 것

<br>

템플릿 사용
``` cpp
template<typename T>     // 템플릿의 타입 이름을 T로 사용
void Print(T a)
{
    cout << a << endl;
}

template<typename T>
T Add(T a, T b)
{
    return a + b;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}
```

<br>

템플릿 특수화
```cpp
class Knight
{
public:

public:
    int _hp = 100;
};

Knight k1;
Print(k1);   // 오류 발생 -> "<<" 연산자를 지원 안함

// 연산자 오버로딩을 통해 해결할 수 있다
ostream& operator<<(ostream& os, const knight& k)
{
    os << k._hp;
    return os;
}

// 템플릿 특수화
template<>
void Print(Knight a)             // knight 타입의 템플릿 함수 특수화
{
    cout << "Knight" << endl;
    cout << a._hp << endl;
}
```

> 함수 템플릿이 각각의 타입에 대해 처음으로 호출될 때, C++ 컴파일러는 해당 타입의 인스턴스를 생성한다

 * 생성된 인스턴스는 해당 타입에 대한 특수화된 템플릿 함수이다
 * 특정 타입에 대한 명시적 특수화를 제공하여 해당 타입에 대해 특별한 동작을 정의할 수 있다


---
<br>

## 클래스 템플릿(Class Template)

``` cpp
template<typename T, int SIZE>
class Randombox
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    T _data[SIZE];
};

RandomBox<int, 10> rb1;
for(int i = 0; i < 10; i++)
{
    rb1._data[i] = i;
}
int value1 = rb1.GetRandomData()
cout << value1 << endl;

RandomBox<float, 20> rb2;
for(int i = 0; i < 20; i++)
{
    rb2._data[i] = i + 0.5f;
}
float value2 = rb1.GetRandomData()
cout << value2 << endl;

// 템플릿 특수화
template<int SIZE>
class Randombox<double, SIZE>         // double 버전의 클래스 템플릿 특수화
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    double _data[SIZE];
};
```

