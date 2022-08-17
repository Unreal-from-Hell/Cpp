#include <iostream>

using namespace std;

// ���ڿ� ���ڿ�
// char�� bool�� ���� �������� '����'�� �ǹ̸� ��Ÿ���� ���� ���

// char : ���ĺ� / ���� ���ڸ� ��Ÿ����.
// wchar_t : �����ڵ� ���ڸ� ��Ÿ����.


// ASCII (American Standard Code for Information Interchange)

// '����'�� �ǹ̷� ���� ����ǥ ''���
char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;

// ����ȭ �ô뿡�� ��� ����� �� ����
// �� ���� ��� ���ڿ� ���� �����ڵ带 �ο��� ���� �����ڵ� (unicode)
// ����) �����ڵ忡�� ���� ���� ��ȣ�� �����ϴ°� �ѱ���/�߱���

// �����ڵ� ǥ�� ����� ���������� �ִ�. (UTF8, UTF16)
// UTF8
// - ���ĺ�, ���� 1����Ʈ (ASCII ������ ��ȣ)
// - �ѱ�, ���� �� 3����Ʈ
// UTF16
// - ���ĺ�, ����, �ѱ�, ���� �� ���� ��κ� ���� 2����Ʈ
// - �ſ� �������� ��� ���ڸ� 4����Ʈ (��ǻ� �����ص� ��)

wchar_t wch = L'��';

// Escape Sequence
// ǥ���ϱ� �ָ��� ���ڸ� ǥ��
// \0 = �ƽ�Ű�ڵ�0 = NULL
// \t = �ƽ�Ű�ڵ�9 = Tab
// \n = �ƽ�Ű�ڵ�10 = LineFeed (���� �Ʒ���)
// \r = �ƽ�Ű�ڵ� 13 = CarriageReturn (Ŀ�� <<)
// \' = ���� ����ǥ

// ���ڿ�
// ���ڵ��� ���� ���� ���ִ� �� (���� �迭)
// ������ (1~8����Ʈ) ���� �����̴�.
// ���ڿ��� \00�� ���ڿ��� ������ ����

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

	// cout�� char ����
	wcout.imbue(locale("kor"));
	wcout << wch << endl;
	// cout << wch << endl;

	cout << str << endl;
}