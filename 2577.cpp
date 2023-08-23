#include <iostream>
#include <string>
using namespace std;
int main() {
	int a = 0, b = 0, c = 0;
	string result;
	cin >> a >> b >> c;
	result = to_string(a * b * c);
	for (int i = 0; i <10; i++) {
		int count = 0;
		for (int j = 0; j < result.length(); j++) {
			if (result[j] == 48 + i)
				count++;
		}
		cout << count << endl;
	}
}