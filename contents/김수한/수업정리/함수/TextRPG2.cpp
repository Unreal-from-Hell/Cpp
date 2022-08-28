#include <iostream>

using namespace std;

// TextRPG

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer,
	PT_Mage
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

struct ObjectInfo
{
	int type;
	int hp;
	int attack;
	int defence;
};

ObjectInfo playerInfo;

ObjectInfo monsterInfo;


void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	srand(time(0));

	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		cout << "--------------------" << endl;
		cout << "�κ� �����߽��ϴ�!" << endl;
		cout << "--------------------" << endl;

		//�÷��̾� ���� ����
		SelectPlayer();

		cout << "------------------------------" << endl;
		cout << "(1) �ʵ� ���� (2) ���� ����" << endl;
		cout << "------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlayer()
{
	while (1)
	{
		cout << "------------------------------" << endl;
		cout << "������ ����ּ���!" << endl;
		cout << "(1) ��� (2) �ü� (3) ����" << endl;
		cout << "> ";

		cin >> playerInfo.type;

		if (playerInfo.type == PT_Knight)
		{
			cout << "��� ������...!" << endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.type == PT_Archer)
		{
			cout << "�ü� ������...!" << endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defence = 3;
			break;
		}
		else if (playerInfo.type == PT_Mage)
		{
			cout << "���� ������...!" << endl;
			playerInfo.hp = 80;
			playerInfo.attack = 25;
			playerInfo.defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (1)
	{
		cout << "--------------------" << endl;
		cout << "�ʵ忡 �����߽��ϴ�!" << endl;
		cout << "--------------------" << endl;

		cout << "[PLAYER] HP : " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF : " << playerInfo.defence << endl;

		CreateRandomMonster();

		cout << "-----------------" << endl;
		cout << "(1) ���� (2) ����" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (playerInfo.hp == 0)
				return;
		}
		else
		{
			return;
		}
	}
}

void CreateRandomMonster()
{
	// 1~3
	monsterInfo.type = 1 + rand() % 3;

	switch (monsterInfo.type)
	{
	case MT_Slime:
		cout << "������ ������...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterInfo.hp = 15;
		monsterInfo.attack = 5;
		monsterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << "��ũ ������...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << "���̷��� ������...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defence = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerInfo.attack - monsterInfo.defence;
		if (damage < 0)
			damage = 0;

		// ����
		monsterInfo.hp -= damage;
		if (monsterInfo.hp < 0)
			monsterInfo.hp = 0;

		cout << "���� ���� ü�� : " << monsterInfo.hp << endl;

		if (monsterInfo.hp == 0)
		{
			cout << "���͸� óġ�߽��ϴ�!" << endl;
			return;
		}
		
		damage = monsterInfo.attack - playerInfo.defence;
		
		if (damage < 0)
			damage = 0;

		// �ݰ�
		playerInfo.hp -= damage;
		if (playerInfo.hp < 0)
			playerInfo.hp = 0;

		cout << "�÷��̾� ���� ü�� : " << playerInfo.hp << endl;
		if (playerInfo.hp == 0)
		{
			cout << "����� ����߽��ϴ�...GAME OVER" << endl;
			return;
		}
	}
}