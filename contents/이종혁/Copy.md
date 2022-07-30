# 얕은 복사와 깊은 복사

<br><br>


``` cpp
class Knight
{
public:

public:
    int _hp = 100;

};

Knight knight;        // 기본 생성자
knight._hp = 200;

knight knight2 = knight    // 복사 생성자
// knight knight2(knight)  // 복사 생성자, 위와 동일하다

knight knight3;        // 기본 생성자
knight3 = knight;      // 복사 대입 연산자 
```

<br>


