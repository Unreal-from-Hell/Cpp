#include <iostream>
using namespace std;

// 타입 변환 (포인터)

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
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

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	{
		// 스택 [ (4) (4) (4096) ]
		Item item;

		// 스택 [ 주소 ] ->힙 [ (4) (4) (4096) ]
		Item* item2 = new Item();

		TestItem(item);
		TestItem(*item2);

		TestItemPtr(&item);
		TestItemPtr(item2);

		// 메모리 누수(Memory Leak) -> 점점 가용 메모리가 줄어 크래시
		delete item2;
	}

	{
		cout << "---------------------------------------" << endl;

		Item item3[100] = {};

		cout << "---------------------------------------" << endl;
		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
			item4[i] = new Item();

		cout << "---------------------------------------" << endl;
		
		for (int i = 0; i < 100; i++)
			delete item4[i];

		cout << "---------------------------------------" << endl;

	}
	return 0;
}