#include <iostream>

using namespace std;

int main() {
	int a, b;
	char select;
	cout << "�� ���� �Է��ϼ��� : ";
	cin >> a >> b;
	cout << "��Ģ������ ��ȣ�� �Է��ϼ��� : ";
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