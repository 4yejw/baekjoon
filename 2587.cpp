#include <iostream>
using namespace std;

int main() {
	int List[5];
	int Sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> List[i];
		Sum +=List[i];
	}
	
	for (int pass = 0; pass < 5; pass++) {
		for (int a = 1; a < 5 - pass; a++) {
			if (List[a - 1] > List[a]) {
				int tmp = List[a];
				List[a] = List[a - 1];
				List[a - 1] = tmp;
			}
		}
	}

	cout << Sum / 5<<endl;
	cout << List[2];
}