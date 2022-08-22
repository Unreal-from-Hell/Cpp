#include <iostream>

using namespace std;

// ���� ����

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [�Ű�����][RET][��������(info)][�Ű�����(&info)[RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// [�Ű�����][RET][��������(info)][�Ű�����(info)[RET][��������]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// ���� �������� �ʴ´ٸ�, ���� �� �ϴ� ���� ����

// 1) �� ���� ���

void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

// 2) �ּ� ���� ���

void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;
}

void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

// StatInfo ����ü�� 1000����Ʈ¥�� ���� ����ü���
// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� ����ȴ�. (�޸� �������̰� ũ��)
// - (�ּ� ����) StatInfo*�� 8����Ʈ �Ű�����
// - (��������)

int main()
{
	// ���� 
	int number = 1;

	// ������
	int* pointer = &number;

	// ����
	int& reference = number;
	// �ο췹��(�����) �������� ���� �۵� ����� �����Ϳ� ����
	// C++ ���������� number��� ������ �� �ٸ� �̸��� �ο��� ��.
	// �����ڿ� �̿��Ͽ� ���� �����ϸ� ���� number ������ ���� �����ϸ� ��

	reference = 3;

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByCopy(info);
}