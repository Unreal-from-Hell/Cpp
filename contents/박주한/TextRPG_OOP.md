# 메인 cpp
``` C++
#include < iostream>
using namespace std;
#include "Game.h"

int main()
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}

	return 0; 
}

```

# Game.h
``` C++

#pragma once

class Player; // 전방 선언
class Field;
// is - a
// has - a
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();
private:

	Player* _player;
	Field* _field;
};
```
# Game. cpp
```c++
#include "Game.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Field.h"
Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game()
{
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;
}

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr)
		CreatePlayer();
	if (_player->IsDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player); // 
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "---------------------" << endl;
		cout << "캐릭터를 생성하세요" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "------------------------" << endl;

		cout << " >";

		int input = 0;
		cin >> input;

		if (input == PT_Knight) {
			_player = new Knight();
		}
		else if (input == PT_Archer)
		{
			_player = new Archer();
		}
		else if (input == PT_Mage)
		{
			_player = new Mage();
		}
	}
}
```


# Field .h

``` c++
#pragma once

class Player;
class Monster;

class Field
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();

	void StartBattle(Player* player);
private:
	Monster* _monster;
	
};


```
# Field .cpp
```C++
#include "Field.h"
#include <stdlib.h>
#include "Monster.h"
#include "Player.h"
Field::Field() : _monster(nullptr)
{

}

Field :: ~Field()
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		CreateMonster();
	StartBattle(player);
}

void Field::CreateMonster()
{
	int randValue = 1 + rand() % 3;

	switch (randValue)
	{
	case MT_SLIME:
		_monster = new Slime();
		break;
	case MT_ORC:
		_monster = new Orc();
		break;
	case MT_SKELETON:
		_monster = new Skeleton();
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		_monster->OnAttacked(player);

		if (_monster->IsDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}
		player->OnAttacked(_monster);

		if (player->IsDead())
		{
			player->PrintInfo();
			break;
		}
	}
}
```
# Monster.h 
```C++
#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELETON = 3
};
class Monster: public Creature
{
public:
	Monster(int monsterType) : Creature(CT_MONSTER), _monsterType(monsterType)
	{

	}
	virtual void PrintInfo();
protected:
	int _monsterType;
};

class Slime : public Monster
{
public:
	Slime() : Monster(MT_SLIME)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
};

class Orc : public Monster
{
public:
	Orc() : Monster(MT_ORC)
	{
		_hp = 80;
		_attack = 8;
		_defence = 3;
	}
};

class Skeleton : public Monster
{
public:
	Skeleton() : Monster(MT_SKELETON)
	{
		_hp = 100;
		_attack = 15;
		_defence = 4;
	}
};
```
# Monster.cpp
```c++
#include "Monster.h"
#include <iostream>
using namespace std;
void Monster::PrintInfo()
{
	cout << "--------------" << endl;
	cout << "[몬스터 정보 ]" << "HP: " << _hp << "ATT: " << _attack << " DEF: " << _defence << endl;
	cout << "--------------" << endl;
}
```

# Creature.h 
```C++
#pragma once
enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1
};
class Creature
{
public:
	Creature(int creatureType) : 
		_creatureType(creatureType), _hp(0), _attack(0), _defence(0)
	{

	}

	virtual ~Creature()
	{

	}

	virtual void PrintInfo() = 0;

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }

protected:
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;
};



```
# Creature.cpp
```C++
#include "Creature.h"

void Creature::OnAttacked(Creature* attacker)
{
	int damage = attacker->_attack - _defence;
	if (damage < 0)
		damage = 0;

	_hp -= damage;

	if (_hp < 0)
		_hp = 0;
}

```

# Player.h

``` C++
#pragma once
#include "Creature.h"
enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};
class Player : public Creature
{
public:
	Player(int playerType) :Creature(CT_PLAYER), _playerType(playerType)
	{

	}
	virtual ~Player()
	{

	}

	virtual void PrintInfo();
protected:
	int _playerType;
};

class Knight : public Player
{
public:
	Knight() : Player(PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}
};

class Archer : public Player
{
public:
	Archer() : Player(PT_Archer)
	{
		_hp = 87;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player
{
public:
	Mage() : Player(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 3;
	}
};
```
# Player.cpp
```C++
#include "Player.h"
#include <iostream>
using namespace std;
void Player::PrintInfo()
{
	cout << "--------------" << endl;
	cout << "[플레이어 정보  ]" << "HP: " << _hp << "ATT: " << _attack << " DEF: " << _defence << endl;
	cout << "--------------" << endl;
}
```

