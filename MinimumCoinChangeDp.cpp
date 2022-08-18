#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 3;
	int  w = 4;

	int coin[3] = {1, 2, 3};

	int dp[n + 1][w + 1];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			if (i == 0 ) {
				dp[i][j] = 0;
			}
			if (j == 0) {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			if (coin[i - 1] <= j) {
				dp[i][j] = min((dp[i][j - coin[i - 1]]), dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}

	}
	// for (int k = 1; k < n + 1; k++) {
	// 	for (int f = 1; f < w + 1; f++) {

	// 		cout << dp[k][f] << " ";
	// 	}
	cout << dp[n][w] << endl;

}