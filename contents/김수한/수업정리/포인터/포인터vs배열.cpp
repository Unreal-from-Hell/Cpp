#include<iostream>

using namespace std;

// ������ vs �迭

// �迭�� ���ڷ� �ѱ�� �����Ϸ��� �˾Ƽ� ������������ ��ȯ��
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