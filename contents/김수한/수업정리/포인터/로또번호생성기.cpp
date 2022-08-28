#include <iostream>

using namespace std;

// 로또 번호 생성기

void Swap(int&, int&);
void Sort(int numbers[], int count);
void ChooseLotto(int numbers[]);

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);

	// cout << a << " " << b << endl;

	// 2) 정렬 함수 만들기 (오름차순)
	int numbers[] = { 1, 42, 3, 15, 5, 6 };
	int length_numbers = sizeof(numbers) / sizeof(int);
	Sort(numbers, sizeof(numbers)/sizeof(int));


	// 3) 로또 번호 생성기
	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count)
{
	for (int i = count; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			int temp = 0;
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));
	
	int count = 0;
	bool found = false;
	while (count < 6)
	{
		numbers[count] = 1 + (rand() % 45);
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == numbers[count])
			{
				found = true;
				break;
			}
		}
		if (found)
			continue;
		count++;
	}

	Sort(numbers, 6);
	// TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요. (단 중복이 없어야 함)
}