#include <iostream>
using namespace std;

// ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class RabbitPet : public Pet
{

};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // ���� ����
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Pet* pet = new Pet();
	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._pet = pet;

	Knight knight2 = knight; // ���� ������
	// Knight knight3(knight);

	Knight knight3; // �⺻ ������
	knight3 = knight; // ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �ȸ��� ��� �����Ϸ��� '�Ͻ�������' ������ش�

	// ���� ����
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)

	// ���� ����
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ����� �ش� (���� ��ü�� �����ϴ� ������ ���� ���� ����)

	//  �Ͻ��� ���������
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ����)
	//  ����� ���� ������
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) ��� Ŭ������ �⺻ ������ ȣ��

	//  �Ͻ��� ���� ���� ������
	// 1) �θ� Ŭ������ ���� ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ����)
	//  ����� ���� ���� ������
	// 1) �˾Ƽ� ���ִ°� ����

	return 0;
}