#include <iostream>

using namespace std;

// 반복문

int main()
{
	// while - 동안에
	// 한번만 실행하는 것이 아닌 계속 반복해야 하는 경우
	// ex) 게임을 끌 때까지 계속 게임을 실행하라
	// ex) 목적지에 도달할 때까지~ 계속 이동하라

	// 루프문의 흐름 제어
	// break, continue

	/*int count = 0;

	while (count < 5)
	{
		cout << "Hello World" << endl;
		count++;
	}*/

	/*do
	{
		cout << "Hello World" << endl;
		count++;
	} while (false);*/

	/*
	for (int count = 0; count < 5; count++)
	{
		cout << "Hello World" << endl;

		// break; // 반복문 탈출

		// continue; // 현재 반복 생략 (반복문 한번 생략)
	}

	int round = 1;
	int hp = 100;
	int damage = 10;
	*/

	/*
	// 무한 루프 : 전투 시작
	while (true)
	{
		hp -= damage;
		if (hp < 0)
		{
			hp = 0; // 음수 체력을 0으로 보정
		}

		// 시스템 메세지
		cout << "Round " << round << " 몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "라운드 종료" << endl;
			break;
		}

		round++;
	}
	*/

	// 1 ~ 10 사이의 홀수만 출력하기
	for (int count = 1; count <= 10; count++)
	{
		bool isEven = ((count % 2) == 0);

		if (isEven)
		{
			continue;
		}
		
		cout << count << endl;
	}

}