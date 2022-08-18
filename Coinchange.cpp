#include<bits/stdc++.h>
using namespace std;
int minimumnumberofcoinchange(vector<int>&denom, int m) {
	vector<int>dp(m + 1, 0);
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		dp[i] = INT_MAX;
		for (auto it : denom) {
			if (i - it >= 0 and dp[i - it] != INT_MAX) {
				dp[i] = min(dp[i], dp[i - it] + 1);
			}
		}

	}
	return dp[m] == INT_MAX ? -1 : dp[m];

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>denom = {1, 5, 7, 10};
	int m = 15;
	cout << minimumnumberofcoinchange(denom, m);
}