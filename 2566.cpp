#include <iostream>
using namespace std;
int main() {
	int A[9][9] = { 0, };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cin >> A[i][j];
	}
	int Max = 0;
	int I = 0, J = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[i][j] > Max) {
				Max = A[i][j];
				I = i;
				J = j;
			}
		}
	}
	cout << Max << '\n' << I+1 << ' ' << J+1;
}