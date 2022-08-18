#include<bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 3;

	int arr[3] = {1, 2, 3};
	int w = 3;
	bool dp[n + 1][w + 1];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			if (i == 0 ) {
				dp[i][j] = false;
			}
			if (j == 0)
				dp[i][j] = true;
		}
	}


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			if (arr[i - 1] <= j) {
				dp[i][j] =  (dp[i - 1][j - arr[i - 1]]) || dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}

	}
	for (int l = 1; l < n + 1; l++) {
		for (int g = 1; g < w + 1; g++) {
			cout << dp[l][g] << " ";
		}
		cout << endl;
	}
}
