#include <iostream>

using namespace std;

// const와 메모리 구조

unsigned char flag; // 부호를 없애야 >>를 하더라도 부호비트가 딸려오지 않음

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int FEAR = 3;
const int INVINCIBLE = 4;

// 전역 변수

// [데이터 영역]
// .data (초기값 있는 경우)
int a = 2;

// .bss (초기값 없는 경우)
int b;

// .rodata (읽기 전용 데이터
const char* msg = "Hello World";

int main()
{
	// [스택 영역]
	int c = 3;
	// INVINCIBLE = 5; 변경 불가!
	// 숫자를 하드코딩 시 코드 수정 시 번거롭다.
	// 0b0000 [무적][공포][변이][스턴][공중부양]

	// 무적 상태로 만든다
	flag = (1 << INVINCIBLE);

	// 변이 상태를 추가한다. (무적 + 변이)
	flag |= (1 << POLYMORPH);

	// 무적인지 확인하고 싶다? (다른 상태는 관심 없음)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool stunOrInvincible = ((flag & 0b1010) != 0);
}