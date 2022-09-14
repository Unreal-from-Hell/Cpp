#include <iostream>
using namespace std;

// Ÿ�� ��ȯ (������)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{

	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDbid = 0;

	char _dummy[4096] = {};
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _damage = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		Knight* knight = new Knight();

		// �Ͻ��� X ����� O
		Item* item = (Item*)knight;
		// item->_itemType = 2;
		// item->_itemDbid = 1;

		delete knight;
	}

	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
	{
		Item* item = new Item();

		Weapon* weapon = (Weapon*)item;

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		Weapon* weapon = new Weapon();

		Item* item = weapon;

		delete weapon;
	}

	// ����� ��ȯ�� �׻� ����
	// �Ͻ����� ����?
	// 

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// ******************* �ſ� �߿� ******************************

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			delete weapon;
		}
		else
		{
			Armor* armor = (Armor*)item;
			delete armor;
		}
	}

	// [���]
	// - ������ vs �Ϲ� Ÿ�� : ���̸� ��������
	// - ������ ������ Ÿ�� ��ȯ(ĳ����)�� �� ���� �ſ� �ſ� �����ؾ� �Ѵ�!
	// - �θ�-�ڽ� ���迡�� �θ� Ŭ������ �Ҹ��ڿ��� ����� ���� virtual�� ������!

	return 0;
}