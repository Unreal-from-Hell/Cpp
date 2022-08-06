# List
> STL의 시퀀스 컨테이너(Sequence container)의 일종으로 `노드 기반` 컨테이너이다

 * 이중 연결리스트(double linked list)와 구조가 동일하다
 * vector, deque와는 다르게 멤버 함수에서 정렬(sort, merge), 이어붙이기(splice)가 있다
 * 원소 탐색 시 반복자(at(), [])는 불가능하고 양방향 반복자(++, --)를 이용해서 탐색한다

<br>

### 이중 연결리스트 구조
<img src = "./Images/List/LinkedList.png" width = 600>

<br>

### 리스트의 선언과 생성자
> 선언은 list<TYPE> 변수 이름 으로 사용한다

``` cpp
list<int> li;     // 비어있는 list 컨테이너 생성

list<int> li2(10);   // defalut(0)로 초기화된 원소 10개를 가진 list 생성

list<int> li3(3, 2); // 2로 초기화된 원소 3개를 가진 list 생성

list<int> li4(li2);  // li2를 li4로 복사 -> 복사생성자
```
<br>

## list의 멤버 함수

<br>

### 데이터 삽입
```cpp
list<int> li;
for (int i = 0; i < 100; i++)
    li.push_back(i);      // 리스트의 뒤에 삽입
// li.push_front();       // 리스트의 앞에 삽입
```

<br>

### 리스트의 크기 반환
```cpp
int size = li.size();     // 리스트의 크기 반환
```
<br>

### 데이터 삭제 및 반환

``` cpp
int first = li.front();              // 첫 번째 데이터 반환
int last = li.back();                // 마지막 데이터 반환

li.pop_front();              // 첫 번째 원소 제거
li.pop_back();               // 마지막 원소 제거
```
<br>

### 리스트의 반복자
``` cpp
list<int>::iterator itBegin = li.begin();  // 시작위치의 반복자 반환
list<int>::iterator itEnd = li.end();  // 마지막 위치의 반복자 반환

// 반복자를 이용한 리스트 순환
for (list<int>::iterator it = li.begint(); it != li.end(); ++it )
{
    cout << *it << endl;
}
```
<br>

```cpp
li.insert(itbegin, 100);  // 해당 위치에 값을 삽입
li.erase(li.begin());
li.pop_front();
li.remove(10); // value와 같은 값을 모두 삭제
```
