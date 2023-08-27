#include <iostream>
using namespace std;

int main() {
	int M = 0, N = 0;
	cin >> M >> N;
	int arr[10001];
	fill_n(arr, 10001, 1);
	arr[1] = 0;

	//�����佺�׳׽��� ü
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
		cout << sum << '\n';//�Ҽ��� ��
		cout << first;//�Ҽ� �� �ּڰ�
	}
	else
		cout << -1;//�Ҽ��� ���� ��
}