#include <iostream>

using namespace std;

// ������

void SetHp(int* hp)
{
	*hp = 100;
}

int main()
{
	int hp = 1;
	SetHp(&hp);

	int number = 1;

	int* ptr = &number;

	int value1 = *ptr;
	*ptr = 2;

	// TYPE�� �� �����ٱ�?
	// * = �������� �ǹ� = �ּҸ� �����ϴ� �ٱ��� = 4 or 8����Ʈ ���� ũ��

	// �ּҿ� ���� �ִ����� ���Ͽ�
	// �����Ͱ� ����Ű�� �ִ� ���� � �ڷ������� �м��� ������ ��� ������ �������� ���� ������ �ʿ��ϱ� ������


	// Ÿ���� ����ġ
	__int64* ptr2 = (__int64*) & number;

	*ptr2 = 0xAABBCCDDEEFF;
}