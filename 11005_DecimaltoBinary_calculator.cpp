#include <iostream>
#include <cstring>

using namespace std;
int main() {
	long long N = 0;
	int B = 0;
	cin >> N >> B;
	char str[40] = { '\0',};
	int i = 0;
	while (N!=0) {
		if (N % B >= 0 && N % B <= 9) //1-9 Á¤¼ö
			str[i] = (N % B) + '0';
		else //A-Z ¾ËÆÄºª
			str[i] = (N % B - 10) + 'A';
			N /= B;
			i++;
	}
	for(int i=strlen(str)-1;i>=0;i--)
		cout << str[i];
}