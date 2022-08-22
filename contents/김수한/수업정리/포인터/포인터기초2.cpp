#include <iostream>

using namespace std;

// 포인터

void SetHp(int* hp)
{
	*hp = 100;
}

int main()
{
	int hp = 1;
	SetHp(&hp);

	int number = 1;

	int* ptr = &number;

	int value1 = *ptr;
	*ptr = 2;

	// TYPE은 왜 붙혀줄까?
	// * = 포인터의 의미 = 주소를 저장하는 바구니 = 4 or 8바이트 고정 크기

	// 주소에 뭐가 있는지에 대하여
	// 포인터가 가르키고 있는 값을 어떤 자료형으로 분석할 것인지 어떻게 접근할 것인지에 대한 정보가 필요하기 때문에


	// 타입의 불일치
	__int64* ptr2 = (__int64*) & number;

	*ptr2 = 0xAABBCCDDEEFF;
}