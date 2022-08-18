
#include<bits/stdc++.h>
using namespace std;

void printParanthesis(int n, string s, int o, int c) {
	if (n == 0 && c == o) {
		cout << s << endl;
		return;
	}
	if (n > 0) {
		printParanthesis(n - 1, s + "(", o + 1, c);
	}
	if (o > c) {
		printParanthesis(n, s + ")", o, c + 1);
	}
}

int main()
{
	int n;
	cin >> n;

	printParanthesis(n, "", 0, 0);

}