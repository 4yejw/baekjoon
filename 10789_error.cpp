#include <iostream>
#include <string>
using namespace std;
struct word {
	string arr;
};
int main() {
	word W[5];
	long unsigned int max = 0;
	for (int i = 0; i < 5; i++) {
		cin >> W[i].arr;
		if (max <= W[i].arr.length()) 
			max = W[i].arr.length();
		else
			W[i].arr.resize(max);

	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < 5; j++) {
			if(W[j].arr[i]!='\0')
				cout << W[j].arr[i];
		}
	}
}