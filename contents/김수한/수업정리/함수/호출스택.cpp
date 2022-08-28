#include <iostream>
using namespace std;

// 호출 스택

// 함수 선언
void Func1();
void Func2(int hp, int mp);
void Func3(float a);

void Func1()
{
	cout << "Func1" << endl;

	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;

	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;

}

int main()
{
	cout << "main" << endl;
	Func1();
}