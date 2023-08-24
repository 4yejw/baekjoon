#include <iostream>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	while (T != 0) {
		int arr[15][15]{ 0, };
		int k = 0, n = 0;
		cin >> k >> n;
		
		for (int i = 1; i <= n; i++) 
			arr[0][i] = i;

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				int sum = 0;
				for (int k = 1; k <= j; k++)
					sum += arr[i - 1][k];
				arr[i][j] = sum;
			}
		}
		cout << arr[k][n] << endl;
		T--;
	}
}