#include <iostream>

using namespace std;

// �Լ� ������

// �����ε� (�ߺ� ���� : �Լ��� �̸��� ����)
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

int Add(int a)
{
	int result = a + 1;
	return result;
}

float Add(float a, float b)
{
	float result = a + b;
	return result;
}

// �⺻ ���ڰ�
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 1, int castleId = 2)
{

}

// ���� �����÷ο�
int Factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * Factorial(n - 1);
}


int main()
{
	float result = Add(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo(100, 40, 10);

	// result = Factorial(1000000);
	cout << result << endl;
}