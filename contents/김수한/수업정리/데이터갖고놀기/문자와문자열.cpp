#include <iostream>

using namespace std;

// 문자와 문자열
// char도 bool과 같이 정수지만 '문자'의 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다.


// ASCII (American Standard Code for Information Interchange)

// '문자'의 의미로 작은 따옴표 ''사용
char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;

// 국제화 시대에는 영어만 사용할 수 없음
// 전 세계 모든 문자에 대해 유일코드를 부여한 것이 유니코드 (unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어

// 유니코드 표기 방식이 여러가지가 있다. (UTF8, UTF16)
// UTF8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 한글, 한자 등 3바이트
// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = L'안';

// Escape Sequence
// 표기하기 애매한 문자를 표현
// \0 = 아스키코드0 = NULL
// \t = 아스키코드9 = Tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드 13 = CarriageReturn (커서 <<)
// \' = 작은 따옴표

// 문자열
// 문자들이 열을 지어 모여있는 것 (문자 배열)
// 정수는 (1~8바이트) 고정 길이이다.
// 문자열은 \00을 문자열의 끝으로 간주

char str[] = { 'h', 'e', 'l', 'l', 'o' };
char str2[] = "Hello World";
wchar_t str3[] = L"Hello World";

int main()
{
	char str[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	cout << str2 << endl;

	cout << ch << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;

	// cout은 char 전용
	wcout.imbue(locale("kor"));
	wcout << wch << endl;
	// cout << wch << endl;

	cout << str << endl;
}