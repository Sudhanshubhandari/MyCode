#include<bits/stdc++.h>
using namespace std;

//----------------------Simple recursion------------------------
// int knapsack(int wt[], int val[], int w, int n) {
// 	if (w == 0 || n == 0) {
// 		return 0;
// 	}
// 	if (wt[n - 1] <= w) {
// 		return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
// 	}
// 	else {
// 		return knapsack(wt, val, w, n - 1);
// 	}
// }

//-----------------------Using Top down DP -----------------------------

// int dp[5][52]; //Give size according to constraint given

// int knapsack(int wt[], int val[], int w, int n) {
// 	memset(dp, -1, sizeof(dp));

// 	if (w == 0 || n == 0) {
// 		return 0;
// 	}
// 	if (dp[n][w] != -1)	{
// 		return dp[n][w];
// 	}
// 	if (wt[n - 1] <= w) {
// 		return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
// 	}
// 	else {
// 		return dp[n][w] = knapsack(wt, val, w, n - 1);
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int wt[] = {1, 2, 3};
// 	int val[] = {4, 8, 5};
// 	int w = 4;
// 	cout << knapsack(wt, val, w, 4);
// }

//---------------- Bottom up Approach------------------


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n = 3;
	int  w = 4;

	int wt[3] = {1, 2, 3};
	int val[3] = {4, 2, 5};
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
			if (wt[i - 1] <= j) {
				dp[i][j] = max((val[i - 1] + dp[i - 1][j - wt[i - 1]]), dp[i - 1][j]);
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