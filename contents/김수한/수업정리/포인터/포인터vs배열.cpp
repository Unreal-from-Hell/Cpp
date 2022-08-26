#include<iostream>

using namespace std;

// 포인터 vs 배열

// 배열을 인자로 넘기면 컴파일러가 알아서 포인터형으로 변환함
void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	const char* test1 = "Hello World";

	char test2[] = "Hello World";

	char test3[1];

	// test3 = test2;

	Test(test2);
	cout << test2 << endl;
}