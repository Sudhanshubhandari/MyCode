
#include<bits/stdc++.h>
using namespace std;
int gridways(int m, int n, int i, int j) {
	if (i == m - 1 && j == n - 1) {
		return 1;
	}
	if (i >= m  or j >= n ) {
		return 0;
	}
	int ways = gridways(m, n, i + 1, j) + gridways(m, n, i, j + 1);
	return ways + 1 ;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	cout << gridways(n, m, 0, 0);
}