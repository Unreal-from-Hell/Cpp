# List
> STL의 시퀀스 컨테이너(Sequence container)의 일종으로 `노드 기반` 컨테이너이다

 * 이중 연결리스트(double linked list)와 구조가 동일하다
 * vector, deque와는 다르게 멤버 함수에서 정렬(sort, merge), 이어붙이기(splice)가 있다
 * 원소 탐색 시 반복자(at(), [])는 불가능하고 양방향 반복자(++, --)를 이용해서 탐색한다

<br>

### 이중 연결리스트 구조
<img src = "./Images/List/LinkedList.png" width = 600>

<br>




<br>

### 리스트 사용
> 선언은 list<TYPE> 변수 이름 으로 사용한다

``` cpp
list<int> li;


```
