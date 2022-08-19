#include <iostream>

using namespace std;

int main()
{
	srand(time(0)); // �õ� ����

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	int wins = 0, total = 0;

	do
	{
		cout << "����(1) ����(2) ��(3) ����ּ���!" << endl;
		cout << "> ";
		
		if (total == 0)
		{
			cout << "���� �·� : ����" << endl;
		}
		else
		{
			int winPercentage = wins * 100 / total;
			cout << "���� �·� : " << winPercentage << endl;
		}

		// ��ǻ��
		int computer = 1 + (rand() % 3);

		// �����
		int input;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (computer)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �̰���ϴ�!" << endl;
				total++;
				wins++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (computer)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				total++;
				wins++;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (computer)
			{
			case SCISSORS:
				cout << "��(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case ROCK:
				cout << "��(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				total++;
				wins++;
				break;
			case PAPER:
				cout << "��(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				break;
			}
		}
		else
		{
			break;
		}

	} while (1);
}