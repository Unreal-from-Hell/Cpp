# 함수포인터 

- typedef  
프로그래머가 타입의 별칭을 생성하고, 실제 타입 이름 대신 별칭 사용 할수 있음
 
 ```C++
typedef double distance

double Far
distance Far  // 두 문장이 같다.
 ```
 
 - typedef 함수
 ```  c++
 typedef int(FUNC_TYPE)(int a, int b);
 typedef2 int(FUNC_TYPE)(int a); 

FUNC_TYPE* fn;

fn = Add;
int result - fn(1,2);
cout << result << endl;

int result2 = (*fn)(1,2); // 함수 포인터는 *(접근 연산자)붙여도 함수 주소
cout << result2 << endl;

 return 0;
 ```
 사용하는 이유 :만약 유사한 함수가 있을경우 조금의 수정으로 굉장히  
 간편하게 수정이 가능 

 ```C++
int Add(int a, int b)
{
    return a+b;
}

int Sub(int a, int b)
{
    return a-b;
}


fn = Add;
int result - fn(1,2);
cout << result << endl;

int result - fn(1,2);
cout << result << endl;

// fn 부분만 Sub으로 바꿔줘도 댐
 ```

 - Typedef의 진실  
 typedef 왼쪽 오른쪽 기준이 아니라 선언 문법에서 typedef을 앞에다 붙이는 쪽  
 함수 포인터를 사용 할 경우 typedef int (*PFUNC)(int, int);처럼 *을 붙여야함  

 위 문법 같은 경우 [전역 / 정적 함수] 만 담을 수 있음