#include <iostream>

using namespace std;

// ĳ���� (Ÿ�� ��ȯ)

class Player
{
public:
	virtual ~Player() { }
};

class Knight : public Player
{
public:

};

class Archur : public Player
{
public:
};

class Dog
{

};

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
	// static cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ������ش�
	// 1) int <-> float
	// 2) Player*(�θ�) -> Knight*(�ڽ�) (�ٿ� ĳ����) <- ��, ������ ���� X

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;

	Player* p = new Knight();
	Knight* k1 = static_cast<Knight*>(p);

	// dynamic_cast : ��� ���迡���� ���� ����ȯ
	// RTTI (RunTime Type Information)
	// �������� Ȱ���ϴ� ���
	// - virtual �Լ��� �ϳ��� �����, ��ü�� �޸𸮿� ���� �Լ� ���̺� (vftable) �ּҰ� ���Եȴ�
	// - ���� �߸��� Ÿ������ ĳ������ ������. nullptr ��ȯ
	// �̸� �̿��ؼ� �´� Ÿ������ ĳ������ �ߴ��� Ȯ�ο� �����ϴ�
	Knight* k2 = dynamic_cast<Knight*>(p);

	// const_cast : const�� �����ų� �� �� ���
	PrintName(const_cast<char*>("Toram"));

	// reinterpret_cast
	// ���� �����ϰ� ������ ������ ĳ����
	// 're-interpret' : �ٽ�-�����ϴ�/�����ϴ�
	// - �����Ͷ� ���� ������� �ٸ� Ÿ�� ��ȯ ��
	__int64 address = reinterpret_cast<__int64>(k2);
	
	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);

	return 0;
}