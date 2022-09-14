#include <iostream>
using namespace std;

// ������

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// ������(Polymorphism = Poly + Morph) = ���� �Ȱ�����, ����� �ٸ��� �����Ѵ�
// - �����ε�(Overloading) = �Լ��� �ߺ��ؼ� ���� = �Լ� �̸��� ����
// - �������̵� (Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// ���ε�(Binding) = ���´�
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε�(Dinamic Binding) : ���� ������ ����

// �Ϲ� �Լ��� ���� ���ε��� �⺻���� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ� (virtual function)

// �׷��� ���� ��ü�� � Ÿ������ ��� �˰� �˾Ƽ� �����Լ��� ȣ�����ذɱ�?
// - ���� �Լ� ���̺� (vftable)

// .virtual [] 4����Ʈ(32) 8����Ʈ(64)
// [VMove] [VDie]

// ���� ���� �Լ� : ������ ���� '�������̽�'�� �����ϴ� �뵵�� ����ϰ� ���� ���
// �߻� Ŭ���� : ���� ���� �Լ��� �� �� �̻� ���ԵǸ� �ٷ� �߻� Ŭ������ ����
// - ���������� ��ü�� ���� �� ���� ��

class Player
{
public:

	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }
	// void Move(int a) { cout << "Move Player (int)!" << endl; }
	virtual void VMove() { cout << "VMove Player !" << endl; }
	virtual void VDie() { cout << "VDie Player !" << endl; }

	// ���� ���� �Լ�
	virtual void VAttack() = 0;
	
public:
	// [  ]���� �Լ� ���̺��� ����Ű�� �ּҰ� ��
	int _hp;
};

class Knight : public Player
{
public:
	Knight()
	{
		_stamina = 100;
	}

	void Move() { cout << "Move Knight !" << endl; }

	// ���� �Լ��� �����Ǹ� �ϴ��� �����Լ��̴�.
	virtual void VMove() { cout << "VMove Knight !" << endl; }
	virtual void VDie() { cout << "VDie Knight !" << endl; }

	virtual void VAttack() { cout << "VAttack Knight" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{

public:
	int _mp;
};

void MovePlayer(Player* player)
{
	player->VMove();
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

int main()
{
	// Player p;
	// MovePlayer(&p); // �÷��̾�� �÷��̾��? YES
	// MoveKnight(&p); // �÷��̾�� ����? NO

	Knight k;
	// 3MoveKnight(&k); // ���� ����? YES
	MovePlayer(&k); // ���� �÷��̾��? YES
}