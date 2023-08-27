#include <iostream>
using namespace std;
int main() {
	while (true) {
		int N = 0;
		cin >> N;
		if (N == -1)
			break;
		int sum = 0;
		int count = 0;
		for (int i = 1; i < N; i++) {
			if (N % i == 0) {
				sum += i;
				count++;
			}
		}
		if (sum == N) {
			cout << N << " = ";
			for (int i = 1; i < N; i++) {
				if (N % i == 0) {
					if (count > 1)
						cout << i << " + ";
					else
						cout << i;
					count--;
				}
			}
			cout << '\n';
		}
		else if (sum != N)
			cout << N << " is NOT perfect.\n";
	}
}