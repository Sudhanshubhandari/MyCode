
#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&v, int temp) {
	if (v.size() == 0 || v.top() <= temp) {
		v.push(temp);
		return ;
	}

	int val = v.top();
	v.pop();
	insert(v, temp);
	v.push(val);

}

void sort(stack<int>&v)
{
	if (v.size() == 1) {
		return ;
	}
	int temp = v.top();
	v.pop();
	sort(v);
	insert(v, temp);

}

int main() {

	stack<int>h;
	h.push(5);
	h.push(8);
	h.push(1);


	sort(h);
	stack<int>s;
	while (!h.empty()) {
		s.push(h.top());
		h.pop();
	}

	while (!s.empty()) {
		cout << s.top() << " " ;
		s.pop();

	}
}





