#include <iostream>
using namespace std;
int main() {
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int H = 0, W = 0, N = 0;
		cin >> H >> W >> N;
		int Y = 0, X = 0;
		if (N % H == 0) {
			Y = H*100;
			X = N / H;
		}
		else {
			Y = (N % H)*100;
			X = N / H+1;
		}
		cout << Y+ X << '\n';
	}
}