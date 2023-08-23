#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a = 0, b = 0, c = 0;
	while (true) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)//000일때 반복 중지
			break;

		bool Invalid = 1;
		if (max({ a,b,c }) >= (a + b + c - max({ a,b,c }))) {
			Invalid = 0;//삼각형 조건을 만족하지 않을 때
			cout << "Invalid\n";
		}

		if (Invalid && a == b && b == c)//세 변이 같을때
			cout << "Equilateral\n";
		else if (Invalid && a == b && b != c)
			cout << "Isosceles\n";
		else if (Invalid && b == c && a != b)
			cout << "Isosceles\n";
		else if (Invalid && a == c && b != c)
			cout << "Isosceles\n";
		else if (Invalid && a != b && a != c)//세 변이 모두 다를때
			cout << "Scalene\n";
	}
}