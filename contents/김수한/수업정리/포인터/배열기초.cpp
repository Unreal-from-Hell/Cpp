#include <iostream>

using namespace std;

// �迭

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// TYPE �̸� [����];

	// �迭 ũ��� ������� �� (VS �����Ϸ� ����)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// ���� �̸��� �����Ͱ� ����Ǵ� �޸𸮿� �̸��� �����ذ�����
	int a = 10;
	int b = a;

	// �迭�� �̸��� ���� �ٸ���
	StatInfo players[monsterCount];

	// players = monster; // ��� �Ұ�

	// �迭�� �̸��̶� ?
	// �迭�� �̸��� �� �迭�� ���� �ּ�
	// ��Ȯ���� ���� ��ġ�� ����Ű�� TYPE* ������
	auto WhoAmI = monsters;

	// StatInfo[ (100, 10, 1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ]  ...
	// monster_0[ �ּ� ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// StatInfo[ 100, 10, 1) ] StatInfo[ (200, 20, 2) ] StatInfo[ ] StatInfo[ ] StatInfo[ ]  ...
	// monster_1[ �ּ� ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// �����Ϳ� ������ ��������� ��ȯ �����ϴ�
	// StatInfo[ 100, 10, 1) ] StatInfo[ (200, 20, 2) ] StatInfo[ (300, 30, 3) ] StatInfo[ ] StatInfo[ ]  ...
	// monster_2[ ������ ]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [����] �Ʒ��� ���� �ٸ� �ǹ̴�
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// �ڵ�ȭ
	for (int i = 0; i < monsterCount; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// �������� ��������.. �� ���ѹ��
	// �ε���
	// �迭�� 0���� ����. N���� �ε����� �ش��ϴ� �����Ϳ� �����Ϸ��� �迭�̸�[N]
	// *(monsters + i) = monster[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	int hp = monsters[0].hp;

	for (int i = 0; i < monsterCount; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// �迭 �ʱ�ȭ ����
	int numbers[5] = {}; // 0���� �ʱ�ȭ
	int numbers1[10] = { 1, 2, 3, 4, 5 }; // ������ ���� ������ 0���� �ʱ�ȭ
	int numbers2[] = { 1, 2, 3, 4, 5, 6, 7, 8 }; // ������ ������ŭ�� ũ�⿡ �ش��ϴ� �迭�� ������ش�.
	
	// ���
	// 1) �����Ѵ�
	int arr[10] = {};

	// 2) �ε����� ����
	arr[1] = 1;
	cout << arr[1] << endl;
}