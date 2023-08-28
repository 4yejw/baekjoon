#include <iostream>
#include <algorithm>
#define SIZE 1000
using namespace std;
void InsertSort(int* A,int size) {
	for (int i = 1; i <= size-1; i++) {
		int CurrentElement = A[i];
		int j = i - 1;
		while (j >= 0 && (A[j] > CurrentElement)) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = CurrentElement;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int A[SIZE] = { 0, };
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> A[i];
	InsertSort(A,N);
	for (int i = 0; i < N; i++)
		cout << A[i] << '\n';
}