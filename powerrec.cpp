#include <bits/stdc++.h>
using namespace std;
int pow(int m, int x) {
	if (x == 0) {
		return 1;
	}
	else if (x % 2 == 0) {
		int	y = pow(m, x / 2);
		return y * y;
	}
	else
		return m * pow(m, x - 1);

}

int main() {
	int a;
	cin >> a;
	int h;
	cin >> h;
	cout << pow(a, h);
}