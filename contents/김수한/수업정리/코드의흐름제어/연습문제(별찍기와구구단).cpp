#include <iostream>

using namespace std;

int main()
{
#pragma region �����
	// ����� 1
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

	// ����� 2
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// ����� 3
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

#pragma region ������
	// ������
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cout << i << "*" << j << "=" << i * j << "\n";
		}
	}
#pragma endregion
}