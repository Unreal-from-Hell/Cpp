#include <iostream>

using namespace std;

int main()
{
#pragma region º°Âï±â
	// º°Âï±â 1
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// º°Âï±â 2
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// º°Âï±â 3
	cin >> N;

	for (int i = N; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
#pragma endregion

#pragma region ±¸±¸´Ü
	// ±¸±¸´Ü
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << "*" << j << "=" << i * j << "\n";
		}
	}
#pragma endregion
}