#include <iostream>
using namespace std;
int main() {
	while (true) {
		int a = 0, b = 0, m = 0;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		m = a * b;
		if (a % b != 0 && b % a == 0)
			cout << "factor" << '\n';
		else if (a % b == 0 && b % a != 0)
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}
}