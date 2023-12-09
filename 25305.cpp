#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	int N, k;
	cin >> N >> k;
	
	int* score = new int[N];
	for (int i = 0; i < N; i++)
		cin >> score[i];

	for (int pass = 0; pass < N; pass++) {
		for (int a = 1; a < N - pass; a++) {
			if (score[a - 1] < score[a]) {
				int tmp = score[a];
				score[a] = score[a - 1];
				score[a - 1] = tmp;
			}
		}
	}

	cout << score[k - 1];
}