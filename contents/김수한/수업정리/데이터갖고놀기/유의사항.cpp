#include <iostream>

using namespace std;

// 유의사항

// 1) 변수의 유효범위

// 전역 변수
int hp = 10;

// 스택
// {} 중괄호의 범위가 생존 범위
// 같은 이름을 두번 사용할 때 문제

// 2) 연산의 우선순위

// 3) 타입 변환

// 4) 사칙 연산 관련


int main()
{
	int hp = 77777;
	cout << hp << endl;


	// 짝수 여부
	bool isEven = (hp % 2 == 0);

	// 짝수거나 3으로 나뉘는 값인지
	bool isEvenOrDivBy3 = (hp % 2 == 0 || hp % 3 == 0); // 우선 순위가 불안하면 소괄호로 감싼다.

	// 형 변환
	short hp2 = hp; // 상위 비트 데이터가 버려지며 저장
	float hp3 = (float)hp; // 실수로 변환할 때 정밀도 차이가 있기 떄문에 데이터 손실
	unsigned int hp4 = (unsigned int)hp; // 비트 단위로 보면 같지만, 분석 방법이 달라져 의미하는 값이 다르다.

	// 곱셈
	// - 오버플로우
	//나눗셈
	// - 0 나누기 조심 (크래시가 나버린다)
	// - 실수 관련 (int형 나누기 int형은 몫이 int형으로 나온다)

	int maxHp = 1000;

	float ratio = hp / maxHp;
}