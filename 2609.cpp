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
	cout << gcd(A, B) << endl;//�ִ�����
	cout << A * B / gcd(A, B);//�ּҰ����
}