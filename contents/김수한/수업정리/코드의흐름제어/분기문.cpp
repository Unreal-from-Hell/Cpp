#include <iostream>

using namespace std;

// �б⹮
// �����͸� �޸𸮿� �Ҵ��ϰ� �����ϴ� ���
// 

int main()
{
	int hp = 100; // ���� hp
	int damage = 100; // �÷��̾� ������

	hp -= damage; // �ǰ� ����
	bool isDead = (hp <= 0); // óġ ����

	// ���Ͱ� �׾����� ����ġ �߰�
	// ��������� CMP JMP

	if (isDead)
	{
		cout << "���͸� óġ�߽��ϴ�" << endl;
		cout << "���͸� óġ�߽��ϴ�" << endl;
	}
	else if (hp <= 20)
	{
		cout << "���Ͱ� �������� �ֽ��ϴ�" << endl;
	}
	else
	{
		cout << "���Ͱ� �ݰ��߽��ϴ�" << endl;
	}

	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	if (input == ROCK)
	{
		cout << "������ �½��ϴ�" << endl;
	}
	else if (input == PAPER)
	{
		cout << "���� �½��ϴ�" << endl;
	}
	else if (input == SCISSORS)
	{
		cout << "������ �½��ϴ�" << endl;
	}
	else
	{
		cout << "�� ���̴ϱ� ? " << endl;
	}

	// switch-case

	// ���� �迭�� ���� �� �ִ�.
	switch (input)
	{
	case ROCK:
		cout << "������ �½��ϴ�" << endl;
		break;
	case PAPER:
		cout << "���� �½��ϴ�" << endl;
		break;
	case SCISSORS:
		cout << "������ �½��ϴ�" << endl;
		break;
	default:
		cout << "�� ���̴ϱ�?" << endl;
		break;
	}
}