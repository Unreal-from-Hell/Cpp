# STL Algorithm
> 원소들에 대해 작업할 수 있는 여러가지 함수를 정의하고 있다

 * 검색, 정렬, 수정, 개수 세기 등등
 * 작업할 원소들은 반복자 혹은 포인터를 통해 가르킬 수 있다
 * 작업을 시작할 원소와, 작업을 끝낼 원소 바로 뒤를 인자로 받는다 (first, last) 형태

---
<br>

## 원소를 수정하지 않는 작업들

<br>

* `all_of`: 범위 안에 있는 모든 원소들이 조건을 만족하는지 확인한다
``` cpp
// 모든 데이터가 홀수인가요?
bool check = count_if(v.begin(), v.end(), [](int){ return (n % 2) != 0;});
```

* `any_of`: 범위 안의 원소들 중 조건을 만족하는 원소가 있는지 확인한다
``` cpp
// 홀수인 데이터가 하나라도 있나요?
bool check = count_if(v.begin(), v.end(), [](int){ return (n % 2) != 0;});
```

* `none_of`: 범위 안에 모든 원소들이 조건을 만족하지 않는지 확인한다
``` cpp
// 모든 데이터가 홀수가 아닌가요?
bool check = count_if(v.begin(), v.end(), [](int){ return (n % 2) != 0;});
```

* `for_each`: 범위 안에 원소들 각각에 대해 전달된 함수를 호출한다
``` cpp 
for(unsigned int i = 0; i < v.size(); i++)
    v[i] *= 3;

// 위의 코드를 간결하게 나타낼 수 있다
for_each(v.begin(), v.end(), [](int &n){ n *= 3;});
```

* `find`: 범위 안에 원소들 중 값이 일치하는 원소의 반복자를 리턴한다
``` cpp
int number = 50;
bool found = false;
vector<int>::iterator it = v.end();

for(unsigned int i = 0; i < v.size(); i++)
{
    if(v[i] == number)
    {
        found = true;
        it = v.begin() + i;
        break;
    }
}

// 위의 코드를 간결하게 나타낼 수 있다
auto itFind = find(v.begin(), v.end(), number);
```

* `find_if`: 범위 안에 원소들 중 조건과 일치하는 원소를 찾는다
``` cpp
bool found = false;
vector<int>::iterator it;

for(unsigned int i = 0; i < v.size(); i++)
{
    int data = v[i];
    if(data % 11 == 0)
    {
        found = true;
        it = v.begin() + i;
        break;
    }
}

// 위의 코드를 간결하게 나타낼 수 있다
auto itFind = find_if(v.begin(), v.end(), [](int n) {return ((n % 11) == 0);});
```

* find_if_not: 범위 안에 원소들 중 조건과 일치하지 않는 원소를 찾는다

* find_end: 어떤 원소들의 나열이 마지막으로 나타나는 위치를 찾는다

* find_first_of: 어떤 원소들 중 첫 번째로 다른 범위에서 나타나는 원소를 찾는다

* adjacent_find: 최초로 연속되서 나타나는 같은 원소를 찾는다

* `count`: 특정 값과 일치하는 원소의 개수를 센다
``` cpp
int count = count(v.begin(), v.end(), 2);
```

* `count_if`: 특정 조건을 만족하는 원소의 개수를 센다
``` cpp
int count = 0;

for(unsigned int i = 0; i < v.size(); i++)
{
    int data = v[i];
    if((data % 2) != 0)
        count++;
}
// 위의 코드를 간결하게 나타낼 수 있다
count = count_if(v.begin(), v.end(), [](int n){ return ((n % 2) != 0);});
```

* mismatch: 두 원소의 나열들 중 첫 번째로 일치하지 않는 위치를 찾는다

* equal: 두 원소의 나열들이 일치하는지 확인한다

* search: 어떤 원소들의 나열을 검색한다

* search_n: 어떤 원소들의 n번 반복된 나열을 검색한다

<br>

### 순열 관련
> 순열(permutation)이란 원소들을 어떤 순서로 나열한 것을 의미한다

<br>

 * is_permutation: 어떤 원소의 나열이 다른 원소의 나열의 순열임을 확인한다

 * next_permutation: 특정 원소들의 다음 순열을 얻는다

 * prev_permutation: 특정 원소들의 이전 순열을 얻는다

---
<br>

## 원소를 수정하는 작업들

<br>

* `copy`: 특정 범위의 값들을 다른 연속된 메모리 공간의 값들에 복사하여 대입한다
``` cpp
int a[5] = {1, 2, 3, 4, 5};
int b[5] = {6, 7, 8, 9, 10};

// a+1부터 a+4의 데이터를 복사하여 b+1부터 대입
copy(a+1, a+4, b+1);
```

* copy_n: 원소들을 n번 복사한다

* copy_if: 특정 조건에 만족하는 원소들을 복사한다

* copy_backward: 원소들을 뒤에서부터 복사한다

* move: 원소들을 이동한다

* move_backward: 원소들을 뒤에서부터 이동한다

* `swap`: 해당 변수에 있는 값들을 바꾼다
``` cpp
int a = 3, b = 5;

swap(a, b);
```
> vector에서 원소를 참조하여 각 원소에 해당하는 값들을 바꾸는 기능으로 주로 사용한다

* `swap_ranges`: 특정 범위의 값들을 다른 연속된 메모리 공간의 값들과 바꾼다

``` cpp
int a[5] = {1, 2, 3, 4, 5};
int b[5] = {6, 7, 8, 9, 10};

// a부터 a+3 범위를 b와 바꾼다
swap_ranges(a, a+3, b);
```
> vector에서 유용하게 사용된다

* `iter_swap`: iterator의 값을 바꾼다
``` cpp
iter_swap(v.begin() + 1, v.begin() + 2);
```
> vector에서 유용하게 사용된다

* transform: 특정 범위의 원소들을 변환한다

* replace: 특정 범위의 원소들을 치환한다

* replace_if: 특정 범위의 원소들을 조건이 맞을 시에 치환한다

* replace_copy: 특정 범위의 원소들을 복사한 후 치환한다

* replace_copy_if: 특정 범위의 원소들을 조건이 맞을 시에 복사한 후 치환한다

* fill: 특정 범위를 어떤 값으로 채운다

* fill_n: 특정 범위의 n개의 원소를 어떤 값으로 채운다

* generate: 특정 범위를 어떤 함수를 계속 호출해서 채운다

* generate_n: 특정 범위의 n개 원소를 어떤 함수를 계속 호출해서 채운다

* `remove`: 특정 값들을 모두 지운다
``` cpp
remove(v.begin(), v.end(), 4);
```

* `remove_if`: 특정 조건을 만족하는 원소들을 모두 지운다
``` cpp
// 1 4 3 5 8 2

// 조건에 맞는 원소들을 앞으로 재배치이후 마지막 다음의 원소를 가르키는 반복자 리턴
// 4 8 2  [iter]5 8 2

// 이후 조건에 맞는 데이터만 다음과 같이 남기기 위해서 이후 데이터들을 삭제해주어야 한다
// 4 8 2
v.erase(remove_if(v.begin(), v.end(), [](int n){return ((n % 2) == 0);}), v.end());
```

* remove_copy: 특정 값들을 복사한 후 지운다

* remove_copy_if: 특정 조건에 만족하는 원소들을 복사한 후 지운다

* `unique`: 중복되는 원소들을 뒤로 보내며 정렬한다
``` cpp
// 뒤에 남겨진 중복된 원소 삭제
v.erase(unique(v.begin(), v.end()), v.end());
```

* unique_copy: 연속적으로 다른 원소들이 나타나도록 같은 원소들을 제거하며 제거된 원소들을 복사한다

* `reverse`: 해당 컨테이너에 있는 원소들을 지정해준 구간에서 역순으로 바꾸어준다
``` cpp
string str = "hello";
reverse(str.begin(), str.end());
```

* reverse_copy: 특정 범위의 원소들의 순서를 거꾸로 해서 복사한다

* rotate: 왼쪽으로 원소들을 회전 -> circular left shift 

* rotate_copy -> 왼쪽으로 원소들을 회전시켜 복사한다

* shuffle: generator을 이용해서 원소들을 섞는다

<br>

### 파티션 관련
> 파티션(partition)이란 특정 조건을 만족하는 원소들은 앞으로 보내고 나머지들은 뒤로 보내는 작업이다

<br>

* is_partitioned: 특정 범위의 원소들이 파티션 되어 있는지 확인한다

* partition: 특정 범위의 원소들을 파티션

* stable_partition: 특정 범위의 원소들을 파티션, 이 때 원소들의 상대적 순서는 바뀌지 않는다

* partition_copy: 특정 범위의 원소들을 파티션 한 것을 복사한다

* partition_point: 파티션 된 원소들을 확인해서 첫 번째 파티션이 끝나는 점을 찾는다

<br>

### 정렬 관련

<br>

* `sort`: 컨테이너내의 원소들을 오름차순으로 정렬한다
``` cpp
sort(v.begin(), v.end());
```

* stable_sort: 특정 범위의 원소들을 안정 정렬(stable sort)한다 참고로 안정 정렬 이란 크기가 같은
원소들의 상대적 순서를 바꾸지 않는 정렬을 말한다

* partial_sort: 일부 원소들만 정렬한다

* partial_sort_copy: 일부 원소만 정렬 한 것을 복사한다

* is_sorted: 어떤 원소들이 정렬되어 있는지 확인한다

* is_sorted_until: 첫 번째로 순서에서 어긋난 원소를 찾는다

* nth_element: n 번째 원소를 찾는다

<br>

### 이진 탐색 관련

<br>

* `lower_bound`: 찾으려는 key값 보다 같거나 큰 숫자가 배열의 몇 번째에 처음 등장하는지 찾는다

* `upper_bound`: 찾으려는 key값 보다 같거나 큰 숫자가 배열의 몇 번째에 처음 등장하는지 찾는다
``` cpp
// v.begin() 을 빼주어 idx를 얻을 수 있다
lower_bound(v.begin(), v.end(), 6) - v.begin();               
upper_bound(v.begin(), v.end(), 6) - v.begin();

typeid(upper_bound(v.begin(), v.end(), 6)).name;              // iterator type
typeid(upper_bound(v.begin(), v.end(), 6) - v.begin()).name;  // int type
```
> 사용하기 전에 오름차순으로 정렬해주는 것이 좋다, iterator를 반환한다

* `equal_range`: (first-lower_bound, second-upper_bound)가 들어있는 pair를 반환한다
``` cpp
vector<int> v = {5,10,15,20, 5,25,30};
pair<vector<int>::iterator, vector<int>::iterator> p;

// first: 해당 범위 내에서 처음으로 5와 같거나 큰 원소의 반복자
// second: 해당 범위 내에ㅐ서 처음으로 5보다 큰 원소의 반복자
p = equal_range(v.begin(), v.end(), 5);
cout << *p.first << '\n';     // 5
cout << *p.second << '\n';    // 10
```
> 사용하기 전에 올므차순으로 정렬해주는 것이 좋다, iterator의 pari를 반환한다

* binary_search: 특정 값과 일치하는 원소를 찾는다

<br>

### 병합(merge) 관련
> 정렬된 원소들에 대해서 정확하게 작동한다

<br>

* merge: 두 개의 정렬된 원소들의 나열을 정렬된 상태가 유지되도록 병합한다

* inplace_merge: 두 개의 정렬된 원소들의 나열을 메모리를 추가적으로 사용하지 않도록 병합한다

<br>


### Set 관련

<br>

* includes: 특정 정렬된 원소들이 다른 정렬된 원소들을 포함하는지 확인

* set_union: 두 정렬된 원소들의 합집합을 구한다

* set_intersection: 두 정렬된 원소들의 교집합을 구한다

* set_difference: 두 정렬된 원소들의 차집합을 구한다

* set_symmetric_difference: 두 정렬된 원소들의 차이를 구한다 ((A-B) U (B-A))

---
<br>


## 힙(Heap) 관련

<br>

* push_heap: 힙에 원소를 삽입한다

* pop_heap: 힙에서 원소를 제거한다

* make_heap: 특정 원소들을 힙으로 만든다

* sort_heap: 힙의 원소들을 정렬한다

* is_heap: 특정 범위의 원소들이 힙인지 확인한다

* is_heap_until: 힙 조건을 만족하지 않는 첫 번째 원소를 찾는다

---
<br>


## 최대 / 최소 관련

<br>

* min: 최솟값을 찾는다

* max: 최댓값을 찾는다

* min_element: 최솟값의 반복자를 리턴한다

* max_element: 최댓값의 반복자를 리턴한다
``` cpp
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());
```

* minmax: 최소 및 최댓값을 찾는다

* minmax_element: 최소 및 최댓값의 반복자를 리턴한다





