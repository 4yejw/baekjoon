#include <iostream>
using namespace std;
int main() {
	int N = 0, M = 0;
	cin >> N >> M;//카드의 개수,최대값

	int arr[100] = { 0, };
	for (int i = 0; i < N; i++) 
		cin >> arr[i];//카드 입력받기 

	int Max = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (Max < sum&&sum<=M)
					Max = sum;
			}
		}
	}
	cout << Max;
}