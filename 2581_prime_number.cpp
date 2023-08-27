#include <iostream>
using namespace std;

int main() {
	int M = 0, N = 0;
	cin >> M >> N;
	int arr[10001];
	fill_n(arr, 10001, 1);
	arr[1] = 0;

	//에라토스테네스의 체
	for (int i = 2; i*i <= N; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= N; j += i)
				arr[j] = 0;
		}
	}

	int count = 0;
	int sum = 0;
	int first = 0;
	for (int i = M; i <= N;i++) {
		if (arr[i] == 1) {
			sum += i;
			count++;
			if (count == 1)
				first = i;
		}
	}
	if (count != 0) {
		cout << sum << '\n';//소수의 합
		cout << first;//소수 중 최솟값
	}
	else
		cout << -1;//소수가 없을 때
}