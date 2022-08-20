#include <iostream>

using namespace std;

// �Լ� (���ν���, �޼ҵ�, ��ƾ)

/*

input���� ������ �ް�, output ������ ������ �����ش�.

��ȯŸ�� �Լ��̸�(����Ÿ�� �Ű�����)
{
	�Լ� ����
	
	return ---;
}

*/

// Hello World�� �ֿܼ� ����ϴ� �Լ��� ����� ����!
// input : ���� / output : ����
// Ÿ�� : int float double char void

void PrintHelloWorld() // input���� ������ �׳� ���� ����
{
	cout << "Hello World" << endl;

	return;
}

// ������ �Է� �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������
// input : int / output : ����

void PrintNumber(int number)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << number << "�Դϴ�" << endl;
}

// 2�� ���ϴ� �Լ��� ������
// input : int / output : int

int MultiplyBy2(int a)
{
	int b = a * 2;

	return b;
}

// �� ���ڸ� ���ؼ� ������� ��� �Լ��� ������
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