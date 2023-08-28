#include <iostream>
using namespace std;
int arr[10000001];
int main() {
	int N = 0;
	cin >> N;
	if (N == 1)
		return 0;
	fill_n(arr, 10001, 1);
	//소수를 만들기 
	arr[1] = 0;
	for (int i = 2; i * i <= N; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= N; j += i)
				arr[j] = 0;
		}
	}
	//소인수분해
	while (N != 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				cout << i << '\n';
				N /= i;
				break;
			}
		}
	}
}