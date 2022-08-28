#include <iostream>

using namespace std;

// 지역 변수와 값 전달

// 전역변수
int globalValue = 0;

void Test()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	hp += 1;
}

// [매개변수][RET][지역변수] [매개변수][RET][지역변수] [매개변수][RET][지역변수]

int main()
{
	// 지역 변수
	int localValue = 0;

	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;

	Test();

	int hp = 1;

	cout << "Increase 호출 전 : " << hp << endl;
	IncreaseHp(hp);
	cout << "Increase 호출 후 : " << hp << endl;


}