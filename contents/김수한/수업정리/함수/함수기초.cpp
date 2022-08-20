#include <iostream>

using namespace std;

// 함수 (프로시져, 메소드, 루틴)

/*

input으로 무엇을 받고, output 무엇을 받을지 정해준다.

반환타입 함수이름(인자타입 매개변수)
{
	함수 내용
	
	return ---;
}

*/

// Hello World를 콘솔에 출력하는 함수를 만들어 보자!
// input : 없음 / output : 없음
// 타입 : int float double char void

void PrintHelloWorld() // input값이 없으면 그냥 생략 가능
{
	cout << "Hello World" << endl;

	return;
}

// 정수를 입력 받아서, 콘솔에 출력하는 함수를 만들어보자
// input : int / output : 없음

void PrintNumber(int number)
{
	cout << "넘겨주신 숫자는 " << number << "입니다" << endl;
}

// 2를 곱하는 함수를 만들어보자
// input : int / output : int

int MultiplyBy2(int a)
{
	int b = a * 2;

	return b;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
// input : int, int / output : int

int MultiplyBy(int a, int b)
{
	int c = a * b;
	return c;
}


int main()
{
	PrintHelloWorld();

	PrintNumber(2);

	int result = MultiplyBy2(3);
	PrintNumber(result);

	int a = 3, b = 5;
	result = MultiplyBy(b, a);
	PrintNumber(result);
}