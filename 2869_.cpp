#include <iostream>
#include <cmath>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int V=0, A=1, B=0;
	cin >> A >> B >> V;
	int Day=0;

	Day += (V - B) / (A - B);

	if ((V - B) % (A - B) != 0) 
		Day++;
	
	if (A >= V)
		cout << 1;
	else
		cout << Day;
}