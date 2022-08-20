#include <iostream>

using namespace std;

// 스택 프레임

void PrintHelloWorld()
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


// f5
// f10
// f11
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