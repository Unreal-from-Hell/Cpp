#include <iostream>

using namespace std;

// 연습 문제

int strLen(const char* str)
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

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = "World";

	/*int len = strLen(a);
	cout << len;*/

	// StrCpy(b, a);

	StrCat(a, b);
}