#include <iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;

	int i, j;

	for (int k = 1;; k++) {
		if (k % 2 == 0) {
			i = 1;
			
			for (j = k; j >= 1; j--) {
				N--; 
				if (N == 0) {
					cout << i << '/' << j;
					goto point;
				}
				i++;
			}
		}
		else {
			i = k;
			
			for (j = 1; j <= k; j++) {
				N--;
				if (N == 0) {
					cout << i << '/' << j;
					goto point;
				}
				i--;
			}
		}
	}
point:
	return 0;
}