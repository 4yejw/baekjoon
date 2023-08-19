#include <iostream>
using namespace std;
int main() {
	int N = 0;
	cin >> N;
	int max_x = -1000000, min_x = 1000000;
	int max_y = -1000000, min_y = 1000000;
	for (int i = 0; i < N; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		if (max_x <= x)
			max_x = x;
		if (min_x >= x)
			min_x = x;
		if (max_y <= y)
			max_y = y;
		if (min_y >= y)
			min_y = y;
	}
	cout << (max_x - min_x) * (max_y - min_y) << '\n';
}