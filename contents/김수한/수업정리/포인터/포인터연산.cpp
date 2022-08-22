#include <iostream>

using namespace std;

// ������ ����

// 1) �ּ� ������ (&)
// 2) ��� ������ (+ -)
// 3) ���� ������ (*)
// 4) ���� ��� ������ (->)

struct Player
{
	int hp; // +0
	int damage; // +4
};

int main()
{
	int number = 1;

	// 1) �ּ� ������ (&)
	// - �ش� ������ �ּҸ� ��ȯ
	int* pointer = &number;
	// char* ptr = &number; // ����

	// 2) ��� ������ (+ -)

	// number += 1; // 1 ����

	// int*
	// - * : ������ Ÿ�� ����
	// - int : �ش� �ּҿ� int�� ������ �ִٴ� ���� �Ͻ�

	// �����Ϳ��� +�� - �� ��� �������� 1�� ���ϰų� ����,
	// �����Ͱ� ����Ű�� �ִ� �ּ� ���� 1�� �����ϴ� ���� �ƴ�
	// �ּҰ��� �ѹ��� TYPE�� ũ�⸸ŭ �������ش�.

	pointer += 2; // sizeof(int) * 2 = 8 ����

	// 3) ���� ������ (*)
	// - �����Ͱ� ����Ű�� �ش� �ּҷ� �̵�
	number = 3;
	*pointer = 3;

	// 4) ���� ��� ������
	// * ���� ������
	// . ����ü�� Ư�� ����� �ٷ� �� ��� (����������� ��ǻ� ����)
	// ->�� *�� .�� �ѹ��� ó��
	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 20;

	playerPtr->hp = 300; 
	playerPtr->damage = 30;
}