#include <iostream>

using namespace std;

int main() {
	int a, b;
	char select;
	cout << "�� ���� �Է��ϼ��� : ";
	cin >> a >> b;
	cout << endl << "��Ģ������ ��ȣ�� �Է��ϼ��� : ";
	cin >> select;
	cout << endl;
	switch (select)
	{
	case '+':
		cout << a + b << endl;
		break;
	default:
		break;
	}
	return 0;
}