#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n = 0;//의견의 개수
	cin >> n;
	int arr[31] = { 0, };

	for (int i = 0; i < n; i++) {
		int dif = 0;//난이도 의견
		cin >> dif;
		arr[dif]++;
	}

	int del = round(n * 0.15);

	int T = 0;
	int i = 1;
	while (true) {
		if (T == del)
			break;
		if (arr[i] == 0)
			i++;
		else if (arr[i] != 0) {
			arr[i]--;
			T++;
		}
	}

	T = 0;
	i = 30;
	while (true) {
		if (T == del)
			break;
		if (arr[i] == 0)
			i--;
		else if (arr[i] != 0) {
			arr[i]--;
			T++;
		}
	}

	double sum = 0.0;
	for (int i = 1; i < 31; i++) {
		if (arr[i] != 0)
			sum += arr[i] * i;
	}

	int people = n - del * 2;
	if (people <= 0)
		cout << 0;
	else
		cout << round(sum / people);
}