#include <iostream>

using namespace std;

// 배열

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// TYPE 이름 [개수];

	// 배열 크기는 상수여야 함 (VS 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 변수 이름은 데이터가 저장되는 메모리에 이름을 붙혀준거지만
	int a = 10;
	int b = a;

	// 배열의 이름은 조금 다르다
	StatInfo players[monsterCount];

	// players = monster; // 사용 불가

	// 배열의 이름이란 ?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAmI = monsters;

	// StatInfo[ (100, 10, 1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ]  ...
	// monster_0[ 주소 ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// StatInfo[ 100, 10, 1) ] StatInfo[ (200, 20, 2) ] StatInfo[ ] StatInfo[ ] StatInfo[ ]  ...
	// monster_1[ 주소 ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다
	// StatInfo[ 100, 10, 1) ] StatInfo[ (200, 20, 2) ] StatInfo[ (300, 30, 3) ] StatInfo[ ] StatInfo[ ]  ...
	// monster_2[ 데이터 ]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 아래는 완전 다른 의미다
	StatInfo temp;
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 자동화
	for (int i = 0; i < monsterCount; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// 가독성이 떨어진다.. 더 편한방법
	// 인덱스
	// 배열은 0부터 시작. N번쨰 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) = monster[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	int hp = monsters[0].hp;

	for (int i = 0; i < monsterCount; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법
	int numbers[5] = {}; // 0으로 초기화
	int numbers1[10] = { 1, 2, 3, 4, 5 }; // 설정된 이후 값들은 0으로 초기화
	int numbers2[] = { 1, 2, 3, 4, 5, 6, 7, 8 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다.
	
	// 요약
	// 1) 선언한다
	int arr[10] = {};

	// 2) 인덱스로 접근
	arr[1] = 1;
	cout << arr[1] << endl;
}