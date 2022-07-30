#  동적 할당(Dynamic Allocation)
> 프로그램이 실행되는 런타임동안 `사용자가 직접` 공간의 크기와 할당받을 시점을 결정하여 `힙 영역`의 메모리를 할당 받는 것

 * 할당받은 메모리는 프로그램이 끝날 때까지 유지되므로 메모리 사용이 끝나면 명시적으로 메모리 할당을 해제해야 한다
 * 대표적으로 C언어의 malloc/free, C++의 new/delete가 있다

<br>

## Malloc / Free
> 기본적으로 (void *)malloc(unsigned int) 의 형식을 가지고 있다

 1. 할당할 메모리 크기를 건네주면 
 2. 메모리 할당 후 시작 주소를 가르키는 포인터를 반환해준다 
    * 단, 실패시 NULL 포인터 반환

<br>

``` cpp
class Knight{}

void * num = malloc(20);

Knight * knight = (Knight *)num;   // 할닫받은 메모리를 Knight 타입으로 사용

free(num);                         // 할당한 메모리 해제
knight = nullptr;                  // 할당 받은 주소를 없앤다

int * num = (int *)malloc(sizeof(int));   // int형 배열 동적할당 
```

> malloc의 기본형이 `void *`이기 때문에 사용하고 싶은 타입으로 형 변환하여 사용해야 한다

 * 할당한 메모리 해제 이후에도 knight가 해당 메모리 영역의 주소를 가르키고 있다
 * 할당하지 않은 메모리 영역에 접근할 수 있기 때문에 해제 이후에는 nullptr로 초기화 해주어야 한다

<br>

### ***스택에 할당되는 고정 배열과는 다르게 `힙 영역`에 할당되므로 많은 메모리를 할당해야 하는 프로그램은 동적 할당하는 것이 일반적이다***
> 100만 개 크기의 배열을 스택에 할당하면 오버플로우가 발생하지만 동적 할당을 이용하면 문제없이 할당할 수 있다

<br>


## New / Delete
> 기본적으로 new TYPE으로 사용한다

 * malloc과는 다르게 할당할 타입을 명시하면 해당 크기만큼 할당해준다

<br>

``` cpp
int * num = new int;          // int형 변수 동적 할당
int * array = new int[5];     // 크기가 5인 int형 배열 동적 할당

int * array2 = new int[5]();  // 동적 배열을 0으로 초기화
int * array3 = new int[5]{1, 2, 3, 4, 5};   

delete num;                  // 변수 메모리 할당 해제
delete[] array;              // 배열 메모리 할당 해제
delete[] array2;
delete[] array3;

```

<br>

> C++ 11 부터 초기화 리스트를 사용해 동적 배열을 초기화할 수 있다.

 * 동적 배열을 길이를 `명시적`으로 선언해야한다 

<br>


### malloc VS new

1. malloc은 `함수`고 new는 `연산자`이다
2. 배열과 같이 N개의 데이터를 같이 할당하려면 new가 편리하다
3. ***new는 생성타입이 클래스일 경우 `생성자와 소멸자를 호출`해준다***



