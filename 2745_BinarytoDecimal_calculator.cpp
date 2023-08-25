#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int main() {
	string N;
	int B = 0;
	cin >> N >> B;
	int sum = 0;
	int k = 0;
	for (int i = N.length()-1; i >= 0; i--) {
		if (isdigit(N[i]))//0-9정수일때
			sum += (N[i] - '0') * pow(B,k);
		else { //알파벳일때
			for (int j = 0; j < 26; j++) {
				if (N[i] == 65 + j) 
					sum += (10 + j) * pow(B, k);
			}
		}
		k++;
	}
	cout << sum;
}