#include <iostream>
using namespace std;
int main() {
	int N = 0;
	cin >> N;
	int arr[101][101] = { 0, };
	for (int i = 0; i < N; i++) {
		int row = 0, col = 0;
		cin >> row >> col;
		for (int i = col; i < col+10; i++) {
			for (int j = row; j < row + 10; j++)
				arr[i][j] = 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] == 1)
				sum++;
		}
	}
	cout << sum;
}