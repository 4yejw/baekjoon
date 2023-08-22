#include <iostream>
using namespace std;

int main() {
	int N = 0, M = 0;
	cin >> N >> M;//M°³¾¿ NÁÙ

	int A[101][101] = { 0, };
	int B[101][101] = { 0, };
	int C[101][101] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) 
			cin >> A[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << C[i][j] << ' ';
		cout << endl;
	}
}