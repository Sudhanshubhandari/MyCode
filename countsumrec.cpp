#include<bits/stdc++.h>
using namespace std;

int count(int sum, int s, int n, int arr[], int index) {

	if (index == n) {
		if (sum == s) {

			return 1;
		}
		else {
			return 0;
		}

	}
	sum += arr[index];
	int l = count( sum, s, n, arr, index + 1);
	sum -= arr[index];
	int c = count( sum, s, n, arr, index + 1);
	return l + c;

}



int main() {
	int c, sum, s;
	int n = 3;
	int arr[] = {1, 2, 3};
	cout << count( 0, 2, n, arr, 0);

}