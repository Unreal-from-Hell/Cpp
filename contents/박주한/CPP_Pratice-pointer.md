## 코드의 흐름과 제어
- 별1
```c++
int main() {
	int input;
	cin >> input;
	for (int i = 0; i < input; i++) {
		{
			for (int j = 0; j < input; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
}
```
- 별 2
```C++
int main() {
		int input;
		cin >> input;
		for (int i = 0; i < input; i++) {
			{
				for (int j = 0; j < i+1; j++) {
					cout << "*";
				}
				cout << endl;
			}
		}
	}
```

- 구구단
```C++
int main() {
		int input;
		cin >> input;
		for (int i = 2; i < 9; i++) {
			{
				for (int j = 1; j < 10; j++) {
					int answer = i * j;
					cout << i << "*" << j << "=" << answer << endl;
				}
				cout << endl;
			}
		}
	}

```

- 가위바위보 

``` C++
int main()
{
	srand(time(0));

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	while (true) {
		cout << "가위 (1) 바위 (2) 보 (3)를 입력하세요" << endl;
		cout << ">";

		int computerValue = 1 + (rand() % 3);

		int input;
		cin >> input;

		if (input == computerValue) {
			cout << "비겼습니다" << endl;
		}
		else if ((input == SCISSORS && computerValue == PAPER) || (input == ROCK && computerValue == SCISSORS) || (input == PAPER && input == ROCK)) {
			cout << "이겼습니다" << endl;
		}
		else if ((input == SCISSORS && computerValue == ROCK) || (input == ROCK && computerValue == PAPER) || (input == PAPER && input == SCISSORS)){
			cout << "졌습니다" << endl;
		}
	}
}  

이외에도 switch으로 가능
```
- 로또번호형 
``` c++
#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int* number, int count) {

	for (int i = 0; i < count; i++)
	{
		// i번째 값
		int best = i;

		// 다른 후보와 비교
		for (int j = i + 1; j < count; j++)
		{
			if (number[j] < number[best])
				best = j;
		}

		// 교체하는 과정
		if (i != best)
			Swap(number[i], number[best]);
	}

}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = rand() % 45 + 1;
		// 이미 찾은 값 확인
		bool found = true;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// 이미 찾은 값
				found = false;
				break;
			}
		}

		// 못 찾았으면 추가!
		if (found == true)
		{
			numbers[count] = randValue;
			count++;
		}
	}
}
int main() {
	// swap 함수 
	int a = 1;
	int b = 2;
	Swap(a, b);
	cout << a << " " << b << endl;

	// 정렬함수
	int number[6] = { 1,42,3,15,5,6 };
	Sort(number, sizeof(number)/sizeof(int));

	// 출력 
	ChooseLotto(number);
	for (int i = 0; i < 6; i++) {
		cout << number[i] << endl;
	}
}
```
- 문자열 연습 문제
``` c++
#include <iostream>
using namespace std;

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(char* str)
{
	// str이라는 문자열의 길이를 반환
	int count = 0;
	
	while (str[count] != '\0')
		count++;

	return count;
}
```
- 문자열 복사 함수
```c++
char* StrCpy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}
```
- 포인터 버전
``` c++
char* StrCpy(char* dest, char* src){
	char* ret = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

return ret;
```
- 문자열 덧 붙이는 함수 
``` c++
char* StrCat(char* dest, char* src)
{
	int len = StrLen(dest);
	
	int i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';

	return dest;
}
```
- 포인터 버전 
```c++
char* StrCat(char* dest, char* src)
{
char* ret = dest;
	while (*dest)
		dest++;
	
	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return ret;
}
```
- 두 문자열 비교하는 함수
```c++
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
```

- 문자열 뒤집는 함수 
```c++
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
```

- 달팽이 문제 
``` c++
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
bool CanGo(int y, int x){
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}
void SetBoard(){
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
int main(){
	cin >> N;
	
	SetBoard();

	PrintBoard();
	
	return 0;
}
```
