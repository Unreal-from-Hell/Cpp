#include <iostream>

using namespace std;

// 연습 문제

int StrLen(const char* str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return len;
}

#pragma warning(disable: 4996)

char* StrCpy(char* dest, char* src)
{
	int index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';

	return dest;
}

char* StrCat(char* dest, char* src)
{
	int index = 0;

	while (dest[index] != '\0')
	{
		index++;
	}

	int gap = index;
 	while (src[index - gap] != '\0')
	{
		dest[index] = src[index - gap];
		index++;
	}
	dest[index] = '\0';

	return dest;
}

int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		else if (a[i] < b[i])
			return -1;
		
		i++;
	}

	return 0;
}

void ReverseStr(char* str)
{
	int len = StrLen(str);
	int index = 0;
	while (index < len / 2)
	{
		int temp = str[index];
		str[index] = str[len - index - 1];
		str[len - index - 1] = temp;
		index++;
	}
}

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Helloo";
	char b[BUF_SIZE] = "aa";

	/*int len = StrLen(a);
	cout << len;*/

	// StrCpy(b, a);

	// StrCat(a, b);

	int value = StrCmp(a, b);
	cout << value << endl;

	ReverseStr(a);

	for (int i = 0; i <= StrLen(a); i++)
	{
		cout << a[i];
	}
}