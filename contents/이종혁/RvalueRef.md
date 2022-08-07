# 우측 값 참조 (Rvalue Reference)
> 우측 값 참조란 메모리의 `복사`가 아닌 `이동`의 개념이다

 * 원본은 날려도 된다는 힌트를 주는 것이다 

<br>

### Lvalue VS Rvalue
* lvalue: 단일식을 넘어서 지속되는 개체
* rvalue: lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

``` cpp
// a와 b는 모두 lvalue
// 1과 2는 대입 이후 소멸되기 때문에 rvalue
int a = 1;
int b = 2;

// rvalue에는 값을 대입할 수 없다
3 = b;      // Error ! 식이 수정할 수 있는 lvalue여야 합니다
```

<br>

### 우측 값 참조 사용
> 연산자 `&&`를 사용한다

``` cpp
// 복사하여 넘겨준다
void TestKnight_Copy(Knight knight){}               // readonly

// 참조자(포인터)를 넘겨준다, lvalue 참조
void TestKnight_LValueRef(Knight& knight){}         // 원본 수정 가능

// rvalue는 수정할 수 없기 때문에 const를 사용하여 넘겨줄 수 있다
void TestKnight_ConstLValueRef(const Knight& knight){}  // readonly, 함수 또한 const만 전달 가능

// 원본을 사용하고 날려도 된다 -> 이동 대상 ! 
void TestKnight_RValueRef(Knight&& knight){}        // 원본 수정 가능

```


<br>

### 이동 생성자와 이동 대입 연산자
``` cpp
// 복사 생성자
Knight(Knight& knight)
{
    // 깊은 복사
    _hp = knight._hp;
    _pet = new Pet(knight->_pet);
}

// 복사 대입 연산자
void operator=(Knight& knight)
{
    // 깊은 복사
    _hp = knight._hp;
    _pet = new Pet(knight->_pet);
}

// 이동 생성자
Knight(Knight&& knight)
{
    // 얕은 복사
    _hp = knight._hp;
    _pet = knight._pet;

    // 원본을 이동 후 삭제
    knight._pet = nullptr;
}

// 이동 대입 연산자
void operator=(Knight&& knight)
{
    // 얕은 복사 
    _hp = knight._hp;
    _pet = knight._pet;

    // 원본을 이동 후 삭제
    knight._pet = nullptr;
}
```

### ***우측 값 참조로 넘겨주었다는 것은 더이상 원본을 유지하지 않아도 된다는 뜻이다***
 * 해당 원본이 `이동 대상`이 되었다는 것

<br>

## std::move

 * 본래 이름 후보 중 하나가 `rvalue_cast` 였다고 한다

``` cpp
Knight k2;
Knight k3;

// 우측 값 참조
k3 = static_cast<Knight&&>(k2);
k3 = move(k2);      // 우측 값 참조로 원본을 이동
```

<br>

### move의 사용
``` cpp
// 1개만 존재해야하는 unique_ptr
unique_ptr<Knight> uptr = make_unique<Knight>();

unique_ptr<Knight> uptr2 = make_unique<Knight>(); // Error ! 

// uptr -> uptr2로 우측 값 참조 (메모리 이동)
unique_ptr<Knight> uptr2 = move(uptr);
```