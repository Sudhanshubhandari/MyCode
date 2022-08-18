#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&s, int k) {
	if (k == 1) {
		cout << s.top();
		return;
	}

	s.pop();
	solve(s, k - 1);

	return ;
}
void insert(stack<int>&s, int temp) {

	if (s.size() == 0 or s.top() <= temp)  {
		s.push(temp);
		return;
	}
	int val = s.top();
	s.pop();

	insert(s, temp);
	s.push(val);

	return;
}
void sort(stack<int>&s) {
	if (s.size() == 1) {
		return;
	}
	int temp = s.top();
	s.pop();
	sort(s);
	insert(s, temp); //5 8 9 7


}
void middle(stack<int>&s) {
	int k = s.size() / 2 + 1;
	if (k == 0) {
		return;
	}
	solve(s, k);
	return ;
}




void reverse(stack<int>&s) {

	if (s.size() == 1) {

		return;
	}


	int temp = s.top();
	s.pop();
	reverse(s);
	insert(s, temp);



	return;
}

int Kthgrammer(int n, int k) {

	if (n == 1 && k == 1) {
		return 0;
	}
	int mid = (pow(2, n - 1)) / 2;

	if (k <= mid) {
		return Kthgrammer(n - 1, k );

	}
	else {
		return !(Kthgrammer(n - 1, k - mid));

	}
}

int main() {
	int y = 2;
	int l = 2;
	int j = Kthgrammer(y, l);
	cout << j;
	// stack<int>s;
	// s.push(5);
	// s.push(7);
	// s.push(9);
	// s.push(8);


	// sort(s);

	// while (!s.empty()) {
	// 	cout << s.top() << endl;
	// 	s.pop();
	// }

}

