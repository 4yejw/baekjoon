#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a = 0, b = 0, c = 0;
	while (true) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)//000�϶� �ݺ� ����
			break;

		bool Invalid = 1;
		if (max({ a,b,c }) >= (a + b + c - max({ a,b,c }))) {
			Invalid = 0;//�ﰢ�� ������ �������� ���� ��
			cout << "Invalid\n";
		}

		if (Invalid && a == b && b == c)//�� ���� ������
			cout << "Equilateral\n";
		else if (Invalid && a == b && b != c)
			cout << "Isosceles\n";
		else if (Invalid && b == c && a != b)
			cout << "Isosceles\n";
		else if (Invalid && a == c && b != c)
			cout << "Isosceles\n";
		else if (Invalid && a != b && a != c)//�� ���� ��� �ٸ���
			cout << "Scalene\n";
	}
}