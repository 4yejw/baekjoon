#include <iostream>
using namespace std;
int main() {
	int N = 0;
	cin >> N;
	bool NoConstructor = 1;
	//N의 자릿수 구하기
	int count = 0;
	int n = N;
	while (n != 0) {
		count++;
		n /= 10;
	}
	for (int i = N - (count * 9); i <= N; i++) {
		int Sum = i;
		int k = i;
		while (k != 0) {
			Sum += k % 10;
			k /= 10;
		}
		if (Sum == N) {
			cout << i << '\n';
			NoConstructor = 0;
			break;
		}
	}
	if (NoConstructor)
		cout << 0;
}