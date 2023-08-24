#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main() {
	int A = 0, B = 0;
	cin >> A >> B;
	cout << gcd(A, B) << endl;//최대공약수
	cout << A * B / gcd(A, B);//최소공배수
}