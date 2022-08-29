#include <iostream>

using namespace std;

// ��ü ������ ����

// ���α׷��� = ������ + ����(����, ����)

// ��ü������ ���ΰ� = ��ü
// ��ü��? �÷��̾�, ����, GameRoom ��

// Knight�� �����ϱ�
// - �Ӽ� (������) : hp, attack, position(x, y)
// - ��� (����) : Move, Attack, Die

// class�� ������ ���赵
class Knight
{
public:
	// ��� �Լ�
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// ��� ����
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

// Instantiate ��ü�� �����!

void Move(Knight* knight, int y, int x)
{
	knight->_posY = y;
	knight->_posX = x;
}

int main()
{
	Knight k1;
	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2;
	k1._hp = 80;
	k1._attack = 50;
	k1._posY = 1;
	k1._posX = 1;

	Move(&k1, 2, 2);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();
}