#include <iostream>

using namespace std;

// �񱳿���� ������

int a = 1;
int b = 2;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isInvincible = true;


int main()
{
#pragma region �� ����

	// ���� �ʿ��Ѱ�?
	// ex) ü���� 0�� �Ǹ� ���
	// ex) ü���� 30% ���ϰ� �Ǹ� �ñر⸦ �ߵ�
	// ex) ����ġ�� 100 �̻��̸� ������

	// a == b : a�� b�� ���� ������?
	// ������ 1, �ٸ��� 0
	isSame = (a == b);

	// a != b : a�� b�� ���� �ٸ���?
	// �ٸ��� 1, ������ 0
	isDifferent = (a != b);

	// a > b : a�� b���� ū��?
	// a >= b : a�� b���� ũ�ų� ������?
	// ������ 1, �ƴϸ� 0
	isGreater = (a > b);

	// a < b : a�� b���� ������?
	// a <= b : a�� b���� �۰ų� ������?
	// ������ 1, �ƴϸ� 0
	isSmaller = (a < b);

#pragma endregion

#pragma region �� ����

	// ���� �ʿ��Ѱ�? ���ǿ� ��� ���� ��� �ʿ��� ��
	// ex) �α����� �� ���̵� ���� AND ��й�ȣ�� ���ƾ� �Ѵ�.
	// ex) ��� �������̰ų� OR ��� �����̸� ��� �ػ� ����

	// ! not
	// 0�̸� 1, �ƴϸ� 0
	test = !isSame;

	// && and
	// a && b -> �� �� 1�̸� 1, �� �� 0
	test = (hp <= 0 && isInvincible == false); // ����

	// || or
	// a || b -> �� �� 0�̸� 0, �� �� 1
	test = (hp > 0 || isInvincible == true); // �����

#pragma endregion
}