#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 3;//size of arr
	int  w = 3;//length

	int length[3] = {1, 2, 3};
	int price[3] = {4, 2, 17};
	int dp[n + 1][w + 1];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			if (length[i - 1] <= j) {
				dp[i][j] = max((price[i - 1] + dp[i][j - length[i - 1]]), dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}

	}
	for (int k = 1; k < n + 1; k++) {
		for (int f = 1; f < w + 1; f++) {

			cout << dp[k][f] << " ";
		}
		cout << endl;
	}
}