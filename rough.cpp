
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subset(vector<vector<int>>&ans, vector<int>&v, int i, int arr[]) {
	if (v.size() == i)
	{
		ans.push_back(v);
	}
	v.push_back(arr[i]);

	subset(ans, v, i + 1, arr);

	return ans;

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[3] = {1, 2, 3};
	vector<int>v;
	vector<vector<int>>ans;
	vector<vector<int>>a = subset(ans, v, 0, arr);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}









