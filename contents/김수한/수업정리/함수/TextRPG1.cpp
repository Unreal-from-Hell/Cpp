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

int PlayerType;
int hp;
int attack;
int defence;

int monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();

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
		cout << "로비에 입장했습니다!" << endl;
		cout << "--------------------" << endl;

		//플레이어 직업 선택
		SelectPlayer();

		cout << "------------------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
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
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";

		cin >> PlayerType;

		if (PlayerType == PT_Knight)
		{
			cout << "기사 생성중...!" << endl;
			hp = 150;
			attack = 10;
			defence = 5;
			break;
		}
		else if (PlayerType == PT_Archer)
		{
			cout << "궁수 생성중...!" << endl;
			hp = 100;
			attack = 15;
			defence = 3;
			break;
		}
		else if (PlayerType == PT_Mage)
		{
			cout << "법사 생성중...!" << endl;
			hp = 80;
			attack = 25;
			defence = 0;
			break;
		}
	}
}

void EnterField()
{
	while (1)
	{
		cout << "--------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "--------------------" << endl;

		cout << "[PLAYER] HP : " << hp << " / ATT : " << attack << " / DEF : " << defence << endl;

		CreateRandomMonster();
	}
}

void CreateRandomMonster()
{
	// 1~3
	monsterType = 1 + rand() % 3;

	switch (monsterType)
	{
	case MT_Slime:
		cout << "슬라임 생성중...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterHp = 15;
		monsterAttack = 5;
		monsterDefence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterHp = 40;
		monsterAttack = 10;
		monsterDefence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterHp = 80;
		monsterAttack = 15;
		monsterDefence = 5;
		break;
	}
}