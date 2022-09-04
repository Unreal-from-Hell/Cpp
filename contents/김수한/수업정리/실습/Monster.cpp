#include <iostream>
#include "Monster.h"
using namespace std;

void Monster::PrintInfo()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "[몬스터 정보] " << "HP: " << _hp << "ATT: " << _attack << "DEF: " << _defence << endl;
	cout << "---------------------------------------------------------------" << endl;
}