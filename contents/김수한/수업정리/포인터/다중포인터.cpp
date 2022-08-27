#include <iostream>

using namespace std;

// 다중 포인터

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}
void SetMessage2(const char*& a)
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	cout << a << endl;

	const char* msg = "Hello";
	SetMessage(msg);
	cout << msg << endl;

	const char** pp = &msg;
	SetMessage(&msg);
	
	cout << msg << endl;

	SetMessage2(msg);

	cout << msg << endl;
}