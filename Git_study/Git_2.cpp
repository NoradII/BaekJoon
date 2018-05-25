#include <iostream>

using namespace std;

int main() {
	int a, b;
	char select;
	cout << "두 수를 입력하세요 : ";
	cin >> a >> b;
	cout << "사칙연산의 부호를 입력하세요 : ";
	cin >> select;
	switch (select)
	{
	case '+':
		cout << a + b << endl;
		break;
	case '-':
		cout << a - b << endl;
		break;
	default:
		break;
	}
	return 0;
}