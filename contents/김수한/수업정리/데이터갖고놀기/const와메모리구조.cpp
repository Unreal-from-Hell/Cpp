#include <iostream>

using namespace std;

// const�� �޸� ����

unsigned char flag; // ��ȣ�� ���־� >>�� �ϴ��� ��ȣ��Ʈ�� �������� ����

// �ѹ� �������� ���� �ٲ��� ���� ����
// constant�� ������ const�� ���� (������ ���ȭ �Ѵٰ� ��)
// const�� �ٿ����� �ʱⰪ�� �ݵ�� �����ؾ� ��

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int FEAR = 3;
const int INVINCIBLE = 4;

// ���� ����

// [������ ����]
// .data (�ʱⰪ �ִ� ���)
int a = 2;

// .bss (�ʱⰪ ���� ���)
int b;

// .rodata (�б� ���� ������
const char* msg = "Hello World";

int main()
{
	// [���� ����]
	int c = 3;
	// INVINCIBLE = 5; ���� �Ұ�!
	// ���ڸ� �ϵ��ڵ� �� �ڵ� ���� �� ���ŷӴ�.
	// 0b0000 [����][����][����][����][���ߺξ�]

	// ���� ���·� �����
	flag = (1 << INVINCIBLE);

	// ���� ���¸� �߰��Ѵ�. (���� + ����)
	flag |= (1 << POLYMORPH);

	// �������� Ȯ���ϰ� �ʹ�? (�ٸ� ���´� ���� ����)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// �����̰ų� ���� �������� Ȯ���ϰ� �ʹٸ�?
	bool stunOrInvincible = ((flag & 0b1010) != 0);
}