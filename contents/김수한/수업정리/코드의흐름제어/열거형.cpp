#include <iostream>

using namespace std;

// 열거형


// 1) 숫자 지정을 안하면 첫 값은 0부터 시작
// 2) 그 다음 값들은 이전 값 + 1
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK, // 2
	ENUM_PAPER // 3
};

// #이 붙은거 -> 전처리 지시문
// #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙!
// 1) 전처리 2) 컴파일 3) 링크
// #define 사용은 최대한 지양하자
#define DEFINE_SCISSORS 1

int main()
{

}