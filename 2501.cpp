#include <iostream>
using namespace std;
int main() {
	int N = 0, K = 0;
	cin >> N >> K;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) 
			count++;
		if (count == K) {
			cout << i;
			break;
		}
	}
	if (count < K)
		cout << 0;
}