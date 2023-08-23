#include <iostream>
using namespace std;

int main() {
	char arr[5][16] = {'\0',};
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 5; i++)
			if (arr[i][j] != '\0')
				cout << arr[i][j];
	}
}