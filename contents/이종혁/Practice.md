# 연습문제

<br>

## 문자열

<br>

```cpp
#include <iostream>
using namespace std;

// 문자열 연습 문제

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(char* str)
{
	// str이라는 문자열의 길이를 반환
	int count = 0;
	
	while (str[count] != '\0')
		count++;

	return count;
}

// 문제2) 문자열 복사 함수
char* StrCpy(char* dest, char* src)
{
	/*int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;*/
	
	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return ret;
}

// 문제3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{
	/*int len = StrLen(dest);
	
	int i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';

	return dest;*/

	char* ret = dest;
	while (*dest)
		dest++;
	
	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return ret;
}

// 문제4) 두 문자열을 비교하는 함수
int StrCmp(char* a, char* b)
{
	int i = 0;

	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;

		if (a[i] < b[i])
			return -1;
		i++;
	}

	return 0;
}

// 문제5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "a";
	char b[BUF_SIZE] = "aa";

	// int len = StrLen(a);
	// cout << len;
	// StrCpy(b, a);
	// StrCat(a, b);

	int value = StrCmp(a, b);
	cout << value << endl;
}
```

---
<br>

## 달팽이

<br>

``` cpp
#include <iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}
void SetBoard()
{
	int dir = RIGHT;
	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;
		
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];
		
		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}
}

int main()
{
	cin >> N;
	
	SetBoard();

	PrintBoard();
	
	return 0;
}
```