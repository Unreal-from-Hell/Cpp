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

// 2) 주소 전달 방식

void PrintInfoByPtr(StatInfo* info)
{
	cout << "----------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "----------------------" << endl;

	// const
	// * 뒤에 붙일 때
	// StatInfo* const info
	// 'info라는 변수의' 내용물(주소)을 바꿀 수 없음
	// info는 주소값을 갖는 변수 -> 이 주소값이 고정된다.
	
	// * 이전에 붙일 때
	// const StatInfo* info
	// info가 '가리키고 있는' 주소의 내용을 바꿀 수 없음
	// 

	// info[주소값]		주소값[데이터]
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

	// 포인터 vs 참조
	// 성능 : 똑같다
	// 편의성 : 참조

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인처는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있다.
	// 참조는 자연스럽게 모르고 지나칠 수도 있음. (가독성이 떨어진다)
	// ex) 마음대로 고친다
	// - const를 사용하여 개선가능 또한 명시적으로 호출할 때 OUT을 붙인다.

	// 참고로 포인터도 const를 사용 가능.
	// * 기준으로 앞 뒤 const선언하는 방식에 따라 의미가 달라짐

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 (별칭)
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음.
	// 포인터에서 '없다'는 의미로 nullptr 사용.
	// 참조 타입은 반드시 무엇인가를 가리켜야 한다는 의미에서 포인터와 미묘하게 다름

	StatInfo* pointer = nullptr;
	// pointer = &info;
	PrintInfoByPtr(&info);

	/*StatInfo& reference;
	reference = info;*/
	StatInfo& reference = info;
	PrintInfoByRef(info);

	// 사실 어느게 더 좋다에 대한 정해진 답은 없다.
	// ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	// * 사용

	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	// & 사용

	
}