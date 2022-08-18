
#include<bits/stdc++.h>
using namespace std;

bool issafe(int mat[][9], int i, int j, int num, int n) {
	for (int k = 0; k < 9; k++) {
		if (mat[i][k] == num or mat[k][j] == num) {
			return false;
		}
	}
	int sx = (i / 3) * 3;
	int sy = (j / 3) * 3;
	for (int x = sx; x < sx + 3; x++) {
		for (int y = sy; y < sy + 3; y++) {
			if (mat[x][y] == num) {
				return false;
			}
		}
	}
	return true;

}


bool solvesud(int mat[][9], int i, int j, int n) {
	if (i == n) {
		for (int g = 0; g < 9; g++) {
			for (int l = 0; l < 9; l++) {
				cout << mat[g][l] << " " ;
			}
			cout << endl;
		}
		return true;
	}
	if (j == n) {
		return solvesud(mat, i + 1, 0, n);
	}
	if (mat[i][j] != 0) {
		return solvesud(mat, i, j + 1, n);
	}
	for (int num = 1; num <= n; num++) {
		if (issafe(mat, i, j, num, n)) {
			mat[i][j] = num;
			bool solvesub = solvesud(mat, i, j + 1, n);
			if (solvesub == true) {
				return true;
			}

		}
	}
	mat[i][j] = 0;
	return false;
}


int main() {
	int n = 9;
	int mat[9][9] =   {{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
	solvesud(mat, 0, 0, n);

}
