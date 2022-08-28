#include <iostream>

using namespace std;

// 포인터 연산

// 1) 주소 연산자 (&)
// 2) 산술 연산자 (+ -)
// 3) 간접 연산자 (*)
// 4) 간접 멤버 연산자 (->)

struct Player
{
	int hp; // +0
	int damage; // +4
};

int main()
{
	int number = 1;

	// 1) 주소 연산자 (&)
	// - 해당 변수의 주소를 반환
	int* pointer = &number;
	// char* ptr = &number; // 에러

	// 2) 산술 연산자 (+ -)

	// number += 1; // 1 증가

	// int*
	// - * : 포인터 타입 선언
	// - int : 해당 주소엔 int형 변수가 있다는 것을 암시

	// 포인터에서 +나 - 등 산술 연산으로 1을 더하거나 빼면,
	// 포인터가 가르키고 있는 주소 값에 1을 증감하는 것이 아닌
	// 주소값을 한번에 TYPE의 크기만큼 증감해준다.

	pointer += 2; // sizeof(int) * 2 = 8 증가

	// 3) 간접 연산자 (*)
	// - 포인터가 가리키는 해당 주소로 이동
	number = 3;
	*pointer = 3;

	// 4) 간접 멤버 연산자
	// * 간접 연산자
	// . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리에서는 사실상 덧셈)
	// ->는 *과 .을 한번에 처리
	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;
	(*playerPtr).hp = 200;
	(*playerPtr).damage = 20;

	playerPtr->hp = 300; 
	playerPtr->damage = 30;
}