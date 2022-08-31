#include <iostream>
using namespace std;

// ��ü���� ������

// 1) struct vs class

// C++������ struct�� class�� ���� ���� ���̴�.
// struct�� �⺻ ���� �����ڰ� public�̰�, class�� private�̴�.
// �� �̷��� ������? C++�� C���� �Ļ��Ǿ� �����߱� ������, ȣȯ���� ��Ű�� ����.
// -> struct�� �׳� ����ü (������ ����)�� ǥ���ϴ� �뵵
// -> class�� ��ü ���� ���α׷����� Ư¡ ��Ÿ���� �뵵

struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};

// 2) static ����, static �Լ� (static = ���� = ������)

class Marine
{
public:
	// Ư�� ���� ��ü�� ������
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		// _hp -= 100;
		s_attack = 100;
	}

	// Ư�� ���� ��ü�� ����
	// �����̶�� 'Ŭ����' ��ü�� ����
	static int s_attack; // ���赵�����θ� ����
};

// static ������ � �޸�?
// �ʱ�ȭ �ϸ� .data
// �ʱ�ȭ ���ϸ� .bss
int Marine::s_attack = 0;

class Player
{
public:
	int _id;
};

int GenerateId()
{
	// �����ֱ� : ���α׷� ����/���� (�޸𸮿� �׻� �ö� ����)
	// ���ù��� : �Լ� ����

	// ���� ���� ��ü
	static int s_id = 1;

	return s_id++;
}

int main()
{
	//TestStruct s;
	//s._a = 1;
	//TestClass c;
	//// c._a = 1;

	Marine m1;
	m1._hp = 35;
	m1.TakeDamage(10);
	
	Marine::s_attack = 6;
	// m1.s_attack = 6;

	Marine m2;
	m2._hp = 14;
	m2.TakeDamage(10);
	// m2.s_attack = 6;

	// ���� ���ݷ� ���׷��̵� �Ϸ�! (Academy���� ���׷��̵� ��)
	Marine::s_attack = 7;
	Marine::SetAttack();

	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
}