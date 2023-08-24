#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c)
		cout << "Equilateral\n";
	else if ((a + b + c == 180) && (a == b || b == c || c == a)&&!(a==b&&b==c))
		cout << "Isosceles\n";
	else if ((a + b + c == 180) && (a != b && b != c && c != a))
		cout << "Scalene\n";
	else 
		cout << "Error\n";
}

