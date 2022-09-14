#include <iostream>

using namespace std;

// 객체 지향의 시작

// 프로그래밍 = 데이터 + 가공(로직, 동작)

// 객체지향의 주인공 = 객체
// 객체란? 플레이어, 몬스터, GameRoom 등

// Knight를 설계하기
// - 속성 (데이터) : hp, attack, position(x, y)
// - 기능 (동작) : Move, Attack, Die

// class는 일종의 설계도
class Knight
{
public:
	// 멤버 함수
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

// Instantiate 객체를 만든다!

void Move(Knight* knight, int y, int x)
{
	knight->_posY = y;
	knight->_posX = x;
}

int main()
{
	Knight k1;
	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2;
	k1._hp = 80;
	k1._attack = 50;
	k1._posY = 1;
	k1._posX = 1;

	Move(&k1, 2, 2);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();
}