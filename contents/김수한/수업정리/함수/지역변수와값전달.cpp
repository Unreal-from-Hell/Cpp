#include <iostream>

using namespace std;

// ���� ������ �� ����

// ��������
int globalValue = 0;

void Test()
{
	cout << "���� ������ ���� : " << globalValue << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	hp += 1;
}

// [�Ű�����][RET][��������] [�Ű�����][RET][��������] [�Ű�����][RET][��������]

int main()
{
	// ���� ����
	int localValue = 0;

	cout << "���� ������ ���� : " << globalValue << endl;
	globalValue++;

	Test();

	int hp = 1;

	cout << "Increase ȣ�� �� : " << hp << endl;
	IncreaseHp(hp);
	cout << "Increase ȣ�� �� : " << hp << endl;


}