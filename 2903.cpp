#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N = 0;
	cin >> N;
	int k = 3;
	for (int i = 2; i <= N; i++)
		k = k + pow(2, i - 1);
	cout << k*k;
}