#include <iostream>
using namespace std;

// ���м�

// ��ü���� (OOP Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// ���м�(Data Hiding) = ĸ��ȭ(encapsulation)
// ���� �Ǵ� ���� ����ϰ� �����.
// ����� ����
// 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ������ ���忡�� ����ϴ� ��?
// - �ڵ�/���/��
// - ���� �Ǵ� �� (�ǵ帮�� ū�ϳ��� ��)
// - ����/���� ���⼱

// pubilc(������?) protected(��ȣ�޴�?) private(������?)
// - public : �������׳� ����
// - protected : �ڼտ��Ը� ����
// - private : �ڽŸ� ����� �� << class Car ���ο�����

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?
// �θ������  �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ���� ����
// - public : ������ ���? �θ���� ���� ���� �״��~ (public -> public, protected -> protected)
// - protected : ��ȣ���� ���? �� �ڼյ����׸� �����ٰž� (public -> protected, protected -> protected)
// - private : �������� ���? �������� �� ���� �ڼյ����״� �ƿ� �ȹ����ٰž� (public -> private, protected -> private)

class Car
{
public: // (���) ���� ������
	void MoveHandle() { }
	void PushPedal() { }
	void OpenDoor() { }

	void TurnKey()
	{
		// ...
		RunEngine();
	}

protected:
	void DisassembleCar() { } // ���� �����Ѵ�
	void RunEngine() { } // ������ ������Ų��
	void ConnectCircuit() { } // ���⼱ ����

public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱
};

class SuperCar : private Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : public SuperCar
{
public:
	void Test()
	{
		// DisassembleCar();
	}
};

// ĸ��ȭ

class Burserker
{
public:

	int GetHP() { return _hp; }

	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBurserkerMode();
	}

	// ��� : ü���� 50���Ϸ� �������� ����Ŀ ��� �ߵ� (������)

private:
	void SetBurserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}

private:
	int _hp = 100;
};

int main()
{
	/*SuperCar car;
	car.PushRemoteController();*/
	TestSuperCar car;
	car.PushRemoteController();

	Burserker b;

	b.SetHp(20);
}