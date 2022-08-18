#include<bits/stdc++.h>
using namespace std;
int canplace(int n, int board[][20], int x, int y) {
	for (int k = 0; k < x; k++) {
		if (board[k][y] == 1) {
			return 0;
		}

	}
	int i = x;
	int j = y;
	while (i >= 0 && j >= 0) {
		if (board[i][j] == 1) {
			return 0;
		}
		i--;
		j--;
	}
	i = x;
	j = y;
	while (i >= 0 && j < n) {
		if (board[i][j] == 1) {
			return 0;
		}
		i--; j++;

	}
	return true;
}
void print(int n, int board[][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int solvequeen(int n, int board[][20], int i) {
	if (i == n) {
		// print(n, board);
		return 1;
	}
	int ways = 0;

	for (int j = 0; j < n; j++) {

		if (canplace(n, board, i, j)) {
			board[i][j] = 1;
			ways += solvequeen(n, board, i + 1);


		}
		board[i][j] = 0;
	}
	return ways;
}
int main() {
	int n = 4;
	int board[20][20] = {0};
	cout << solvequeen(n, board, 0);
}
