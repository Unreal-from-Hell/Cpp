# 전달 참조 (Forwarding Reference)
> 함수의 인자로 `T&&`을 사용하고 lvalue, rvalue 모두 전달 받을 수 있다

<br>

### forward 사용
``` cpp
Knight(){cout << "기본 생성자" << endl;}
knight(const Knight& knight){cout << "복사 생성자" << endl;}
Knight(Knight&& knight){cout << "이동 생성자" << endl;}

// lvalue를 전달하면 lvalue reference
// rvalue를 전달하면 rvalue reference
template<typename T>
void Test_ForwardingRef(T&& param)
{
    // param은 우측 값 참조로 lvalue다

    // lvalue라면 복사
    Test_Copy(param)        // Knight& 전달 -> 복사 생성자 호출

    // rvalue라면 이동
    Test_Copy(move(param)); // Knight&& 전달 -> 이동 생성자 호출

    // 위의 두 가지 경우를 한 번에 해결해준다
    // 전달 참조에 의해 해당 참조에 맞는 생성자를 호출한다
    Test_Copy(forward<T>(param));
}

void Test_Copy(Knight k)
{

}

Knight k1;                      // lvalue
Test_ForwardingRef(k1);         // Knight& -> lvalue
Test_ForwardingRef(move(k1));   // Knight&& -> rvalue

auto&& k2 = k1;                 // knight& -> lvalue
auto&& k3 = move(k1);           // kngiht&& -> rvalue
```

### ***타입 추론이 발생할 때 전달 참조가 발생한다***
 * lvalue를 전달하면 -> lvalue reference
 * rvalue를 전달하면 -> value reference