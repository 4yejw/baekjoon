#include <iostream>
#include <string>
using namespace std;
int main() {
	while (true) {
		string Str;
		int N = 0;
		cin >> N;
		Str = to_string(N);
		if (Str == "0")
			break;
		bool No = 0;
		for (long unsigned int i = 0; i < Str.length() / 2; i++) {
			if (Str[i] != Str[Str.length() - (i + 1)])
				No = 1;
		}
		if (No)
			cout << "no\n";
		else
			cout << "Yes\n";
	}
}
