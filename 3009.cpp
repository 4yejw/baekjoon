#include <iostream> 
using namespace std;
struct point {
	int x;
	int y;
};
int main() {
	point P[4];
	cin >> P[0].x >> P[0].y;
	cin >> P[1].x >> P[1].y;
	cin >> P[2].x >> P[2].y;

	if (P[0].x == P[1].x)
		P[3].x = P[2].x;
	else if (P[0].x == P[2].x)
		P[3].x = P[1].x;
	else if (P[1].x == P[2].x)
		P[3].x = P[0].x;

	if (P[0].y == P[1].y)
		P[3].y = P[2].y;
	else if (P[0].y == P[2].y)
		P[3].y = P[1].y;
	else if (P[1].y == P[2].y)
		P[3].y = P[0].y;

	cout << P[3].x << ' ' << P[3].y << '\n';
}
