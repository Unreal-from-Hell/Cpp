#include <iostream>

using namespace std;

// ���� ����

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [�Ű�����][RET][��������(info)][�Ű�����(&info)[RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 2) �ּ� ���� ���

void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;

	// const
	// * �ڿ� ���� ��
	// StatInfo* const info
	// 'info��� ������' ���빰(�ּ�)�� �ٲ� �� ����
	// info�� �ּҰ��� ���� ���� -> �� �ּҰ��� �����ȴ�.
	
	// * ������ ���� ��
	// const StatInfo* info
	// info�� '����Ű�� �ִ�' �ּ��� ������ �ٲ� �� ����
	// 

	// info[�ּҰ�]		�ּҰ�[������]
}

#define OUT
void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

int main()
{
	StatInfo info;

	CreateMonster(&info);

	// ������ vs ����
	// ���� : �Ȱ���
	// ���Ǽ� : ����

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// ����ó�� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִ�.
	// ������ �ڿ������� �𸣰� ����ĥ ���� ����. (�������� ��������)
	// ex) ������� ��ģ��
	// - const�� ����Ͽ� �������� ���� ��������� ȣ���� �� OUT�� ���δ�.

	// ����� �����͵� const�� ��� ����.
	// * �������� �� �� const�����ϴ� ��Ŀ� ���� �ǹ̰� �޶���

	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸� (��Ī)
	// -> �����ϴ� ����� ������ �ȵ�
	// �ݸ� �����ʹ� �׳� � �ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����.
	// �����Ϳ��� '����'�� �ǹ̷� nullptr ���.
	// ���� Ÿ���� �ݵ�� �����ΰ��� �����Ѿ� �Ѵٴ� �ǹ̿��� �����Ϳ� �̹��ϰ� �ٸ�

	StatInfo* pointer = nullptr;
	// pointer = &info;
	PrintInfoByPtr(&info);

	/*StatInfo& reference;
	reference = info;*/
	StatInfo& reference = info;
	PrintInfoByRef(info);

	// ��� ����� �� ���ٿ� ���� ������ ���� ����.
	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ ������ ���
	// ex) �𸮾� �������� reference�� �ֿ�

	// Bonus) �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	// * ���

	// Bonus) ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?
	// & ���

	
}