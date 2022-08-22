#include <iostream>

using namespace std;

// 참조 기초

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [매개변수][RET][지역변수(info)][매개변수(&info)[RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// [매개변수][RET][지역변수(info)][매개변수(info)[RET][지역변수]
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식

void PrintInfoByCopy(StatInfo info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

// 2) 주소 전달 방식

void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;
}

void PrintInfoByRef(StatInfo& info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "----------------------" << endl;
}

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사된다. (메모리 성능차이가 크다)
// - (주소 전달) StatInfo*는 8바이트 매개변수
// - (참조전달)

int main()
{
	// 변수 
	int number = 1;

	// 포인터
	int* pointer = &number;

	// 참조
	int& reference = number;
	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 포인터와 같음
	// C++ 관점에서는 number라는 변수에 또 다른 이름을 부여한 것.
	// 참조자에 이용하여 값을 변경하면 실제 number 변수의 값을 변경하면 됨

	reference = 3;

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByCopy(info);
}