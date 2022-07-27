## 로또 번호 생성기

<br>

``` cpp
#include <iostream>

using namespace std;

// 로또 번호 생성기

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i번째 값이 제일 좋은 후보라고 가정
		int best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾아나선다
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		// 제일 좋은 후보와 교체하는 과정
		if(i != best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = rand() % 45 + 1;

		// 이미 찾은 값인지?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// 이미 찾은 값
				found = true;
				break;
			}
		}

		// 못 찾았으면 추가!
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };
	Sort(numbers, sizeof(numbers) / sizeof(int));

	// 3) 로또 번호 생성기
	ChooseLotto(numbers);

	// 행운의 로또 앱 완성!
	for (int i = 0; i < 6; i++)
		cout << numbers[i] << endl;
}
```