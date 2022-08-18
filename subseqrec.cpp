#include<bits/stdc++.h>
using namespace std;
void subs(vector<int >arr, vector<vector<int>>&ans, int index, vector<int>&h) {


	if (arr.size() == index) {
		ans.push_back(h);
		return;
	}
	h.push_back(arr[index]);
	subs(arr, ans, index + 1, h);
	h.pop_back();
	subs(arr, ans, index + 1, h);


}
int main() {
	vector<int>arr = {3, 1, 2};
	vector<vector<int>>ans;
	vector<int>h(0);
	subs(arr, ans, 0, h);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}


