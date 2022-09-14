#include <iostream>
using namespace std;

// 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
};

class RabbitPet : public Pet
{

};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // 깊은 복사
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // 깊은 복사
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Pet* pet = new Pet();
	Knight knight; // 기본 생성자
	knight._hp = 200;
	knight._pet = pet;

	Knight knight2 = knight; // 복사 생성자
	// Knight knight3(knight);

	Knight knight3; // 기본 생성자
	knight3 = knight; // 복사 대입 연산자

	// [복사 생성자] + [복사 대입 연산자]
	// 둘 다 안만든 경우 컴파일러가 '암시적으로' 만들어준다

	// 얕은 복사
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)

	// 깊은 복사
	// 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어 준다 (원본 객체가 참조하는 대상까지 새로 만들어서 복사)

	//  암시적 복사생성자
	// 1) 부모 클래스의 복사 생성자 호출
	// 2) 멤버 클래스의 복사 생성자 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사)
	//  명시적 복사 생성자
	// 1) 부모 클래스의 기본 생성자 호출
	// 2) 멤버 클래스의 기본 생성자 호출

	//  암시적 복사 대입 연산자
	// 1) 부모 클래스의 복사 대입 연산자 호출
	// 2) 멤버 클래스의 복사 대입 연산자 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사)
	//  명시적 복사 대입 연산자
	// 1) 알아서 해주는게 없음

	return 0;
}